//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0
const int pResistor2 = A1;// Led pin at Arduino pin 9
const int pResistor3 = A2;



const int dSensor1 = A3; // Distance sensors
const int dSensor2 = A4;
const int dSensor3 = A5;


//LED outputs
const int leftforward = 2;      //Motor control pins
const int leftback = 3;
const int rightforward = 4;
const int rightback =5;


//Variables
int pvalue1;          //Left resistor
int pvalue2; //middle resistor
int pvalue3;
int dvalue1;
int dvalue2;
int dvalue3;
const int LED3 = 4;
const int blackVal = 460;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT); // Set lepPin - 9 pin as an output
 pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
 pinMode(pResistor2, INPUT);
 pinMode(pResistor3, INPUT);
 pinMode(dSensor1, INPUT);
 pinMode(dSensor2, INPUT);
 pinMode(dSensor3, INPUT);
 pinMode(leftforward, OUTPUT);  //D 2
 pinMode(rightforward, OUTPUT); //D4

}

void loop() {
   pvalue1 = analogRead(pResistor1);
  pvalue2 = analogRead(pResistor2);
  pvalue3 = analogRead(pResistor3);
  
while(pvalue2 >blackVal){
  goStraight();
}


}
 // delay(500); //Small delay

 void goStraight(){
  
    
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
  

}
void left() {
 digitalWrite(leftforward, LOW);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
}
void right() {
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, LOW);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
}
void stopMotor(){
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  
  
}
