#include <HC595.h> 

//for 1st 3 ic's
const int ShiftPWM_latchPin = 12;  
const int ShiftPWM_clockPin = 10;  
const int ShiftPWM_dataPin = 11;  
//for 2nd 2 ic's
const int chipCount = 2;
const int latchPin = 7;  
const int clockPin = 5;  
const int dataPin = 6; 

#define SHIFTPWM_NOSPI
const bool ShiftPWM_invertOutputs = false; 
const bool ShiftPWM_balanceLoad = false;

#include <ShiftPWM.h>

HC595 ledArray(chipCount,latchPin,clockPin,dataPin);

int d1 = 100;
int d2 = 200;
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
int numRegisters = 3;
int numRGBleds = numRegisters*8/3;

void setup() {
  
 
  ledArray.reset();
  pinMode(OUTPUT,2);
  pinMode(OUTPUT,3);
  digitalWrite(2,HIGH);
  ShiftPWM.SetAmountOfRegisters(numRegisters);
  ShiftPWM.Start(pwmFrequency,maxBrightness);
 
}


void(* resetFunc) (void) = 0; 

void set2zero(){
  for (int i = 0; i<=12; i++){ledArray.setPin(i,LOW);}
}

void P1(){
  
ShiftPWM.SetAll(0);
 for  (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
 }

 for (int i = 0; i<=6; i++){
  ShiftPWM.SetOne(i,255);
  delay(d1);
 }

 for (int i = 0; i<=6; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 }
//////////////////////////////////////////////
for (int i = 7; i<=13; i++){
  ShiftPWM.SetOne(i,255);
  delay(d1);
 }

 for (int i = 7; i<=13; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 }
 ////////////////////////////////////////
 for (int i = 14; i<=20; i++){
 ShiftPWM.SetOne(i,255);
  delay(d1);
 }

 for (int i = 14; i<=20; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 } 
 ShiftPWM.SetAll(0);
}

void P2(){
ShiftPWM.SetAll(0);
   set2zero();
  for (int i = 0; i<=6; i++){ShiftPWM.SetOne(i,255);}

 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
  delay(d1);
 }
 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,LOW);
  delay(d1);
}
 for (int i = 0; i<=6; i++){
  ShiftPWM.SetOne(i,LOW);
 }
////////////////////////////////
 for (int i = 7; i<=13; i++){
 ShiftPWM.SetOne(i,255);
 }

 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
  delay(d1);
 }
 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,LOW);
  delay(d1);
}
 for (int i = 7; i<=13; i++){
  ShiftPWM.SetOne(i,LOW);
 }
/////////////////////////////////
 for (int i = 14; i<=20; i++){
  ShiftPWM.SetOne(i,255);
 }

 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
  delay(d1);
 }
 for (int i = 0; i<=12; i++){
  ledArray.setPin(i,LOW);
  delay(d1);
}
 for (int i = 14; i<=20; i++){
 ShiftPWM.SetOne(i,LOW);
 }
 ShiftPWM.SetAll(0);
}

void P3(){
ShiftPWM.SetAll(0);
  set2zero();
   for  (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
 }

 
 for (int i = 0; i<=6; i++){
  ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}

 for (int i = 6; i>=0; i--){
  ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}
//////////////////////////////////
for (int i = 7; i<=13; i++){
  ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}

 for (int i = 13; i>=7; i--){
 ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}
//////////////////////////////////
for (int i = 14; i<=20; i++){
  ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}

 for (int i = 20; i>=14; i--){
  ShiftPWM.SetOne(i,255);
  delay(d1);
  ShiftPWM.SetOne(i,LOW);
}
ShiftPWM.SetAll(0);
 
}

void P4_base(){
  
ledArray.setPin(0,HIGH);
ledArray.setPin(12,HIGH);
delay(d1);
ledArray.setPin(1,HIGH);
ledArray.setPin(11,HIGH);
delay(d1);
ledArray.setPin(2,HIGH);
ledArray.setPin(10,HIGH);
delay(d1);
ledArray.setPin(3,HIGH);
ledArray.setPin(9,HIGH);
delay(d1);
ledArray.setPin(4,HIGH);
ledArray.setPin(8,HIGH);
delay(d1);
ledArray.setPin(5,HIGH);
ledArray.setPin(7,HIGH);
delay(d1);
ledArray.setPin(6,HIGH);
delay(d1);

ledArray.setPin(0,LOW);
ledArray.setPin(12,LOW);
delay(d1);
ledArray.setPin(1,LOW);
ledArray.setPin(11,LOW);
delay(d1);
ledArray.setPin(2,LOW);
ledArray.setPin(10,LOW);
delay(d1);
ledArray.setPin(3,LOW);
ledArray.setPin(9,LOW);
delay(d1);
ledArray.setPin(4,LOW);
ledArray.setPin(8,LOW);
delay(d1);
ledArray.setPin(5,LOW);
ledArray.setPin(7,LOW);
delay(d1);
ledArray.setPin(6,LOW);
delay(d1);

 
  
}

