String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int degree = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (stringComplete) {
    degree = inputString.toInt();
    blink(degree);
    // clear the string:
    inputString = "";
    stringComplete = false;
  } 
  
}

void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == 'x') {
      stringComplete = true;
    }else{
      // add it to the inputString:
      inputString += inChar;
    }
  }
}

void blink(int deg){
  for(int i=0;i<deg;i++){
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    delay(1000);
  }  
} 
