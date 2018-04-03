
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial mySerial(3, 2); // RX, TX


Servo myservo;  // create servo object to control a servo
Servo myservo1;                // twelve servo objects can be created on most boards
#define led 4
#define enable 12
#define right_side_direction_1 8
#define left_side_direction_1 10
#define right_side_direction_2 9
#define left_side_direction_2 11

int pos = 0;  // right servo
int pos1 = 0; // left servo
void setup() {
  // Open serial communications and wait for port to open:
    Serial.begin(57600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.println("Goodnight moon!");
    pinMode(led,OUTPUT);
    pinMode(enable, OUTPUT);
    pinMode(right_side_direction_2, OUTPUT);
    pinMode(right_side_direction_1, OUTPUT);
    pinMode(left_side_direction_1, OUTPUT);
    pinMode(left_side_direction_2, OUTPUT);
    myservo.attach(5);     //right servo
    myservo1.attach(6);  //left servo
    
  // set the data rate for the SoftwareSerial port
    mySerial.begin(9600);
    mySerial.println("Hello, world?");
  
}

void loop() { // run over and over
  
  if (mySerial.available()) {
        char value = mySerial.read();
        Serial.println(value);
        digitalWrite(led,HIGH);
    
    if (value == '1'){            //control right myservo 5
    
        for (pos ; pos <= 180; pos += 1) { 
        myservo.write(pos);          
       delay(15);  
       value = mySerial.read();
       if (value == '0'){
           myservo.write(pos); 
           break; }
        else if ( value =='2'){
           for (pos ; pos >= 0; pos -= 1) {
           myservo.write(pos);            
           delay(15);                     }
                             }
    }     } 
    else if ( value =='2'){
           for (pos ; pos >= 0; pos -= 1) {
           myservo.write(pos);            
           delay(15);   
           value = mySerial.read();
       if (value == '0'){
           myservo.write(pos); 
           break;
              }                       
       else if (value == '1'){
           for (pos ; pos <= 180; pos += 1) { 
           myservo.write(pos);          
           delay(15);  } }
              }
               }
                  

     if (value == '3'){     //control left myservo1 6
    
        for (pos1 ; pos1 <= 180; pos1 += 1) { 
        myservo1.write(pos1);          
       delay(15);  
       value = mySerial.read();
       if (value == '0'){
           myservo1.write(pos1); 
           break; }
        else if ( value =='4'){
           for (pos1 ; pos1 >= 0; pos1 -= 1) {
           myservo1.write(pos1);            
           delay(15);                     }
                             }
    }     } 
  else if ( value =='4'){
           for (pos1 ; pos1 >= 0; pos1 -= 1) {
           myservo1.write(pos1);            
           delay(15);   
           value = mySerial.read();
       if (value == '0'){
           myservo1.write(pos1); 
           break;
              }                       
       else if (value == '3'){
           for (pos1 ; pos1 <= 180; pos1 += 1) { 
           myservo1.write(pos1);          
           delay(15);  }
           }
              }
               }
     else if (value == '0'){
           myservo.write(pos);
           myservo1.write(pos1); 
           
              }  
                           
             if (value == 'F')  {    //control motor forword
                  digitalWrite(enable, HIGH);
                  digitalWrite(right_side_direction_1, LOW);
                  digitalWrite(right_side_direction_2, HIGH);
                  digitalWrite(left_side_direction_1, HIGH);
                  digitalWrite(left_side_direction_2, LOW);
                                  }
             else if (value == 'B')  {    //control motor backword
                  digitalWrite(enable, HIGH);
                  digitalWrite(right_side_direction_1, HIGH);
                  digitalWrite(right_side_direction_2,LOW);
                  digitalWrite(left_side_direction_1, LOW);
                  digitalWrite(left_side_direction_2, HIGH);
                                  }
             else if (value == 'R')  {    //control motor GO RIGHT
                  digitalWrite(enable, HIGH);
                  digitalWrite(right_side_direction_1, HIGH);
                  digitalWrite(right_side_direction_2, LOW);
                  digitalWrite(left_side_direction_1, HIGH);
                  digitalWrite(left_side_direction_2, LOW);
                                  }
               else if (value == 'L')  {    //control motor GO LEFT
                  digitalWrite(enable, HIGH);
                  digitalWrite(right_side_direction_1, LOW);
                  digitalWrite(right_side_direction_2, HIGH);
                  digitalWrite(left_side_direction_1, LOW);
                  digitalWrite(left_side_direction_2, HIGH);
                                  }
               else if (value == '5')  {    //control motor TO STOP   
                  digitalWrite(enable, LOW);
                  digitalWrite(right_side_direction_1, LOW);
                  digitalWrite(right_side_direction_2, LOW);
                  digitalWrite(left_side_direction_1, LOW);
                  digitalWrite(left_side_direction_2, LOW);
                                  }
                
   } 
}
    
  

