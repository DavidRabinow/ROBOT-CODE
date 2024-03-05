#include <IRremote.h>  //including IRremote library file

int ir = 11; //connecting data pin of reciever to pin 12 of arduino
IRrecv recieve(ir);
decode_results code;

void setup() {
  Serial.begin(9600);
  recieve.enableIRIn();
}

void loop() {
  if(recieve.decode(&code)){
    Serial.println("HEX CODE RECORDED IS :");
    Serial.println(code.value,HEX); //printing value of decoded result in HEX format
    delay(75);
    recieve.resume();  //ready to recieve next code
  }
}

