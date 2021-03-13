#include<SoftwareSerial.h>
SoftwareSerial Shivam(10, 11); //(TXD , RXD)
#include<string.h>

char text[255];                           //String for storing response from the user.
int Index=0;                              //Counter.
void setup() {
  
  pinMode(13 ,OUTPUT);                    //LED(green+) for indicating that the motor is ON.
  pinMode(12, OUTPUT );                   //LED (green-).
  digitalWrite(12, LOW);                  //Setting pin 12 as low(ground).
  pinMode(8 , OUTPUT);                    //IN1 for 
  digitalWrite(8 , HIGH);
  pinMode( 9, OUTPUT);                    //IN4
  digitalWrite(9 , HIGH);
  pinMode(3 , OUTPUT);                    //LED red +
  digitalWrite(3, HIGH);
  pinMode(2 , OUTPUT);                    //LED red ground
  digitalWrite(2 , LOW);
  
  Serial.begin(9600);
  Shivam.begin(9600);
  
  Serial.write("Welcome\n");
  Shivam.write("AT\r");
  Shivam.write("AT+DDET=1\r");
  Shivam.write("ATS0=1\r");
 
  delay(15000);
  Shivam.write("ATD8788201789;\r");
}

void loop() {
  
  Serial.write("Welcome\n");
  Shivam.write("AT\r");
  Shivam.write("AT+DDET=1\r");
  Shivam.write("ATS0=1\r");
  for(int j=0 ; j<1000 ;j++){
     while (Shivam.available()){
           text[Index] = Shivam.read();
           Serial.print( text[Index ]);
           Index++;
           }
    for(int i =0;i<2;i++){
       if( text[9] == '*' ){
         digitalWrite(13 , HIGH);
         digitalWrite(3, LOW);
         digitalWrite(9 , LOW);
         delay(500);
         digitalWrite(9 , HIGH);
         Serial.print(" HIGH \t");
         Shivam.write("ATH\r");
      
         Shivam.write("AT+CMGF=1\r");
         delay(1000);
         Shivam.write("AT+CSCS=\"GSM\"\r");
         delay(1000);
         Serial.write("\n");
         Shivam.write("AT+CMGS=\"8788201789\"\r");
         delay(1000);
         Shivam.write("The starter is turned ON,\nHave a Nice Day\n:) ");
         Shivam.write("\r");
         delay(1000);
         Shivam.write((char)26);
         Serial.write("Message sent ");
       }
      
       Serial.print("text[6] -(" ); 
       Serial.print( text[9]);
       Serial.print(")\n"); 
    
       if(text[9] == '#'){
         digitalWrite(13 , LOW);
         digitalWrite(3, HIGH);
         digitalWrite(8 , LOW);
         delay(500);
         digitalWrite(8 , HIGH);
         Serial.print("LOW\n");
         Shivam.write("ATH\r");
      
         Shivam.write("AT+CMGF=1\r");
         delay(1000);
         Shivam.write("AT+CSCS=\"GSM\"\r");
         delay(1000);
         Serial.write("\n");
         Shivam.write("AT+CMGS=\"8788201789\"\r");
         delay(1000);
         Shivam.write("The starter is turned OFF,\nHave a Nice Day\n:) \r");
         delay(1000);
         Shivam.write((char)26);
         Serial.write("Message sent ");
         delay(2000);
        }
      }
      Index = 0;
    }
 }
