// SYSTEM FUNCTIONS

void UpdateEncoder(){
  int MSB = digitalRead(ENCODER_PIN_A);
  int LSB = digitalRead(ENCODER_PIN_B);
  
  int Encoded = (MSB << 1) | LSB;
  int sum  = (LastEncoded << 2) | Encoded;
  if(sum==0b0100){
    if(MenuPage < MAX_MENU_PAGE && DataSetting == false){
      MenuPage++;
    }
    if(DataSetting){
      Data++;
    }
  }
  if(sum==0b0111){
    if(MenuPage > MIN_MENU_PAGE && DataSetting == false){
      MenuPage--;
    }
    if(DataSetting){
      Data--;
    }
  }
  LastEncoded = Encoded; //store this value for next time
} 

void ResetClock(){
  rtc.writeProtect(false);
  SystemTime = rtc.getTime();
  draw.HourData = SystemTime.hour;
  draw.MinuteData = SystemTime.min;
  draw.SecondData = SystemTime.sec;
  rtc.setTime(draw.HourData, draw.MinuteData, draw.SecondData);
  rtc.writeProtect(true);
}

void ResetMillis(){
  timer0_millis = 0;
}

void Irrigation(){
  if(DataSetting == false){
    if(IRRIGATION_state == 1){
      ResetMillis();
      IRRIGATION_state = 2;
    }
    Timer = millis() / 1000;
    digitalWrite(INVERTER, HIGH);
    if(Timer > OFFSET){
      digitalWrite(WATER_PUMP, HIGH);
    }
    if(Timer > (draw.Irrigation_Time * 60) || IRRIGATION_state == 3){
      digitalWrite(WATER_PUMP, LOW);
      if(SetClock == false){
        delay(500);
        ResetClock();    
      }
      SetClock = true;
    }
    if(Timer > (draw.Irrigation_Time * 60) + OFFSET || IRRIGATION_state == 3){
      digitalWrite(INVERTER, LOW);
      SetClock = false;
      if(SetClock == false){
        delay(500);
        ResetClock();
        IRRIGATION_state = 0;
      }
      if(SystemAuto == true){
        IrrigationDone = true;
      }
    }
  }
}

void Automatic(){
  if(SystemAuto == true){
    SystemTime = rtc.getTime();
    if(SystemTime.hour == draw.MorningData && IrrigationDone == false || SystemTime.hour == draw.AfternoonData && IrrigationDone == false || SystemTime.hour == draw.EveningData && IrrigationDone == false){
      if(IRRIGATION_state == 0){
        IRRIGATION_state = 1;
      }
      Irrigation();
      IrrigationHourEvent = SystemTime.hour;
    }
    if(IrrigationHourEvent != SystemTime.hour && IrrigationDone == true){
      IrrigationDone = false;
    }
  }
}
