const int switchPin = 14;
const int ledPin = 15;

int switchState = 0;

void setup(){
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

//digital mengirim dan menerima sinyal
void loop(){
  switchState = digitalRead(switchPin);

  if(switchState == HIGH){ //ditekan
    digitalWrite(ledPin, HIGH);
    delay(1000);
    digitalWrite(ledPin, LOW);
    delay(1000);   
  }else{
    digitalWrite(ledPin, LOW);
}

}

//pin digital untuk mengirim 