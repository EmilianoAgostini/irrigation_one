// GRAPHIC FUNCTIONS
// MAIN MENU

void DrawGraphic_MAIN(const char top[MAX_STR], char body1[MAX_STR], char body2[MAX_STR], char body3[MAX_STR], int data1, int data2, int data3){                                           
  // ********************************************************* TOP
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 12, 9, top);
  u8g.drawLine(0, 12, 128, 12);
  // ********************************************************* BODY
  u8g.setFont(u8g_font_6x10);
  // MORNING 
  u8g.drawStr( 5, 22, body1);
  u8g.drawStr( 75, 22, itoa(data1, str, 10));
  // AFTERNOON
  u8g.drawStr( 5, 34, body2);
  u8g.drawStr( 75, 34, itoa(data2, str, 10));
  // EVENING
  u8g.drawStr( 5, 46, body3);
  u8g.drawStr( 75, 46, itoa(data3, str, 10));
  u8g.drawLine(0, 49, 128, 49);
  // ********************************************************* BOTTOM
  // RTC NOW
  u8g.setFont(u8g_font_helvR08); 
  u8g.drawStr( 5, 61, rtc.getDateStr());
  u8g.drawStr( 80, 61, rtc.getTimeStr());
}


void DrawGraphic_RTC_MAIN_SETUP(char top[MAX_STR], char body1[MAX_STR], char body2[MAX_STR], char bottom[MAX_STR]){
    // ********************************************************* TOP
    u8g.setFont(u8g_font_6x13);
    u8g.drawStr( 12, 9, top);
    u8g.drawLine(0, 12, 128, 12);
    // ********************************************************* BODY
    // RTC 
    u8g.setFont(u8g_font_6x10);
    u8g.drawStr( 5, 26, body1);
    u8g.drawStr( 5, 42, body2);
    u8g.setFont(u8g_font_helvR08);    
    u8g.drawStr( 50, 26, rtc.getDateStr());
    u8g.drawStr( 50, 42, rtc.getTimeStr());
    u8g.drawLine(0, 49, 128, 49);
    // ********************************************************* BOTTOM
    u8g.setFont(u8g_font_6x13);
    u8g.drawStr( 7, 61, bottom);   
}

void DrawGraphic_IRRIGATION_MAIN_SETUP(char top[MAX_STR], char body1[MAX_STR], char body2[MAX_STR], char body3[MAX_STR],char bottom[MAX_STR], int data1, int data2, int data3){
  // ********************************************************* TOP
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 12, 9, top);
  u8g.drawLine(0, 12, 128, 12);
  // ********************************************************* BODY
  u8g.setFont(u8g_font_6x10);
  // MORNING 
  u8g.drawStr( 5, 22, body1);
  u8g.drawStr( 75, 22, itoa(data1, str, 10));
  // AFTERNOON
  u8g.drawStr( 5, 34, body2);
  u8g.drawStr( 75, 34, itoa(data2, str, 10));
  // EVENING
  u8g.drawStr( 5, 46, body3);
  u8g.drawStr( 75, 46, itoa(data3, str, 10));
  u8g.drawLine(0, 49, 128, 49);
  // ********************************************************* BOTTOM
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 7, 61, bottom);   
}

//                        SETUP MENU

void DrawGraphic_SETUP(char top[MAX_STR],char body1[MAX_STR], char bottom1[MAX_STR], int data1){
  // ********************************************************* TOP    
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 16, 9, top);
  u8g.drawLine(0, 12, 128, 12);
  // ********************************************************* BODY
  u8g.setFont(u8g_font_6x10);
  u8g.drawStr( 5, 34, body1);
  u8g.setFont(u8g_font_helvR08);
  u8g.drawStr( 75, 34, itoa(data1, str, 10));
  u8g.drawLine(0, 49, 128, 49);
  // ********************************************************* BOTTOM
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 5, 61, bottom1);
}

void DrawGraphic_MANUAL_IRR(char top[MAX_STR], char body1[MAX_STR], char body2[MAX_STR], char bottom1[MAX_STR], int data1){
  // ********************************************************* TOP    
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 7, 9, top);
  u8g.drawLine(0, 12, 128, 12);
  // ********************************************************* BODY
  u8g.setFont(u8g_font_6x10);
  u8g.drawStr( 5, 26, body1);
  u8g.drawStr( 5, 42, body2);
  u8g.setFont(u8g_font_helvR08);    
  u8g.drawStr( 50, 42, itoa(data1, str, 10));
  u8g.drawLine(0, 49, 128, 49);
  // ********************************************************* BOTTOM
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 7, 61, bottom1);
}

void DrawGraphic_System_SETUP(char top[MAX_STR],char body1[MAX_STR], char bottom1[MAX_STR]){
  // ********************************************************* TOP    
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 24, 9, top);
  u8g.drawLine(0, 12, 128, 12);
  // ********************************************************* BODY
  u8g.setFont(u8g_font_6x10);
  u8g.drawStr( 5, 34, body1);
  u8g.drawLine(0, 49, 128, 49);
  // ********************************************************* BOTTOM
  u8g.setFont(u8g_font_6x13);
  u8g.drawStr( 5, 61, bottom1);
}
