/*********************************************************************
This is an example sketch for our Monochrome Nokia 5110 LCD Displays

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/338

These displays use SPI to communicate, 4 or 5 pins are required to
interface

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.
BSD license, check license.txt for more information
All text above, and the splash screen must be included in any redistribution
*********************************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <Wire.h>
#include <Rtc_Pcf8563.h>
#include <DHT.h>

#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT11   // DHT 11 


// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
//init the real time clock
Rtc_Pcf8563 rtc;
//init the DHT sensor
DHT dht(DHTPIN, DHTTYPE);
float hum=0;
float temp=0;

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

const static unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup()   {
  Serial.begin(9600);
  dht.begin();
  //clear out all the registers
  rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  rtc.setDate(14, 6, 3, 0, 10);
  //hr, min, sec
  rtc.setTime(1, 15, 40);

  display.begin();
  // init done

  // you can change the contrast around to adapt the display
  // for the best viewing!
  display.setContrast(40);

  //display.display(); // show splashscreen
  //delay(2000);
  display.clearDisplay();   // clears the screen and buffer
}


void loop() {
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    //No update
  } else{
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(0,0);
    display.println(rtc.formatTime());
    display.println(rtc.formatDate(RTCC_DATE_ASIA));
    
    display.print("Hum: ");
    display.print(h);
    display.println("%");
    display.print("Temp: ");
    display.print(t);
    display.println("*C");

    
    display.display();
    delay(1000);
    display.clearDisplay();
  }  

}

