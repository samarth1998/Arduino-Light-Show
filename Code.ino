int DO = 2; //Pin for Digital Output - DO
int DA = A0; // Pin for Analog Input - AO
int threshold = 15; //Set minimum threshold for LED lit
int sensorvalue = 0;
int button = LOW;
int lightState = 0;
int buttonInput = 13;
int previousMillis = 0;
int interval = 600;
bool ledState = LOW;
int i=0;
 
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(buttonInput, INPUT);
  //digitalWrite(9,LOW);
  //delay(2000);
}
 
void loop() {
  int buttonState = digitalRead(buttonInput);
  if(button==HIGH){
  sensorvalue = analogRead(DA);  //Read the analog value
  Serial.print("Analog: ");
  Serial.println(sensorvalue);  //Print the analog value
  if (sensorvalue >= threshold) {
    digitalWrite(3, HIGH);
    delay(10);
    if (sensorvalue >= threshold*2) {
      digitalWrite(4, HIGH);
      delay(10);
      if (sensorvalue >= threshold*3) {
        digitalWrite(5, HIGH);
        delay(10);
        if (sensorvalue >= threshold*4) {
          digitalWrite(6, HIGH);
          delay(10);
          if (sensorvalue >= threshold*5) {
            digitalWrite(7, HIGH);
            delay(10);
            if (sensorvalue >= threshold*6) {
              digitalWrite(8, HIGH);
              delay(10);
              if (sensorvalue >= threshold*7) {
                digitalWrite(9, HIGH);  
                delay(10);
               }
             }
          }
        }
      }
    }
    
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
  }
  }
  else{
   int sensorValue = analogRead(A0);
   if(lightState == 0){
        digitalWrite(9, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
   }
    else if(lightState == 1){
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis > interval){  
        previousMillis = currentMillis;
        if (ledState == LOW){
        digitalWrite(9, HIGH);
        digitalWrite(8, HIGH);
        digitalWrite(7, HIGH);
        digitalWrite(6, HIGH);
        digitalWrite(5, HIGH);
        digitalWrite(4, HIGH);
        digitalWrite(3, HIGH);
        ledState = HIGH;
        }
        else {
        digitalWrite(9, LOW);
        digitalWrite(8, LOW);
        digitalWrite(7, LOW);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        digitalWrite(4, LOW);
        digitalWrite(3, LOW);
        ledState = LOW;
        }
      }
    }


    if (lightState == 2){
      
        digitalWrite(9, HIGH);
        delay(50);
        digitalWrite(9, LOW);
        digitalWrite(8, HIGH);
        delay(50);
        digitalWrite(8, LOW);
        digitalWrite(7, HIGH);
        delay(50);
        digitalWrite(7, LOW);
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(6, LOW);
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(5, LOW);
        digitalWrite(4, HIGH);
        delay(50);
        digitalWrite(4, LOW);
        digitalWrite(3, HIGH);
        delay(50);
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        delay(50);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
        delay(50);
        digitalWrite(5, LOW);
        digitalWrite(6, HIGH);
        delay(50);
        digitalWrite(6, LOW);
        digitalWrite(7, HIGH);
        delay(50);
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);
        delay(50);
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
        delay(50);   
i++;
       if(i%6==0){
        lightState=0;}
   }
    
    if (sensorValue >= 40 && lightState == 0){
        lightState = 1;
        delay(100);
      }
    else if (sensorValue >= 40 && lightState == 1){
        lightState = 2;
        delay(100);
      }
     
  }
  
  if(buttonState == LOW && button == HIGH){
      button = LOW;
      delay(500);
    } 
    else if (buttonState == LOW && button == LOW){
      button = HIGH;
      delay(500);
    }
}

