#include <LiquidCrystal.h>

const int LDRpin = A0;
const int PIRpin = 3;
const int LED = 2;
const int btn1 = 4, btn2 = 5;
const int E = 12, RS = 11, D4 = 10, D5 = 9, D6 = 8, D7 = 7;
LiquidCrystal lcd(11,12,10,9,8,7);


bool btn2Flag = false;
bool btn1Flag = false;
bool LEDstate = false;

bool movementDetection = false;
int ambientLight = 0;
int thresholdValue = 200;

void setup()
{
  pinMode(LDRpin, INPUT);  
  pinMode(PIRpin,INPUT);
  pinMode(LED, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);

  Serial.begin(9600);
  lcd.begin(16,2);
  
  
}

void loop()
{


  if(digitalRead(btn1) && !btn1Flag){
    btn1Flag = true;
    digitalWrite(LED,!LEDstate);
  }
   if(!digitalRead(btn1) && btn1Flag){
    btn1Flag = false;
    LEDstate = !LEDstate;
  }
  lcd.setCursor(0,0);
  lcd.print("LightStatus: ");
  lcd.print(LEDstate ? "On " :"Off" );

  
  ambientLight = analogRead(LDRpin);
  lcd.setCursor(0,1);
  lcd.print("Amb: ");
  lcd.print(ambientLight);
  lcd.print(" TH: ");
  lcd.print(thresholdValue);

  if(digitalRead(btn2) && !btn2Flag){
    btn2Flag = true;
    thresholdValue += 50;
    if (thresholdValue > 800){
      thresholdValue = 200;
    }
  }
  if(!digitalRead(btn2) && btn2Flag){
    btn2Flag = false;
  }
  
  if(digitalRead(PIRpin)){
    if(ambientLight < thresholdValue){
      digitalWrite(LED,HIGH);
      LEDstate = true;
    }
  }





  
}

