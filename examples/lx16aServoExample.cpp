#include <Arduino.h>
#include <lx16a-servo.h>
#define TX 27 // pin 27 (GPIO 17) //The lx16a-servo Library does not use the GPIO pin numbers
#define RX 25 // pin 25 (GPIO 16)

int id = 2; //(Change this id to match your motor ID)
LX16ABus servoBus;
LX16AServo servo(&servoBus, id); //Target motor with ID ?

void setup() {
    servoBus.begin(&Serial2, TX, RX);
    Serial.begin(115200);
}

void loop() {
	int divisor =4;
	for (int i = 0; i < 1000/divisor; i++) {
		long start = millis();
		uint16_t angle = i * 24*divisor;
		int16_t pos = 0;
		pos = servo.pos_read();
		Serial.printf("\n\nPosition at %d -> %s\n", pos,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");

		do {
			servo.move_time(angle, 10*divisor);
		} while (!servo.isCommandOk());
		Serial.printf("Move to %d -> %s\n", angle,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");
		Serial.println("Voltage = " + String(servo.vin()));
		Serial.println("Temp = " + String(servo.temp()));
		Serial.println("ID  = " + String(servo.id_read()));
		Serial.println("Motor Mode  = " + String(servo.readIsMotorMode()));
		long took = millis()-start;
		long time = (10*divisor)-took;
		if(time>0)
			delay(time);
		else{
			Serial.println("Real Time broken, took: "+String(took));
		}
	}

	servo.move_time(0, 3000);
	delay(3000);
}
