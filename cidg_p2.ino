/*

*/

void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  Serial.begin(9600);
  analogWrite(3,80);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0 Deg
  if(digitalRead(8)==LOW){
    mover(254);
  }
  // 45 Deg
  if(digitalRead(9)==LOW){
    mover(240);
  }
  // 90 Deg
  if(digitalRead(10)==LOW){
    mover(183);
  } 
  // 135 Deg
  if(digitalRead(11)==LOW){
    mover(125);
  }
  // 180 Deg
  if(digitalRead(12)==LOW){
    mover(80);
  }
  
}

void turn(){
  for(int i=0; i<=255; i++){
    analogWrite(3,i);
    delay(100);
    Serial.println(i);
  }
}

void mover(int a){
  if(a==240){
    analogWrite(3,125);
    delay(10);
    analogWrite(3,240);  
  }else if(a==183){
    analogW rite(3,125);
    delay(10);
    analogWrite(3,183);
  }
  else{
    analogWrite(3,a);  
  }
  Serial.println(a);
}
