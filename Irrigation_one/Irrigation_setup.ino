// IRRIGATION SETUP FUNCTIONS

void SetupMorning(){
  draw.MorningData = Data;
  strcpy(draw.top, "Imposta l'ora");
  strcpy(draw.body1, "Mattina");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.MorningData);
  if(draw.MorningData > 23){
    Data--;
    draw.MorningData = Data;
  }
  if(draw.MorningData < 0){
    Data++;
    draw.MorningData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_setup_state == 1){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    IRRIGATION_setup_state = 2;
    Data = DEFAULT_DATA;
  } 
}

void SetupAfternoon(){
  draw.AfternoonData = Data;
  strcpy(draw.top, "Imposta l'ora");
  strcpy(draw.body1, "Pomeriggio");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.AfternoonData);
  if(draw.AfternoonData > 23){
    Data--;
    draw.AfternoonData = Data;
  }
  if(draw.AfternoonData < 0){
    Data++;
    draw.AfternoonData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_setup_state == 2){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    IRRIGATION_setup_state = 3;
    Data = DEFAULT_DATA;
  }   
}

void SetupEvening(){
  draw.EveningData = Data;
  strcpy(draw.top, "Imposta l'ora");
  strcpy(draw.body1, "Sera");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.EveningData);
  if(draw.EveningData > 23){
    Data--;
    draw.EveningData = Data;
  }
  if(draw.EveningData < 0){
    Data++;
    draw.EveningData = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_setup_state == 3){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    IRRIGATION_setup_state = 4;
    Data = DEFAULT_DATA;
  }  
}

void SetupIrrigationTime(){
  draw.Irrigation_Time = Data;
  strcpy(draw.top, "Imposta la durata");
  strcpy(draw.body1, "Minuti");
  strcpy(draw.bottom1, "Premi per continuare");
  DrawGraphic_SETUP(draw.top, draw.body1, draw.bottom1, draw.Irrigation_Time);
  if(draw.Irrigation_Time > 30){
    Data--;
    draw.Irrigation_Time = Data;
  }
  if(draw.Irrigation_Time < 1){
    Data++;
    draw.Irrigation_Time = Data;
  }   
  if((digitalRead(ENCODER_BUTTON)) == 0 && IRRIGATION_setup_state == 4){
    while((digitalRead(ENCODER_BUTTON)) == 0);
    DataSetting = false, SetupIRRIGATION = false; 
    IRRIGATION_setup_state = 0;
    Data = DEFAULT_DATA;
  }  
}
