#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

#include <LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,1);

const int button[] = {13,8,7};
const int ledpin[] = {10,9,6};

int ButtonState[] = {0,0,0};
int lastButtonState[] = {0,0,0};
int password[] = {0,2,1,0};
int level = 0;

byte degree_symbol[8] = 
{
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              }; 

const int Sensor = A0;
bool onAndOff = false;

void setup() {
  //Serial.begin(9600);
  //Serial.println("Select a button");
  
  
  
  pinMode(Sensor, INPUT);
  pinMode(button[0], INPUT);
  pinMode(button[1], INPUT);
  pinMode(button[2], INPUT);
  
  pinMode(ledpin[0], OUTPUT);
  pinMode(ledpin[1], OUTPUT);
  pinMode(ledpin[2], OUTPUT);
  
  lcd.begin(16,2);
  lcd.setCursor(0, 0);;
  lcd.print("Welcome");
  lcd.setCursor(0, 1);
  lcd.print("Buddy");
  delay(4000);
  lcd.clear();


}

void loop() {

if(onAndOff == false){
  champagne();
  
  loop();
}
        
  
  for(int i=0; i<4; i++){   
    ButtonState[i] = digitalRead(button[i]);
    
    if(ButtonState[i] != lastButtonState[i]){

      if(ButtonState[i] == LOW){
        
        switch(level){
          case 0: {if(i == password[0]){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Set the code:");
            
            
            //Serial.println("Set the code");
            digitalWrite(ledpin[1], HIGH);
            delay(1000);
            digitalWrite(ledpin[1], LOW);
            
            level++;       
          }
            else {
              //Serial.println("Button 1");
              lcd.clear();
              digitalWrite(ledpin[0], HIGH);
              
      
              lcd.setCursor(0, 0);
              lcd.print("Press the button");
              lcd.setCursor(0, 1);
              lcd.print("1 to set the Psw");
              delay(1000);
              digitalWrite(ledpin[0], LOW);
              
              level=5;
            }}
                  break;
          case 1: {if(i == password[1]){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Set the code:");
            lcd.setCursor(4, 1);
            lcd.print("*");
            delay(500);
            
            level++;
          }
                  else {
              
                //    Serial.println("Button 1");
              lcd.clear();
              digitalWrite(ledpin[0], HIGH);
              
      
              lcd.setCursor(0, 0);
              lcd.print("Press the button");
              lcd.setCursor(0, 1);
              lcd.print("1 to set the Psw");
              delay(1000);
              digitalWrite(ledpin[0], LOW);
                    level=5;
                  }}
                  break;
          case 2: {if(i == password[2]){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Set the code:");
            lcd.setCursor(4, 1);
            lcd.print("**");
            delay(500);
            
            level++;
          }
                  else {
              
                  //  Serial.println("Button 1");
              lcd.clear();
              digitalWrite(ledpin[0], HIGH);
              
      
              lcd.setCursor(0, 0);
              lcd.print("Press the button");
              lcd.setCursor(0, 1);
              lcd.print("1 to set the Psw");
              delay(1000);
              digitalWrite(ledpin[0], LOW);
                    level=5;
                  }}
                  break;
          case 3: {if(i == password[3]){

            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Set the code:");
            lcd.setCursor(4, 1);
            lcd.print("***");
            delay(1000);
            lcd.clear();
            
            level++;
          }
                  else {
              
                    //Serial.println("Button 1");
              lcd.clear();
              digitalWrite(ledpin[0], HIGH);
              
      
              lcd.setCursor(0, 0);
              lcd.print("Press the button");
              lcd.setCursor(0, 1);
              lcd.print("1 to set the Psw");
              delay(1000);
              digitalWrite(ledpin[0], LOW);
                    level=5;
                  }}
                  break;
          }
      }
      lastButtonState[i] = ButtonState[i];
    }
  }

  
  
  if(level==4){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Psw is correct!");
    digitalWrite(ledpin[2], HIGH);
    delay(1000);
    digitalWrite(ledpin[2], LOW);
    delay(100);
    
    
    
  //Serial.println("Psw correct");  
  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_E4);
  delay(500); 
  
  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_E4);
  delay(500); 

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 

  digitalWrite(ledpin[0],LOW); 
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_F4);
  delay(500);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_G4);
  delay(500); 

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_G4);
  delay(500); 

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0],LOW); 
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_F4);
  delay(500);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_E4);
  delay(500); 

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0],LOW); 
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_D4);
  delay(500);

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0],LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_C4);
  delay(500);

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0],LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_C4);
  delay(500);

  digitalWrite(ledpin[0], LOW);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0],LOW); 
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_D4);
  delay(500);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_E4);
  delay(500);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 

  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  tone(2, NOTE_E4);
  delay(500);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], HIGH);
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_D4);
  delay(200);

  digitalWrite(ledpin[0], LOW); 
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  noTone(2);
  delay(200); 
  
  digitalWrite(ledpin[0], HIGH);  
  digitalWrite(ledpin[1], HIGH);
  digitalWrite(ledpin[2], HIGH);
  tone(2, NOTE_D4);
  delay(1000);
  noTone(2);
  lcd.clear();
  digitalWrite(ledpin[0], LOW);  
  digitalWrite(ledpin[1], LOW);
  digitalWrite(ledpin[2], LOW);
  champagne();
    level=0;
    }

  if(level==5){
    for(int j=0; j<4; j++){
      
      
      lcd.clear();
    }
    champagne();
    level=0;
    
  }

  
 
  delay(20);

}



void champagne(){
  float temp_reading = analogRead(Sensor);
  float temperaturec = temp_reading*(5.0/1023.0)*100;
  float temperature = (temperaturec-32)/1.8;
  delay(10); 

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp in C:");
  lcd.setCursor(11,0);
  lcd.print(temperature);
  lcd.setCursor(0,1);
  lcd.print("Press to update");
  //lcd.print(" C");

  onAndOff = true;
  
 

}
