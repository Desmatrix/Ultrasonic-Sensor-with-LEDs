int Trig = 2;  //pin 2 Arduino połączony z pinem Trigger czujnika
int Echo = 3;  //pin 3 Arduino połączony z pinem Echo czujnika
int CM;        //odległość w cm
long CZAS;     //długość powrotnego impulsu w uS
int incomingByte = 0; 

void setup()
{
  Serial.begin(9600);                        //inicjalizaja monitora szeregowego
  pinMode(Trig, OUTPUT);                     //ustawienie pinu 2 w Arduino jako wyjście
  pinMode(Echo, INPUT);                      //ustawienie pinu 3 w Arduino jako wejście
  pinMode(4, OUTPUT);                        //przypisanie pinu do LED

  Serial.println("Test czujnika odleglosci");
}

void pomiar_odleglosci ()
{
  digitalWrite(Trig, LOW);        //ustawienie stanu wysokiego na 2 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);       //ustawienie stanu wysokiego na 10 uS - impuls inicjalizujacy - patrz dokumentacja
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  digitalWrite(Echo, HIGH); 
  CZAS = pulseIn(Echo, HIGH);
  CM = CZAS / 58;   
  }             //szerokość odbitego impulsu w uS podzielone przez 58 to odleglosc w cm - patrz dokumentacja


void loop()
{
  pomiar_odleglosci();              //pomiar odległości

  if (CM<100) 
  {  
  digitalWrite(4, HIGH); // turn the LED on (HIGH is the voltage level)

  Serial.println(CM);

  }   //wyświetlanie wyników na ekranie w pętli co 800 ms
  else
  {
  digitalWrite(4, LOW); // turn the LED off by making the voltage LOW  
  }
  delay(800);
}
  
