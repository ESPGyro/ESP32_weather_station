// 客制化自己要顯示的文字檔

#include <pgmspace.h>

const unsigned char font_week_24 PROGMEM[] =  // 周
{
	0x00,0x00,0x00,0x10,0x00,0x04,0x0F,0xFF,0xFC,0x08,0x0C,0x08,0x08,0x08,0x08,0x08,0x08,0x28,0x0F,0xFF,
    0xF8,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x28,0x0F,0xFF,0xF8,0x08,0x00,0x08,0x09,0x01,0x08,0x08,
    0xFF,0x88,0x08,0x81,0x08,0x08,0x81,0x08,0x18,0x81,0x08,0x10,0x81,0x88,0x10,0xFE,0x08,0x10,0x00,0x08,
    0x20,0x01,0x08,0x40,0x00,0xF8,0x40,0x00,0x10,0x00,0x00,0x00  
};
const unsigned char font_Mon_24 PROGMEM[] =  // 一
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x40,0x00,0x0E,0x7F,0xFF,0xF0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char font_Tue_24 PROGMEM[] = // 二
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x18,0x00,0x70,0x07,0xFF,0x88,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x7F,0xFF,0xFE,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_Wed_24 PROGMEM[] = // 三
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x38,0x1F,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x0F,0xFF,0xF0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x08,0x00,0x00,0x0C,
    0x7F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_Thu_24 PROGMEM[] = // 四
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x20,0x00,0x04,0x1F,0xFF,0xFC,0x10,0xC2,0x0C,0x10,0xC2,0x0C,0x10,0xC2,
    0x0C,0x10,0xC2,0x0C,0x10,0x82,0x0C,0x10,0x82,0x0C,0x10,0x82,0x0C,0x10,0x82,0x0C,0x11,0x02,0x0C,0x11,
    0x02,0x0C,0x12,0x03,0xFC,0x14,0x00,0x0C,0x18,0x00,0x0C,0x10,0x00,0x0C,0x30,0x00,0x0C,0x3F,0xFF,0xFC,
    0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_Fri_24 PROGMEM[] =  // 五
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x3F,0xFF,0xFC,0x00,0x20,0x00,0x00,0x20,0x00,0x00,0x20,
    0x00,0x00,0x40,0x00,0x00,0x40,0x00,0x00,0x40,0x40,0x1F,0xFF,0xE0,0x00,0xC0,0x40,0x00,0x80,0x40,0x00,
    0x80,0x40,0x00,0x80,0x40,0x01,0x80,0x40,0x01,0x00,0x40,0x01,0x00,0x40,0x01,0x00,0x40,0x01,0x00,0x48,
    0x42,0x00,0x4C,0x7D,0xFF,0xB2,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_Sat_24 PROGMEM[] =  // 六
{
	0x00,0x00,0x00,0x00,0x40,0x00,0x00,0x20,0x00,0x00,0x10,0x00,0x00,0x18,0x00,0x00,0x08,0x00,0x00,0x08,
    0x0C,0x7F,0xFF,0xFE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x82,0x00,0x00,0xE1,0x00,0x00,0x80,0x80,0x01,
    0x80,0x40,0x01,0x00,0x40,0x02,0x00,0x20,0x02,0x00,0x10,0x04,0x00,0x18,0x08,0x00,0x08,0x10,0x00,0x0C,
    0x20,0x00,0x0C,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_Sunday_24 PROGMEM[] = // 日 
{
	0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x30,0x07,0xFF,0xE0,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,
    0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x07,0xFF,0xE0,0x04,0x00,0x20,0x04,
    0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x04,0x00,0x20,0x07,0xFF,0xE0,
    0x04,0x00,0x20,0x04,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00
};
const unsigned char font_snow PROGMEM[] =  // 雪 
{
	0x3F,0xF8,0x01,0x00,0x7F,0xFE,0x41,0x02,0x9D,0x74,0x01,0x00,0x1D,0x70,0x00,0x00,
	0x3F,0xF8,0x00,0x08,0x00,0x08,0x1F,0xF8,0x00,0x08,0x00,0x08,0x3F,0xF8,0x00,0x08
};

const unsigned char font_rain PROGMEM[] =  // 雨
{
	0x00,0x00,0xFF,0xFE,0x01,0x00,0x01,0x00,0x01,0x00,0x7F,0xFC,0x41,0x04,0x41,0x04,
	0x49,0x44,0x45,0x24,0x41,0x04,0x49,0x44,0x45,0x24,0x41,0x04,0x41,0x14,0x40,0x08
};

const unsigned char font_sun PROGMEM[] =  // 晴
{
	0x00,0x20,0x00,0x20,0x7B,0xFE,0x48,0x20,0x49,0xFC,0x48,0x20,0x4B,0xFE,0x78,0x00,
	0x49,0xFC,0x49,0x04,0x49,0xFC,0x49,0x04,0x79,0xFC,0x49,0x04,0x01,0x14,0x01,0x08
};

const unsigned char font_shade PROGMEM[] = // 陰
{
	0x00,0x00,0x6C,0x38,0x7E,0x6C,0x6C,0xC6,0x6F,0xFF,0x78,0x00,0x79,0xFE,0x6C,0x0C,
	0x6C,0xFE,0x66,0x00,0x67,0xFF,0x66,0x60,0x7C,0xCC,0x79,0x86,0x63,0xFF,0x61,0x83 
};


const unsigned char font_more PROGMEM[] = // 多
{
	0x02,0x00,0x02,0x00,0x07,0xF0,0x08,0x20,0x38,0x40,0x04,0x80,0x03,0x40,0x0C,0x80,
	0x71,0xF8,0x02,0x08,0x0C,0x10,0x32,0x20,0x01,0x40,0x01,0x80,0x0E,0x00,0x70,0x00 
};

const unsigned char font_cloud PROGMEM[] =  // 雲
{
	0x00,0x00,0x00,0x10,0x0F,0xF8,0x20,0x82,0x3F,0xFF,0x20,0x82,0x4C,0x98,0x02,0xA0,
	0x0C,0x98,0x00,0x00,0x0F,0xF8,0x00,0x02,0x7F,0xFF,0x02,0x10,0x1F,0xFC,0x08,0x04 

};


const unsigned char font_zhu PROGMEM[] =  // 竹
{
    0x00,0x00,0x18,0x60,0x10,0x40,0x12,0x42,0x1F,0x7F,0x24,0x88,0x24,0x88,0x45,0x08,
	0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x08,0x04,0x38,0x04,0x10 
};

const unsigned char font_bei PROGMEM[] =  // 北
{
    0x00,0x00,0x03,0x60,0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x44,0x7E,0x7E,0x02,0x40,
	0x02,0x40,0x02,0x40,0x02,0x40,0x02,0x40,0x03,0x42,0x0E,0x42,0x70,0x43,0x20,0x3E 
};

const unsigned char font_deg PROGMEM[] = // 度
{
	0x00,0x00,0x00,0x00,0x01,0x80,0x02,0x40,0x02,0x40,0x01,0x80,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  
};
