int fila = 10;
int col = 2;
int X;
int Y;
int direccion;

//      2  3  4  5  6  7  8  9 
//  10  x
//  11     x
//  12        x
//  13           x
//  14              x
//  15                 x
//  16                    x
//  17                       x

int vel = 200;

void setup() {
  Serial.begin(9600);
  for (int j=2; j<18; j++){
    pinMode(j, OUTPUT);
  }
}


void restart(){
  col = 2;
  fila = 10;
  direccion = 0;
}

void gameOver(){
  for (int i=10; i<18; i++){
    digitalWrite(i, LOW);
  }
  for (int j=2; j<18; j++){
    digitalWrite(j, HIGH);
    delay(80);
  }
  for (int i=10; i<18; i++){
    digitalWrite(i, HIGH);
  }
  for (int j=2; j<18; j++){
    digitalWrite(j, LOW);
  }
}

void derecha(int c, int f){
  digitalWrite(f, LOW);
  digitalWrite(col+1, HIGH);
  digitalWrite(col, LOW);
  if(col<9){
    col = col+1;
  }else {
    gameOver();
    restart();
  }
}
void izquierda(int c, int f){
  digitalWrite(f, LOW);
  digitalWrite(col-1, HIGH);
  digitalWrite(col, LOW);
  if(col>2){
    col = col-1;
  }else {
    gameOver();
    restart();
  }
}
void arriba(int c, int f){
  digitalWrite(c, HIGH);
  digitalWrite(fila-1, LOW);
  digitalWrite(fila, HIGH);
  if(fila>10){
    fila = fila-1;
  }else {
    gameOver();
    restart();
  }
}
void abajo(int c, int f){
  digitalWrite(c, HIGH);
  digitalWrite(fila+1, LOW);
  digitalWrite(fila, HIGH);
  if(fila<17){
    fila = fila+1;
  }else {
    gameOver();
    restart();
  }
}

void loop() {
  X = analogRead(A4);
  Y = analogRead(A5);

  int x2 = abs(map(X, 0, 1023, -100, 100));
  int y2 = abs(map(Y, 0, 1023, -100, 100));

  if (x2>y2){
    if(X>=0 && X<240){
      direccion = 3;  // izquierda
      Serial.println("izquierda");
    } else if(X>750 && X<=1023){
      direccion = 1;  // derecha
      Serial.println("derecha");
    }
  } else {
    if(Y>=0 && Y<240){
      direccion = 4;  // abajo
      Serial.println("abajo");
    } else if(Y>750 && Y<=1023){
      direccion = 2;  // arriba
      Serial.println("arriba");
    }
  }

  for (int i=2; i<10; i++){
    digitalWrite(i, LOW);
  }
  for (int i=10; i<18; i++){
    digitalWrite(i, HIGH);
  }

  if (direccion == 1){
    derecha(col, fila);
  } else if (direccion == 3){
    izquierda(col, fila);
  } else if (direccion == 2){
    arriba(col, fila);
  } else if (direccion == 4){
    abajo(col, fila);
  }
  delay(vel);
  
}
