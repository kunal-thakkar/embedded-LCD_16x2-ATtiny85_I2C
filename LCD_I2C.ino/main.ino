//https://www.instructables.com/id/Using-an-I2C-LCD-on-Attiny85/

/* ATtiny85 as an I2C Master
 * Modified for Digistump
 * SETUP:
 * ATtiny Pin 1 = (RESET) N/U                      ATtiny Pin 2 = (D3) N/U
 * ATtiny Pin 3 = (D4) N/U                         ATtiny Pin 4 = GND
 * ATtiny Pin 5 = (D0) SDA on DS1621  & GPIO       ATtiny Pin 6 = (D1) to LED2
 * ATtiny Pin 7 = (D2) SCK on DS1621  & GPIO       ATtiny Pin 8 = VCC (2.7-5.5V)
 * Kindly add pull up registor 4.7K for both SDA and SCK to +5V
 * LiquidCrystal_I2C lib was modified for ATtiny - on Playground with TinyWireM lib.
 * TinyWireM USAGE & CREDITS: - see TinyWireM.h
 */

#include <TinyWireM.h>              //I2C lib
#include <LiquidCrystal_I2C.h>      //LCD lib

#define LCD_I2C_ADD 0x3F

LiquidCrystal_I2C lcd(LCD_I2C_ADD,16,2);  // set address & 16 chars / 2 lines

void setup()
{
  TinyWireM.begin();                    // initialize I2C lib

  lcd.init();                           // initialize the lcd 
  lcd.backlight(); 
  lcd.clear();  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Hello World");
  lcd.setCursor(0, 1);
  lcd.print("ATtiny45 I2C");
  delay(3000);
}

void loop()
{

}
