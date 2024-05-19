#include <IRLibAll.h>

// IR vericiyi pin 3'e bağlayın
IRsend mySender;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT); // Pin 3'ü çıkış olarak ayarla
  Serial.println(F("IR LED testine hoş geldiniz. Komutları girin:"));
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim(); // Komutun başındaki ve sonundaki boşlukları temizle

    if (command == "VOLUME_UP") {
      Serial.println(F("Ses artırma komutu gönderiliyor..."));
      mySender.send(NEC, 0x400555AA, 32); // Ses artırma komutunu gönder
    } else if (command == "VOLUME_DOWN") {
      Serial.println(F("Ses azaltma komutu gönderiliyor..."));
      mySender.send(NEC, 0x400556A9, 32); // Ses azaltma komutunu gönder
    } else if (command == "POWER_TOGGLE") {
      Serial.println(F("Güç değiştir komutu gönderiliyor..."));
      mySender.send(NEC, 0x400501FE, 32); // Aç/kapat komutunu gönder
    } else if (command == "LEVEL") {
      Serial.println(F("Seviye komutu gönderiliyor..."));
      mySender.send(NEC, 0x400550AF, 32); // Level komutunu gönder
    } else if (command == "EFFECT") {
      Serial.println(F("Efekt komutu gönderiliyor..."));
      mySender.send(NEC, 0x4005708F, 32); // Effect komutunu gönder
    } else if (command == "INPUT") {
      Serial.println(F("Giriş komutu gönderiliyor..."));
      mySender.send(NEC, 0x400510EF, 32); // Input komutunu gönder
    } else if (command == "MUTE") {
      Serial.println(F("Sessiz komutu gönderiliyor..."));
      mySender.send(NEC, 0x400557A8, 32); // Mute komutunu gönder
    } else {
      Serial.println(F("Bilinmeyen komut."));
    }
  }
}
