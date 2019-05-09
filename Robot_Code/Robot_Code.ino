
//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0  LEFT
const int pResistor2 = A1;// Led pin at Arduino pin 9 RIGHT




const int dSensor1 = A2; // Distance sensors


const int leftforward = 2;      //Motor control pins
const int rightforward = 3;


const int obsDistance = 350;    //constants used to evaluate
const int rblackVal = 450;
            //800~~~ in dark environment (CLobby), 200-300 in bright environment (makerstudio 2nd flor)
const int lblackVal = 450 ;
const int light = 13;



//Variables
int pvalue1;          //Left resistor
int pvalue2; //middle resistor

int dvalue1;


void setup(){
 pinMode(13, OUTPUT); // Set lepPin - 9 pin as an output
 pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
 pinMode(pResistor2, INPUT);
 pinMode(dSensor1, INPUT);
 pinMode(leftforward, OUTPUT);
 pinMode(rightforward, OUTPUT);
 Serial.begin(9600);
 Serial.println("Hello World");

 
}

void loop(){
 

 
 pvalue1 = analogRead(pResistor1);
  pvalue2 = analogRead(pResistor2);
  
  dvalue1 = analogRead(dSensor1);



//You can change value "25"

  
    
if( dvalue1< obsDistance) {
  Serial.write("NIF \n");

  if( pvalue2 > rblackVal && pvalue1 < lblackVal){
    Serial.write("RT \n");
    right();
    
  }
  else if (pvalue2 < rblackVal && pvalue1 > lblackVal){
    left();
    Serial.write("LT \n");
  }
  else{
    goStraight();
    Serial.write("S \n");
  }
  
  
}

else{
  stopMotor();
  Serial.write("SIF \n");
}
 
}
void goStraight(){
  
    for(int i = 0; i <300; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
    }

}
void left() {
 for(int i = 0; i <100; i++){
 digitalWrite(leftforward, LOW);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
 }
}
void right() {
  for(int i = 0; i <100; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, LOW);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
  }
}
void stopMotor(){
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  
  
}
