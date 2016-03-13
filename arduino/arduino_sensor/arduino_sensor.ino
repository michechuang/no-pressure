/**
 * Arduino Sensor
 * 
 * Bridges our hardware components with the Android Application
 */

#define BT_MODULE_BAUD_RATE 9600

int led_pin = 13; /* The Arduino UNO's built-in LED is on pin 13 */
int state = 0;
int last_state = 0;

static void android_receive_data();
static void check_sensors();
static void android_send_data();

void setup() {
    /* Set pins as outputs */
    pinMode(led_pin, OUTPUT);
    digitalWrite(led_pin, LOW);
    Serial.begin(BT_MODULE_BAUD_RATE);
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
  char next_char;
  
  if (Serial.available()) {
   next_char = Serial.read();

   state = (next_char == '0' ? 0 : 1);
  }
}

/**
 * Do stuff on hardware
 */
static void check_sensors() {
  digitalWrite(led_pin, state);
  return;
}

/**
 * Send data to Android
 */
static void android_send_data() {
  char msg[32];

  if (last_state != state) {
    sprintf(msg, "LED: %d", state);
    Serial.println(msg);  
    last_state = state;
  }
}
