#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <stdlib.h>
#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10,11);
Adafruit_SSD1306 display(-1);

int* b = (int*)calloc(50,sizeof(int)); // stores the length of all words present in a text
int count = 0;
String a;
void setup()
{
  bluetooth.begin(9600); // Initialize the serial monitor
  // initialize with the I2C addr 0x3C
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Initialize the Display with its I2C address
  display.clearDisplay(); // Clear the buffer.
  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0, 0); // Cursor is set to the co-ordinates (0,0)
}

void loop() {
  display.clearDisplay(); // Clear the buffer.
  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0,0);
  display.print("Enter Text");
  display.display();
  while(bluetooth.available() == 0);
  display.clearDisplay();
  a = bluetooth.readString(); // store the input from bluetooth device in a variable
  int c = countWords(a); // Total number of words present in the input text.
  int line = 0; // To know which line the word being printed in in
  int space = 20; // To know how many characters can the present line accomodate
  int j = 0; //for printing the string
  display.clearDisplay(); //Clear the display buffer
  display.setTextSize(1); // Set the text size 1
  display.setTextColor(WHITE); // Set the text color to white
  display.setCursor(0, 0); // Cursor is set to the co-ordinates (0,0)
  display.setTextWrap(true);
  for(int i = 0;i < c;i++)
  {
    if (line >= 32){ // if the text has more than four lines, refresh the screen and print the remaining text
      delay(500);
      display.clearDisplay();
      display.setCursor(0,0);
      line = 0;
    }
    if(b[i] > space) // if the length of the current word is more than the available space on the current line, move to the next line
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
    display.display();  
  }
  delay(5000);
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
