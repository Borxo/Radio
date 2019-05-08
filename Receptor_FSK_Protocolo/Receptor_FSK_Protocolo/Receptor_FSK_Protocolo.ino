/*
 Name:		Receptor_FSK_Protocolo.ino
 Created:	03/05/2019
 Author:	Borxo García
*/

#define data 5
#define LedRojo 13
#define LedVerde 7

int dato = 0;
float pulso = 0;
float Tiempo = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(data, INPUT);
	pinMode(LedRojo, OUTPUT);
	pinMode(LedVerde, OUTPUT);
}

void loop()
{
	RecibirDato();

	switch (dato)
	{
	case 0:
		digitalWrite(LedRojo, HIGH);
		digitalWrite(LedVerde, LOW);
		Serial.print("Rojo");
		break;
	case 1:
		digitalWrite(LedVerde, HIGH);
		digitalWrite(LedRojo, LOW);
		Serial.print("Verde");
		break;
	}

	Serial.print("Tiempo: ");
	Serial.print(Tiempo);
	Serial.print("    ");
	Serial.print("valor: ");
	Serial.println(dato);
}


void EnviarBit(int dato)
{
	switch (dato)
	{
	case 0:

		digitalWrite(data, HIGH);
		//delay(2000);
		break;

	case 1:

		digitalWrite(data, LOW);
		//delay(3000);
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