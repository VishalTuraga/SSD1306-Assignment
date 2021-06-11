#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <string.h>
#include <SoftwareSerial.h>

Adafruit_SSD1306 display(-1);

String a; // Global Variable to store the incoming text message

void setup()
{
  Serial.begin(9600); // Initialize the serial monitor
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize the Display with its I2C address

  
  display.clearDisplay(); // Clear the buffer.


  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0, 0); // Cursor is set to the co-ordinates (0,0)
}

void loop() {
  display.clearDisplay(); //Clear the display buffer
  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0, 0); // Cursor is set to the co-ordinates (0,0)
  display.print("Enter Text"); // Load the display buffer with the text "Enter the Text"
  display.display(); // display what is in the display buffer
  
  while(Serial.available() == 0); // wait for serial monitor to give a text input
  a = Serial.readString(); // store the data coming from the serial monitor in the initialized string.
  int b = a.length(); // calculate the length of the string (Number of characters in the string)
  int c = (ceil(b/20)-4)*8; // number of times the screen has to scroll down the pixel. Supposed to be (ceil(b/20)-4)*16) but that was also being to long so it was decreased to 8
  //Serial.println(a.length());
  //Serial.println(c);
  
  if (a.length() >= 80) // scrolling will happen only if the number of characters in the string is greater than or equal to 80 since the screen cant accomodate more than that
  {
    for(int j = 0; j >-1*c;j--)
    {
      display.clearDisplay();
      display.setCursor(0,j); // send the text up by one row (essentially decreasing the value of the y coordinate of the display
      display.setTextSize(1);
      display.setTextWrap(true); // Set text wrapping to true to make sure no character is being cut off.
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
  delay(5000);
}
