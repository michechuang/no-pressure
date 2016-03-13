/**
 * Arduino Sensor
 * 
 * Bridges our hardware components with the Android Application
 */
#include <SoftwareSerial.h>

#define BT_MODULE_BAUD_RATE 9600

int led_pin = 13; /* The Arduino UNO's built-in LED is on pin 13 */
int pressure = 0;
int analog_pin = A0;

unsigned long prev_millis = 0;
const long interval = 1000;           // interval at which to blink (milliseconds)

SoftwareSerial bt_serial(9, 10);


static void android_receive_data();
static void check_sensors();
static void android_send_data();

void setup() {
    /* Set pins as outputs */
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
    Serial.begin(BT_MODULE_BAUD_RATE);
    bt_serial.begin(BT_MODULE_BAUD_RATE);
}

void loop() {
  /* Listen for data from Android Phone */
  android_receive_data();

  /* Check the sensors and update data */
  check_sensors();

  /* Send data to Android Phone */
  android_send_data();
}

/**
 * Receive data from Android
 */
static void android_receive_data() {
  //char next_char;
  
  //if (bt_serial.available()) {
   //next_char = bt_serial.read();

   pressure = analogRead(analog_pin);
  //}
}

/**
 * Do stuff on hardware
 */
static void check_sensors() {
  digitalWrite(led_pin, pressure);
  return;
}

/**
 * Send data to Android
 */
static void android_send_data() {
  char msg[32];
  unsigned long current_millis = millis();

  if (current_millis - prev_millis >= interval) {
    // save the last time you broadcasted
    prev_millis = current_millis;
    
    sprintf(msg, "%d", pressure);
    bt_serial.println(msg);
    Serial.println(msg);
  }
}
