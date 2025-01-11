#include <Ultrasonic.h>
Ultrasonic u= Ultrasonic(4,8);

#include <Servo.h>
Servo s=Servo();


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  //M1
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);

  //M2
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);

  pinMode(6,OUTPUT);
  analogWrite(6,150);

  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);

  s.attach(7);
}

void loop() {
  // put your main code here, to run repeatedly:
  int x = Serial.read();

  if(x=='4'){                  //FORWARD
    s.write(65);

    int d = u.distanceRead();
    if(d>40){
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);
      digitalWrite(13,HIGH);
      digitalWrite(2,LOW);

      delay(500);

      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(13,LOW);
      digitalWrite(2,LOW);
    }else if(d<40){
      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
  }

  if(x=='1'){              //BACKWARD
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(2,HIGH);

    delay(500);

    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }

  if(x=='5'){              //BRAKE
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
  }

  if(x=='3'){             //RIGHT
    s.write(10);
    delay(300);
    int d = u.distanceRead();
    if(d>20){
      digitalWrite(12,HIGH);
      digitalWrite(11,LOW);
      digitalWrite(10,LOW);
      digitalWrite(9,HIGH);

      delay(500);

      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    s.write(65);
  }

  if(x=='2'){                  //LEFT
    s.write(140);
    delay(300);
    int d = u.distanceRead();
    if(d>20){
      digitalWrite(12,LOW);
      digitalWrite(11,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(9,LOW);

      delay(500);

      digitalWrite(11,LOW);
      digitalWrite(12,LOW);
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
    }
    s.write(65);
  }

}
