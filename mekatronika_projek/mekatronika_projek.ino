// panggil library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// definisi pin
#define turbidity A1
#define ph A0

// servo
Servo asam;
Servo basa;

// definisi variabel
const float vref = 5.0;
const int adc_res = 1024;
const float ph_offset = 0.00; // calibration offset ph
const float ph_scale = 3.5; // scaling factor ph
int turbidityValue;
int phValue;
float mapPh, voltage;
int mapT;

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // pinMode
  pinMode(turbidity, INPUT);
  pinMode(ph, INPUT);

  // initiate lcd
  lcd.init();                      
  lcd.backlight();

  // attach servo
  asam.attach(9);
  basa.attach(10);
}

void loop() {
  // panggil fungsi pembacaan sensor
  baca_turbidity();
  baca_ph();

  // tampilkan pembacaan di lcd
  lcd.setCursor(0, 0);
  lcd.print("Kekeruhan: ");
  lcd.setCursor(0, 1);
  lcd.print("Ph: ");
  lcd.setCursor(10, 0);
  lcd.print(mapT);
  lcd.setCursor(13, 0);
  lcd.print("NTU");
  lcd.setCursor(10, 1);
  lcd.print(mapPh);
  lcd.setCursor(13, 1);
  lcd.print("Ph");

  // panggil logikaFuzzy
  logikaFuzzy();

  delay(100);
}
