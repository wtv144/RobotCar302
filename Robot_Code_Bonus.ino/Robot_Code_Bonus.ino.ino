
//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0  LEFT
const int pResistor2 = A1;// Led pin at Arduino pin 9 RIGHT
const int pResistor3 = A5;


const int dSensor1 = A2; // Distance sensors

const int ldSensor = A3;
const int rdSensor = A4;

const int leftforward = 2;      //Motor control pins
const int rightforward = 3;


const int obsDistance = 700;    //constants used to evaluate
const int obsDistanceb =450 ;
const int rblackVal = 300;
            //800~~~ in dark environment (CLobby), 200-300 in bright environment (makerstudio 2nd flor)
const int lblackVal = 300 ;
const int light = 13;

const int redMin = 295;
const int redMax = 550;


//Variables
int pvalue1;          //Left resistor
int pvalue2; //middle resistor
int pvalue3; //red resistor
int dvalue1;
int dvalue2; 
int dvalue3;

void setup(){
 pinMode(13, OUTPUT); // Set lepPin - 9 pin as an output
 pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
 pinMode(pResistor2, INPUT);
 pinMode(pResistor3, INPUT);
 pinMode(dSensor1, INPUT);
 pinMode(ldSensor, INPUT);
 pinMode(rdSensor, INPUT);
 pinMode(leftforward, OUTPUT);
 pinMode(rightforward, OUTPUT);
 Serial.begin(9600);
 Serial.println("Hello World");

 
}

void loop(){
 
 
 pvalue1 = analogRead(pResistor1);
  pvalue2 = analogRead(pResistor2);
  pvalue3 = analogRead(pResistor3);
  
  dvalue1 = analogRead(dSensor1);

  dvalue2 = analogRead(ldSensor);
  dvalue3 = analogRead(rdSensor);

//You can change value "25"
String myString = String(pvalue3);
String fsensor = String(dvalue1);
String rsensor = String(pvalue2);
String lsensor = String(pvalue1);
String ld = String(dvalue2);
String rd = String(dvalue3);

      
  Serial.println("Red sensor: " +myString);
  Serial.println("Front: " + fsensor);
  Serial.println("Right Photoresistor: "+ rsensor);
  Serial.println("Left Photoresistor: " +lsensor);
  Serial.println("LDS: " + ld);
  Serial.println("RDS: " +rd);

if( dvalue1 < obsDistance && !isRed(pvalue3) ) {
  
  Serial.write("NIF \n");
  /*Serial.println(myString);
  Serial.println(fsensor);
  Serial.println(rsensor);
  Serial.println(lsensor);
  */
  

  if( pvalue2 > rblackVal ){
    Serial.write("RT \n");
    right();
    
  }
  else if (pvalue1 > rblackVal  ){
    left();
    Serial.write("LT \n");
  }
  else if (dvalue2> obsDistanceb){
    right();
    Serial.write("RTDS");
   
  }
  else if (dvalue3 >obsDistanceb){
    left();
    Serial.write("LTDS");
  }
  
  else{
    goStraight();
    Serial.write("S \n");
  }
  
  
}

else{
  stopMotor();
  Serial.write("SIF \n");
  if(isRed(pvalue3)){
    Serial.write("STOP");
  }
}

delay(250);
}

void goStraight(){
  
    for(int i = 0; i <300; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(325);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(675);
    }

}
void left() {
 for(int i = 0; i <300; i++){
 digitalWrite(leftforward, LOW);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(400);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(600);
 }
}
void right() {
  for(int i = 0; i <200; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, LOW);
  delayMicroseconds(300);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(700);
  }
}
void stopMotor(){
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  
  
}

bool isRed(int p3val){
  return (p3val > redMin && p3val < redMax) ;
  
}
