#include <LiquidCrystal.h>
#include <DHT.h>
#include <ESP32Servo.h>

// --- ASIGNACIÓN DE PINES  ---
const int PIN_RS = 19, PIN_E = 18, PIN_D4 = 5, PIN_D5 = 17, PIN_D6 = 16, PIN_D7 = 4;
const int PIN_DHT = 15;
const int PIN_SERVO = 13;
const int LED_ERROR = 2;  // Diagnóstico de Fallo
const int LED_SYS_OK = 14; // Estado del Sistema

// Objetos
LiquidCrystal lcd(PIN_RS, PIN_E, PIN_D4, PIN_D5, PIN_D6, PIN_D7);
DHT dht(PIN_DHT, DHT22);
Servo motorVentana;

void setup() {
  Serial.begin(115200);
  dht.begin();
  motorVentana.attach(PIN_SERVO);
  
  pinMode(LED_ERROR, OUTPUT);
  pinMode(LED_SYS_OK, OUTPUT);
  
  lcd.begin(16, 2);
  lcd.print("SMART - BCM");
  lcd.setCursor(0, 1);
  lcd.print("SISTEMA ACTIVO");
  delay(2000);
  lcd.clear();
}

void loop() {
  float tempAmbiente = dht.readTemperature();
  
  // --- MÓDULO DE AUTODIAGNÓSTICO  ---
  if (isnan(tempAmbiente)) {
    digitalWrite(LED_ERROR, HIGH);
    digitalWrite(LED_SYS_OK, LOW);
    lcd.setCursor(0,0);
    lcd.print("ERROR: DATA BUS ");
    lcd.setCursor(0,1);
    lcd.print("CHECK SENSOR    ");
    return; 
  }

  // Operación Normal
  digitalWrite(LED_ERROR, LOW);
  digitalWrite(LED_SYS_OK, HIGH);

  // --- LÓGICA DE CONTROL DE CONFORT ---
  lcd.setCursor(0, 0);
  lcd.print("TEMP: "); lcd.print(tempAmbiente); lcd.print(" C");

  lcd.setCursor(0, 1);
  if (tempAmbiente > 32.0) {
    lcd.print("VENTANA: OPEN   ");
    motorVentana.write(180); // Posición de seguridad / ventilación
  } else {
    lcd.print("VENTANA: CLOSED ");
    motorVentana.write(0);
  }

  delay(1500);
}