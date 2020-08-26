#include <Ultrasonic.h> //https://github.com/filipeflop/Ultrasonic

#define echoPin 3 //Pino 3 recebe o pulso do echo
#define trigPin 2 //Pino 2 envia o pulso para gerar o echo

void setup()
{
  Serial.begin(9600);

  pinMode(echoPin, INPUT);  // define o pino 3 como entrada (recebe)
  pinMode(trigPin, OUTPUT); // define o pino 2 como saida (envia)

  Serial.println("Reading Distance");
}

void loop()
{
  measure();
  delay(1000);
}

int measure()
{
  float initialHeigh = 100.0;
  float amount, distance = 0;
  long microsec = ultrasonic.timing();

  distance = ultrasonic.convert(microsec, Ultrasonic::CM);
  amount = (distance / initialHeigh);

  return amount;
}
