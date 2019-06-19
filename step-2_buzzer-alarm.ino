//////// VIRIABLES ///////
int buzzerPin = 3;
int x=0;

//////// SETUP ///////////
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
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

////////// loop() ///////////////////
void loop() {
  // put your main code here, to run repeatedly:
  soundAlarm(3);
  delay(1000);

}
