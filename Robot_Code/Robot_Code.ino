/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */
   

//Constants
const int pResistor1 = A0; // Photoresistor at Arduino analog pin A0
const int pResistor2 = A1;// Led pin at Arduino pin 9
const int pResistor3 = A2;



const int dSensor1 = A3; // Distance sensors
const int dSensor2 = A4;
const int dSensor3 = A5;

const int leftforward = 2;      //Motor control pins
const int leftback = 3;
const int rightforward = 4;
const int rightback =5;

const int obsDistance = 200;    //constants used to evaluate
const int blackVal = 750;       //800~~~
const int light = 13;



//Variables
int pvalue1;          //Left resistor
int pvalue2; //middle resistor
int pvalue3;
int dvalue1;
int dvalue2;
int dvalue3;

void setup(){
 pinMode(13, OUTPUT); // Set lepPin - 9 pin as an output
 pinMode(pResistor1, INPUT);// Set pResistor - A0 pin as an input (optional)
 pinMode(pResistor2, INPUT);
 pinMode(pResistor3, INPUT);
 pinMode(dSensor1, INPUT);
 pinMode(dSensor2, INPUT);
 pinMode(dSensor3, INPUT);
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
  dvalue2 = analogRead(dSensor2);
  dvalue3 = analogRead(dSensor3);
  //You can change value "25"
  

if(dvalue1 < obsDistance ) 
{
  Serial.write("NIF\n");
  delay(1000);
 if(pvalue2 > blackVal)
 { 
    Serial.write("M \n");
  if(pvalue1 > blackVal && pvalue3 <blackVal)
  {
    Serial.write("L \n");
  }
  else if (pvalue3 >blackVal && pvalue1 <blackVal)
    {
      Serial.write("R \n");
    }
        else
        {
          
        Serial.write("S \n");
        }
  
 }

  else{
  if(pvalue1 > blackVal)
      {
       Serial.write("L2\n");
      }
  if(pvalue3 > blackVal)
    {
    Serial.write("R2\n");
    }
 
        }
}

else {
  digitalWrite(light, LOW);
  stopMotor();
}


}
void goStraight(){
  
    for(int i = 0; i <500; i++){
  digitalWrite(leftforward, HIGH);
  digitalWrite (rightforward, HIGH);
  delayMicroseconds(250);
  digitalWrite(leftforward,LOW);
  digitalWrite(rightforward, LOW);
  delayMicroseconds(750);
    }

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
