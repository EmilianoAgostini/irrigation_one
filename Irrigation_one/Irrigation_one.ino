// ARDUINO NANO PINOUT - ATMEGA 328
// DS1302:  CE pin    -> Arduino Digital 6
//          I/O pin   -> Arduino Digital 7
//          SCLK pin  -> Arduino Digital 8
// Library
#include "U8glib.h"
#include <DS1302.h>
// Rele Module
#define INVERTER 9
#define WATER_PUMP 10
// Encoder RepRap Adapter
#define ENCODER_PIN_A 2
#define ENCODER_PIN_B 3
#define ENCODER_BUTTON 4
// LCD 12864 RepRap Adapter
#define LCD_E 16
#define LCD_RS 17
#define LCD_4 18
// RTC DS1302
#define CE_PIN 6
#define IO_PIN 7
#define SCLK_PIN 8
// Constant
#define OFFSET 5
#define MIN_MENU_PAGE 1
#define MAX_MENU_PAGE 5
#define DEFAULT_YEAR 2022
#define DEFAULT_DATA 1
#define MAX_STR 30
// Variable
extern unsigned long timer0_millis;
int MenuPage = 1, Data = 1, LastEncoded = 0, Timer = 0, IrrigationHourEvent = 0;
int RTC_setup_state = 0, IRRIGATION_setup_state = 0, IRRIGATION_state = 0;
char str[MAX_STR];
// Boolean
bool DataSetting = false;
bool SetupRTC = false;
bool SetupIRRIGATION = false;
bool IrrigationDone = false;
bool SetClock = false;
bool SystemAuto = false;

struct GraphicStruct {
  char top[MAX_STR];
  char body1[MAX_STR];
  char body2[MAX_STR];
  char body3[MAX_STR];
  char bottom1[MAX_STR];
  char bottom2[MAX_STR];
  int HourData = 0;
  int MinuteData = 0;
  int SecondData = 0;
  int DayData = 0;
  int MonthData = 0;
  int YearData = 0;
  int MorningData = 8; 
  int AfternoonData = 12;
  int EveningData = 20;
  int Irrigation_Time = 1;
};

// Creazione oggetti
// GRAPHIC DRAW
GraphicStruct draw;
// LCD 12864
U8GLIB_ST7920_128X64_1X u8g(LCD_4, LCD_E, LCD_RS);
// RTC
DS1302 rtc(CE_PIN, IO_PIN, SCLK_PIN);
Time SystemTime;

void setup() { 
  u8g.setColorIndex(1);
  Serial.begin(9600);
  rtc.halt(false);
  rtc.writeProtect(true);
  pinMode(INVERTER, OUTPUT);
  pinMode(WATER_PUMP, OUTPUT);
  pinMode(ENCODER_PIN_A, INPUT_PULLUP);
  pinMode(ENCODER_PIN_B, INPUT_PULLUP);
  pinMode(ENCODER_BUTTON,  INPUT_PULLUP);
  // Set default pin status
  digitalWrite(INVERTER, LOW);   
  digitalWrite(WATER_PUMP, LOW);
  digitalWrite(ENCODER_PIN_A, HIGH);
  digitalWrite(ENCODER_PIN_B, HIGH);
  digitalWrite(ENCODER_BUTTON,  HIGH);
  // Set interrupt mode
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_A), UpdateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_PIN_B), UpdateEncoder, CHANGE);
}

void loop() {
  Automatic();
  u8g.firstPage();  
  do{
    switch(MenuPage){
      case 1:Main_Menu();
             break;
      case 2:SetupRTC_Menu();
             break;
      case 3:SetupIRRIGATION_Menu();
             break;
      case 4:Manual_Irrigation();
             break;
      case 5:System_Setup();
             break;
    }  
  }while(u8g.nextPage());
}
