# SEEED_TOUCHSCREEN_V2_HMI
A work in progress but the idea is that I am currently making objects such as buttons and 
active variable boxes to simplify the creation of control screens using the SEEED 2.8'' 
TFT Touch Shield V2.0

This library is dependant on both https://github.com/Seeed-Studio/TFT_Touch_Shield_V2 
and https://github.com/Seeed-Studio/Touch_Screen_Driver to opperate. I have also included
a modified version of the Touch_Screen_Driver that will prevent redefinition errors that
were caused by a missing wrapper in SeeedTouchScreen.h that can be found here: 
https://github.com/Gooseday/Touch_Screen_Driver.

Features so far:<br>
  Simple button:<br>
    Can be constructed with or without text<br>
    Button may be read as an int with 4 states:<br>
      0-Button is open (no pressure present)<br>
      1-Button is being held down. Will return one so long as the button is pressed.<br>
      2-Button was just pressed.<br>
      3-Button was just released.<br>
  
Works in progress:<br>
  Simple button:<br>
    Add in another constructor to allow the use of .bmp images for button icon.<br><br>
    
  Slider:<br>
    The aim of the slider is to allow the user to adjust a variable within a set range<br>
    Working on writing a set of overloaded constructors allowing for the use of byte, word,<br>
    long, int, unsigned long, unsigned int.<br>
  
  Radio buttons:<br>
    Add in the option of radio buttons. With expandibility as an option.<br>
    
  Keywords.txt:<br>
    Need to add a keywords.txt file.<br>
    
  Ports:<br>
    Future plans to port all files (including the driver and Seeed library) to the Freescale<br>
    S08 family of micro controllers.<br>
