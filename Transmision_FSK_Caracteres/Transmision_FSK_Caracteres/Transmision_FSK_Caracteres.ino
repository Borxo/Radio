/*
 Name:		Transmision_FSK_Caracteres.ino
 Created:	09/05/2019 
 Author:	Borxo García
*/

#define data 11
#define Button 8

int dato = 0;
char texto;
unsigned char mask = 0b000000001;
unsigned char caracter;

void setup()
{
	Serial.begin(9600);
	pinMode(data, OUTPUT);
	pinMode(Button, INPUT);
	Serial.println("Caracter");
}

void loop()
{

	if (Serial.available()) //Espera a que se escriba en el monitor serie
	{

		texto = Serial.read();  //Lee lo escrito y lo carga en la variable texto. 
		EnviarByte(texto);      //Envia los caracteres a la variable EnviarByte. 
		Serial.println("Enviado");
	}
}

void EnviarByte(char Caracter) // Convierte el caracter de 8 bit en serie. 
{
	
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
		
	}

	Serial.println("FIN");

}


void EnviarBit(int dato)  // Crea los o y 1 segun el protocolo anterior. 
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
