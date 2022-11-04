// RTC SETUP FUNCTIONS

void SetupDay(){
  draw.DayData = Data;
  strcpy(draw.top, "Imposta la data");
  strcpy(draw.body1, "Giorno");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.DayData);
  if(draw.DayData > 31){
    Data--;
    draw.DayData = Data;
  }
  if(draw.DayData < 1){
    Data++;
    draw.DayData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && RTC_setup_state == 1){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    RTC_setup_state = 2;
    Data = DEFAULT_DATA;
  }
}

void SetupMonth(){
  draw.MonthData = Data;
  strcpy(draw.top, "Imposta la data");
  strcpy(draw.body1, "Mese");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.MonthData);
  if(draw.MonthData > 12){
    Data--;
    draw.MonthData = Data;
  }
  if(draw.MonthData < 1){
    Data++;
    draw.MonthData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && RTC_setup_state == 2){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    RTC_setup_state = 3;
    Data = DEFAULT_YEAR;
  }
}

void SetupYear(){
  draw.YearData = Data;
  strcpy(draw.top, "Imposta la data");
  strcpy(draw.body1, "Anno");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.YearData);
  if((digitalRead(ENCODER_BUTTON)) == 0 && RTC_setup_state == 3){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    RTC_setup_state = 4;
    Data = DEFAULT_DATA;
  }
}

void SetupHour(){
  draw.HourData = Data;
  strcpy(draw.top, "Imposta l'ora");
  strcpy(draw.body1, "Ora");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.HourData);
  if(draw.HourData > 23){
    Data--;
    draw.HourData = Data;
  }
  if(draw.HourData < 0){
    Data++;
    draw.HourData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && RTC_setup_state == 4){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    RTC_setup_state = 5;
    Data = DEFAULT_DATA;
  } 
}

void SetupMinute(){
  draw.MinuteData = Data;
  strcpy(draw.top, "Imposta l'ora");
  strcpy(draw.body1, "Minuti");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.MinuteData);
  if(draw.MinuteData > 59){
    Data--;
    draw.MinuteData = Data;
  }
  if(draw.MinuteData < 0){
    Data++;
    draw.MinuteData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && RTC_setup_state == 5){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    rtc.setDate(draw.DayData, draw.MonthData, draw.YearData);
    delay(100);
    rtc.setTime(draw.HourData, draw.MinuteData, draw.SecondData);
    delay(100);
    rtc.writeProtect(true);
    DataSetting = false, SetupRTC = false; 
    RTC_setup_state = 0;
  }  
}
