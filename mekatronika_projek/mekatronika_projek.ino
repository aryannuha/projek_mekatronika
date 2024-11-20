// panggil library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// definisi variabel
#define turbidity A1
#define ph A0

int turbidityValue;
int phValue;
int mapT;

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,20,4);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();                      

  lcd.backlight();
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
  lcd.print(phValue);
  lcd.setCursor(13, 1);
  lcd.print("Ph");

  delay(100);
}
