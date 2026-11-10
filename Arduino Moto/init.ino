#include "Pines.h";

//VARIABLES
int valorFrenoDel = 0;
int valorFrenoTra = 0;
int valorEmbrag = 0;
int valorVolan = 0;
int posicionCambio = 0;
int temperatura = 0;

bool llave = false;
bool giroIzquierdo = false;
bool giroDerecho = false;
bool baliza = false;
bool luzDelantera = false;
bool boton = false;

float acelerador = 0.0;
float velocidad = 0.0;
float aceleracion = 0.0; 
float arranque = 0.0; 
float cebador = 0.0;

unsigned long tiempo = millis(); // cuenta el tiempo que transcurrio desde que se prende el ESP32
unsigned long tiempoAnterior = 0; // cuenta el tiempo transcurrido desde 1 segundo, para que cada 1 segundo aumente la tempertatura

void setup() {
Serial.begin(115200);
pinMode(PIN_LLAVE, INPUT_PULLUP);
pinMode(BOT_ARRANQUE, INPUT_PULLUP);
temperatura = random(0,51);
}

void loop() {
llave = (digitalRead(PIN_LLAVE) == LOW);
arranque = (analogRead(PATA_DE_ARRANQUE));
boton = (digitalRead(BOT_ARRANQUE) == LOW);

if(temperatura < 35){
  cebador = (analogRead(CEBADOR));
}else {
    cebador = 0;
  }

if(cebador > 0 && temperatura < 35 && (millis() - tiempoAnterior >= 1000)){
  tiempoAnterior = millis();
  temperatura = temperatura + 2;  // se va sumando a medida que el cebador va aumentando
  Serial.println(temperatura);
}



if ((llave && arranque > 350 && temperatura >= 35) || (llave && boton && temperatura > 35)){
  Serial.println("Moto Encendida");
}else{
  Serial.println(boton);
  Serial.println(llave)
}

}
