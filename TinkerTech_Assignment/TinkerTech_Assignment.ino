#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>
#include <SoftwareSerial.h>

Adafruit_SSD1306 display(-1);

//String a = "This is a very long message so I am going to extend this to a level"; //where the text needs to keep scrolling and scrolling and scrolling till I stop texting which is never going to happen anytime sooon";
int* b = (int*)calloc(50,sizeof(int));
int count = 0;
String a;
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
  while(Serial.available() == 0);
  a = Serial.readString();
  int c = countWords(a);
  int line = 0;
  int space = 20;
  int j = 0; //for printing the string
  display.clearDisplay(); //Clear the display buffer
  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0, 0); // Cursor is set to the co-ordinates (0,0)
  display.setTextWrap(true);
  for(int i = 0;i < c;i++)
  {
    if(b[i] > space)
    {
      //display.print("\n");
      space = 20;
      line += 8 ;
      display.setCursor(0,line);
      while(a[j] != 32)
      {
        display.print(a[j]);
        j++;
      }
      space -= (b[i] + 1);
    }
    else
    {
      space -= (b[i]+1);
      while(a[j] != 32)
      {
        display.print(a[j]);
        j++;
      }
    }
    display.print(" ");
    j++;
  }
  display.display();

  
//  for(int i = 0;i < c;i++)
//  {
//    Serial.print(b[i]);
//    Serial.print(" ");
//  }
//  Serial.println(" ");
  delay(1000);
}

int countWords(String a)
{
  int index = 0;
  for (int i = 0; i < a.length(); i++)
  {
    if (a[i] != 32)
      count++;
    else
    {
      b[index] = count;
      index++;
      count = 0;
    }
  }
  b[index] = count;
  index++;
  count = 0;
  return index;
}
