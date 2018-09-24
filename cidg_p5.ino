// pins for the encoder inputs
#define LH_ENCODER_A 2
#define LH_ENCODER_B 4

// resolution of encoder in degrees 
const int DeltaTh = 30; 

// variables to store the number of encoder pulses
// for each motor
volatile unsigned long leftCount = 0;
unsigned long StartTime = millis();
unsigned long LH_CurrentTime = 0; 
unsigned long LH_LastTime = 0;
unsigned long  LH_DeltaTime = 0;
unsigned long  LH_Omega = 0;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(LH_ENCODER_A, INPUT);
  pinMode(LH_ENCODER_B, INPUT);
  pinMode(RH_ENCODER_A, INPUT);
  pinMode(RH_ENCODER_B, INPUT);
  
  // initialize hardware interrupts
  attachInterrupt(0, leftEncoderEvent, CHANGE);
  attachInterrupt(1, rightEncoderEvent, CHANGE);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(LH_Omega);
  delay(1);
}
 
// encoder event for the interrupt call
void leftEncoderEvent() {
  LH_CurrentTime = millis();
  LH_DeltaTime  = LH_CurrentTime - LH_LastTime;
  LH_Omega = DeltaTh/LH_DeltaTime;
  LH_LastTime = LH_CurrentTime; 
}
 
// encoder event for the interrupt call
void rightEncoderEvent() {

}
