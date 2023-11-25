#include <WiFi.h>


const char* ssid = "afifah99";
const char* password = "AFIFAH123";
const unsigned long wifiConnectTimeout = 5000; // Waktu maksimal untuk mencoba terhubung dalam milidetik

void setup(){
  Serial.begin(115200);
  delay(100);

  Serial.println("Mencoba terhubung ke WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  unsigned long startTime = millis();
  while (WiFi.status() != WL_CONNECTED && (millis() - startTime) < wifiConnectTimeout) {


    Serial.print(".");
    delay(5000);
  }


  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nTerhubung ke jaringan WiFi");
    //Serial.print("IP Address: " + WiFi.localIP());
    Serial.println("SSID: " + WiFi.SSID());
  } else {
    Serial.println("\nTidak dapat terhubung ke WiFi yang ditentukan.");
    Serial.println("Mencari jaringan WiFi dengan autentikasi terbuka...");

    // Cari jaringan WiFi dengan autentikasi terbuka
    WiFi.disconnect();
    int numNetworks = WiFi.scanNetworks();
    for (int i = 0; i < numNetworks; i++) {
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
        Serial.println("Menghubungkan ke jaringan WiFi dengan autentikasi terbuka");
        WiFi.begin(WiFi.SSID(i).c_str());
        Serial.println("\nTerhubung ke jaringan WiFi");
        Serial.println("SSID: " + WiFi.SSID(i));
        break;
      }
    }
  }
}

void loop(){
  
}