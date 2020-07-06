const int PIN_TRIGGER = 5;
const int PIN_ECHO = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(PIN_TRIGGER,OUTPUT);
  pinMode(PIN_ECHO,INPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIGGER,LOW);

  double selang=pulseIn(PIN_ECHO,HIGH);
  double jarak=0.0343*(selang/2);

  if (jarak>400||jarak<=0)
  {
    Serial.println("Diluar jangkauan sensor");
   }
   else
   {
    Serial.print(jarak);
    Serial.println("cm");
   }
   delay(1000);

}
