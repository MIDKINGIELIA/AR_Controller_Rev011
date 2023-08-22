#include <Arduino.h>
// #include "BluetoothSerial.h"
#include<WiFi.h>
// BluetoothSerial SerialBT;

WiFiServer server(80);
#define LED_STATUS 40
#define BAT_ADC_Check 4
#define LED_DATA_OUT 6
#define Motor_CTL 16

#define Trig_SleepMode_SW 13
#define Reserved_SW1 12
#define Reserved_SW2 21
#define Reserved_SW3 47
#define Reserved_SW4 18
#define Reserved_SW5 17

#define Reserved_IO1 1
#define Reserved_IO2 2
#define Reserved_IO3 42
#define Reserved_IO4 41

#define IMU_SDA 8
#define IMU_SCL 9
#define IMU_INT 14

#define USB_A 19
#define USB_B 20

#define UART_TX_DEBUG 43
#define UART_RX_DEBUG 44


const char * ssid = "PARKGIBUM";
const char* password = "12345678";
void setup() {
  // Serial.begin(115200);
  // SerialBT.begin("PARK GI BUM");
  // Serial.println("블루투스 통신 시작");\
  //단순 출력
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print(F("Connecting to"));
  Serial.println(ssid);
//나의 esp32를 wifi 공유기에 접속 가능하도록 STA모드 설정
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(F("."));
  }
  Serial.println();
  Serial.println(F("WIFI connected"));
//-----------------여기까지 와이파이 연결 부분..

//웹서버
server.begin();
Serial.println(F("Server started"));
}

void loop() {
  //서버가 클라이언트의 접속을 기다린다(리스닝 상태)
  WiFiClient client = server.available();
  //클라이언트가 서버에 접소되면 아래 조건문이 참이된다!
  if(!client){
    return;
  }
  Serial.println(F("서버가 접속됨"));

// 클라이언트가 서버쪽으로 request 전송한다!
//그러므로 서버는 request를 수신해야된다.
//클라이언트가 전송된 request 전문을 USB 연결된 PC로 전송하겠다.
  while(client.available()){
    Serial.write(client.read());
  }


//서버가 클라이언트에게 response를 전송함

  client.print("heellow i'm parkgibum");

  Serial.println(F("disconnecting from"));





//   //pc에서 ESP32쪽으로 데이터를 전송함
//   if(Serial.available()){
//     SerialBT.write(Serial.read());
//   }

// // 블루투스통신으로 ESP32에게 전달
  
//   if(SerialBT.available()){
//     Serial.write(SerialBT.read());
//   }    
    

}

