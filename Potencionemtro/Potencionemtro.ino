int LED = 3;
int BRILLO;
int POT = 0;

void setup() {
  pinMode(LED, OUTPUT);
  // las entradas analogicas (ANALOG IN) no requieren inicializacion.
}

void loop() {
  BRILLO = analogRead(POT)/4;     // analogRead ofrece un rango de 0-1020, y el brillo de led a 0-255, dividiendo en 4 se equilibra
  analogWrite(LED, BRILLO);
}