void P4(){

  set2zero();
  ShiftPWM.SetAll(0);
  
  for (int i=0; i<=6; i++){
    ShiftPWM.SetOne(i,255);
  }
  
  P4_base();
  
  for (int i=0; i<=6; i++){
    ShiftPWM.SetOne(i,LOW);
  }
  
  
  for (int i=7; i<=13; i++){
    ShiftPWM.SetOne(i,255);
  }
  
  P4_base();
  
   for (int i=7; i<=13; i++){
   ShiftPWM.SetOne(i,LOW);
  }

    for (int i=14; i<=20; i++){
    ShiftPWM.SetOne(i,255);
  }
  
  P4_base();
  
   for (int i=14; i<=20; i++){
    ShiftPWM.SetOne(i,LOW);
  }
  ShiftPWM.SetAll(0);
}

void P5(){
  set2zero();
  ShiftPWM.SetAll(0);
  for (int i = 0; i<=12; i++){ledArray.setPin(i,HIGH);}

  for (int i=0; i<=6; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
  }
  delay(d1);
  for (int i=7; i<=13; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
  }
delay(d1);
  for (int i=14; i<=20; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
  }
  ShiftPWM.SetAll(0);
}
void P6(){
  set2zero();
  ShiftPWM.SetAll(0);
  for (int i = 0; i<=12; i++){ledArray.setPin(i,HIGH);}

  for (int i=0; i<=6; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
  }

  for (int i=7; i<=13; i++){
  ShiftPWM.SetOne(i,255);
    delay(d1);
  }
   for (int i=0; i<=6; i++){
    ShiftPWM.SetOne(i,LOW);
    delay(d1);
  }
  for (int i=14; i<=20; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
  }
  for (int i=7; i<=13; i++){
   ShiftPWM.SetOne(i,LOW);
  }
   for (int i=14; i<=20; i++){
    ShiftPWM.SetOne(i,LOW);
    delay(d1);
  }
  ShiftPWM.SetAll(0);
}

void P7(){
  set2zero();
  ShiftPWM.SetAll(0);
  for (int i = 0; i<=12; i++){ledArray.setPin(i,HIGH);}
  for (int i = 0; i<=6; i++){ShiftPWM.SetOne(i,255);}
  delay(d2);
  for (int i = 0; i<=6; i++){ShiftPWM.SetOne(i,LOW);}
  delay(d2);

   for (int i = 7; i<=13; i++){ShiftPWM.SetOne(i,255);}
  delay(d2);
  for (int i = 7; i<=13; i++){ShiftPWM.SetOne(i,LOW);}
  delay(d2);

   for (int i = 14; i<=20; i++){ShiftPWM.SetOne(i,255);}
  delay(d2);
  for (int i = 14; i<=20; i++){
    ShiftPWM.SetOne(i,LOW);
    delay(d1);
    }
    ShiftPWM.SetAll(0);
  
  
}



