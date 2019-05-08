/*
	Name:       Transmisor_ASK_1Khz.ino
	Created:	30/04/2019
	Author:     Borxo García
*/

#define data 8

void setup()
{
	pinMode(data, OUTPUT);
}

void loop()
{
	digitalWrite(data, HIGH);
	delay(1);
	digitalWrite(data, LOW);
	delay(1);
}