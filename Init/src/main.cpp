#include <Arduino.h>

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

void setup() {
  pinMode(LED_STATUS,OUTPUT);

}

void loop() {
    digitalWrite(LED_STATUS,LOW);
    
}

