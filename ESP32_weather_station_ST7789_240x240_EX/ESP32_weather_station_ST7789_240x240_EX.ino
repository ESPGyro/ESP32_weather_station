// 天氣時鐘範例: 
// 使用 ESP32 + ST7789 抓取網路上的天氣資料並顯示在 TFT 上
// Library : TFT_eSPI / ArduinoJson
// FB : https://www.facebook.com/mason.chen.1420

#include <TFT_eSPI.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>    
#include <NTPClient.h>   
#include <ArduinoJson.h> 
#include <WiFiUdp.h>
#include "Arduino.h"
#include "Custom_font.h"  // 16x16字體和 24x24 字體
#include "Weather_icon.h"
#include "image.c"        // 匯入自己的照片檔
StaticJsonDocument<5000> doc;
int weatherKind;

// 設定要連的 WIFI 帳號和密碼
const char *ssid     = "xxxx";  
const char *password = "a12341234"; 

String now_address="",now_time="",now_high_tem="",now_low_tem="",now_rainfall="",now_wind_direction="",now_wind_speed="",now_hum="",now_weather=""; 
String weekDays[7]={"font_Sunday_24", "font_Mon_24", "font_Tue_24","font_Wed_24", "font_Thu_24", "font_Fri_24", "font_Sat_24"};
String months[12]={"January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December"};

// Open weather information 
// 如何得到自己的 key 請看影片 https://www.youtube.com/watch?v=xvZ69vHWvyQ
String apiKey = "c002da0891ab7f7cf450e862eee685d9";
String location = "Hsinchu,TW";  // Tainan,Kaohsiung,Taoyuan,Hsinchu,Taichung,Keelung
char server[] = "api.openweathermap.org";

String image_name = "test_0606";
WiFiClient wifiClient;
String weatherStr, nowTemp, maxTemp, minTemp;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "ntp.aliyun.com"); // NTP 得到時間
TFT_eSPI tft = TFT_eSPI();  
unsigned long currentSec;
int flag = 1;
int tm_Hour,tm_Minute,monthDay,tm_Month;
int weather_state;
int week_day; 

// 抓取 openweathermap 的氣象資訊
void get_openweather_data()
{
  String jsonTmp ;
  wifiClient.stop();
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (wifiClient.connect(server, 80)) {
    Serial.println("connected to server");
    // Make a HTTP request:
    wifiClient.print("GET /data/2.5/weather?");
    wifiClient.print("q=" + location);
    wifiClient.print("&appid=" + apiKey);
    wifiClient.print("&cnt=3");
    wifiClient.println("&units=metric");
    wifiClient.println("Host: api.openweathermap.org");
    wifiClient.println("Connection: close");
    wifiClient.println();
    wifiClient.flush();
  } else {
    Serial.println("unable to connect");
  }

  delay(500);
  while (wifiClient.available())
  {
    String jsonData = wifiClient.readStringUntil('\r');  
    Serial.println(jsonData);
    DeserializationError error = deserializeJson(doc, jsonData);

    // Test if parsing succeeds.
    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      //return;
    }
    //JsonArray array = doc.as<JsonArray>();
    // 解析 Json 的資料，把裏面的內容抓出來放到定義的變數 ( data1~8) 裏
    String data1 = doc["main"]["temp"];
    String data2 = doc["main"]["temp_min"];
    String data3 = doc["main"]["temp_max"];
    String data4 = doc["weather"][0]["main"];
    String data5 = doc["visibility"]["rain"]["3h"];
    String data6 = doc["wind"]["deg"];
    String data7 = doc["wind"]["speed"];
    String data8 = doc["main"]["humidity"];

    nowTemp = data1;
    minTemp = data2;
    maxTemp = data3;
    weatherStr = data4;
    
    now_high_tem = data3;
    now_low_tem = data2;
    now_rainfall = data5;
    now_wind_direction = data6;
    now_wind_speed = data7;
    now_hum = data8;
  }
}

void setup()
{
    Serial.begin(115200);

    tft.init();                         // 初始化
    tft.fillScreen(TFT_WHITE);          // 填上白色
    tft.setTextColor(TFT_BLACK);        // 字體為黑色
    tft.setCursor(15, 30, 1);           // 設定顯示的座標
    tft.setTextSize(2);
    
    tft.println("Connect to Wifi ~");

    WiFi.begin(ssid, password);              
    while (WiFi.status() != WL_CONNECTED)   
    {
      delay(500);
      Serial.print(".");
    }
    Serial.println("WiFi connected");        // 連線成功
    Serial.print("IP address: ");            
    Serial.println(WiFi.localIP());          // 印出 IP address
    tft.fillScreen(TFT_WHITE);
    tft.setCursor(20, 30, 2);            
    tft.setTextSize(2);  
    tft.println("WiFi Connected!");
    delay(200);
    
    get_openweather_data();
   
  if (WiFi.status() == WL_CONNECTED )
  {
    // 使用 NTP 抓取網路時間
    timeClient.begin();
    timeClient.setTimeOffset(8 * 3600); //UTC+8
    while (!timeClient.update()) {
      timeClient.forceUpdate();
    }
  }
    tft.fillScreen(TFT_BLACK);
}

