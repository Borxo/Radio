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
	RecibirDato(); // Se llama a la función dato//

	switch (dato) // Dependiendo de la variable dato se enciende un led o otro. 
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

void RecibirDato()
{
	pulso = pulseIn(data, HIGH); //Lee el pin 
	Tiempo = pulso / 1000; // COnvierte el tiempo en ms

	if (Tiempo <= 1.5)
	{
		dato = 1; // Cambia la variable dato a 1 
	}
	else if (Tiempo > 0)
	{
		dato = 0; // Cambia la variable dato a 0
	}
}