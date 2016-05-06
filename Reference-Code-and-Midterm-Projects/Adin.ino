int flexSensorPinTh = A0; //analog pin 0
int flexSensorPinPoint = A1; //analog pin 1
int flexSensorPinMid = A2; //analog pin 2
int green = 8;
int red = 7;
int yellow = 4;
int blue = 2;

void setup(){
  Serial.begin(9600);
  pinMode(blue, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);

}

void loop(){
  int flexSensorReadingPt = analogRead(flexSensorPinPoint); 
  int flexSensorReadingTh = analogRead(flexSensorPinTh);
  int flexSensorReadingMid = analogRead(flexSensorPinMid);
  Serial.println(flexSensorReadingPt);
  Serial.println(flexSensorReadingTh);
  Serial.println(flexSensorReadingMid);
  
  if(flexSensorReadingTh <= 55 && flexSensorReadingPt >= 133 && flexSensorReadingMid >= 150){
  digitalWrite(yellow, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  digitalWrite(blue, HIGH);   // turn the blue LED on (HIGH is the voltage level)       
  }   

 
else if(flexSensorReadingPt <= 133 && flexSensorReadingTh <= 55 && flexSensorReadingMid >= 150){
  digitalWrite(blue, HIGH); 
  digitalWrite(yellow, HIGH); 
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);   // turn the blue and yello LED on (HIGH is the voltage level)        
  }   
else if(flexSensorReadingPt >= 135 && flexSensorReadingTh <= 55 && flexSensorReadingMid <= 150){
  digitalWrite(blue, HIGH); 
  digitalWrite(yellow, LOW); 
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);   // turn the blue and yello LED on (HIGH is the voltage level)
          
  }   

else if(flexSensorReadingPt<= 135 && flexSensorReadingTh <= 55 && flexSensorReadingMid <= 150){
  digitalWrite(blue, HIGH); 
  digitalWrite(yellow, HIGH); 
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
}

   else{
  digitalWrite(blue, LOW); 
  digitalWrite(yellow, LOW); 
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);  
 }

  delay(500); //just here to slow down the output for easier reading
}

