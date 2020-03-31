#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <EEPROM.h>
#include "RTClib.h"

//Preliminary definitions.
#define PIN 6
#define LENGTH 100
#define BUTTON_DELAY 50
#define HOLD_DELAY 1000
#define RAINBOW_DELAY 150
RTC_DS3231 rtc;

#define DEBUG false

//Initialize the LED grid.
Adafruit_NeoPixel grid = Adafruit_NeoPixel(LENGTH, PIN, NEO_GRB + NEO_KHZ800);

//Color indices
byte top_color;
byte bottom_color;
bool colors_saved = false;
int cycle_count = 0;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  grid.begin();
  grid.show();

  // The following allow for updating of the RTC on upload and execution of the sketch.
  // Uncomment the appropriate line, upload and run the sketch, then comment the line back out
  // and upload the sketch again.
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  //rtc.adjust(DateTime(2020, 03, 31, 15, 17, 0)); //manual adjustment

  // reads the stored color values from EEPROM.
  top_color = EEPROM.read(0);
  bottom_color = EEPROM.read(1);

  pinMode(8, INPUT);
  pinMode(9, INPUT);
}

void loop() {
  static byte state = 0; // Keeps track of the current clock state.

  if (DEBUG)
  {
    if (cycle_count++ > 1000)
    {
      int t_hour = get_hour();
      int t_minute = get_min();
      int t_second = get_sec();
  
      char t_buff[16]; 
      sprintf(t_buff, "%d:%d:%d", t_hour, t_minute, t_second); 
      
      Serial.print("Cycle count hit 1000.\n");
      Serial.print("Time is currently: ");
      Serial.print(t_buff);
      Serial.print("\n\n");

      cycle_count = 0;
    }
  }

  //wipe();
  //switch(state){
  //  case 0: // Regular clock display
      //display_time(colors(top_color), colors(bottom_color));
      display_time(grid.Color(0, 222, 222), grid.Color(255, 0, 164));
      display_bday();
  //    check_buttons(&state);
  //    break;
  /*
    case 1: // Second menu state
      S(grid.Color(255, 255, 255));
      if(colors_saved == true){
        little_C(grid.Color(0, 255, 0));
      }
      else{
        little_C(grid.Color(255, 128, 0));
      }
      check_buttons(&state);
      break;
    case 2: // Minute menu state
      M(grid.Color(255, 255, 255));
      if(colors_saved == true){
        little_C(grid.Color(0, 255, 0));
      }
      else{
        little_C(grid.Color(255, 128, 0));
      }
      check_buttons(&state);
      break;
    case 3: // Hour menu state
      H(grid.Color(255, 255, 255));
      if(colors_saved == true){
        little_C(grid.Color(0, 255, 0));
      }
      else{
        little_C(grid.Color(255, 128, 0));
      }
      check_buttons(&state);
      break;
    case 4: // Numerical time display
      display_hm(colors(top_color), colors(bottom_color));
      check_buttons(&state);
      break;
    case 11: // Clock edit - seconds
      display_ms(grid.Color(255, 255, 255), flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100));
      check_buttons(&state);
      break;
    case 12: // Clock edit - minutes
      display_ms(flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100), grid.Color(255, 255, 255));
      check_buttons(&state);
      break;
    case 13: // Clock edit - hours
      display_hm(flash_color(grid.Color(255, 255, 255), grid.Color(255, 0, 0), 100), grid.Color(255, 255, 255));
      check_buttons(&state);
      break;
      */
  }
  grid.show();
}
