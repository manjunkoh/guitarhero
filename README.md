# Overview
A Guitar Hero like rhythm game using a microcontroller and its features such as ADC (Analog-to-Digital Converter), display, and PWM(Pulse-width modulation). Developed with BoosterPack MKII microcontroller and CCS (Code Composer Studio). Note that one must have CCS and the BoosterPack to fully experience this repository. 

# Design Implementation 
Instead of a guitar, one had to use the Boosterpack and its
joystick and S1 push button as “strumming the chord”. The game consisted of the splash screen
which is the main starting screen and it displays for 3 seconds, then moves onto the main menu
screen. The main menu consists of three sections: “play”, “how to play”, “high scores”. Inside
the “play” section it consists of three songs, Enter Sandman, Hokie Fight, and Game of Thrones
(GoT) theme song.

**Graphics**

The application includes graphics features that are similar to that of Guitar Hero such as
circular notes with both vertical and horizontal lines. Those were achieved by using the
MSP432P4 Graphics library. It uses functions such as graphicsDrawString, DrawVLine, Draw
HLine, and others. Another major part was using the Image Reformer from TI.

**ADC and PWM**

A major part of this application is utilizing the ADC using the Joystick. Joystick was
used to properly propagate through the menu and song lists. By applying the debouncing feature
on the Joystick, it can properly propagate through the menu and song list by just moving it once.
Without Debouncing it will be moving through the menu extremely fast. The PWM and
Timer_A were used to control the rate of the horizontal line and the notes. And it was also used
when to stop the song or break out of the loop such as the while loop of the song function. And itwas also used for the splash screen. The last major part was implementing the non-blocking. One
had to implement the PlaySong function to blend into the playing notes function.
