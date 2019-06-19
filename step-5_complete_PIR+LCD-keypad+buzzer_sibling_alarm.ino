/* PIR_LCD_keypad_sibling_alarm
This letscodeblacksburg.org project is completed example code for "Sibling Detector" 
alarm to show how to integrate the PIR sensor, LCD/button shield and speaker/buzzer 
to make a motion activated alarm system.

code - https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm
requires - LiquidCrystal.h, 1602 LCD+button shield*, PIR motion sensor HC-SR501**
  * - for example https://www.amazon.com/dp/B007MYZF9S
 ** - for example https://www.amazon.com/dp/B0140WFNYQ/
 * 
By Thomas "Tweeks" Weeks, tweeks-homework(at)theweeks.org, 2016-07-14
*/

#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);  // Our LCD uses these pins (4bit mode)

/////////////VARIABLES////////////////
// PIR Motion Sensor Variables
int calibrationTime = 20; // the time we give the sensor to calibrate (20-30sec)
int pirPin = 2;           // the digital pin connected to the PIR sensor's output
int ledPin = 13;          // the LED pin (if used)
int buzzerPin = 3;       // the alarm buzzer pin 
int x = 0;                // counter var

// LCD variables and pre-comppiler defines used by the LCD and buttons
int lcd_key     = 0;
int adc_key_in  = 0;
// When you use a #define line, the pre-compiler replaces the 1st value everywhere
// in your code, with the second value, before compiling (for human readability)
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5

#define motionYes 1
#define motionNo 0

int motion = 0;     // motion variable


///////////////SETUP//////////////
void setup(){

// LCD Setup
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Initializing... ");

  // PIR Setup
  Serial.begin(9600);
  pinMode(pirPin, INPUT);       // Set up the various I/O pins
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  //give the sensor some time to calibrate (monitor state on the serial port)
  Serial.print("calibrating sensor ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
    delay(1000);
    }
  Serial.println(" done");
  Serial.println("Sensor Ready!");
  delay(50);

  lcd.setCursor(0,0);
  lcd.print("Sensor Ready!   "); 
  delay(1500);
  }


/////////// read_LCD_buttons() ///////////
int read_LCD_buttons()
{
 adc_key_in = analogRead(0);      // read the value from the sensor 
 if (adc_key_in > 1000) return btnNONE; // We make this the 1st option for speed reasons since it will be the most likely result
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 250)  return btnUP; 
 if (adc_key_in < 450)  return btnDOWN; 
 if (adc_key_in < 650)  return btnLEFT; 
 if (adc_key_in < 1000)  return btnSELECT;  

 return btnNONE;  // when all others fail, return this...
}


//////////// checkMotion() /////////////
int checkMotion() {
  // Check PIR Sensor
  if(digitalRead(pirPin) == HIGH){        // If the PIR is HIGH
    return motionYes;
  }
  else {
    return motionNo;
  }  
}


/////////// soundAlarm() ////////////
void soundAlarm(int cnt){
  for (x=0 ; x<cnt ; x++){
    tone(buzzerPin, 1000, 1000);
    delay(1000);
    tone(buzzerPin, 800, 1000);
    delay(1000);
  }
  
}
  


//////////// loop() ////////////////
void loop(){

  // Press Any Key To Arm System
  Serial.println("Press Any key to arm!");    // print to serial port
  delay(50);
  lcd.setCursor(0,0);
  lcd.print("Any key to arm! ");              // print to top row of LCD
  delay(50);
  lcd_key = read_LCD_buttons();  // read the buttons
  while( lcd_key == btnNONE ){       // while no key is hit.. 
  lcd_key = read_LCD_buttons();  // read the buttons
  delay(5);
  }
 
  // Arming Countdown
  for(x=10 ; x>1 ; x--){
    Serial.print("Arming in ");     // print to serial port
    Serial.print(x-1);
    Serial.println(" seconds!");
    lcd.setCursor(0,0);
    lcd.print("Arming in       "); // print to top row of LCD
    lcd.setCursor(0,1);
    lcd.print("  seconds!      "); // print to bottom row of LCD
    lcd.setCursor(0,1);
    lcd.print(x-1);                  // put number in 0th position (overwriting the blank space)
    tone(buzzerPin,2000,10);
    delay(1000);
  }

  // Message: System Armed! + Low Beep
  Serial.println(" System Armed!  ");
  Serial.println("   scanning.... ");
  lcd.setCursor(0,0);
  lcd.print("  System Armed! "); 
  lcd.setCursor(0,1);
  lcd.print("   scanning.... "); 
  tone(buzzerPin,20,250);
  delay(250);
  tone(buzzerPin,20,250);


  // Watch for motion
  motion = checkMotion();
  while(motion == 0){
    motion = checkMotion();
  }
  Serial.println(" Sibling Alert! ");
  Serial.println("  Sound Alarm!  ");
  lcd.setCursor(0,0);
  lcd.print(" Sibling Alert! "); 
  lcd.setCursor(0,1);
  lcd.print("  Sound Alarm!  "); 
  soundAlarm(3);                      // sound alarm (n) times

   lcd.clear();                        // clear the LCD

  // reset values
  Serial.println("Resetting to top of loop");
  motion = 0;
  lcd_key = 1023;
  delay(2000);
}
