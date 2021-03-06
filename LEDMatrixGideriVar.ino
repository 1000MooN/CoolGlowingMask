//We always have to include the library
#include "LedController.hpp"
#define SensorPin 1
#define clk 4
#define cs 6
#define din 13

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to the CLK 
 pin 10 is connected to LOAD 
 We have only a single MAX72XX.
 */
LedController lc;
void setup() {
  /*
   The MAX72XX is in power-saving mode on startup,
   we have to do a wakeup call
   */
        lc=LedController(13,4,6,1);
  /* Set the brightness to a medium values */
 lc.setIntensity(14);
  /* and clear the display */
  lc.clearMatrix();
  
  Serial.begin(9600);
  pinMode(SensorPin,INPUT);  

}

/*
 This method will display the characters for the
 word "Arduino" one after the other on digit 0. 
 */
void writeArduinoOn7Segment() {
   for(int i=0;i<17;i++) {
  lc.setChar(0,0,'a',false);   
  lc.setRow(0,i+1,0x05);  
 
  lc.setRow(0,i,0x1c);     
  lc.setRow(0,i,'B11010110');    
  lc.setRow(0,i,0x15);   
  lc.setRow(0,i,0x1D);   

  lc.setChar(0,i,'c',false);
  lc.setChar(0,i,'d',false);
 
  lc.setChar(0,i,'x',false);
   }
 lc.setChar(0,1,'d',false); 
  lc.setChar(0,2,'c',false); 
  lc.setChar(0,3,'e',false);
  lc.setChar(0,4,'f',false);
  lc.setChar(0,5,'g',false);
} 

/*
  This method will scroll all the hexa-decimal
 numbers and letters on the display. You will need at least
 four 7-Segment digits. otherwise it won't really look that good.
 */
void scrollDigits() {
  for(int i=0;i<57;i++) {
    lc.setDigit(0,3,i,false);
    lc.setDigit(0,2,i+1,false);
    lc.setDigit(0,1,i+2,false);
    lc.setDigit(0,4,i+3,false);
    lc.setDigit(0,5,i+4,false);
    lc.setDigit(0,6,i+5,false);
    lc.setDigit(0,7,i+6,false);
    lc.setDigit(0,8,i+7,false);
    lc.setDigit(0,9,i+8,false);
    lc.setDigit(0,10,i+9,false);
    lc.setDigit(0,11,i+10,false);
    lc.setDigit(0,12,i+11,false);
    lc.setDigit(0,13,i+12,false);
    lc.setDigit(0,14,i+13,false);
    lc.setDigit(3,15,i+14,false);
    lc.setDigit(2,16,i+15,false);
    lc.setDigit(1,17,i+16,false); 
  }
    
}

void yuksek(){
   for(int i=5;i<17;i++){
   lc.setChar(0,i,'d',false); 
}
}
void orta(){
  for(int i=1;i<17;i++){
   lc.setChar(0,i,'c',false); 
}
}
int count=0;
void az(){

   Serial.println("Az aktif");
   digitalWrite(4,LOW);
   digitalWrite(13,LOW);
   digitalWrite(6,LOW);
   delay(300);

}
void test(){
 
}
//28 29 30 37 1022 
int sesdegeri=1023;
  
void loop(){

   sesdegeri=analogRead(1);
  Serial.println(sesdegeri);
/*
for(int a=1;a<9;a++)   
{lc.setRow(1,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(2,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(3,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(4,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(5,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(6,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(7,a,false);}
for(int a=1;a<9;a++)
{lc.setRow(8,a,false);}
*/
//sesdegeri 30 dan yüksek ise ledleri kapat
if(sesdegeri>=29){
digitalWrite(4,HIGH);
 digitalWrite(13,HIGH);
 digitalWrite(6,HIGH);
 delay(5);
}
//sesdegeri 28 ise count u arttırır
if((sesdegeri>=28&&sesdegeri<=29)){
  count++;
  Serial.println("1.DEĞER");
  delay(5);
}
//tekrar kontrol eder eğer 28 den fazla ise sıfırlar count u count en az 4 olunca çalışacağı için araya ekledim bunu ki mikrafondan tekrar veri alayım 
if(sesdegeri>=30){
    Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("2.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
    Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("3.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
  Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("4.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
  Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("5.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
    Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("6.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
   Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("7.DEĞER");
      delay(5);
  }
   if(sesdegeri>=30){
  Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("8.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
     Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("9.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
    Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("10.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
     Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("11.DEĞER");
      delay(5);
  }
  if(sesdegeri>=30){
     Serial.println(sesdegeri);
    count=0;  
    delay(5);
  }
  else{
      count++;
       Serial.println("12.DEĞER");
      delay(5);
  }

  //tekrar bakıyorum üst üste iki defa 28 denk geldiyse az method una gidiyor
if((sesdegeri>=28&&sesdegeri<=29)){ 
  count++;
   Serial.println("13.DEĞER");
  if(count>=13){
    count=0;
   az();
      delay(5);
  }    
}


}
