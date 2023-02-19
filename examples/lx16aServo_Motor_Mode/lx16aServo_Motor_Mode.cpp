#include <Arduino.h>
#include <lx16a-servo.h>

#define TX 27 // pin 27 (GPIO 17) //The lx16a-servo Library does not use the GPIO pin numbers
#define RX 25 // pin 25 (GPIO 16)

int id = 2; //Id of motor we want to put into Motor_Mode
LX16ABus servoBus;
LX16AServo servo(&servoBus, id); //Target motor with ID ?

void setup() {
    servoBus.begin(&Serial2, TX, RX);
    Serial.begin(115200);
}

void loop() {
	for (int i = -10; i < 10; i++) {
		int16_t pos = 0;
		pos = servo.pos_read();
		Serial.printf("\n\nPosition at %d -> %s\n", pos,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");

		int16_t angle = i * 100;


		servo.motor_mode(angle);

		Serial.printf("Move to %d -> %s\n", angle,
				servo.isCommandOk() ? "OK" : "\n\nERR!!\n\n");
		Serial.println("Voltage = " + String(servo.vin()));
		Serial.println("Temp = " + String(servo.temp()));
		Serial.println("ID  = " + String(servo.id_read()));
		delay(500);
	}
	servo.move_time(0, 500);
	delay(5000);
}
