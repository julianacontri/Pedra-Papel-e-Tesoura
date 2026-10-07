
CPP

const int pinoBotao = 2;
const int ledPedra = 8;
const int ledPapel = 9;
const int ledTesoura = 10;

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(ledPedra, OUTPUT);
  pinMode(ledPapel, OUTPUT);
  pinMode(ledTesoura, OUTPUT);
  
  // Semente aleatória usando porta analógica desconectada
  randomSeed(analogRead(A0));
  Serial.begin(9600);
}

void loop() {
  // Espera apertar o botão
  if (digitalRead(pinoBotao) == LOW) {
    apagarLeds();
    delay(300); // Debounce simples
    
    // Sorteia 1, 2 ou 3
    int jogada = random(1, 4);
    
    if (jogada == 1) {
      digitalWrite(ledPedra, HIGH);
      Serial.println("Arduino escolheu: PEDRA");
    } else if (jogada == 2) {
      digitalWrite(ledPapel, HIGH);
      Serial.println("Arduino escolheu: PAPEL");
    } else {
      digitalWrite(ledTesoura, HIGH);
      Serial.println("Arduino escolheu: TESOURA");
    }
    
    delay(3000); // Mostra o resultado por 3 segundos
    apagarLeds();
  }
}

void apagarLeds() {
  digitalWrite(ledPedra, LOW);
  digitalWrite(ledPapel, LOW);
  digitalWrite(ledTesoura, LOW);
}
