// A4 SDA  A5 SDC

#include <Wire.h> 

int ADXLAddress = 0X36; 
int ANG_DEG;
int ANG1;
int ANG2; 

#define ANG_DATO1 0X0E 
#define ANG_DATO2 0X0F
#define STATUS 0x0B

// 1.6 SCL y 1.7 SDC 
void setup()
{
  // put your setup code here, to run once:
  Wire.begin();   
  Serial.begin(9600);

}

void loop()
{
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(ADXLAddress);
  Wire.write(ANG_DATO1);
  Wire.write(ANG_DATO2);
  Wire.endTransmission(); 
  
  Wire.requestFrom(ADXLAddress,2);
  
  if(Wire.available()<=2){
     ANG1 = Wire.read(); 
     ANG2 = Wire.read();  
  }
  
  Serial.print("ANG1 = ");
  Serial.print(ANG1);
  Serial.print(" ");
  Serial.print("ANG2 = ");
  Serial.println(ANG2);
}
