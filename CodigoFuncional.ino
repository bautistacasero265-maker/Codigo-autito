// -------- L298N IZQUIERDO --------
#define IZQ_IN1 5
#define IZQ_IN2 6
#define IZQ_IN3 9
#define IZQ_IN4 10

// -------- L298N DERECHO --------
#define DER_IN1 7
#define DER_IN2 8
#define DER_IN3 11
#define DER_IN4 12

void setup() {

  Serial.begin(9600);

  pinMode(IZQ_IN1, OUTPUT);
  pinMode(IZQ_IN2, OUTPUT);
  pinMode(IZQ_IN3, OUTPUT);
  pinMode(IZQ_IN4, OUTPUT);

  pinMode(DER_IN1, OUTPUT);
  pinMode(DER_IN2, OUTPUT);
  pinMode(DER_IN3, OUTPUT);
  pinMode(DER_IN4, OUTPUT);

  parar();
}

void loop() {

  if (Serial.available()) {

    char dato = Serial.read();

    switch (dato) {

      case 'F':
        adelante();
        break;

      case 'B':
        atras();
        break;

      case 'L':
        izquierda();
        break;

      case 'R':
        derecha();
        break;

      case 'S':
        parar();
        break;
    }
  }
}

//================ MOVIMIENTOS ================

void adelante() {

  digitalWrite(IZQ_IN1, HIGH);
  digitalWrite(IZQ_IN2, LOW);
  digitalWrite(IZQ_IN3, HIGH);
  digitalWrite(IZQ_IN4, LOW);

  digitalWrite(DER_IN1, HIGH);
  digitalWrite(DER_IN2, LOW);
  digitalWrite(DER_IN3, HIGH);
  digitalWrite(DER_IN4, LOW);
}

void atras() {

  digitalWrite(IZQ_IN1, LOW);
  digitalWrite(IZQ_IN2, HIGH);
  digitalWrite(IZQ_IN3, LOW);
  digitalWrite(IZQ_IN4, HIGH);

  digitalWrite(DER_IN1, LOW);
  digitalWrite(DER_IN2, HIGH);
  digitalWrite(DER_IN3, LOW);
  digitalWrite(DER_IN4, HIGH);
}

void izquierda() {

  digitalWrite(IZQ_IN1, LOW);
  digitalWrite(IZQ_IN2, HIGH);
  digitalWrite(IZQ_IN3, LOW);
  digitalWrite(IZQ_IN4, HIGH);

  digitalWrite(DER_IN1, HIGH);
  digitalWrite(DER_IN2, LOW);
  digitalWrite(DER_IN3, HIGH);
  digitalWrite(DER_IN4, LOW);
}

void derecha() {

  digitalWrite(IZQ_IN1, HIGH);
  digitalWrite(IZQ_IN2, LOW);
  digitalWrite(IZQ_IN3, HIGH);
  digitalWrite(IZQ_IN4, LOW);

  digitalWrite(DER_IN1, LOW);
  digitalWrite(DER_IN2, HIGH);
  digitalWrite(DER_IN3, LOW);
  digitalWrite(DER_IN4, HIGH);
}

void parar() {

  digitalWrite(IZQ_IN1, LOW);
  digitalWrite(IZQ_IN2, LOW);
  digitalWrite(IZQ_IN3, LOW);
  digitalWrite(IZQ_IN4, LOW);

  digitalWrite(DER_IN1, LOW);
  digitalWrite(DER_IN2, LOW);
  digitalWrite(DER_IN3, LOW);
  digitalWrite(DER_IN4, LOW);
}