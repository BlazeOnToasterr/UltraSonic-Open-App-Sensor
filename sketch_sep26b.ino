int redled = 5;
int trig = 11;
int echo = 10;
int TX = 0;
int RX = 1;
long travel_time;
int delay_time1 = 25;
int delay_time2 = 10;
void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(TX, INPUT);
  pinMode(RX, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(delay_time2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(delay_time2);
  digitalWrite(trig, LOW);
  travel_time = pulseIn(echo, HIGH);
  delay(delay_time1);
  travel_time = (travel_time) / (144.66);
  if (travel_time <= 44) {

    digitalWrite(redled, HIGH);
    delay(250);
  }
  if (travel_time > 44) {
    digitalWrite(redled, LOW);
    delay(250);
  }
  Serial.println(travel_time);
  delay(1000);
}
