#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
 
// Define some values used by the panel and buttons
int lcd_key = 0;
int adc_key_in = 0;
float total = 0.00;
 
// Define button constants
#define btnLoonie 3
#define btnQuarter 4
 
// Read the buttons
int read_LCD_buttons()
{
  adc_key_in = analogRead(0); // Read the value from the sensor
  if (adc_key_in < 650)
    return btnLoonie;
  if (adc_key_in < 850)
    return btnQuarter;
  return 0; // Add a default case to handle situations where no button is pressed
}
 
void setup()
{
  lcd.begin(16, 2); // Start the library
  lcd.setCursor(0, 0);
  lcd.print("Total: $ 0.00"); // Print a simple message
}
 
void loop()
{
  lcd.setCursor(9, 0);           // Move to the beginning of the second line
  lcd_key = read_LCD_buttons();  // Read the buttons
 
  switch (lcd_key)               // Depending on which button was pushed, we perform an action
  {
    case btnLoonie:
      total += 0.25;
      lcd.print(total);
      delay(200);
      break;
    case btnQuarter:
 
      total += 1.00;
      lcd.print(total);
      delay(200);
      break;
    default:
      // Handle the default case when no button is pressed
      break;
  }
}
 