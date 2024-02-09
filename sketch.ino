#include <Servo.h>


Servo servo1;


const int pinTRIGGER = 8;
const int pinECHO = 9;
float durasi, jarak;



void setup()
{
Serial.begin(9600);
servo1.attach(10);
servo1.write(0);

pinMode(pinTRIGGER, OUTPUT);
pinMode(pinECHO, INPUT);

delay(1000);
}


void loop()
{
digitalWrite(pinTRIGGER, HIGH);
delayMicroseconds(10);
digitalWrite(pinTRIGGER, LOW);

durasi = pulseIn(pinECHO, HIGH);
jarak = ((durasi * 0.034) / 2);

Serial.print("Jarak: ");
Serial.println(jarak);

if (jarak <= 6)
{
servo1.write(90);
delay(1000);
servo1.write(0);
}

else
{
servo1.write(0);
}

delay(100);
}