Fire Safety System Code:
#define GAS_SENSOR A0
#define TEMP_SENSOR A1
#define LED_PIN 2
#define BUZZER_PIN 8
#define MOTOR_PIN 9
void setup() {
pinMode(GAS_SENSOR, INPUT);
pinMode(TEMP_SENSOR, INPUT);
pinMode(LED_PIN, OUTPUT);
pinMode(BUZZER_PIN, OUTPUT);
pinMode(MOTOR_PIN, OUTPUT);
Serial.begin(9600);
Serial.println(" 🔥Fire Safety System Initialized");
Serial.println("System is in standby... waiting for sensor trigger.");
}
void loop() {
int gasValue = analogRead(GAS_SENSOR);
int tempValue = analogRead(TEMP_SENSOR);
float voltage = (tempValue * 5.0) / 1023.0;
float temperature = (voltage - 0.5) * 100.0;
Serial.print("Gas: ");
Serial.print(gasValue);
Serial.print(" | Temp: ");
Serial.print(temperature);
Serial.println(" °C");
if (gasValue > 300 || temperature > 50.0) {
Serial.println("🚨 Fire or Gas Leak Detected!");
Serial.println("🔔 Buzzer ON");
Serial.println("🔴 LED Blinking");
Serial.println("⚙️ Motor Running (Opening Emergency Gate)");
digitalWrite(BUZZER_PIN, HIGH);
digitalWrite(MOTOR_PIN, HIGH);
for (int i = 0; i < 3; i++) {
digitalWrite(LED_PIN, HIGH);
delay(300);
digitalWrite(LED_PIN, LOW);
delay(300);
}
} else {
Serial.println(" Environment Safe. System on standby.");
digitalWrite(LED_PIN, LOW);
digitalWrite(BUZZER_PIN, LOW);
digitalWrite(MOTOR_PIN, LOW);
}
delay(1000);
}
