
    /*     Arduino Rotary Encoder Tutorial
     *      
     *  by Dejan Nedelkovski, www.HowToMechatronics.com
     *  Modified by Elias L. G. badrobobot@gmail.com
     */
     
#include <LiquidCrystal.h>
     
     #define outputA 12
     #define outputB 11
     #define reset   10 // Push Button
     #define DD4     5
     #define DD5     4
     #define DD6     3
     #define DD7     2
     #define RRS     9
     #define ENB     8       
     
     LiquidCrystal lcd(RRS, ENB, DD4, DD5, DD6, DD7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 
     
     int counterStep = 0;
     int counterTurn = 0;
     int aState;
     int aLastState;
     
     const int num_turn = 40;
     const int max_turn = 2;
       
     void setup() { 
       pinMode (outputA,INPUT);
       pinMode (outputB,INPUT);
       pinMode (reset,INPUT_PULLUP);

       // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display 
       lcd.begin(16,2); 
       // Initializes the serial comunication
       //Serial.begin (115200);
       
       // Reads the initial state of the outputA
       aLastState = digitalRead(outputA);

       // Print initial strings to the lcd
       lcd.print("Turn:"); // Prints "Turn:" on the LCD
       lcd.setCursor(7,0); // Sets the location at which subsequent text will be written lcd.setCursor(col, row) 
       lcd.print("Step:"); // Prints "Step:" on the LCD
       lcd.setCursor(14,0);
       lcd.print("%"); 
     }
      
     void loop() { 
       if_reset();
       if_encoder();
     }

     void if_reset(){
      if(digitalRead(reset)==LOW){
        //Update encoder's clock
        aLastState = digitalRead(outputA);
        //Reset counters
        counterStep = 0; 
        counterTurn = 0;
        //Reset LCD
        lcd.setCursor(5,0);
        lcd.print("  ");
        lcd.setCursor(12,0); 
        lcd.print("  ");
        lcd.setCursor(0,1); 
        lcd.print("   ");
      } 
     }

     void if_encoder(){
      aState = digitalRead(outputA); // Reads the "current" state of the outputA
       // If the previous and the current state of the outputA are different, that means a Pulse has occured
       if (aState != aLastState){     
         // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
         
         if (digitalRead(outputB) != aState) { // Check direction of rotation and add to counterStep
           counterStep ++; // Counter clockwise
         } else {
           counterStep --; // Clockwise
         }

         if(counterStep==num_turn){ // Add a turn to counterTurn
          if(counterTurn<max_turn){
            counterTurn ++;
            counterStep = 0;
          }else {
            counterTurn=0;
            counterStep=0;
          }
            printTurn_LCD(); // Update turn value in LCD
                    
         } else if (counterStep==-num_turn){
          if(counterTurn < -max_turn+1){
            counterTurn=0 ;
            counterStep=0;
          }else{
            counterTurn --;
            counterStep=0;
          }
          printTurn_LCD();  // Update turn value in LCD
         }
 
         aLastState = aState; // Updates the previous state of the outputA with the current state
         printStep_LCD(); // Update steps value in LCD
       } 
     }
     
  void printSerial(){
    Serial.print(" Turn: ");
    Serial.print(counterTurn);
    Serial.print("Step: ");
    Serial.println(counterStep);
  }

  void printTurn_LCD(){
    int temp = counterTurn;
    if (temp<0) temp = temp*-1;
    lcd.setCursor(5,0); 
    lcd.print(temp);
    if (counterTurn>0){
      lcd.setCursor(0,1); 
      lcd.print("CWS");     
    } else if(counterTurn<0){
      lcd.setCursor(0,1); 
      lcd.print("CCW");     
    } else {
      lcd.setCursor(0,1); 
      lcd.print("   ");     
    }
  }

  void printStep_LCD(){
    int temp = counterStep*2.5;
    if (temp<0) temp = temp*-1;
    if (temp<10){// Clean the second digid
      lcd.setCursor(13,0);
      lcd.print(" ");  
    }    
    lcd.setCursor(12,0);
    lcd.print(temp);  
  }
