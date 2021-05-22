#include <FirebaseESP32.h>
#include <DHT.h>
#include  <WiFi.h>

#define FIREBASE_HOST "https://myfarm-f6cfb-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "w51J9Ia0gQr2rd1WwAzq0VaAZN6qbRy7YZ9romO5"
#define WIFI_SSID "IoT Lab" // Thay đổi tên wifi của bạn
#define WIFI_PASSWORD "CCE@HCMUTE" // Thay đổi password wifi của bạn
#define DHTPIN 4    // Chân dữ liệu của DHT 11 , với NodeMCU chân D5 GPIO là 14
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
FirebaseData fbdo;
int fireStatus;
int f;

void setup() {

  Serial.begin(9600);
  delay(1000);
  pinMode(2,OUTPUT);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Dang ket noi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  dht.begin();
  Serial.println ("");
  Serial.println ("Da ket noi WiFi!");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt(fbdo, "ledStatus", 0);

}

void loop() {

  fireStatus = Firebase.getInt(fbdo,"ledStatus",f);
  Serial.println (f);
  if(f == 1){
    Serial.println("LED On");

    digitalWrite(2, HIGH);
    }
  else if(f == 0){
    Serial.println("LED OFF");

    digitalWrite(2, LOW);
    }
   else {

    Serial.println("Wrong Credential! Please send ON/OFF");

  }

   

  float h = dht.readHumidity();
  float t = dht.readTemperature();  // Đọc nhiệt độ theo độ C

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;

  }

  Serial.print("Nhiet do: ");
  Serial.print(t);
  Serial.print("*C  ");
  Serial.print("Do am: ");
  Serial.print(h);
  Serial.println("%  ");

  Firebase.setFloat( fbdo,"Nhiet do", t);

  Firebase.setFloat ( fbdo,"Do am", h);

  delay(200);

}
