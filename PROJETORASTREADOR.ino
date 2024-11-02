#include <SoftwareSerial.h>
#include <TinyGPS.h>

// Pinos para o SIM800L e NEO-6M
SoftwareSerial mySerial(3, 2); // SIM800L Tx & Rx
SoftwareSerial SerialGPS(8, 9); // GPS NEO-6M Tx & Rx

TinyGPS GPS;

float lat, lon;
unsigned long data, hora;
unsigned short sat;

void setup() {
  Serial.begin(9600);           // Comunicação com o monitor serial
  mySerial.begin(9600);          // Comunicação com o SIM800L
  SerialGPS.begin(9600);         // Comunicação com o NEO-6M

  Serial.println("Inicializando...");
  delay(1000);

  mySerial.println("AT");         // Teste de comunicação com o SIM800L
  updateSerial();
  mySerial.println("AT+CMGF=1");  // Configuração para modo de texto
  updateSerial();
}

void loop() {
  // Checar se o GPS tem dados disponíveis
  while (SerialGPS.available()) {
    if (GPS.encode(SerialGPS.read())) {

      // Coletar latitude e longitude do GPS
      GPS.f_get_position(&lat, &lon);

      if (lat != TinyGPS::GPS_INVALID_F_ANGLE && lon != TinyGPS::GPS_INVALID_F_ANGLE) {
        // Construir o link do Google Maps
        String link = "http://maps.google.com/maps?q=";
        link += String(lat, 6);
        link += ",";
        link += String(lon, 6);

        // Enviar o link via SMS
        enviarSMS(link);
      }

      // Pequeno atraso para evitar envios excessivos
      delay(3000); // Envia a cada minuto (ajuste conforme necessário)
    }
  }
}

void enviarSMS(String mensagem) {
  mySerial.println("AT+CMGS=\"+5581992286170\"");  // Substitua pelo número desejado
  updateSerial();
  mySerial.print(mensagem);  // Conteúdo do SMS com o link do Google Maps
  updateSerial();
  mySerial.write(26);         // Código ASCII para o fim da mensagem
  delay(1000);
}

void updateSerial() {
  delay(500);
  while (Serial.available()) {
    mySerial.write(Serial.read());
  }
  while (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
