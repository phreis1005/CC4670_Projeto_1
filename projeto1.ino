
#include <LiquidCrystal.h>
#include <EEPROM.h>

// Define os pinos para os componentes
int ledPin = 6;
int buttonYesPin = A3;
int buttonNoPin = A2;
int buttonSkipPin = A1;
int buttonStartStopPin = A0;
int buzzerPin = 8;

// Define o objeto para o display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Vetores para armazenar perguntas e respostas
String perguntas[][3] = {
	{"Corrente e medida em volts?", "LED emite luz com corrente?", "Resistor limita corrente?"},
    {"Resistor muda corrente?", "Potenciometro e tipo de resistor?", "Corrente e diferenca de potencial?"},
    {"Interruptor controla tensao?", "Fusivel protege contra corrente?", "Transistor reduz sinais?"},
    {"Sensor de luz detecta luminosidade?", "Servo motor controla movimento?", "Arduino e plataforma de prototipagem?"},
    {"Smartphones usam redes neurais?", "Resistor muda tensao?", "Potenciometro muda corrente?"},
    {"Bluetooth permite comunicacao sem fio?", "NFC usado em pagamentos?", "Memoria RAM importante?"},
    {"HTML e linguagem de marcacao?", "JavaScript estiliza paginas?", "CSS torna paginas interativas?"},
    {"Arduino Uno possui portas analogicas?", "Biblioteca controla motores?", "Circuito integrado tem componentes?"}
};

bool respostas[][3] = {
  {false, true, true},
  {true, true, false},
  {false, true, false},
  {true, true, true},
  {true, false, true},
  {true, true, true},
  {true, false, false},
  {true, false, true},
  {true, false, false},
  {true, false, true},
  {false, true, false},
  {true, false, false}
};


// Variáveis globais
int score = 0;
int questao = 1;
int level = 0;
int skippedQuestions = 0;
int scorePerLevel[] = {10, 20, 30};


void setup() {
  Serial.begin(9600);
  // Inicializa os componentes
  pinMode(buttonYesPin, INPUT);
  pinMode(buttonNoPin, INPUT);
  pinMode(buttonSkipPin, INPUT);
  pinMode(7, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Inicializa o display LCD
  lcd.begin(16, 2);
}
int buttonState = 0;
void loop() {

  waitForStart();

  startGame();
}

void waitForStart() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Aperte START");
  lcd.setCursor(2, 1);
  lcd.print("para iniciar");
  while (digitalRead(buttonStartStopPin) == LOW) {
    // Espera o jogador pressionar o botão de iniciar
  }
  score = 0;
  skippedQuestions = 3;
  questao = 1;
  level = 0;
  delay(1000);
}


