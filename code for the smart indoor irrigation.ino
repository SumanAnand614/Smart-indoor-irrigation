
// AUTOMATIC IRRIGATION SYSTEM
// CREATED BY TEAM-U FOR DIY PROJECT
// AMAN SINGH (21EC30010)
// SUMAN ANAND(21MA10061)
// SAMAY SAWAL (21ME10068)
/* 
Connection Details 
ARDUINO PINS
0-------> N/C
1-------> N/C
2-------> LCD-14
3-------> LCD-13
4-------> LCD-12
5-------> LCD-11
6-------> N/C
7-------> WATER_LEVEL_STATUS_LED
8-------> N/C
9-------> SPEAKER
10------> N/C
11------> LCD-6
12------> LCD-4
13------> PUMP STATUS LED) AND TO RELAY
A0------> SOIL MOISTURE SENSOR

LCD-1---> GND
LCD-5---> GND
LCD-2---> +Vcc
LCD-3---> LCD_BRIGHTNESS


*/
 
#include <LiquidCrystal.h> //including LCD Library

#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523 

int temp; //int T_Sensor = A4;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   //Assigning Pins to the LCD

void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
    pinMode(9,OUTPUT);
    Serial.begin(9600);
    
    lcd.setCursor(0,1);
    lcd.print("TEAM U");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("AUTOMATIC");
    lcd.setCursor(0,1);
    lcd.print("IRIGATION SYSTEM");
    delay(2500);
    lcd.clear(); 
   
  
    delay(1000);
}

void loop()
{
  
  lcd.clear();
    
  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value 
  Serial.println(Moisture);

 if (Moisture> 200)   // for dry soil
  { 
        lcd.setCursor(0,0);
        lcd.print("DRY SOIL");
        //lcd.setCursor(11,1);
        //lcd.print("SOIL");
       if (digitalRead(W_led)==1) //Test for the availability of water in storage tank
       {
         digitalWrite(13, HIGH);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
       }
       else
       {
         digitalWrite(13, LOW);
         lcd.setCursor(0,1);
         lcd.print("PUMP:OFF");
         lcd.setCursor(11,0);
        lcd.print("WATER");
        lcd.setCursor(11,1);
        lcd.print("LOW");
         
           
           tone(Speaker, NOTE_C4, 500); 
           delay(500); 
           tone(Speaker, NOTE_D4, 500);
           delay(500); 
           tone(Speaker, NOTE_E4, 500); 
           delay(500); 
           tone(Speaker, NOTE_F4, 500); 
           delay(500); 
           tone(Speaker, NOTE_G4, 500); 
           delay(500);
       }
    }
 
     if (Moisture>= 70 && Moisture<=200) //for Moist Soil
    { 
      lcd.setCursor(0,0);
     lcd.print("MOIST SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
  }
 
  if (Moisture < 70)  // For WET soil
  { 
    lcd.setCursor(0,0);
     lcd.print("WET SOIL");
     //lcd.setCursor(11,1);
     //lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(1000);    
}  
