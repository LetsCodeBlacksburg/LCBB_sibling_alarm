// VARIABLES
int buzzerPin = 3;        // the alarm buzzer pin 
int x = 0;

// variable used for counting
///////////////SETUP This just runs once ////////////// 
void setup(){ 
  pinMode(buzzerPin, OUTPUT);
}

/////////// soundAlarm() This is the alarm function ////////////
void soundAlarm(int cnt){
  for (x=0 ; x<cnt ; x++){
    tone(buzzerPin, 1000, 1000);  // High tone (arduino pin, the tone, how long)
    delay(1000);                  // do nothing for 1,000ms (1second)
    tone(buzzerPin, 800, 1000);   // Low tone (arduino pin, the tone, how long)
    delay(1000);                  // do nothing for 1,000ms (1second)
  }
}

//////////// loop() This loops over and over //////////////
void loop(){
// This is the main program loop
  soundAlarm(3);     // Sound alarm (n) times
  delay(10000);      // wait for 10 seconds, then go to top of the loop
}

