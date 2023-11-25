#define LIGHT_SENSOR_PIN 4
#define BUZZER_PIN 2
#define LED_PIN 13  // Misalkan Anda menggunakan pin 13 untuk lampu LED

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);  // Atur pin lampu sebagai OUTPUT
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(LIGHT_SENSOR_PIN);
  Serial.print("Analog Value: ");
  Serial.println(sensorValue);

  if (sensorValue < 500) {
    Serial.println("-> Gelap");
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, LOW);  // Matikan lampu
    delay(1000);
  } else if (sensorValue >= 500 && sensorValue < 1000){
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
    Serial.println(" => Redup");
  }else {
    Serial.println("=> Terang");
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, HIGH);  // Hidupkan lampu
    delay(1000);
  }
}
