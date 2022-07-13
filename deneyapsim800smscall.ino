const String PHONE = "+905555555555"; // mesaj gönderilecek telefon numaranız

// gerekli kütüphaneler
#include "deneyap.h"
#include "lsm6dsm.h"
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <HTTPClient.h>

int durum= 0;
const char* ssid = "Rose 2.4"; //wifi adı
const char* password = "35603560"; // wifi şifresi
WiFiServer server(80);

int rxPin = D3;
int txPin = D2;
#define BAUD_RATE 9600
HardwareSerial sim800(1);
double konum;

LSM6DSM IMU;  

// google earth'ten alınmış örnek konum
double lat = 38.394520;
double lng = 27.096154;

int switchpin=D4;

int buzzer = D9;
int i;


void setup() {
    pinMode(buzzer,OUTPUT);
    pinMode(switchpin,INPUT);
  
  Serial.begin(9600);
    IMU.begin();
  Serial.println("esp32 serial initialize");
  
   sim800.begin(BAUD_RATE, SERIAL_8N1, rxPin, txPin);
  Serial.println("SIM800L serial initialize");
  
    sim800.print("AT+CMGF=1\r"); //SMS text modu
    delay(3000);
  Serial.println();
  Serial.println(); Serial.print("Connecting to "); Serial.println(ssid);WiFi.begin(ssid, password);    
  
   while (WiFi.status() != WL_CONNECTED) 
    {
      delay(500);
      Serial.print(".");
    }
       
    Serial.println(""); Serial.println("WiFi connected");
     
    // server başlatılıyor
    server.begin();
    Serial.println("Server started");
     
    // baglantı saglandıktan sonra serial monitorde bize ip adresini gösteriyor.
    Serial.print("Use this URL to connect: ");
    Serial.print("http://");
    Serial.print(WiFi.localIP());
    Serial.println("/");
     Serial.print("gatewayIP(): ");
    Serial.print("http://");
    Serial.print(WiFi.gatewayIP());
    Serial.println("/");
    
    Serial.println(WiFi.RSSI()); //sinyal gücü desibel cinsinden -70 ve daha düşük (sıfıra yakın) olması iyi 
}

void loop() 
{
  
 
   if (IMU.readFloatAccelX()<0.45 & IMU.readFloatAccelX()>-0.45){}
   else if (IMU.readFloatAccelX()<0.45) durum=1;
   else if (IMU.readFloatAccelX()<-0.45) durum=1;

   int switchoku = digitalRead(switchpin);
   if (switchoku==0) durum=1;
   
  
   //kendi ayarladığımız döngü,switch aktif olduğunda çalışacak şekilde, buradan fonksiyonları istediğimiz sırayla çağırabiliriz
   if(durum==1)
   {
      konumat();
      webgonder();
      ara();
      sinyal();
      durum=0;
   }
   
//delay(20000);
}



void smsat(String text)
{
      sim800.print("AT+CMGF=1\r");
      delay(1000);
      sim800.print("AT+CMGS=\""+PHONE+"\"\r");
      delay(1000);
      sim800.print(text);
      delay(100);
      sim800.write(0x1A); //ascii code for ctrl-26 //  sim800.println((char)26); //ascii code for ctrl-26
      delay(1000);
      Serial.println("SMS Sent Successfully.");
}

/****************************************************************/

void konumat()
{
   if (IMU.readFloatAccelX()<0.30 & IMU.readFloatAccelX()>-0.15){}
   else if (IMU.readFloatAccelX()<0.30 || IMU.readFloatAccelX()<-0.15 ) 
    sim800.print("AT+CMGF=1\r");
    delay(1000);
    sim800.print("AT+CMGS=\""+PHONE+"\"\r");
    delay(1000);
    sim800.print("http://maps.google.com/maps?q=loc:");
    sim800.print(lat, 6);
    sim800.print(",");
    sim800.print(lng, 6);
    delay(100);
    sim800.write(0x1A); //ascii code for ctrl-26 //  sim800.println((char)26); //ascii code for ctrl-26
    delay(1000);
    Serial.println("SMS Sent Successfully.");
    delay(1000);
    
}

/****************************************************************/

void ara()
{
      sim800.println("ATD"+ PHONE +";"); // çağrı gönderme
      delay(30000);
      sim800.println("ATH"); // çağrıyı sonlandırma kodu
 //telefon çağrısı yapıldı 30 saniye (30000 ms) boyunca çağrı devam etti ve kapandı
  }

/****************************************************************/  

void webgonder()
{
          WiFiClient client = server.available();
            if (client) 
            {
                  if (client.connected()) 
                  {
                        Serial.println("Connected to client");
                        client.println("<html>deneme</html>");
                  }
                    client.stop();// close the connection:
            }
              // aşağıdaki kod NodeMCU'nun Deneyap kartı'ın bir web sitesine (server'a) istek gönderme ve geleni yazma kodu
              
                HTTPClient http;
                // http begin'deki linki kendi locahost'unuzun ip'sine göre kendi php html kodunuza göre aktabilirsiniz .
                // farklı http post yöntemleri bulunmaktadır youtube da http get post arduino diye aratarak ilgili içerikleri bulabilirsiniz. 
                // kendi php-html kodumu klosöre bırakacağım anlamadığınız yer olursa ulaşabilirsiniz.
                http.begin("http://192.168.1.106/e-Kutu/ekle.php?deger1=Aktif&deger2="+ String(lat,6)+","+ String(lng,6)+"&deger3=İdeal");
   
                int httpResponseCode = http.GET();            
                 if (httpResponseCode>0) 
                    {
                      Serial.print("HTTP Response code: ");
                      Serial.println(httpResponseCode);
                      String payload = http.getString();
                      Serial.println(payload);
                    } 
                    else 
                    {
                      Serial.print("Error code: ");
                      Serial.println(httpResponseCode);
                    }  
                    // Free resources
                    http.end();
                    delay(2000);
  }
  
/****************************************************************/

void sinyal()
  {
     for(i=0;i<50;i++){
      digitalWrite(buzzer,1);
      delay(10);
      digitalWrite(buzzer,0);
      delay(10);}
   }

/****************************************************************/
