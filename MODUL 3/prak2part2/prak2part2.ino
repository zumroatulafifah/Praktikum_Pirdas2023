#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiSTA.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

// #include <WiFi.h>

// const char* ssid = "afifah99"; // Nama SSID yang ditentukan
// const char* password = "AFIFAH123"; // Kata sandi jaringan yang ditentukan

// void setup() {
//   Serial.begin(115200);

//   // Coba terhubung ke jaringan Wi-Fi dengan kata sandi
//   if (WiFi.begin(ssid, password) == WL_CONNECTED) {
//     Serial.println("Connected to the WiFi network");
//     Serial.print("SSID: ");
//     Serial.println(ssid);
//     Serial.print("Alamat IP: ");
//     Serial.println(WiFi.localIP());
//   } else {
//     // Jika gagal terhubung, coba cari jaringan WiFi terbuka
//     Serial.println("Failed to connect to the specified network. Trying to connect to an open network...");

//     // WiFi.disconnect(); // Matikan koneksi sebelum mencoba jaringan terbuka
//     delay(1000);

//     int numNetworks = WiFi.scanNetworks();
//     for (int i = 0; i < numNetworks; i++) {
//       if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
//         Serial.println("Connecting to an open WiFi network...");
//         WiFi.begin(WiFi.SSID(i).c_str());
//         while (WiFi.status() != WL_CONNECTED) {
//           delay(500);
//           Serial.println("Connecting to WiFi..");
//         }

//         Serial.println("Connected to an open WiFi network");
//         Serial.print("SSID: ");
//         Serial.println(WiFi.SSID(i));
//         Serial.print("Alamat IP: ");
//         Serial.println(WiFi.localIP());
//         break; // Keluar dari loop jika terhubung ke jaringan WiFi terbuka       
//       }
//     }

//     if (WiFi.status() != WL_CONNECTED) {
//       Serial.println("Failed to connect to any network.");
//     }
//   }
// }

// void loop() {}

#include <WiFi.h>

const char* ssid = "afifah99"; // Nama SSID yang ditentukan
const char* password =  "AFIFAH123"; // Kata sandi jaringan yang ditentukan

void setup() {
  Serial.begin(9600);

  if (WiFi.begin(ssid, password) == WL_CONNECTED) {
    Serial.println("Connected to the WiFi network");
    Serial.print("SSID: ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to the specified network. Trying to connect to an open network...");

    WiFi.disconnect(); // Matikan koneksi sebelum mencoba jaringan terbuka
    delay(1000);

    int numNetworks = WiFi.scanNetworks();
    for (int i = 0; i < numNetworks; i++) {
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
        Serial.println("Connecting to an open WiFi network...");
        WiFi.begin(WiFi.SSID(i).c_str());
        while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.println("Connecting to WiFi..");
        }

        Serial.println("Connected to an open WiFi network");
        Serial.print("SSID: ");
        Serial.println(WiFi.SSID(i));
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
        break; // Keluar dari loop jika terhubung ke jaringan WiFi terbuka       
      }
    }
  }

  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {}
