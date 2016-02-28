// FORKING Project by Alvaro Garcia 2016

const int but1 = 39;
const int but2 = 41;
const int but3 = 45;
const int but4 = 33;
const int but5 = 35;
const int but6 = 37;
const int but7 = 27;
const int but8 = 29;
const int but9 = 31;
const int but10 = 23;
const int butCall = 43;
const int butHang = 47;



int counter =11;
int limit = 10;
int ringing = 53;
int rotaryCounter = 0;
int rotaryCountLow = false;
int ring = 4;
int rang = 7;
int takeCall = 12;
int takeCallLow = false;
int callCountdown = 0;




void setup() {

  Serial.begin(9600);
  pinMode(takeCall, INPUT_PULLUP); //LOW when Taken
  pinMode(ringing, INPUT_PULLUP); //LOW when Ringing
  pinMode(counter, INPUT_PULLUP); //red
  pinMode(limit, INPUT_PULLUP); //white
  pinMode(but1, OUTPUT);
  pinMode(but2, OUTPUT);
  pinMode(but3, OUTPUT);
  pinMode(but4, OUTPUT);
  pinMode(but5, OUTPUT);
  pinMode(but6, OUTPUT);
  pinMode(but7, OUTPUT);
  pinMode(but8, OUTPUT);
  pinMode(but9, OUTPUT);
  pinMode(but10, OUTPUT);
  pinMode(butCall, OUTPUT);
  pinMode(butHang, OUTPUT);
  pinMode(ring,OUTPUT);
  pinMode(rang,OUTPUT);

}

void loop() {
  
 if (digitalRead(takeCall) == LOW ){

    takeCallLow = true;
    if(digitalRead(limit) == LOW){                              
            callCountdown = 0;

      if (digitalRead(counter) == LOW && rotaryCountLow == false){    
  
        delay(8);
        if (digitalRead(counter) == LOW){
  
          rotaryCounter++;
          rotaryCountLow = true;
          
        }
      }
      if (digitalRead(counter) == HIGH && rotaryCountLow == true){
        
        rotaryCountLow = false;
      }
    }
      if(digitalRead(limit)== HIGH && rotaryCounter>=1){
        
         
        
        if (rotaryCounter ==1){
          digitalWrite(but1,HIGH);
          delay(200);
          digitalWrite(but1,LOW);
        }
        if (rotaryCounter ==2){
          digitalWrite(but2,HIGH);
          delay(200);
          digitalWrite(but2,LOW);
        }
        if (rotaryCounter ==3){
          digitalWrite(but3,HIGH);
          delay(200);
          digitalWrite(but3,LOW);
        }
        if (rotaryCounter ==4){
          digitalWrite(but4,HIGH);
          delay(200);
          digitalWrite(but4,LOW);
        }
        if (rotaryCounter ==5){
          digitalWrite(but5,HIGH);
          delay(200);
          digitalWrite(but5,LOW);
        }
        if (rotaryCounter ==6){
          digitalWrite(but6,HIGH);
          delay(200);
          digitalWrite(but6,LOW);
        }
        if (rotaryCounter ==7){
          digitalWrite(but7,HIGH);
          delay(200);
          digitalWrite(but7,LOW);
        }
        if (rotaryCounter ==8){
          digitalWrite(but8,HIGH);
          delay(200);
          digitalWrite(but8,LOW);
        }
        if (rotaryCounter ==9){
          digitalWrite(but9,HIGH);
          delay(200);
          digitalWrite(but9,LOW);
        }
        if (rotaryCounter ==10){
          digitalWrite(but10,HIGH);
          delay(200);
          digitalWrite(but10,LOW);
        }
    
        
        rotaryCounter = 0;
    }
    if(digitalRead(limit)== HIGH){
    
     delay(20);
       if (callCountdown >= 300){
          digitalWrite(butCall,HIGH);
          delay(200);
          digitalWrite(butCall,LOW);
          callCountdown = 0;
       }
      }
    callCountdown++;
  
 }
 if (digitalRead(takeCall) == HIGH && takeCallLow == true){
  delay(10);
  if(digitalRead(takeCall) == HIGH){
      takeCallLow =false;
      digitalWrite(butHang,HIGH);
      delay(200);
      digitalWrite(butHang,LOW);
      callCountdown = 0;
      
  }
}
  

  //FINISHED DIALING
  
 if (digitalRead(ringing) == LOW){

    digitalWrite(ring,HIGH);
    digitalWrite(rang,LOW);
    delay(20);
    digitalWrite(ring,LOW);  
    delay(20);
  
    digitalWrite(ring,LOW);
    digitalWrite(rang,HIGH);
    delay(20);
    digitalWrite(rang,LOW);
    delay(20);

    if (digitalRead(takeCall) == LOW){
      digitalWrite(butCall,HIGH);
      delay(200);
      digitalWrite(butCall,LOW);
      }
      
  }
  

 
}
