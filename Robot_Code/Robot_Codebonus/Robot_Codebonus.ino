//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0  LEFT
const int pResistor2 = A1;// Led pin at Arduino pin 9 RIGHT




const int dSensor1 = A2; // Distance sensors
const int ldSensor = A3;
const int rdSensor =  A4;


const int leftforward = 2;      //Motor control pins
const int rightforward = 3;


const int obsDistance = 480;    //constants used to evaluate
const int obsDistanceb = 500;
const int rblackVal = 350;
            //800~~~ in dark environment (CLobby), 200-300 in bright environment (makerstudio 2nd flor)
const int lblackVal = 350 ;
const int light = 13;

const int redMin = 260;
const int redMax = 325;



//Variables
int pvalue1;          //Left resistor
int pvalue2; //middle resistor

int dvalue1;
int dvalue2;
int dvalue3;


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
  dvalue2 = analogRead(ldSensor);
  dvalue3 = analogRead(rdSensor);
 /*
Serial.print(pvalue1);
Serial.print("\n");
delay(1000);
Serial.print(pvalue2);
Serial.print("\n");
delay(1000);


//You can change value "25"

  */
    
if( dvalue1 < obsDistance && !isRed(pvalue1, pvalue2)) {
  Serial.write("NIF \n");

  if( pvalue2 > rblackVal && pvalue1 < lblackVal){
    Serial.write("RT \n");
    right();
    
  }
  else if (pvalue2 < rblackVal && pvalue1 > lblackVal){
    left();
    Serial.write("LT \n");
  }
  else if (dvalue2 > obsDistanceb){
    right();
    Serial.write("RT");
  }
  else if (dvalue3 > obsDistanceb){
    left();
    Serial.write("LT");
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
delay(200);
 
}
void goStraight(){
  
    for(int i = 0; i <300; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(390);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(610);
    }

}
void left() {
 for(int i = 0; i <300; i++){
 digitalWrite(leftforward, LOW);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(390);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(610);
 }
}
void right() {
  for(int i = 0; i <300; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, LOW);
  delayMicroseconds(390);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(610);
  }
}
void stopMotor(){
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  
  
}

bool isRed(int value1, int value2){
  return(value1>redMin && value1<redMax) || (value2>redMin && value2<redMax);
}
  
