#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
    
    if(results.value == 0xURSHERE
    ){
      //forward
      move(1,0,1,0);
    }
    else if (results.value == 0xURSHERE){
      //right
      move(0,1,1,0);
    }
    else if (results.value == 0xURSHERE){
      //back
      move(0,1,0,1);
    }
    else if (results.value == 0xURSHERE){
     //left
      move(1,0,0,1);
    }
    else{
      //stop
      move(0,0,0,0);
    }
  }
  delay(100);
  
}

void move(int m1a, int m1b, int m2a, int m2b){
  digitalWrite(6,m1a);
  digitalWrite(5,m1b);
  digitalWrite(10,m2a);
  digitalWrite(9,m2b);
}