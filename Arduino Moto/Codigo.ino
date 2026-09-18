//ENTRADA ANALOGICA
#define PATA_DE_ARRANQUE 39
#define FRENO_DELANTERO 34
#define FRENO_TRASERO 35
#define CEBADOR 33
#define ACELERADOR 32
#define EMBRIAGUE 36
#define POS_CAMBIO 26
#define VOLANTE 25

//ENTRADA DIGITAL
#define BOT_ARRANQUE 4
#define PIN_LLAVE 18
#define LUZ_DELANTERA 13
#define BOCINA 19
#define BALIZA 21  
#define LUZ_GINIO_DERE 15 
#define LUZ_GINIO_IZQ 16 


//SALIDAS
#define BOCINA_OUT 2
#define LUZ_DELANTERA_OUT 5
#define LUZ_TRASERA_OUT 27
#define LUZ_GINIO_IZQ_OUT 12
#define LUZ_GINIO_DER_OUT 14

//VARIABLES
int valorFrenoDel = 0;
int valorFrenoTra = 0;
int valorEmbrag = 0;
int valorVolan = 0;
int posicionCambio = 0;
int temperatura = random(0,51);

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

unsigned long tiempo = millis() // cuenta el tiempo que transcurrio desde que se prende el ESP32
unsigned long tiempoActual = 0; // cuenta el tiempo transcurrido desde que se prendio el boton

void setup() {
Serial.begin(115200);
pinMode(PIN_LLAVE, INPUT);
pinMode(BOT_ARRANQUE, INPUT);

void loop() {
llave = (digitalRead(PIN_LLAVE) == HIGH);
arranque = (analogRead(PATA_DE_ARRANQUE));
boton = (digitalRead(BOT_ARRANQUE));

if(temperatura < 25){
  cebador = (analogRead(CEBADOR));
}

if(boton){
  tiempoActual = millis() - tiempo;
}

temperatura = temperatura + cebador; // se va sumando a medida que el cebador va aumentando

if ((llave && arranque > 350 && temperatura > 25) || (llave && boton && tiempoActual > 1500 && temperatura > 25)){
  serial.println("Moto Encendida");
}
//INPUT
// Aceleracion = analogRead(ACELERADOR);
// valorFrenoDel = analogRead(FRENO_DELANTERO);
// valorFrenoTra = analogRead(FRENO_TRASERO);
// valorEmbrag = analogRead(EMBRIAGUE);
// valorVolan = analogRead(VOLANTE);
// posicionCambio = analogRead(POS_CAMBIO);
}

}
