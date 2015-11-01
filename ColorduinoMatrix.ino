#include <Wire.h>
#include <EEPROM.h>

#include <Colorduino.h>


//The setup function is called once at startup of the sketch
void setup()
{
	// I2C Slave address, read from EEPROM
	unsigned char	slaveAddress = 1;

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

#define CMD_REDRAW			0x81
#define CMD_TURN_ON			0x82
#define CMD_TURN_OFF		0x83

void ProcessCommand(unsigned char command)
{
	switch (command)
	{
	case CMD_REDRAW:
		break;

	case CMD_TURN_ON:
		break;

	case CMD_TURN_OFF:
		break;
	}
}

void SetPixel(unsigned char pos, unsigned char r, unsigned char g, unsigned b)
{

}

void Redraw()
{
	// Switch display buffer
	Colorduino.FlipPage();

	// Copy display buffer to memory buffer
	Colorduino.CopyDisplayMem();
}

