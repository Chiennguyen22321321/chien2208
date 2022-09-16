#include <LiquidCrystal_I2C.h>
#include <Wire.h> 

int LR = 11;//Biến khai báo chân đèn LED được nối vào Arduino
int LG=10;
int LB=9;
int QT=A0;
int BT1=2;//Biến khai báo chân của button
int BT2=3;
int BT3=4;
int BT4=5;
LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
pinMode(LR,OUTPUT);//Đặt chân led là output
pinMode(LG,OUTPUT);
pinMode(LB,OUTPUT);
pinMode(QT,INPUT);
pinMode(BT1,INPUT);//Đặt chân bt là output
pinMode(BT2,INPUT);
pinMode(BT3,INPUT);
pinMode(BT4,INPUT);
lcd.init();                
lcd.backlight();

}

void loop() {
digitalWrite(LR,LOW);//Tắt đèn led
digitalWrite(LG,LOW);
digitalWrite(LB,LOW);
int BTST1 = read_BT(BT1); 
int BTST2 = read_BT(BT2);  
int BTST3 = read_BT(BT3);
int BTST4 = read_BT(BT4);
 
lcd.setCursor(6, 1);
lcd.print("Nhom 4");
lcd.setCursor(3, 2);
lcd.print("Bao Cao De Tai");  


if(BTST1==HIGH) {
                Showinformationgroup();  
                }
if(BTST2==HIGH) {
                ControlledRGB();
                }
if(BTST3==HIGH) {
                Shownightday();
                 }
if(BTST4==HIGH) {
                LCD_RGB_AUTORUN();
                 }
                
}

bool read_BT(int bt_pin){
  int low_state = 0;
  bool retVal=false;
  if(digitalRead(bt_pin)!=low_state){
    while(digitalRead(bt_pin)!=low_state){
            
      }
      retVal=true;
     }
     return retVal;
      }


void Showinformationgroup(){
 lcd.clear();
 lcd.setCursor(0, 1);
 lcd.print("Thong Tin");
 lcd.setCursor(0, 2);
 lcd.print("Thanh Vien Nhom:");
 delay(2000);
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Nguyen Viet Anh ");
 lcd.setCursor(0, 1);
 lcd.print("Nguyen Duc Anh");
 lcd.setCursor(0, 2);
 lcd.print("Nguyen Van Chien ");
 lcd.setCursor(0, 3);
 lcd.print("Do Viet Duc");
 delay(5000);
 lcd.clear();
 
                           } 
 void showRGB(int color)
{
 int redPWM;
  int greenPWM;
  int bluePWM;
   
  if (color <= 255)          // phân vùng 1
  {
    redPWM = 255 - color;    // red đi từ sáng về tắt
    greenPWM = color;        // green đi từ tắt thành sáng
    bluePWM = 0;             // blue luôn tắt
  }
  else if (color <= 511)     // phân vùng 2
  {
    redPWM = 0;                     // đỏ luôn tắt
    greenPWM = 255 - (color - 256); // green đi từ sáng về tắt
    bluePWM = (color - 256);        // blue đi từ tắt thành sáng
  }
  else // color >= 512       // phân vùng 3
  {
    redPWM = (color - 512);         // red tắt rồi lại sáng
    greenPWM = 0;                   // green luôn tắt nhé
    bluePWM = 255 - (color - 512);  // blue sáng rồi lại tắt
  }
 
   
  analogWrite(LR, redPWM);
  analogWrite(LB, bluePWM);
  analogWrite(LG, greenPWM);
}

 void ControlledRGB(){//hiện giá trị quang trở
  lcd.clear();
  int BTST5 = read_BT(BT2);
  while(BTST5==0){
  int GTQT = analogRead(QT);
  lcd.setCursor(0, 2);
  lcd.print("Gia Tri QT: ");
  lcd.setCursor(12, 2);
  lcd.print(GTQT);
  showRGB(GTQT);
  delay(300);
 BTST5 = read_BT(BT2);
                 }
  lcd.clear();
                     }
                     
void Shownightday(){
  int BTST6 = read_BT(BT3);
  int GTQT = analogRead(QT);
  lcd.clear();
  while(BTST6==0){
  GTQT = analogRead(QT);
  if(GTQT<=150)
  {
    lcd.clear();
    lcd.setCursor(1, 2);
    lcd.print("Dang La Ban NGAY`");
    digitalWrite(LR,LOW);
    digitalWrite(LG,LOW);
    digitalWrite(LB,LOW);
    delay(500);
  }
  else{
    lcd.clear();
    lcd.setCursor(1, 2);
    lcd.print("Dang La Ban DEM");
    digitalWrite(LR,HIGH);
    digitalWrite(LG,HIGH);
    digitalWrite(LB,HIGH);
    delay(500);
      }
    BTST6 = read_BT(BT3);
                }
    lcd.clear();
   }
  
void LCD_RGB_AUTORUN(){
  lcd.clear();
  int BTST7 = read_BT(BT4);
  while(BTST7==0){
  int GTQT = analogRead(QT);
  lcd.setCursor(0, 2);
  lcd.print("Gia Tri QT: ");
  lcd.setCursor(12, 2);
  lcd.print(GTQT);
  showRGB(random(10000));
  delay(300);
  BTST7 = read_BT(BT4);
                       }
  lcd.clear();
                       }  
