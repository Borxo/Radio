/*
 Name:		Receptor_ASK_1Khz.ino
 Created:	30/04/2019
 Author:	Borxo García
*/

#define data 5
int val = 0;
void setup()
{
	Serial.begin(9600);
	pinMode(data, INPUT);
}

void loop()
{
	val = digitalRead(data);
	Serial.print("Valor:");
	Serial.println(val);
}