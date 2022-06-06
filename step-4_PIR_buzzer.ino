/////////////////////////////
// Buzzer Variables
int buzzerPin = 3;        // the alarm buzzer pin 
int x = 0;
int ledPin = 13;          // the built in LED pin (if used)

// PIR Motion Sensor Variables
int calibrationTime = 20; //the time we give the sensor to calibrate (20­30sec)
int pirPin = 2;     //the digital pin connected to the PIR sensor's output
/////////////////////////////

void setup(){
  // setup buzzer
  pinMode(buzzerPin, OUTPUT);

  // setup PIR
  Serial.begin(9600);
  pinMode(pirPin, INPUT);       // Set up the various I/O pins
  pinMode(ledPin, OUTPUT);
  digitalWrite(pirPin, LOW);
  //give the sensor some time to calibrate (monitor state on the serial port)
  Serial.print("calibrating sensor ");	//prints to the serial monitor..
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }

/////////// soundAlarm() ////////////
void soundAlarm(int cnt){
  for (x=0 ; x<cnt ; x++){
    tone(buzzerPin, 1000, 1000);  // High tone (arduino pin, the tone, how long)
    delay(1000);                  // do nothing for 1,000ms (1second)
    tone(buzzerPin, 800, 1000);   // Low tone (arduino pin, the tone, how long)
    delay(1000);                  // do nothing for 1,000ms (1second)
  }
  
}

void loop(){
  if(digitalRead(pirPin) == HIGH){        // If the PIR is HIGH
	digitalWrite(ledPin, HIGH);             // then turn on the LED pin and
	Serial.println("HIGH (motion)");        // print "HIGH (motion)" on serial port
	soundAlarm(3);			                    // play alarm
  }
  else {
	digitalWrite(ledPin, LOW);              // else, make the LED pin low and
	Serial.println("LOW (no motion)");      // print "LOW (no motion)" on serial port
  }
  delay(250);                             // 250mS delay
}
