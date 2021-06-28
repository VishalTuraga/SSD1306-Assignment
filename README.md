# SSD1306-Assignment
The task is to create a program that takes input from Software Serial and display the received text on SSD1306 OLED screen. 

## Algorithm for the code
```
1. Set up the display screen
2. Take input from the bluetooth device
3. Store the data in a string variable
  String a = bluetooth.readString();
4. Calculate the length of the string
  int c = a.length();
5. Store the length of all the words present in an arrar b[]
6. intialize variables "line" and "space" to store the number of lines and the number of characters a line can print
7. if the number of lines is less than 4:
  a. check the number of characters a line can print. if it is greater that the lenght of current word, print it and decrement the available space
  b. if the length of current word is greater than the available space. increment the line index and reset space to 20. dectement the available space.
8. if the number of lines is greater than 4:
  a. clear the screen.
  b. set the cursor to (0,0)
  c. follow step 7
9. Repeat from step 2.
```


Video Demonstration link is given below
https://drive.google.com/file/d/1DX6swkqWIF1C972e5VI6-f4b-tT7DGKJ/view?usp=sharing


Updated Video Demonstration Link (28 June 2021)
https://drive.google.com/file/d/1nf9tMspRf3_XkPAZJQsIi_7DFnuDdkyn/view?usp=sharing
