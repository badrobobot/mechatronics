// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4;

// define variables
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete
int degree = 0;

 
int gradopaso = 0;
int pasoact = 0;
boolean sentido;
int x = 0; 
int tiempo=150;
String leeCadena;
int retardo=5;
boolean isfirst=true;


void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (stringComplete) {
    degree = inputString.toInt();
    isfirst = false;
    gradopaso = degree; // Copy the degree
    //blink(degree); // A function just to measure
    // clear the string:
    inputString = "";
    stringComplete = false;
  }

  if(!isfirst){
    
    if((pasoact-gradopaso)>0){
      sentido=true;
      x=pasoact-gradopaso;
    }
    else {
      sentido=false;
      x=gradopaso-pasoact;
    }

    digitalWrite(dirPin,sentido); //Changes the rotations direction

    while(x>0){
      digitalWrite(stepPin,HIGH);
      delay(tiempo);
      digitalWrite(stepPin,LOW);
      delay(tiempo);
      x--;
    }
    
    delay(1000);
    pasoact=gradopaso;
    x=0;
    isfirst=true;
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
