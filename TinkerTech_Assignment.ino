#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include <SoftwareSerial.h>

Adafruit_SSD1306 display(-1);

int k = 0;
int kk = 0;
int counter = 0;

//char a[] = "Hello my name is Raj Vishal Turaga and this is the first time I am using this display peripheral and I'm not sure how much text it can take so lets see where this thing goes";
String a;
//char a[] = "Hello World";

char b[50];

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

  while(Serial.available() == 0);
  a = Serial.readString();
}

void loop() {
  if (a.length() >= 120)
  {
    for(int j = 0; j >-100;j--)
    {
      display.clearDisplay();
      display.setCursor(0,j);
      display.setTextSize(1);
      display.setTextWrap(true);
      display.print(a);
      display.display();
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
}


//  while(kk < strlen(a))
//    {
//        
//        for(int i = (counter*16);i <= (counter+1)*16 - 1; i++)
//        {
//            b[k] = a[i];
//            k++;
//            kk++;
//        }
//        
//        display.print(b);
//        display.display();
//        display.clearDisplay();
//        display.setCursor(0,0);
//        delay(500);
//        k = 0;
//        counter++;
//        
//    }
