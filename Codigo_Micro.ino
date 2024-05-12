#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h> // Agregar la biblioteca del servo motor
#define DHTPIN A1 // Pin del sensor de temperatura cambiado a A1
#define DHTTYPE DHT11
#define FAN_PIN 11 // Pin del ventilador
#define BASE_RESISTOR 1000 // Valor de la resistencia base del transistor
#define LOW_THRESHOLD 36 // Umbral de temperatura para velocidad baja
#define HIGH_THRESHOLD 39// Umbral de temperatura para velocidad alta

DHT dht(DHTPIN, DHTTYPE);

Servo servoMotor; // Crear un objeto del servo motor
// Inicializa el objeto LCD con la dirección I2C y el tamaño del LCD (20x4)

LiquidCrystal_I2C lcd(0x27, 20, 4);  // Dirección I2C y tamaño del LCD
const int PHOTO = A0;

const int LED = 9;

void setup() {

  Serial.begin(9600);

  dht.begin();

  servoMotor.attach(6); // Adjuntar el servo al pin 6

  // Inicializa la comunicación I2C y el LCD

  lcd.init();

  lcd.backlight(); // Enciende la retroiluminación

  // Muestra un mensaje de inicio en el LCD

  lcd.setCursor(0, 0);

  lcd.print("Temperatura:   ");

  lcd.setCursor(0, 1);

  lcd.print("Humedad:       ");

  lcd.setCursor(0, 2);

  lcd.print("Luz:           ");

  pinMode(PHOTO, INPUT);

  pinMode(LED, OUTPUT);

}

void loop() {

  // Espera un momento antes de leer los valores nuevamente

  delay(2000);

  // Lee la temperatura y la humedad

  float temperatureC = dht.readTemperature();

  float humidity = dht.readHumidity();

  // Lectura del fotoresistor

  int value = analogRead(PHOTO);

  // Agrega un retraso para la lectura del fotoresistor

  delay(500);

  // Verifica si la lectura es válida

  if (!isnan(temperatureC) && !isnan(humidity)) {

    // Muestra los valores de temperatura y humedad en el LCD

    lcd.setCursor(12, 0);

    lcd.print(temperatureC);

    lcd.setCursor(12, 1);

    lcd.print(humidity);

    lcd.setCursor(5, 2);

    lcd.print(value);

    // Muestra los valores por serial para depuración

    Serial.print("Temperature: ");

    Serial.print(temperatureC);

    Serial.println(" °C");

    Serial.print("Humidity: ");

    Serial.print(humidity);

    Serial.println(" %");

    Serial.print("Light: ");

    Serial.println(value);
    // Controla la velocidad del ventilador en base a la temperatura

 if (temperatureC >= HIGH_THRESHOLD) {
  // Si la temperatura es igual o mayor que el umbral alto, enciende el ventilador a máxima velocidad
  analogWrite(FAN_PIN, 255);
} else if (temperatureC >= LOW_THRESHOLD) {
  // Si la temperatura está entre el umbral bajo y el umbral alto, establece el ventilador a media velocidad
  analogWrite(FAN_PIN, 127);
} else {
  // Si la temperatura es menor que el umbral bajo, apaga el ventilador
  analogWrite(FAN_PIN, 0);
}

    // Controla el servo motor para abrir o cerrar la ventana

    if (temperatureC >= HIGH_THRESHOLD) {

      // Si la temperatura es igual o mayor que el umbral alto, abre la ventana (posición 180 grados)

      servoMotor.write(180);

    } else if (temperatureC >= LOW_THRESHOLD) {

      // Si la temperatura está entre el umbral bajo y alto, cierra la ventana (posición 0 grados)

      servoMotor.write(90);

    }

  } else {

    // Si la lectura no es válida, muestra un mensaje de error en el LCD

    lcd.setCursor(0, 3);

    lcd.print("Error: NaN");

    // Muestra un mensaje de error por serial

    Serial.println("Error: Lectura inválida");

  }

  // Controlar la intensidad del LED

  if (value > 380) {

    digitalWrite(LED, 0);

  } else {

    // Invertir y ajustar la lectura del fotoresistor de manera más pronunciada

    int luz = map(value, 0, 1023, 155, 0);

    luz = constrain(luz, 0, 155); // Asegurarse de que la intensidad esté dentro del rango

    digitalWrite(LED, luz);

  }

}