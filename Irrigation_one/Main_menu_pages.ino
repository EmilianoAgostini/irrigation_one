// MAIN MENU

void Main_Menu() {
  strcpy(draw.top, "Timer irrigazione");
  strcpy(draw.body1, "Mattina");
  strcpy(draw.body2, "Pomeriggio");
  strcpy(draw.body3, "Sera");
  DrawGraphic_MAIN(draw.top, draw.body1, draw.body2, draw.body3, draw.MorningData, draw.AfternoonData, draw.EveningData);
 }

void SetupRTC_Menu() {
  if(SetupRTC == false){
    strcpy(draw.top, "Setup data e ora");
    strcpy(draw.body1, "Data");
    strcpy(draw.body2, "Ora");
    strcpy(draw.bottom1, "Premi per impostare");
    DrawGraphic_RTC_MAIN_SETUP(draw.top, draw.body1, draw.body2, draw.bottom1); 
  }
  if((digitalRead(ENCODER_BUTTON)) == 0 && DataSetting == false){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    if(DataSetting == false){
      rtc.writeProtect(false);
      DataSetting = true, SetupRTC = true;
      RTC_setup_state = 1;
      Data = DEFAULT_DATA;
    }
  }
  if(SetupRTC){
    switch(RTC_setup_state){
      case 1:SetupDay();
             break;
      case 2:SetupMonth();
             break;
      case 3:SetupYear();
             break;
      case 4:SetupHour();
             break;
      case 5:SetupMinute();
             break;
    }
  }
}

void SetupIRRIGATION_Menu() {
  if(SetupIRRIGATION == false){
    strcpy(draw.top, "Setup irrigazione");
    strcpy(draw.body1, "Mattina");
    strcpy(draw.body2, "Pomeriggio");
    strcpy(draw.body3, "Sera");
    strcpy(draw.bottom1, "Premi per impostare");
    DrawGraphic_IRRIGATION_MAIN_SETUP(draw.top, draw.body1, draw.body2, draw.body3, draw.bottom1, draw.MorningData, draw.AfternoonData, draw.EveningData);   
    if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_setup_state == 0){
      while((digitalRead(ENCODER_BUTTON)) == 0);
      if(DataSetting == false){
        DataSetting = true, SetupIRRIGATION = true;
        IRRIGATION_setup_state = 1;
        Data = DEFAULT_DATA;
      }
    }
  }
  if(SetupIRRIGATION){
    switch(IRRIGATION_setup_state){
      case 1:SetupMorning();
             break;
      case 2:SetupAfternoon();
             break;
      case 3:SetupEvening();
             break;
      case 4:SetupIrrigationTime();
             break;
    }
  }
}

void Manual_Irrigation(){
  if(IRRIGATION_state == 0){
    strcpy(draw.top, "Irrigazione manuale");
    strcpy(draw.body1, "Sistema OFF");
    strcpy(draw.body2, "Durata");
    strcpy(draw.bottom1, "Premi per avviare");
    DrawGraphic_MANUAL_IRR(draw.top, draw.body1, draw.body2, draw.bottom1, draw.Irrigation_Time);
    if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_state == 0){
      while((digitalRead(ENCODER_BUTTON)) == 0);
      IRRIGATION_state = 1;
    }
  }
  if(IRRIGATION_state == 1 || IRRIGATION_state == 2){
    strcpy(draw.top, "Irrigazione manuale");
    strcpy(draw.body1, "Sistema ON");
    strcpy(draw.body2, "Durata");
    strcpy(draw.bottom1, "Premi per fermare");
    DrawGraphic_MANUAL_IRR(draw.top, draw.body1, draw.body2, draw.bottom1, draw.Irrigation_Time);
    Irrigation();
    if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_state == 2){
      while((digitalRead(ENCODER_BUTTON)) == 0);
      IRRIGATION_state = 3;
    }
  } 
  if(IRRIGATION_state == 3){
    strcpy(draw.top, "Irrigazione manuale");
    strcpy(draw.body1, "Sistema ON");
    strcpy(draw.body2, "Durata");
    strcpy(draw.bottom1, "Arresto in corso...");
    DrawGraphic_MANUAL_IRR(draw.top, draw.body1, draw.body2, draw.bottom1, draw.Irrigation_Time);
    Irrigation();
  }
}

void System_Setup(){
  if(SystemAuto == false){
    strcpy(draw.top, "Setup sistema");
    strcpy(draw.body1, "Sistema MANUALE");
    strcpy(draw.bottom1, "Premi per impostare");
    DrawGraphic_System_SETUP(draw.top, draw.body1, draw.bottom1);
    if((digitalRead(ENCODER_BUTTON)) == 0 && SystemAuto == false){
      while((digitalRead(ENCODER_BUTTON)) == 0);
      SystemAuto = true;
    }
  }
  if(SystemAuto == true){
    strcpy(draw.top, "Setup sistema");
    strcpy(draw.body1, "Sistema AUTOMATICO");
    strcpy(draw.bottom1, "Premi per impostare");
    DrawGraphic_System_SETUP(draw.top, draw.body1, draw.bottom1);
    if((digitalRead(ENCODER_BUTTON)) == 0 && SystemAuto == true){
      while((digitalRead(ENCODER_BUTTON)) == 0);
      SystemAuto = false;
    }
  }
}
