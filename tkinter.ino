char userInput;

void setup(){

  Serial.begin(9600);                        //  setup serial
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}


void loop(){
  
if(Serial.available()> 0){ 
    
    userInput = Serial.read();               // read user input
      
      if(userInput == 'o'){                
        digitalWrite(2, HIGH); 
      }
      if(userInput == 'x'){
        digitalWrite(2, LOW);         
      }
      if(userInput == 'f'){                
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);  
      }
      if(userInput == 's'){
        digitalWrite(4, HIGH); 
        delay(100);
        digitalWrite(4, LOW);         
      }


  } // Serial.available
} // Void Loop
