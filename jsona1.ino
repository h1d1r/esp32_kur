
#include <ArduinoJson.h>          //https://github.com/bblanchon/ArduinoJson.git
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid     = "******";
const char* password = "******";


int count = 0; 

String response="";
StaticJsonDocument<1536> doc;
      
void setup() 
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Connecting...");
  }
}

void loop() {
  get_kur();
  delay(6000);
}

void get_kur(){
    if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http; //Object of class HTTPClient
    http.begin("https://api.genelpara.com/embed/para-birimleri.json");
    int httpCode = http.GET();

    if (httpCode > 0) 
    {

   response = http.getString();

    //Serial.println(response);
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(doc, response);
           
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return;
      }
      

JsonObject USD = doc["USD"];
const char* USD_satis = USD["satis"]; // "8.1113"
const char* USD_alis = USD["alis"]; // "8.1089"
const char* USD_degisim = USD["degisim"]; // "-0,04"

JsonObject EUR = doc["EUR"];
const char* EUR_satis = EUR["satis"]; // "9.5715"
const char* EUR_alis = EUR["alis"]; // "9.5474"
const char* EUR_degisim = EUR["degisim"]; // "-0,17"

JsonObject GBP = doc["GBP"];
const char* GBP_satis = GBP["satis"]; // "11.2822"
const char* GBP_alis = GBP["alis"]; // "11.2166"
const char* GBP_degisim = GBP["degisim"]; // "-0,34"

JsonObject BTC = doc["BTC"];
const char* BTC_satis = BTC["satis"]; // "59517.9"
const char* BTC_alis = BTC["alis"]; // "59515.39"
const char* BTC_degisim = BTC["degisim"]; // "1,09"

JsonObject ETH = doc["ETH"];
const char* ETH_satis = ETH["satis"]; // "1989.21"
const char* ETH_alis = ETH["alis"]; // "1989.21"
const char* ETH_degisim = ETH["degisim"]; // "0,95"

JsonObject XRP = doc["XRP"];
const char* XRP_satis = XRP["satis"]; // "0.5685"
const char* XRP_alis = XRP["alis"]; // "0.5685"
const char* XRP_degisim = XRP["degisim"]; // "0,80"

JsonObject BCH = doc["BCH"];
const char* BCH_satis = BCH["satis"]; // "555.36"
const char* BCH_alis = BCH["alis"]; // "555.36"
const char* BCH_degisim = BCH["degisim"]; // "0,40"

JsonObject LTC = doc["LTC"];
const char* LTC_satis = LTC["satis"]; // "203.51"
const char* LTC_alis = LTC["alis"]; // "203.51"
const char* LTC_degisim = LTC["degisim"]; // "1,19"

JsonObject GA = doc["GA"];
const char* GA_satis = GA["satis"]; // "452.936"
const char* GA_alis = GA["alis"]; // "452.725"
const char* GA_degisim = GA["degisim"]; // "0,33"

JsonObject GAG = doc["GAG"];
const char* GAG_satis = GAG["satis"]; // "6.5081"
const char* GAG_alis = GAG["alis"]; // "6.5002"
const char* GAG_degisim = GAG["degisim"]; // "-0,20"

JsonObject XAU_USD = doc["XAU/USD"];
const char* XAU_USD_satis = XAU_USD["satis"]; // "1737.08"
const char* XAU_USD_alis = XAU_USD["alis"]; // "1736.27"
const char* XAU_USD_degisim = XAU_USD["degisim"]; // "0,37"

JsonObject EUR_USD = doc["EUR/USD"];
const char* EUR_USD_satis = EUR_USD["satis"]; // "1.17779"
const char* EUR_USD_alis = EUR_USD["alis"]; // "1.17768"
const char* EUR_USD_degisim = EUR_USD["degisim"]; // "-0,01"

JsonObject XU100 = doc["XU100"];
const char* XU100_satis = XU100["satis"]; // "1427"
const char* XU100_alis = XU100["alis"]; // "1427"
const char* XU100_degisim = XU100["degisim"]; // "2,51"

      Serial.print("Gram S :");
      Serial.print(GA_satis);
      Serial.print(" Gram A : ");
      Serial.print(GA_alis); 

      Serial.print(" || USD S :");
      Serial.print(USD_satis);
      Serial.print(" USD A : ");
      Serial.print(USD_alis); 
      
      Serial.print(" -- Count : "); Serial.println(count++);

    }  // end  if (httpCode > 0)
    http.end(); //Close connection
  }
  
  }
