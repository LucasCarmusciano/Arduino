int PULSADOR = 2;
int LED = 3;
int ESTADO = LOW;

void setup() {
  pinMode(2, INPUT);      // pin 2 como entrada
  pinMode(3, OUTPUT);      // pin 3 como salida
}

void loop() {
  while (digitalRead(PULSADOR) == LOW){
    // bucle vacio para que no realice ninguna accion mientras no se aprieta
  }
  ESTADO = digitalRead(LED);        // lee el estado
  digitalWrite(LED, !ESTADO);       // realiza el estado opuesto
  while (digitalRead(PULSADOR) == HIGH){
    // bucle vacio para que no realice ninguna accion mientras se mantiene apretado
}
}
