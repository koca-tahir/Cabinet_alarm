#define TRIG_PIN 2
#define ECHO_PIN 3
#define buton_1 5
#define buton_2 6
#define buzzer 4

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buton_1, INPUT);
  pinMode(buton_2, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int buton1 = digitalRead(buton_1);

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long sure = pulseIn(ECHO_PIN, HIGH);
  float mesafe = sure * 0.0343 / 2;

  Serial.print("Mesafe: ");
  Serial.println(mesafe);

  if (mesafe > 7) {
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
  }

  // Butona basılırsa buzzer'ı zorla kapat
  if (buton1 == HIGH) {
    digitalWrite(buzzer, LOW);
    delay(10000);
  }

  delay(200);
}
