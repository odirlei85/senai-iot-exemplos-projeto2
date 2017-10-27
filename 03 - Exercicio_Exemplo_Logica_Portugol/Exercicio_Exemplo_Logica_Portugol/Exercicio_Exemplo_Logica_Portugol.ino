// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e
// precisa ser instalada pelo gerenciador de bibliotecas
#include <Ultrasonic.h>

const int ledVermelho = 8;
const int ledAmarelo = 10;
const int buzzer = 2;

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
Ultrasonic ultrasonic(12, 13);

void setup() {
  // Inicializa a porta Serial
  Serial.begin(9600);
  pinMode (ledVermelho, OUTPUT);
  pinMode (ledAmarelo, OUTPUT);
  pinMode (buzzer, OUTPUT);
}

void loop() {
  // Lê o valor do sensor
  int distancia = ultrasonic.distanceRead();

  // Escreve o valor da distância no painel Serial
  Serial.print("Distance in CM: ");
  Serial.println(distancia);

  delay(1000);

  if (distancia < 30 && distancia > 20) {
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } else if (distancia < 20 && distancia > 10) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    noTone(buzzer);
  } else if (distancia < 10) {
    tone(buzzer, 500);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else {
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  }
}



//  SE distancia MENOR QUE 100 E distancia MAIOR QUE 80
//    acender led amarelo
//  SENAO SE distancia MENOR QUE 80 E distancia MAIOR QUE 60
//    acender led vermelho
//  SENAO SE distancia MENOR QUE 60
//    tocar buzzer
//  SENAO
//    desligar buzzer
//    desligar led vermelho
//    desligar led amarelo


// Links para traduzir o código
//
// SE/SENAO = IF/ELSE -> https://www.arduino.cc/en/Reference/Else
// E = && (logical and) -> https://www.arduino.cc/en/Reference/Boolean
