int Trig = 2;  //pin 2 Arduino connected with Trigger pin in the sensor
int Echo = 3;  //pin 3 Arduino connected with Echo pin in the sensor
float CM;      //Distance in cm
float CZAS;    //lengh of returning impulse in uS
int incomingByte = 0; 

void setup()
{
  Serial.begin(9600);                        //iniciation of time port
  pinMode(Trig, OUTPUT);                     //set pin 2 as output
  pinMode(Echo, INPUT);                      //set pin 3 as input
  pinMode(4, OUTPUT);                        //set pin 4 (connected led) as output

  
}

void measure_distance ()          //code that will measure distance and save it as CM
{
  digitalWrite(Trig, LOW);        //set low status
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);       //set high status
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH); 
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;   //lengh of returining signal divided by 58 gives the distance in cm
  }             


void loop()
{
  measure_distance();            

  if (CM<100) 
  {  
  digitalWrite(4, HIGH); // turn the LED on (HIGH is the voltage level)

  Serial.println(CM);

  }   
  else
  {
  digitalWrite(4, LOW); // turn the LED off by making the voltage LOW  
  }
  delay(800); //repeat the loop after given amount of mS
}
  
  

