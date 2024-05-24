#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(9600);

  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  Serial.println("MPU6050 Found!");
}


void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  int temperature = temp.temperature;
  Serial.println(" degC");

  int LEDcolour = map(temperature, 24, 30, 0, 255);

  if (temperature > 25){
    digitalWrite(5, LEDcolour);
  } else {
    digitalWrite(6, LEDcolour);
  }

  

  Serial.println("");
  delay(1500);
  
  digitalWrite(5, 0);
  digitalWrite(6, 0);
}