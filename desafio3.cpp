// Jogo de Adivinhação de Números Aleatórios

long numeroSecreto;
const int MIN_NUMERO = 1;
const int MAX_NUMERO = 100; // O número secreto será entre 1 e 99

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial

  // Inicializa o gerador de números pseudo-aleatórios. [9]
  // Usar analogRead(A0) em um pino desconectado fornece uma semente mais variada. [9, 10]
  randomSeed(analogRead(A0));

  // Gera o número secreto
  numeroSecreto = random(MIN_NUMERO, MAX_NUMERO); // Gera um número entre MIN_NUMERO (inclusive) e MAX_NUMERO (exclusive) [9]

  Serial.println("--- Jogo de Adivinhação ---");
  Serial.print("Pensei em um número entre ");
  Serial.print(MIN_NUMERO);
  Serial.print(" e ");
  Serial.print(MAX_NUMERO - 1);
  Serial.println(". Tente adivinhar!");
}

void loop() {
  if (Serial.available()) {
    // Lê a entrada do usuário como uma String
    String entradaUsuario = Serial.readStringUntil('\n');
    entradaUsuario.trim(); // Remove espaços em branco iniciais/finais

    // Converte a String para um número inteiro
    int palpite = entradaUsuario.toInt();

    Serial.print("Seu palpite: ");
    Serial.println(palpite);

    if (palpite == 0 && entradaUsuario.length() > 0 && entradaUsuario.charAt(0)!= '0') {
      // toInt() retorna 0 se a conversão falhar, então verificamos se a entrada não era "0"
      Serial.println("Entrada inválida. Por favor, digite um número.");
    } else if (palpite < MIN_NUMERO |
| palpite >= MAX_NUMERO) {
      Serial.print("Por favor, digite um número entre ");
      Serial.print(MIN_NUMERO);
      Serial.print(" e ");
      Serial.print(MAX_NUMERO - 1);
      Serial.println(".");
    } else if (palpite < numeroSecreto) {
      Serial.println("É maior!");
    } else if (palpite > numeroSecreto) {
      Serial.println("É menor!");
    } else {
      Serial.println("Parabéns! Você acertou o número!");
      Serial.println("Um novo número secreto foi gerado.");
      // Gera um novo número secreto para reiniciar o jogo
      randomSeed(analogRead(A0) + millis()); // Adiciona millis() para uma semente ainda mais variada
      numeroSecreto = random(MIN_NUMERO, MAX_NUMERO);
    }
  }
}
