  const int ledPin = LED_BUILTIN;
  int ledState = LOW;
  const int arret = 2000;

  void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
  }
  void Allume() {
    Serial.println("Allume – 6202142");
    digitalWrite(ledPin, !ledState);
    delay(arret);
  }

  void Blink() {
    Serial.println("Clignotement – 6202142");
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, ledState);
      delay(250);
      digitalWrite(ledPin, !ledState);
      delay(250);
    }
  }

  void Variation() {
    Serial.println("Variation – 6202142");
    const int Vmax = 255;
    const int nb_pas = 256;
    const int ramp_time = 2048;
    const int increment = 256 / nb_pas;
    const int t = ramp_time / nb_pas;
    for (int fadeValue = 0; fadeValue <= Vmax; fadeValue += increment) {
      analogWrite(ledPin, fadeValue);
      delay(t);
    }
  }

  void Eteint() {
    Serial.println("Eteint – 6202142");
    digitalWrite(ledPin, ledState);
    delay(arret);
  }


  void loop() {
    Allume();
    Blink();
    Variation();
    Eteint();
  }
