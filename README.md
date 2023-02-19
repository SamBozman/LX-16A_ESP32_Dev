# LX-16A_ESP32_Dev

I ran accross [Kevin Harrionton's code] (https://github.com/madhephaestus/lx16a-servo) that he designed to control the LX-16A servo motor directly instead of using the HiWonder BusLinker board. 
However, I was not able to get any of his examples to work with my ESP32 WROOM development board. Eventually, through trial and many errors, I did find a solution. I forked his code and rewrote the setup in each example to run on my board so that I could share with anyone who is interested.

Here is a shot of the back side of one of the LX-16A servo motors showing the connections for GND, VCC and the bidirectional signal for motor control.


![LX-16A Servo pic2](https://user-images.githubusercontent.com/15849536/219958841-be6f6604-74ab-4773-bfc7-40f66382eb01.png)

