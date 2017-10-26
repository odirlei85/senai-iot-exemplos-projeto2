// Inclusão da biblioteca do sensor
// Essa biblioteca não vem por padrão com o arduino e
// precisa ser instalada pelo gerenciador de bibliotecas
#include <Ultrasonic.h>

// Inicializa o objeto do sensor ultrasônico
// Usando as portas 12 e 13 para trigger e echo
Ultrasonic ultrasonic(12, 13);
const int ledVermelho = 11;
const int ledAmarelo = 10;

void setup() {
  // Inicializa a porta Serial
  Serial.begin(9600);
  pinMode (ledVermelho, OUTPUT);
  pinMode (ledAmarelo, OUTPUT);

}

void loop() {
  // Lê o valor do sensor
  int distancia = ultrasonic.distanceRead();

  // Escreve o valor da distância no painel Serial
  Serial.print("Distance in CM: ");
  Serial.println(distancia);

  delay(1000);

  if (distancia <= 10) {
    digitalWrite(ledVermelho, HIGH);
  }
  else {
    digitalWrite(ledVermelho, LOW);
    }
  }
