# LX-16A_ESP32_Dev

I ran accross [Kevin Harrionton's code](https://github.com/madhephaestus/lx16a-servo) used to control the LX-16A servo motor **directly** instead of using the HiWonder BusLinker board. 
However, I was not able to get any of his examples to work with my ESP32 WROOM development board. Eventually, through trial and many errors, I did find a solution. I forked his code and rewrote the Serial -> LX-16A setup in each example to run on my board so that I could share with anyone who is interested.

I did not ever get his 1 wire ESP32 example to work. 
Since I only have 2 servo's at this time, I did not test the lx16aServo_Calibrate_Motors.cpp file. (It would have to be modified to work with 2 motors)

Here is a shot of the back side of one of the LX-16A servo motors showing the connections for GND, VCC and the bidirectional signal for motor control.

![LX-16A Servo pic2](https://user-images.githubusercontent.com/15849536/219958841-be6f6604-74ab-4773-bfc7-40f66382eb01.png)

**Here is a [link](https://www.mischianti.org/wp-content/uploads/2020/11/ESP32-DOIT-DEV-KIT-v1-pinout-mischianti-1024x501.png) to the pinout diagram of the ESP32 Development board I am using for my project(s).**

You will find in the setup code that I am refering to the **pin numbers instead of the GPIO numbers**. Most libraries use the GPIO numbers to refer to pins but for some reason the library does not. Keep that in mind if you have a different ESP32 board. You may have to experiment to find the correct pins for your setup.

Below is my connection diagram. Multiple servos can be chained together as they all have dual ports on the back.

![Test](https://user-images.githubusercontent.com/15849536/219963792-640c69ba-5361-4982-9713-ecc5f4fd9ac2.png)

(I recently ran accross information that suggested that the LX-16A servo motor is actually rated for 4.5V. The article suggested that using a voltage up to 7V would be fine as long as you were not running the motor at full speed, but just to be safe I would suggest limiting the motor voltage to 6V.)


