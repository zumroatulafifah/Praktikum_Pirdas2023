#include <Wire.h>
#include <MPU6050.h>
#include <WiFi.h>

MPU6050 mpu;

const char* ssid = "imelda";
const char* password = "imelda123";

const float threshold = 5.0; // Ambang perubahan sudut yang akan memicu bunyi
const int buzzerPin = 25;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  
  Wire.begin();
  Wire.beginTransmission(0x68); // Alamat MPU6050
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // Matikan sleep mode
  Wire.endTransmission(true);
  
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Baca data dari sensor MPU6050
  int16_t ax, ay, az, gx, gy, gz;
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // Hitung sudut perubahan
  float angleX = (gx / 131.0); // Faktor pengali sesuai spesifikasi sensor
  float angleY = (gy / 131.0);
  float angleZ = (gz / 131.0);

  // Tampilkan nilai sudut pada Serial Monitor
  Serial.print("Angle X: ");
  Serial.print(angleX);
  Serial.print(" | Angle Y: ");
  Serial.print(angleY);
  Serial.print(" | Angle Z: ");
  Serial.println(angleZ);

  // Periksa perubahan sudut
  if (abs(angleX) > threshold) {
    digitalWrite(buzzerPin, HIGH);
    // Bunyi buzzer yang berbeda untuk sudut kanan
    tone(buzzerPin, 1000, 500); // Contoh nada 1000Hz selama 500ms
    Serial.println("Perubahan sudut di sebelah kanan");
  } else if (abs(angleY) > threshold) {
    digitalWrite(buzzerPin, HIGH);
    // Bunyi buzzer yang berbeda untuk sudut kiri
    tone(buzzerPin, 1500, 500); // Contoh nada 1500Hz selama 500ms
    Serial.println("Perubahan sudut di sebelah kiri");
  } else if (angleZ > threshold) {
    digitalWrite(buzzerPin, HIGH);
    // Bunyi buzzer yang berbeda untuk sudut depan
    tone(buzzerPin, 2000, 500); // Contoh nada 2000Hz selama 500ms
    Serial.println("Perubahan sudut di depan");
  } else if (angleZ < -threshold) {
    digitalWrite(buzzerPin, HIGH);
    // Bunyi buzzer yang berbeda untuk sudut belakang
    tone(buzzerPin, 2500, 500); // Contoh nada 2500Hz selama 500ms
    Serial.println("Perubahan sudut di belakang");
  } else {
    noTone(buzzerPin); // Matikan bunyi buzzer jika tidak ada perubahan sudut
  }
  
  delay(1000); // Delay 1 detik
}