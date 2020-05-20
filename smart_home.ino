int centimetre;
int time;
int trigPin= 2;
int echoPin= 3;
int ledDistance= 5;
int ledLight= 7;
int ledTemp= 6;

int lm35Pin = A0;
int temp ;

int light = A1;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledDistance, OUTPUT);   
  pinMode(ledLight, OUTPUT);   
  pinMode(ledTemp, OUTPUT);
  pinMode(light, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  time = pulseIn(echoPin, HIGH);  
  centimetre = (time/58.2);
  
  if(centimetre < 10){
   digitalWrite(ledDistance,HIGH);
    
   temp = ((analogRead(lm35Pin) * 4.88)-500)/10;
   light = analogRead(A1);
    
    if ((temp > 20)&&(light < 250)){
      digitalWrite(ledTemp,LOW);
      digitalWrite(ledLight,HIGH);
    } 
    else if((temp < 20) && (light < 250)){
      digitalWrite(ledTemp,HIGH);
      digitalWrite(ledLight,HIGH);
    }
    else if((temp > 20) && (light > 250)){
      digitalWrite(ledTemp,LOW);
      digitalWrite(ledLight,LOW);
    }
    else if((temp < 20) && (light > 250)){
      digitalWrite(ledTemp,HIGH);
      digitalWrite(ledLight,LOW);
    }
 
   Serial.print(centimetre);
  Serial.println("cm");
  
  Serial.print("temperature=");
  Serial.println(temp);
 
  Serial.print("light=");
  Serial.println(light);
   delay(500);
  
  }
  else{
   temp = ((analogRead(lm35Pin) * 4.88)-500)/10;
   light = analogRead(A1);
    digitalWrite(ledDistance,LOW);
  Serial.print(centimetre);
  Serial.println("cm");
  
  Serial.print("temperature=");
  Serial.println(temp);
 
  Serial.print("light=");
  Serial.println(light);
   delay(500);
  }
}
