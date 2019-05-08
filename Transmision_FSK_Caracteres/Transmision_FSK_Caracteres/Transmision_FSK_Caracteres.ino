/*
 Name:		Transmision_FSK_Caracteres.ino
 Created:	09/05/2019 
 Author:	Borxo García
*/

#define data 11
#define Button 8

int dato = 0;
float pulso = 0;
float Tiempo = 0;
int estado = 0;
char final = 0;
char texto;
unsigned char mask = 0b000000001;
unsigned char caracter;
void setup()
{
	Serial.begin(9600);
	pinMode(data, OUTPUT);
	pinMode(Button, INPUT);
	Serial.println("holaaaaa");
	Serial.println("Caracter");
}

void loop()
{

	if (Serial.available())
	{

		texto = Serial.read();
		EnviarByte(texto);
		Serial.println("Enviado");

		/*if (texto !='\r')
		{
		//Serial.print(texto);
		EnviarByte(texto);
		}
		else if(texto =='\r')
		{
		  Serial.println("Enviado");
		}*/
	}



	/*estado = digitalRead(Button);
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
	}*/
}

void EnviarByte(char Caracter)
{
	//Serial.print(Caracter,BIN);
	for (int i = 0; i < 8; i++)
	{
		if (Caracter&mask)
		{
			EnviarBit(1);
			Serial.print("1");
		}
		else
		{
			EnviarBit(0);
			Serial.print("0");
		}
		Caracter = Caracter >> 1;
		//delay(200);
	}

	Serial.println("FIN");

}

void RecibirByte()
{
	for (int i = 0; i < 8; i++)
	{
		RecibirDato();
		final = dato + (final << 1);
	}
	Serial.print(final);
}
void EnviarBit(int dato)
{
	switch (dato)
	{
	case 0:
		//Serial.print("0");
		digitalWrite(data, HIGH);
		delay(2);
		digitalWrite(data, LOW);
		delay(1);
		break;

	case 1:
		//Serial.print("1");
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