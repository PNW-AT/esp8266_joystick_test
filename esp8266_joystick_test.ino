class OneAnalogJoystick {
  protected:
    byte pinA;
    byte pinXM;
    byte pinXP;
    byte pinYM;
    byte pinYP;
  public:
    OneAnalogJoystick(byte _pinA, byte _pinXM, byte _pinXP, byte _pinYM, byte _pinYP) {
      pinA = _pinA;
      pinXM = _pinXM;
      pinXP = _pinXP;
      pinYM = _pinYM;
      pinYP = _pinYP;
    }
    int readX() {
      digitalWrite(pinYP, LOW);
      pinMode(pinYP, INPUT);
      digitalWrite(pinYM, LOW);
      pinMode(pinYM, INPUT);
      pinMode(pinXM, OUTPUT);
      digitalWrite(pinXM, LOW);
      pinMode(pinXP, OUTPUT);
      digitalWrite(pinXP, HIGH);
      return analogRead(pinA);
    }
    int readY() {
      digitalWrite(pinXP, LOW);
      pinMode(pinXP, INPUT);
      digitalWrite(pinXM, LOW);
      pinMode(pinXM, INPUT);
      pinMode(pinYM, OUTPUT);
      digitalWrite(pinYM, LOW);
      pinMode(pinYP, OUTPUT);
      digitalWrite(pinYP, HIGH);
      return analogRead(pinA);
    }
};

OneAnalogJoystick stick = OneAnalogJoystick(A0, D1, D2, D5, D6);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.print(stick.readX());
  Serial.print(",");
  Serial.print(stick.readY());
  Serial.println();
}