void P8(){

  set2zero();

  for (int i = 0; i<=12; i++){
    ledArray.setPin(i,HIGH);
  }

  for (int pin = 0; pin < 7; pin++){
    for (unsigned char b = 0; b < 255; b++){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
     for (unsigned char b = 255; b > 0; b--){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
  }
ShiftPWM.SetAll(0);
  for (int pin = 7; pin < 14; pin++){
    for (unsigned char b = 0; b < 255; b++){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
     for (unsigned char b = 255; b > 0; b--){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
  }

  ShiftPWM.SetAll(0);
  for (int pin = 14; pin < 21; pin++){
    for (unsigned char b = 0; b < 255; b++){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
     for (unsigned char b = 255; b > 0; b--){
      ShiftPWM.SetOne(pin, b);
      delayMicroseconds(100);
    }
  }
  ShiftPWM.SetAll(0);

}

void P9(){
  set2zero();
  ShiftPWM.SetAll(0);
 for  (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);
 }
 
for (int b = 0; b<256; b++){
 for (int i = 0; i<=6; i++){
  ShiftPWM.SetOne(i,b);
 delayMicroseconds(50);
 }
}

 for (int i = 0; i<=6; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 }
//////////////////////////////////////////////
for (int b = 0; b<256; b++){
for (int i = 7; i<=13; i++){
  ShiftPWM.SetOne(i,b);
  delayMicroseconds(50);
 }
}

 for (int i = 7; i<=13; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 }
 ////////////////////////////////////////
 for (int b = 0; b<256; b++){
 for (int i = 14; i<=20; i++){
 ShiftPWM.SetOne(i,b);
  delayMicroseconds(50);
 }
 }

 for (int i = 14; i<=20; i++){
   ShiftPWM.SetOne(i,LOW);
  delay(d1);
 } 
 ShiftPWM.SetAll(0);
}

void P10(){
  set2zero();
   ShiftPWM.SetAll(0);
 for  (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);}

  for (int i = 0; i<=5; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
    
  }
  ShiftPWM.SetOne(6,255);
  for (int i = 0; i<=4; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
  }
  ShiftPWM.SetOne(5,255);

   for (int i = 7; i<=10; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
    
  }
  ShiftPWM.SetOne(11,255);
   for (int i = 14; i<=16; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
   
  }
   ShiftPWM.SetOne(17,255);

   for (int i = 7; i <= 8; i++){
    ShiftPWM.SetOne(i,255);
    delay(d1);
    ShiftPWM.SetOne(i,LOW);
   
  }
   ShiftPWM.SetOne(9,255);
  ShiftPWM.SetOne(0,255);
  delay(d1);
  ShiftPWM.SetOne(0,LOW);
  ShiftPWM.SetOne(1,255); 
   ShiftPWM.SetOne(0,255); 
/////////////all fade system////////////////////////
   for (int b=255; b>=0; b--){
  ShiftPWM.SetOne(6,b);
  ShiftPWM.SetOne(5,b);
  ShiftPWM.SetOne(11,b);
  ShiftPWM.SetOne(17,b); 
  ShiftPWM.SetOne(9,b);
  ShiftPWM.SetOne(1,b);
  ShiftPWM.SetOne(2 ,b); 
  delayMicroseconds(300);    
   
   }
    for (int b=0; b<=255; b++){
  ShiftPWM.SetOne(6,b);
  ShiftPWM.SetOne(5,b);
  ShiftPWM.SetOne(11,b);
  ShiftPWM.SetOne(17,b); 
  ShiftPWM.SetOne(9,b);
  ShiftPWM.SetOne(1,b);
  ShiftPWM.SetOne(2 ,b); 
  delayMicroseconds(300);    
   
   }

   for (int b=255; b>=0; b--){
  ShiftPWM.SetOne(6,b);
  ShiftPWM.SetOne(5,b);
  ShiftPWM.SetOne(11,b);
  ShiftPWM.SetOne(17,b); 
  ShiftPWM.SetOne(9,b);
  ShiftPWM.SetOne(1,b);
  ShiftPWM.SetOne(2 ,b); 
  delayMicroseconds(300);    
   
   }
    for (int b=0; b<=255; b++){
  ShiftPWM.SetOne(6,b);
  ShiftPWM.SetOne(5,b);
  ShiftPWM.SetOne(11,b);
  ShiftPWM.SetOne(17,b); 
  ShiftPWM.SetOne(9,b);
  ShiftPWM.SetOne(1,b);
  ShiftPWM.SetOne(2 ,b); 
  delayMicroseconds(300);    
   
   }
    
   ShiftPWM.SetAll(0);   
  
}

void P11(){
  set2zero();
  ShiftPWM.SetAll(0);
   for  (int i = 0; i<=12; i++){
  ledArray.setPin(i,HIGH);}
  
  for (int i = 14; i<=16; i++){
    ShiftPWM.SetOne(i,255);
  delay(d1);
  }
  
  ShiftPWM.SetOne(17,100);
   ShiftPWM.SetOne(3,255);
    delay(d1);
       
for (int i = 18; i<=20; i++){
    ShiftPWM.SetOne(i,255);
  delay(d1);
  }
 
 for (int i = 14; i<=16; i++){
    ShiftPWM.SetOne(i,LOW);
  delay(d1);
  }

    ShiftPWM.SetOne(17,LOW);
   ShiftPWM.SetOne(3,LOW);
    delay(d1);

  for (int i = 18; i<=20; i++){
    ShiftPWM.SetOne(i,LOW);
  delay(d1);
  }

  ///////////////////////////////////end 1 set///////////////////////
  
   for (int i = 0; i<=2; i++){
    ShiftPWM.SetOne(i,255);
  delay(d1);
  }

   ShiftPWM.SetOne(10,255);
    delay(d1);
       
for (int i = 4; i<=6; i++){
    ShiftPWM.SetOne(i,255);
  delay(d1);
  }
  
  for (int i = 0; i<=2; i++){
    ShiftPWM.SetOne(i,LOW);
  delay(d1);
  }

   ShiftPWM.SetOne(10,LOW);
    delay(d1);
       
for (int i = 4; i<=6; i++){
    ShiftPWM.SetOne(i,LOW);
  delay(d1);
  }
  ShiftPWM.SetAll(0);
}





void loop() {
 digitalWrite(2,HIGH);
int c = 0;
 while(c <= 3){
   P1();
   c++;
}
c=0;

 while(c <= 3){
   P2();
   c++;
}
c=0;

 while(c <= 3){
   P3();
   c++;
}
c=0;
 while(c <= 3){
   P5();
   c++;
}
c=0;

 while(c <= 3){
   P4();
   c++;
}
c=0;

 while(c <= 3){
   P6();
   c++;
}
c=0;

 while(c <= 3){
   P8();
   c++;
}
c=0;

 while(c <= 3){
   P9();
   c++;
}
c=0;
 while(c <= 3){
   P10();
   c++;
}
c=0;

 while(c <= 3){
   P11();
   c++;
}
c=0;

digitalWrite(3,HIGH);
  P1();
   P2();
   P3();
   P5();
   P4();
   P6();
   P7();
   P8();
   P9();
   P10();
   P11();
digitalWrite(3,LOW);
   
 

}
