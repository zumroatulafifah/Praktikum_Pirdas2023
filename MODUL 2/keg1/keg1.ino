#define LIGHT_SENSOR_PIN 4
#define LED_PIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Analog Value = ");
  Serial.println(sensorValue);

  if(sensorValue <500){
    Serial.println(" => Gelap");
    digitalWrite(LED_PIN, LOW);
    delay(1000);
  } else if (sensorValue >= 500 && sensorValue < 1000){
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    Serial.println(" => Redup");
  } else {
    Serial.println(" => Terang");
    digitalWrite(LED_PIN, HIGH);
    delay(1000);
  }
}
