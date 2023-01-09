int LED = 3;
int MIC = 2;
int ESTADO;
int VALOR;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(MIC, INPUT);
}

void loop() {
  VALOR = digitalRead(MIC);
  if (VALOR == HIGH){
    ESTADO = digitalRead(LED);
    digitalWrite(LED, !ESTADO);
    delay(500);
  }
}