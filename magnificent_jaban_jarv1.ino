#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (32,16,2);
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2,3,4,5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6,7,8,9}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
byte c=0;

char pass [6]={'1','2','3','4','5','6'};
  char epass[6]={};
char x[6]={};
  byte count =0;
 bool isreset=0;
void setup(){
  Serial.begin(9600);
lcd.init();
lcd.backlight();
  lcd.setCursor(2,0);
 lcd.print("Enter password");
  lcd.setCursor(0,1);
 lcd.print("to reset press A"); 
  delay(1000);
  lcd.clear();
 lcd.setCursor(0,1);
}
  
void loop(){
  char key = keypad.getKey();
  if(key){
    lcd.print('*');     
    if(key!='D' && key!='A'){
      epass[count]=key;
      count++;
    }
    else if(key=='D'&&key!='A'){
    for(int i=0 ;i<6;i++){
    if(epass[i]==pass[i]){
      c++; }}
    if (c>=6&&isreset==0){lcd.clear();lcd.print("true pass");lcd.setCursor(0,1);count=0;c=0;isreset=0;}
   else  {lcd.clear();lcd.print("wrong pass");lcd.setCursor(0,1);count=0;c=0;isreset=0;}
    }
      else if(key!='D'&&key=='A'){
        for(int i=0 ;i<6;i++){
   x[i]=epass[i];
      c++;
        isreset=1;}
        for(int i=0 ;i<6;i++){
   pass[i]=x[i];
        }
    if(c==6)  lcd.clear();lcd.print("pass is reset");lcd.setCursor(0,1);count=0;c=0;isreset=0;}
    }delay(200);}
  