# SEEED_TOUCHSCREEN_V2_HMI
A work in progress but the idea is that I am currently making objects such as buttons and 
active variable boxes to simplify the creation of control screens using the SEEED 2.8'' 
TFT Touch Shield V2.0

This library is dependant on both https://github.com/Seeed-Studio/TFT_Touch_Shield_V2 
and https://github.com/Seeed-Studio/Touch_Screen_Driver to opperate. I have also included
a modified version of the Touch_Screen_Driver that will prevent redefinition errors that
were caused by a missing wrapper on SeeedTouchScreen.h that can be found here: 
