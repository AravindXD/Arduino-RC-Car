const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int ENA=9;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int ENB=10;

const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;

const int redbuzz=7;
const int green=6;

int ObstacleCheck(){
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if(distance<10){
    digitalWrite(redbuzz,HIGH);
    delay(500);
    digitalWrite(redbuzz,LOW);
    return 1;} //obstacle present
  else return 0;}

void Forward(){
  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,HIGH);
  digitalWrite(motor2Pin2,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,255);}

void Left(){
  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,HIGH);
  digitalWrite(motor2Pin2,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,0);}

void Right(){
  digitalWrite(motor1Pin1,HIGH);
  digitalWrite(motor1Pin2,LOW);
  digitalWrite(motor2Pin1,HIGH);
  digitalWrite(motor2Pin2,LOW);
  analogWrite(ENA,0);
  analogWrite(ENB,255);}

void Backward(){
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,HIGH);
  analogWrite(ENA,255);
  analogWrite(ENB,255);}

void FL() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(ENA, 127);
  analogWrite(ENB, 255);}

void FR() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 127);}

void BL() {
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 255);}

void BR() {
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 150);}

void Stop(){
  digitalWrite(motor1Pin1,LOW);
  digitalWrite(motor1Pin2,HIGH);
  digitalWrite(motor2Pin1,LOW);
  digitalWrite(motor2Pin2,HIGH);
  analogWrite(ENA,0);
  analogWrite(ENB,0);;}

void setup(){
  // put your setup code here, to run once:
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(ENA, OUTPUT); 
  pinMode(ENB, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(redbuzz,OUTPUT);
  pinMode(green,OUTPUT);

  Serial.begin(9600);  //bluetooth
}

void loop() {
  // put your main code here, to run repeatedly:
  int v = ObstacleCheck();

  if (v == 0) {
    while (Serial.available() > 0) {
      char State = Serial.read();
      Serial.println(State);

      switch (State) {
        case 'F':
          Forward();
          break;
        case 'B':
          Backward();
          break;
        case 'L':
          Left();
          break;
        case 'R':
          Right();
          break;
        case 'I':
          FL();
          break;
        case 'G':
          FR();
          break;
        case 'J':
          BL();
          break;
        case 'H':
          BR();
          break;
        default:
          Stop();
      }
    }
  } else {
    Stop();
  }

  delay(500);
}
