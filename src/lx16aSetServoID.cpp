//Updated to work with the ESP32. See ReadMe.md
// lx16aSetServoID example
#include <Arduino.h>
#include <lx16a-servo.h>
#define TX 27 // pin 27 (GPIO 17) //The lx16a-servo Library does not use the GPIO pin numbers
#define RX 25 // pin 25 (GPIO 16)

int id = 2; //Id we want to set on any motor connected to ESP32
LX16ABus servoBus;
LX16AServo servo(&servoBus, id); //Target motor with ID 2

void setup() {
    servoBus.begin(&Serial2, TX, RX);
    Serial.begin(115200);
}

void loop() {
	// Set any motor plugged in to ID 2
	// this INO acts as an auto-provisioner for any motor plugged in
	servo.id_write(id);
	Serial.println("Attempting set to ID "+String (id));
	int read=servo.id_read();
	if(read!=id || read==0){
		Serial.println("\r\nERROR ID set failed");
		delay(500);
	}else{
		Serial.println("\r\nCurrent ID is now "+String(read));
	}
	delay(200);

}