void loop()
{    
    timeClient.update();
    unsigned long epochTime = timeClient.getEpochTime();
    Serial.println(epochTime);
    if(flag == 1)
    {
      currentSec = epochTime;
      flag = 0;
    }
    
    String formattedTime = timeClient.getFormattedTime();
    int tm_Hour = timeClient.getHours();
    int tm_Minute = timeClient.getMinutes();
    int tm_Second = timeClient.getSeconds();
    week_day = timeClient.getDay();
    
    struct tm *ptm = gmtime ((time_t *)&epochTime);
    int monthDay = ptm->tm_mday;
    int tm_Month = ptm->tm_mon+1;
    String currentMonthName = months[tm_Month-1];
    int tm_Year = ptm->tm_year+1900;
    String currentDate = String(tm_Month) + "/" + String(monthDay);
    String currentTime, hour, minute;
    if (tm_Hour < 10)
      hour = "0" + String(tm_Hour);
    else
      hour = String(tm_Hour);
    if (tm_Minute < 10)
      minute = "0" + String(tm_Minute);
    else
      minute = String(tm_Minute);
    currentTime = hour + ":" + minute;

//    Serial.println(currentTime);
    Serial.println(tm_Year);
    //Serial.println(currentSec);

      if(tm_Year > 2000) {
         get_openweather_data();
         tft.fillScreen(TFT_BLACK);   // 清空螢幕
         show_weather(currentTime, currentDate, tm_Year);  // 顯示時間和天氣介面
     }     
      delay(5000); // 等待 5 秒後換顯示個人照片
      
      tft.fillScreen(TFT_BLACK);   // 清空螢幕
      tft.setSwapBytes(true);      // 設定颜色由RGB->BGR
      tft.pushImage(4, 4, 240, 240, test_0606);  // 換成您要顯示的照片
      delay(15000);  // 等待 5 秒後換顯示天氣資料
   //   tft.fillScreen(TFT_BLACK);
}

// 顯示時間和氣象資訊 function
void show_weather(String currentTime, String currentDate, int tm_Year)
{ 
    uint16_t FG_color = TFT_WHITE;
    uint16_t BG_color = TFT_BLACK;
    //顯示時間
    tft.setCursor(25, 5, 4);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(3);
    tft.println(currentTime);    
    tft.drawFastHLine(10, 70, 200, tft.alphaBlend(0, BG_color,  FG_color)); //畫橫線
    // 顯示年
    tft.setCursor(150, 120, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(tm_Year);    
    // 顯示日期 
    tft.setCursor(150, 160, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(currentDate);    
    //顯示中文的星期幾
    tft.drawBitmap(160, 200, font_week_24, 24, 24, TFT_YELLOW);
    if ( week_day == 0 ){
        tft.drawBitmap(185, 200, font_Sunday_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 1 ){
        tft.drawBitmap(185, 200, font_Mon_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 2 ){
        tft.drawBitmap(185, 200, font_Tue_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 3 ){
        tft.drawBitmap(185, 200, font_Wed_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 4 ){
        tft.drawBitmap(185, 200, font_Thu_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 5 ){
        tft.drawBitmap(185, 200, font_Fri_24, 24, 24, TFT_YELLOW);      
        }
    if ( week_day == 6 ){
        tft.drawBitmap(185, 200, font_Sat_24, 24, 24, TFT_YELLOW);      
        }   
    tft.pushImage(0, 75, 30, 30, tem_icon);
    // 顯示溫度
    tft.setCursor(30, 75, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(nowTemp);    
    // 顯示度
    tft.drawBitmap(103, 80, font_deg, 16, 16, TFT_WHITE);
    // 顯示C
    tft.setCursor(120, 75, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println("C");    
  //  showtext(130,75,1,1,fg,bg,now_high_tem );
  //  showtext(130,85,1,1,fg,bg,now_low_tem);
    tft.pushImage(135, 75, 30, 30, hum_icon);
    // 顯示溼度
    tft.setCursor(163, 75, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(now_hum+"%");    
    // 顯示天氣狀況
    if ( weatherStr == "Clear"  ){
        tft.drawBitmap(90, 140, font_sun, 16, 16, TFT_WHITE);    
        weather_state = 0;  
        }
    if ( weatherStr == "Clouds" ){
        tft.drawBitmap(90, 140, font_more, 16, 16, TFT_WHITE);      
        tft.drawBitmap(106, 140, font_cloud, 16, 16, TFT_WHITE);      
        weather_state = 1;
        }
    if ( weatherStr == "Rain" ){
        tft.drawBitmap(90, 140, font_rain, 16, 16, TFT_WHITE);   
        weather_state = 2;   
        }
    if ( weatherStr == "Drizzle" ){
        tft.drawBitmap(90, 140, font_shade, 16, 16, TFT_WHITE);  
        weather_state = 3;    
        }
    if ( weatherStr == "Thunderstorm" ){
        tft.drawBitmap(90, 140, font_snow, 16, 16, TFT_WHITE);  
        weather_state = 4;    
        }

    // 顯示照片
    tft.setSwapBytes(true);    //圖片颜色由RGB->BGR
    tft.pushImage(15, 105,  64, 64, weather_icon[weather_state]);
    // 顯示位置 : 竹北
    tft.drawBitmap(90, 115, font_zhu, 16, 16, TFT_RED);
    tft.drawBitmap(107, 115, font_bei, 16, 16, TFT_RED);
   
    tft.pushImage(5, 165, 30, 30, rain_s_icon);
    tft.pushImage(5, 200, 30, 30, wind_icon);
    // 顯示降雨量
    tft.setCursor(45, 165, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(now_rainfall +" mm");    
    // 顯示風速
    tft.setCursor(45, 200, 2);
    tft.setTextColor(FG_color,BG_color);
    tft.setTextSize(2);
    tft.println(now_wind_speed +"m/s");    
}