void startGame() {
  lcd.clear();
  for(int i=0; i < 3; i++){
    while(questao < 6){
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Questao");
      lcd.setCursor(8, 0);
      lcd.print(questao);
      lcd.setCursor(9, 0);
      lcd.print(":");
      delay(1500);
      pergunta();
    }
    lcd.clear();
  	lcd.setCursor(1, 0);
  	lcd.print("PROXIMA FASE");
    delay(2000);
    level += 1;
    questao = 0;
  }
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Questao FINAL:");
  delay(1500);
  final();
}

 
void pergunta() {
  if(skippedQuestions < 0){
  	gameOver();
  }
  int index = random(0, 4);
  lcd.clear();
  lcd.print(perguntas[index][level]);
  delay(1800);


  // Rola o texto da pergunta para a esquerda
  for (int j = 0; j < perguntas[index][level].length()+25; j++) {
    lcd.scrollDisplayLeft();
    delay(250); // Velocidade da rolagem
  }

  delay(200);

  lcd.clear();
  lcd.print("Score atual:");
  lcd.setCursor(13,0);
  lcd.print(score);
  lcd.setCursor(2, 1);
  lcd.print("SIM ou NAO ?");
  delay(300);
  int seconds = 0;
  
  while (seconds < 11) {
    delay(1000);
    seconds += 1;
    if (seconds > 7) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
    if (digitalRead(buttonYesPin) == HIGH){
      if (respostas[index][level] == true){
            tone(buzzerPin, 1000, 500);
            delay(1000);
            // Adicione a pontuação
            score += scorePerLevel[level];
        	questao += 1;
        	lcd.clear();
        	lcd.setCursor(6, 0);
  			lcd.print("CERTO");
        	delay(1000);
        } else {
        	tone(buzzerPin, 500, 500);
            delay(1000);
        	lcd.clear();
        	lcd.setCursor(6, 0);
  			lcd.print("VOCE");
        	lcd.setCursor(5, 1);
  			lcd.print("ERROU");
        	delay(1500);
            gameOver();
            return;
        }
      break;
    }
    if (digitalRead(buttonNoPin) == HIGH){
    	if (respostas[index][level] == false){
            tone(buzzerPin, 1000, 500);
            delay(1000);
            // Adicione a pontuação
            score += scorePerLevel[level];
        	questao += 1;
          	lcd.clear();
          	lcd.print("CERTO");
        	delay(1000);
        } else {
          	tone(buzzerPin, 500, 500);
            delay(1000);
            lcd.clear();
            lcd.setCursor(6, 0);
  			lcd.print("VOCE");
        	lcd.setCursor(5, 1);
  			lcd.print("ERROU");
        	delay(1500);
            gameOver();
            return;
        }
      break;
    }
    if (digitalRead(buttonSkipPin) == HIGH){
      skippedQuestions -= 1;
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("QUESTAO PULADA");
      lcd.setCursor(0, 1);
      lcd.print("Restam");
      lcd.setCursor(7, 1);
      lcd.print(skippedQuestions);
      lcd.setCursor(9, 1);
      lcd.print("chances");
      delay(2000);
      break;
    }
    if (seconds == 10) {
      skippedQuestions -= 1;
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("TEMPO ESGOTADO");
      delay(2000);
      lcd.setCursor(0, 1);
      lcd.print("Restam");
      lcd.setCursor(7, 1);
      lcd.print(skippedQuestions);
      lcd.setCursor(9, 1);
      lcd.print("chances");
      delay(2000);
    }
  }
}

void gameOver() {
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Fim de jogo");
  lcd.setCursor(0, 1);
  lcd.print("Pontuacao: ");
  lcd.setCursor(11, 1);
  lcd.print(score);
  delay(5000);
  waitForStart();
}
void final() {
  if(skippedQuestions < 0){
  	gameOver();
  }
  
  lcd.clear();
  lcd.print("Celulares usam redes neurais?");
  delay(1800);

  // Rola o texto da pergunta para a esquerda
  for (int j = 0; j < 28+25; j++) {
    lcd.scrollDisplayLeft();
    delay(250); // Velocidade da rolagem
  }

  delay(200);

  lcd.clear();
  lcd.print("Score atual:");
  lcd.setCursor(13,0);
  lcd.print(score);
  lcd.setCursor(2, 1);
  lcd.print("SIM ou NAO ?");
  delay(300);
  int seconds = 0;
  
  while (seconds < 11) {
    delay(1000);
    seconds += 1;
    if (seconds > 7) {
      digitalWrite(ledPin, HIGH);
      delay(100);
      digitalWrite(ledPin, LOW);
      delay(100);
    }
    if (digitalRead(buttonNoPin) == HIGH){
      tone(buzzerPin, 500, 500);
      delay(1000);
      lcd.clear();
      lcd.setCursor(6, 0);
      lcd.print("VOCÊ");
      lcd.setCursor(5, 1);
      lcd.print("ERROU");
      delay(1500);
      gameOver();
      break;
    }
    if (digitalRead(buttonYesPin) == HIGH){
      tone(buzzerPin, 1000, 500);
      delay(1000);
      // Adicione a pontuação
      score += 50;
      lcd.clear();   	
      lcd.setCursor(6, 0);
      lcd.print("VOCE");
      lcd.setCursor(5, 1);
      lcd.print("GANHOU");
      delay(3000);
      gameOver();
      break;
    }

    if (seconds == 10) {
      skippedQuestions -= 1;
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("TEMPO ESGOTADO");
      delay(2000);
      lcd.setCursor(0, 1);
      lcd.print("Restam");
      lcd.setCursor(7, 1);
      lcd.print(skippedQuestions);
      lcd.setCursor(9, 1);
      lcd.print("chances");
      delay(2000);
    }
  }
}
