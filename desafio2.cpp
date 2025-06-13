// Monitor de Status Dinâmico com Objeto String

// Variáveis globais para simular leituras de sensores
// Declarar Strings de longa duração como globais e reservar espaço em setup()
// ajuda a minimizar a fragmentação da memória. [4]
String statusMessage;
int temperatura = 25;
int umidade = 60;

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial

  // Pré-alocar memória para a String para evitar realocações e fragmentação. [4]
  // Estime o tamanho máximo da sua string.
  statusMessage.reserve(50); // Ex: "Temperatura: 99C, Umidade: 99%" (aprox. 25 chars + folga)
  Serial.println("Monitor de Status Iniciado.");
}

void loop() {
  // Simular variação das leituras dos sensores
  temperatura = random(20, 31); // Temperatura entre 20 e 30
  umidade = random(50, 71);     // Umidade entre 50 e 70

  // Construir a mensagem de status usando concatenação e conversão de tipos
  // Evite o operador '+' para concatenação repetida no loop, prefira 'concat()' ou '+=' [4]
  statusMessage = "Temperatura: ";
  statusMessage.concat(temperatura);
  statusMessage.concat("C, Umidade: ");
  statusMessage.concat(umidade);
  statusMessage.concat("%");

  // Converter a mensagem para maiúsculas para destaque
  statusMessage.toUpperCase(); [5]

  Serial.println(statusMessage);

  // Demonstrar outras operações da classe String
  if (statusMessage.indexOf("UMIDADE")!= -1) { // Verifica se a palavra "UMIDADE" está na string [6]
    Serial.println(" -> Contém 'UMIDADE'.");
  }

  delay(2000); // Atualiza a cada 2 segundos
}
