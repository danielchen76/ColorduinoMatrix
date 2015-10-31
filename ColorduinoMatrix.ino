#include <Wire.h>
#include <EEPROM.h>

#include <Colorduino.h>


//The setup function is called once at startup of the sketch
void setup()
{
	// I2C Slave address, read from EEPROM
	byte	slaveAddress = 1;

	Serial.begin(9600);

	Colorduino.Init();

	// Read I2C address from EEPROM

	// if read EEPROM failed, then only display erro on Colorduino, and has not any function.
	slaveAddress = EEPROM.read(1);

	// EEPROM
	Wire.begin(slaveAddress);
	Wire.onReceive(receiveEvent);
}

// The loop function is called in an endless loop
void loop()
{
	delay(100);
}

// I2C slave receive function
void receiveEvent(int howMany)
{

}

