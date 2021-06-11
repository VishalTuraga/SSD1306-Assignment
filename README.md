# SSD1306-Assignment
The task is to create a program that takes input from Software Serial and display the received text on SSD1306 OLED screen. 

## Algorithm for the code
```
1. Set up the display screen
2. Take input from the serial monitor
3. Store the data in a string variable
  String a = Serial.readString();
4. Calculate the length of the string
  int b = a.length();
5. Calculate the count value for scrolling
  int c = (ceil(b/20)-4)*8;
6.a. If length of string >= 80
    i. for i from 0 to -1*c
      A. Clear Display
      B. set cursor to (0,i)
      C. Display the text
      D. Decrement i
  b. if length of string < 80
    i. CLear display
    ii. Display the text
  c. Go to step 2
```


Video Demonstration link is given below
https://drive.google.com/file/d/1DX6swkqWIF1C972e5VI6-f4b-tT7DGKJ/view?usp=sharing
