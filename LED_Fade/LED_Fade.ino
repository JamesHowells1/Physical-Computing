int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);

  int mappedVal = map(val, 0, 1023, 0, 100);

  analogWrite(6, mappedVal);
}
