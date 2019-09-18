#include <ReceiveOnlySoftwareSerial.h>
ReceiveOnlySoftwareSerial mySerial(5); // pino digita que será usado para leitura.

float temp;
int tds;
void setup() {
 Serial.begin(9600);
 mySerial.begin(300);  // baixa velocidade para evitar corromper dados
}

void loop() {
  leitura();
  delay(1000);
}


void leitura() {
  if ( mySerial.available() > 0 ) {
    String msg = mySerial.readStringUntil('\n'); // lê os valores via serial

  for ( int i = 0; i < msg.length(); i++) {
     if (msg.substring(i, i+1) == ":") {      // separa os valores
           temp = msg.substring(0, i).toFloat();  // obtem a primeira parte, temperatura em float
           tds = msg.substring(i+1).toInt();   // obtem a segunda parte,  TDS  em inteiro
   break;
         }
       } 
   Serial.println("Valor Temperatura e: "+String(temp));
   Serial.println("Valor TDS e: "+String(tds));
  }
}

