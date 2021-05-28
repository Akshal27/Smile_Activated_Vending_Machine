#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display



Servo servo1, servo2, servo3, servo4;   // DS04-NFC motors


#define button1 13
#define button2 12
#define button3 11
#define button4 10

int buttonPressed;

 
void setup()
{

  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);

  
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);

  lcd.init();
  lcd.clear();         
  lcd.backlight(); // Make sure backlight is on
  
  // Print a message on both lines of the LCD.
  lcd.setCursor(2,0);   //Set cursor to character 2 on line 0
  lcd.print("Smile For");
  
  lcd.setCursor(2,1);   //Move cursor to character 2 on line 1
  lcd.print("Chocolate");
  Serial.begin(9600);
}

void loop()
{
  if(Serial.read() == '1')
  {
    lcd.clear();
    lcd.setCursor(2,0);  
    lcd.print("Hooray");
    lcd.setCursor(2,1);  
    lcd.print("Nice Smile");
    delay(2000);
  lcd.clear();
  lcd.setCursor(2, 0);
  lcd.print("Select your item");
  
  lcd.setCursor(2, 1);
  lcd.print(" 1, 2, 3 or 4?");
  delay(2000); 
  Serial.end();
  }
  else if(Serial.read() == '0')
          { 
            lcd.clear();
            lcd.setCursor(2,0);  
            lcd.print("Better Smile");
            lcd.setCursor(2,0);  
            lcd.print("Next time");
            
        } 

   while (true) {
          if (digitalRead(button1) == LOW) {
            buttonPressed = 1;
            break;
          }
          if (digitalRead(button2) == LOW) {
            buttonPressed = 2;
            break;
          }
          if (digitalRead(button3) == LOW) {
            buttonPressed = 3;
            break;
          }
          if (digitalRead(button4) == LOW) {
            buttonPressed = 4;
            break;
          }


          switch (buttonPressed) {
          case 1:
            // Move the container to location 1
            
            // Rotate the helical coil, discharge the selected item
            for (int i = 0 ; i<=3;i++){
            servo1.write(180); // rotate
            delay(950);
            servo1.write(50);  // stop
            delay(500);
            }
            servo1.write(0);
            break;
            
           case 2:
            // Move the container to location 2
            for (int i = 0 ; i<=3;i++){
            servo2.write(180); // rotate
            delay(950);
            servo2.write(50);  // stop
            delay(500);
            }
            servo2.write(0);
            break;
            
            case 3:
            // Move the container to location 3
            for (int i = 0 ; i<=3;i++){
            servo3.write(180); // rotate
            delay(950);
            servo3.write(50);  // stop
            delay(500);
            }
            servo3.write(0);
            break;
            case 4:
            // Move the container to location 4
            for (int i = 0 ; i<=3;i++){
            servo3.write(180); // rotate
            delay(950);
            servo3.write(50);  // stop
            delay(500);
            }
            servo1.write(0);
            break;

            default:
             break;
             Serial.begin(9600);
      
          }
          
          
          lcd.clear(); // Clears the display
          lcd.setCursor(0, 0);
          lcd.print("Item delivered!"); // Prints on the LCD
          delay(2000);
        
          
}
}
