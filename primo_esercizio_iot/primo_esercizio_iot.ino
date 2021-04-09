int delayAmount;
bool increase;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delayAmount=2000;
  increase = true;
}

void loop() {

  if ( increase ) {
    delayAmount = delayAmount * 2;
  }
  else {
    delayAmount = delayAmount / 2; 
  }

  if ( delayAmount < 100 ) {
    increase = true;
  }

  else if ( delayAmount > 5000 ) {
    increase = false;
  }
  
  Serial.print("hello world, current delay interval: ");
  Serial.print(delayAmount);
  Serial.println("");
  delay(delayAmount);
  // put your main code here, to run repeatedly:
}
