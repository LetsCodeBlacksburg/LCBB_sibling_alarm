# LCBB_sibling_alarm
<IMG src=/misc/LCD_shield_glamour-shot.jpg width=500 align=right>
This letscodeblacksburg.org project for our "Sibling Detector Alarm", stepping students through how to integrate the PIR (infra-red motion) sensor recipe, the LCD/button shield recipe and the speaker/buzzer recipe to "mix & bake" a motion activated alarm system. See code for hardware/software requirements.

* [LCBB_Sibling_Alarm.pdf](https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm/raw/master/LCBB_Sibling_Alarm.pdf)
This is the Sibling Detector Alarm Workshop PDF Handout (aka build doc) that contains step by step build directions and references to sensor recipes (in the cookbook (below).	

* [LCBB Arduino Cookbook](https://github.com/LetsCodeBlacksburg/arduino-recipes/blob/master/LCBB_Arduino_Cookbook.pdf)
This is the cookbook with all the build and coding recipies needed for this build. If you want to save on paper, recommend only printing the pages:
  * Arduino reference sheet (pg 4-5)
  * "Breadboard recipe" (pg 11-12)
  * "OUTPUT: Buzzer Alarms" recipe (pg 30-31)
  * "INPUT: People Motion Sensor" recipe (pg 41-42)
  * "INPUT/OUTPUT: The LCD/Keypad Shield" recipe (pg 44-50).

## Sample Code Snippets
Not requires, but nice to have (on line) to help with class time. If students/helpers get stuck, helpers can copy/paste code for each of the steps to help get student back on track.

* [Step-2 Example Code - step-2_buzzer-alarm.ino](https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm/blob/master/step-2_buzzer-alarm.ino) If you have problems with the passive buzzer code, feel free to copy/paste this code for this step.

* [Step-3 Example Code - step-3_PIR-motion.ino](https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm/blob/master/step-3_PIR-motion.ino)
If you have problems with the PIR (Passive Infra Red/motion detector) code, feel free to copy/paste this code for this step.

* [Setp-4 Example Code - step-4_PIR+buzzer.ino](https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm/blob/master/step-4_PIR%2Bbuzzer.ino)
If you have problems with merging the PIR and buzzer code, feel free to copy/paste this code for this step.

* [Step-5 Example Code - step-5_complete_PIR_LCD-keypad_buzzer_sibling_alarm.ino](https://github.com/LetsCodeBlacksburg/LCBB_sibling_alarm/blob/master/step-5_complete_PIR_LCD-keypad_buzzer_sibling_alarm.ino)
Merging the LCD code along with the PIR and buzzer coad can be a challenge. See how your code differs from this.

Other example code from our cookbook recipeis can be found here:
* PIR Motion Sensor - https://github.com/LetsCodeBlacksburg/arduino-recipes/tree/master/PIR_sensor_blink
* LCD-keypad Shield - https://github.com/LetsCodeBlacksburg/arduino-recipes/tree/master/shields/lcd_keypad
* Master LCBB Arduino Cookbook - https://github.com/LetsCodeBlacksburg/arduino-recipes/blob/master/LCBB_Arduino_Cookbook.pdf

## DIY Parts List (~$30)
* [Generic ARduino ~$10](https://www.amazon.com/dp/B07GDKLLMJ)
* [HC-SR501 PIR Passive Infrared sensor ~$2ea](https://www.amazon.com/dp/B012ZZ4LPM)
* [Passive peizo buzzer <$1ea](https://www.amazon.com/dp/B01GJLE5BS)
* [LCD Button Shield ~$15](https://www.amazon.com/dp/B006D903KE) (NOTE: Requires pin headers be soldered on, or you need to use a breadboard instead)
* [Dupont 12" connector wires ~$8](https://www.amazon.com/dp/B06XRV92ZB/)
* [Small breadboard ~$2ea](https://www.amazon.com/dp/B00LSG5BJK)

All LCBB code and related materials are copy left (open sourced) under the Creative Commons (CC)(BY)(SA)[1] License.

[1] - https://en.wikipedia.org/wiki/Creative_Commons_license#Types_of_licenses
