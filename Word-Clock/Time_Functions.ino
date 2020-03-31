//----------------------------------------------------------------------------------------------
//FUNCTIONS THAT MODIFY AND ACCESS TIME
/*
// Adds a second to the RTC time.
void add_sec(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 1));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts a second from the RTC time.
void sub_sec(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 1));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

// Adds a minute to the RTC time.
void add_min(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 60));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts a minute from the RTC time.
void sub_min(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 60));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

// Adds an hour to the RTC time.
void add_hour(){
  rtc.adjust(DateTime(rtc.now().unixtime() + 3600));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}

//Subtracts an hour from the RTC time.
void sub_hour(){
  rtc.adjust(DateTime(rtc.now().unixtime() - 3600));
    Serial.print(rtc.now().hour(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().minute(), DEC);
    Serial.print(':');
    Serial.print(rtc.now().second(), DEC);
    Serial.println();
}
*/

//Returns integer value of the second.
int get_sec(void){
  int s;
  s = (int)rtc.now().second();
  return s;
}

//Returns integer value of the minute.
int get_min(void){
  int m;
  m = (int)rtc.now().minute();
  return m;
}

//Returns integer value of the hour.
int get_hour(void){
  int h;
  h = (int)rtc.now().hour() + DST;
  return h;
}

//Daylight saving time check
void dstCheck(void)
{
 // ********************* Calculate offset for Sunday *********************
   int y = rtc.now().year();                          // DS3231 uses two digit year (required here)
   int x = (y + y/4 + 2) % 7;      // remainder will identify which day of month
                                                // is Sunday by subtracting x from the one
                                                // or two week window.  First two weeks for March
                                                // and first week for November
 // *********** Test DST: BEGINS on 2nd Sunday of March @ 2:00 AM *********
   if (rtc.now().month() == 3 && rtc.now().day() == (14 - x) && rtc.now().hour() >= 2 && useDST)
       {                                   
        DST = 1;                           // Daylight Savings Time is TRUE (add one hour)
       }
   if ((rtc.now().month() == 3 && rtc.now().day() > (14 - x)) || rtc.now().month() > 3 && useDST)
       {
        DST = 1;
       }
// ************* Test DST: ENDS on 1st Sunday of Nov @ 2:00 AM ************       
   if (rtc.now().month() == 11 && rtc.now().day() == (7 - x) && rtc.now().hour() >= 2)
       {
        DST = 0;                            // daylight savings time is FALSE (Standard time)
       }
   if ((rtc.now().month() == 11 && rtc.now().day() > (7 - x)) || rtc.now().month() > 11 || rtc.now().month() < 3)
       {
        DST = 0;
       }
}
