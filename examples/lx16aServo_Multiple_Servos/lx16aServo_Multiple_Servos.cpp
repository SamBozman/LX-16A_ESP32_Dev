//example of controlling multiple servo motors

#include <Arduino.h>
#include <lx16a-servo.h>
LX16ABus servoBus;
LX16AServo servo1(&servoBus, 1); //ID 1
LX16AServo servo2(&servoBus, 2);//ID 2
//LX16AServo servo3(&servoBus, 3); //ID3
#define TX 27 // pin 27 (GPIO 17) //The lx16a-servo Library does not use the GPIO pin numbers
#define RX 25 // pin 25 (GPIO 16)

void setup() {
    servoBus.begin(&Serial2, TX, RX);
    Serial.begin(115200);
	servoBus.retry = 1; // enforce synchronous real time
	servoBus.debug(true);
	Serial.println("Beginning Coordinated Servo Example");

}
// 40ms trajectory planning loop seems the most stable

void loop() {
	int divisor = 3;
	for (int i = 0; i < 1000 / divisor; i++) {
		long start = millis();
		int16_t pos = 0;
		pos = servo1.pos_read();
		int16_t pos2 = servo2.pos_read();
		//int16_t pos3 = servo3.pos_read();

		uint16_t angle = i * 24 * divisor;
servo1.move_time_and_wait_for_sync(angle, 10 * divisor);
		servo2.move_time_and_wait_for_sync(angle, 10 * divisor);
		//servo3.move_time_and_wait_for_sync(angle, 10 * divisor);
		

		servoBus.move_sync_start();

		//if(abs(pos2-pos)>100){
		Serial.printf("\n\nPosition at %d and %d-> %s\n", pos, pos2,
				servo1.isCommandOk() ? "OK" : "\n\nERR!!\n\n");
		Serial.printf("Move to %d -> %s\n", angle,
				servo1.isCommandOk() ? "OK" : "\n\nERR!!\n\n");
		//}
		long took = millis() - start;

		long time = (10 * divisor) - took;
		if (time > 0)
			delay(time);
		else {
			Serial.println("Real Time broken, took: " + String(took));
		}
	}
	Serial.println("Interpolated Set pos done, not long set");

	servoBus.retry = 5; // These commands must arrive
	servo1.move_time(0, 10000);
	servo2.move_time(0, 10000);
	//servo3.move_time(0, 10000);
	servoBus.retry = 0; // Back to low latency mode
	for (int i = 0; i < 1000 / divisor; i++) {
		long start = millis();
		int16_t pos = 0;
		pos = servo1.pos_read();
		int16_t pos2 = servo2.pos_read();
		//int16_t pos3 = servo3.pos_read();

		Serial.printf("\n\nPosition at %d and %d\n", pos, pos2);

		Serial.println("Voltage = " + String(servo1.vin()));
		Serial.println("Temp = " + String(servo1.temp()));

		long took = millis() - start;

		long time = (10 * divisor) - took;
		if (time > 0)
			delay(time);
		else {
			Serial.println("Real Time broken, took: " + String(took));
		}
	}
	Serial.println("Loop resetting");
	delay(1000);
}
