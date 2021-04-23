#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid     = "hdr-2.4G";
const char* password = "hdr03200";
const long utcOffsetInSeconds = 10800;
int yil, ay, gun, saat, dakika, saniye;
 
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) { delay ( 500 );
    Serial.print ( "." ); }
  
  timeClient.begin();
}

void loop() {
  timeClient.update();
  String Time;Time = timeClient.getFormattedDate();
 
    yil = Time.substring( 0,  4).toInt();
    ay = Time.substring( 5,  7).toInt();
    gun = Time.substring( 8, 10).toInt();
    saat = Time.substring(11, 13).toInt();
    dakika = Time.substring(14, 16).toInt();
    saniye = Time.substring(17, 19).toInt();
    Serial.printf("tarih :  %d-%d-%d \t saat : ",yil,ay,gun);

    Serial.print(timeClient.getHours());
    Serial.print(":");
    Serial.print(timeClient.getMinutes());
    Serial.print(":");
    Serial.println(timeClient.getSeconds());
    delay(1000);
}
