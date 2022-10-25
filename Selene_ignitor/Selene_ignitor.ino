#include <IRremote.h>
int pin = 3;
int recv_pin = 11;

IRrecv irrecv(recv_pin);

decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}
int k=1;
void loop() {
  // put your main code here, to run repeatedly:
  if(k==1)digitalWrite(13, HIGH);
  if(irrecv.decode(&results)){
    Serial.println(results.value, HEX);
    if(results.value == 0xFF6897){ //0 누르면 시작
      digitalWrite(13, LOW);k=0;
      digitalWrite(12, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(9, HIGH);
      digitalWrite(pin, HIGH);
      delay(10);
    }    if(results.value == 0xFF4AB5){ // 8 누르면 정지
      digitalWrite(12, LOW);
      digitalWrite(10, LOW);
      digitalWrite(9, LOW);
      digitalWrite(pin, LOW);
      delay(30000);
      digitalWrite(13, HIGH);k=0;
    }
  }
  irrecv.resume();
}
