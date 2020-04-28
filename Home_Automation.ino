#define relay1 2    
#define relay2 3    
#define relay3 4    
#define relay4 5    
String voice;

void setup()
{
  Serial.begin(9600);            //Baud Rate
  pinMode(relay1, OUTPUT);       //LEDs
  pinMode(relay2, OUTPUT);       //FAN
  pinMode(relay3, OUTPUT);       //Charger
  pinMode(relay4, OUTPUT);       //Buzzer
  digitalWrite(relay1, HIGH);     //Switch relay1 off
  digitalWrite(relay2, HIGH);     //Swtich relay2 off
  digitalWrite(relay3, HIGH);     //Switch relay3 off
  digitalWrite(relay4, HIGH);     //Swtich relay4 off
}

void loop() 
{
  while (Serial.available()){ 
     delay(10);  
    char c = Serial.read(); 
    if (c == '#') {break;} //Exit the loop when the # is detected after the word
    voice += c; 
  }
  if (voice.length() > 0)
  {
    if(voice == "*turn on LEDs"){  
      digitalWrite(relay1, LOW);  
      }
    else if(voice == "*turn on FAN"){ 
      digitalWrite(relay2, LOW);    
      }
    else if(voice == "*turn on Charger") {     
      digitalWrite(relay3, LOW);   
    }
    else if(voice == "*turn on BUZZER") {      
      digitalWrite(relay4, LOW);   
    }
    

    else if(voice == "*turn off light") {       
      digitalWrite(relay1, HIGH);   
    }
    else if(voice == "*turn off LED") {      
      digitalWrite(relay2, HIGH);   
    }
    else if(voice == "*turn off buzzer") {      
      digitalWrite(relay3, HIGH);   
    }
    else if(voice == "*turn off fan") {      
      digitalWrite(relay4, HIGH);   
    }
    else if(voice == "*turn all devices off") {      
      switchalloff();               
    }
    
  voice=""; 
  }
}
void switchalloff()               
{
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, HIGH);
  digitalWrite(relay4, HIGH);
}
