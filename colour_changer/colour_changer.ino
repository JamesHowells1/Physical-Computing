

int num1;
int num2;
int num3;

int red = 9;
int green = 10;
int blue = 11;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop() {
  
  num1 = analogRead(A0);
  num2 = analogRead(A1);
  num3 = analogRead(A2);


  num1 = map(num1, 0, 1023, 0, 255);
  num2 = map(num2, 0, 1023, 0, 255);
  num3 = map(num3, 0, 1023, 0, 255);


  analogWrite(red, num1);
  analogWrite(green, num2);
  analogWrite(blue, num3);
}
