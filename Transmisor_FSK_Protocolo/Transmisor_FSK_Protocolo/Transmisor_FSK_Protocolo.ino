/*
 Name:		Receptor_FSK_Protocolo.ino
 Created:	03/05/2019
 Author:	Borxo García
*/

#define data 5
#define Button 8

int dato = 0;
float pulso = 0;
float Tiempo = 0;
int estado = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(data, OUTPUT);
	pinMode(Button, INPUT);
	Serial.print("holaaaaa");
}

void loop()
{
	estado = digitalRead(Button);
	switch (estado)
	{
	case 0:
		EnviarBit(0);
		Serial.print("0");
		break;

	case 1:
		EnviarBit(1);
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

void RecibirDato()
{
	pulso = pulseIn(data, HIGH);
	Tiempo = pulso / 1000;

	if (Tiempo <= 1.5)
	{
		dato = 1;
	}
	else if (Tiempo > 0)
	{
		dato = 0;
	}
}