#define LIGHT_SENSOR_PIN 4
#define BUZZER_PIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead (LIGHT_SENSOR_PIN);
  Serial.print("Analog Value : ");
  Serial.println(sensorValue);

  if(sensorValue < 500){
    Serial.println(" -> Gelap");
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
  } else {
    Serial.println(" => Terang");
    digitalWrite(BUZZER_PIN, LOW);
    delay(1000);
  }

}
