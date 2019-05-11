/*
 Name:		Receptor_FSK_Protocolo.ino
 Created:	03/05/2019
 Author:	Borxo García
*/

#define data 5
#define Button 8

int estado = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(data, OUTPUT);
	pinMode(Button, INPUT);
}

void loop()
{
	estado = digitalRead(Button);  //Lee el pin del boton
	switch (estado)
	{
	case 0:
		EnviarBit(0);  //Envia un 0
		Serial.print("0");
		break;

	case 1:
		EnviarBit(1);  //Envia un 1
		Serial.print("1");
		break;
	}
}


void EnviarBit(int dato)
{
	switch (dato)
	{
	case 0:
		digitalWrite(data, HIGH);
		delay(2);
		digitalWrite(data, LOW);
		delay(1);
		break;

	case 1:
		digitalWrite(data, HIGH);
		delay(1);
		digitalWrite(data, LOW);
		delay(1);
		break;
	}
}
