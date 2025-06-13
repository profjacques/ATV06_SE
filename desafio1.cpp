// Exercício 2: Simulação de Movimento Circular com Funções Trigonométricas

#include <math.h> // Necessário para M_PI, sin() e cos()

double anguloAtual = 0.0; // Ângulo inicial em radianos
const double incrementoAngulo = 0.1; // Incremento do ângulo por passo (em radianos)
const double raio = 50.0; // Raio do círculo

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial
  Serial.println("Simulando movimento circular...");
}

void loop() {
  // Calcular as coordenadas X e Y usando seno e cosseno
  // As funções sin() e cos() esperam o ângulo em radianos. [3]
  double coordX = raio * cos(anguloAtual);
  double coordY = raio * sin(anguloAtual);

  // Exibir as coordenadas no Monitor Serial
  Serial.print("Ângulo (rad): ");
  Serial.print(anguloAtual, 2); // 2 casas decimais
  Serial.print(" -> X: ");
  Serial.print(coordX, 2);
  Serial.print(", Y: ");
  Serial.println(coordY, 2);

  // Incrementar o ângulo para o próximo passo
  anguloAtual += incrementoAngulo;

  // Resetar o ângulo se ele exceder 2*PI (um círculo completo)
  if (anguloAtual >= (2 * M_PI)) {
    anguloAtual -= (2 * M_PI); // Volta para o início do círculo
  }

  delay(100); // Pequeno atraso para observar o movimento
}
