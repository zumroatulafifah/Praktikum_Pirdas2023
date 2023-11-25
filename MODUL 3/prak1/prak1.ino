// #include <WiFi.h>

// const char* ssid = "afifah99";      // Ganti dengan SSID jaringan WiFi Anda
// const char* password = "AFIFAH123";  // Ganti dengan kata sandi jaringan WiFi Anda

// void setup() {
//   Serial.begin(9600);

//   // Mulai koneksi WiFi
//   Serial.print("Mencoba terhubung ke jaringan WiFi: ");
//   Serial.println(ssid);
//   WiFi.begin(ssid, password);

//   // Tunggu hingga terhubung atau hingga 15 detik
//   int i = 0;
//   while (WiFi.status() != WL_CONNECTED && i < 15) {
//     delay(1000);
//     Serial.print(".");
//     i++;
//   }

//   if (WiFi.status() == WL_CONNECTED) {
//     Serial.println();
//     Serial.println("Terhubung ke jaringan WiFi: " + String(ssid));
//     Serial.println("Alamat IP: " + WiFi.localIP().toString());
//   } else {
//     Serial.println();
//     Serial.println("Gagal terhubung ke jaringan WiFi: " + String(ssid));
//     Serial.println("Mencoba terhubung ke jaringan WiFi terbuka...");

//     // Cari jaringan WiFi terbuka
//     int numNetworks = WiFi.scanNetworks();
//     for (int i = 0; i < numNetworks; i++) {
//       if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
//         Serial.print("Mencoba terhubung ke jaringan WiFi terbuka: ");
//         Serial.println(WiFi.SSID(i));
//         WiFi.begin(WiFi.SSID(i).c_str());

//         // Tunggu hingga terhubung atau hingga 15 detik
//         int j = 0;
//         while (WiFi.status() != WL_CONNECTED && j < 15) {
//           delay(1000);
//           Serial.print(".");
//           j++;
//         }

//         if (WiFi.status() == WL_CONNECTED) {
//           Serial.println();
//           Serial.println("Terhubung ke jaringan WiFi terbuka: " + WiFi.SSID(i));
//           Serial.println("Alamat IP: " + WiFi.localIP().toString());
//           break;
//         } else {
//           Serial.println();
//           Serial.println("Gagal terhubung ke jaringan WiFi terbuka: " + WiFi.SSID(i));
//         }
//       }
//     }
//   }
// }

// void loop() {
//   // Kode program utama Anda di sini
// }


// #include <WiFi.h>

// Replace with your network credentials (STATION)
// const char* ssid = "afifah99";
// const char* password = "AFIFAH123";

// unsigned long previousMillis = 0;
// unsigned long interval = 30000;

// void initWiFi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
//   Serial.print("Connecting to WiFi ..");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print('.');
//     delay(1000);
//   }
//   Serial.println(WiFi.localIP());
// }

// void setup() {
//   Serial.begin(115200);
//   initWiFi();
//   Serial.print("RSSI: ");
//   Serial.println(WiFi.RSSI());
// }

// void loop() {
//   unsigned long currentMillis = millis();
//   // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
//   if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
//     Serial.print(millis());
//     Serial.println("Reconnecting to WiFi...");
//     WiFi.disconnect();
//     WiFi.reconnect();
//     previousMillis = currentMillis;
//   }
// }

#include <WiFi.h>

const char* ssid = "afifah99"; // Nama SSID yang ditentukan
const char* password =  "AFIFAH12"; // Kata sandi jaringan yang ditentukan

void setup() {
  Serial.begin(9600);

  if (WiFi.begin(ssid, password) == WL_CONNECTED) {
    Serial.println("Connected to the WiFi network");
    Serial.print("SSID: ");
    Serial.println(ssid);
  } else {
    // Jika gagal terhubung, coba cari jaringan WiFi terbuka
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
        break; // Keluar dari loop jika terhubung ke jaringan WiFi terbuka       
      }
    }
  }

  Serial.println("Terhubung ke jaringan WiFi: " + String(ssid));
  Serial.println("Alamat IP: " + WiFi.localIP().toString());
  // Serial.println("WiFi connected.");

  // Serial.println("IP address: ");
  // Serial.println(WiFi.localIP());
}

void loop() {}
