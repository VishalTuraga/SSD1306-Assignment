#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include <SoftwareSerial.h>

Adafruit_SSD1306 display(-1);

String a;

void setup()
{
  Serial.begin(9600);
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Clear the buffer.
  display.clearDisplay();

  // Display Text
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print("Enter Text");
  display.display();
  
  while(Serial.available() == 0);
  a = Serial.readString();
  int b = a.length();
  int c = (ceil(b/20)-4)*8;
  //Serial.println(a.length());
  //Serial.println(c);
  
  if (a.length() >= 120)
  {
    for(int j = 0; j >-1*c;j--)
    {
      display.clearDisplay();
      display.setCursor(0,j);
      display.setTextSize(1);
      display.setTextWrap(true);
      display.print(a);
      display.display();
      //Serial.println(j);
      delay(500);    
    }
  }
  else
  {
    display.clearDisplay();
    display.setCursor(0,0);
    display.setTextSize(1);
    display.setTextWrap(true);
    display.print(a);
    display.display();
    delay(1000);
  } 
  delay(1000);
}
