#include<SoftwareSerial.h>
SoftwareSerial Shivam(10, 11);
#include<string.h>


//char ATtest[255];
char text[255];
int Index=0;
//char ok[3] = "OK";
//int seven = -75;
void setup() {
  pinMode(13 ,OUTPUT);
  pinMode(8 , OUTPUT);
  digitalWrite(8 , LOW);
  pinMode( 9, OUTPUT);
pinMode(6 , OUTPUT);
digitalWrite(6 , LOW);
pinMode(7 , OUTPUT);
  
  Serial.begin(9600);
  Shivam.begin(9600);
  
  //delay(500);
  Serial.write("Welcome\n");
  //delay(500);
  Shivam.write("AT\r");
  //delay(1000);
  Shivam.write("AT+DDET=1\r");
  //delay(1000);

 //Shivam.write("ATD9923380771;\r");
 Shivam.write("ATS0=1\r");
 // while(Shivam.available(){
   // ATtest[] = Shivam.read
    //}
}

void loop() {
  Serial.write("Welcome\n");
  Shivam.write("AT\r");
  Shivam.write("AT+DDET=1\r");
  Shivam.write("ATS0=1\r");
  for(int j=0 ; j<1000 ;j++){
  while (Shivam.available())
  {
    text[Index] = Shivam.read();
    Serial.print( text[Index ]);
    Index++;
  }
  //delay(1000); 
  for(int i =0;i<2;i++)
  {
  //Serial.println(strcmp(ok[0] ,text[6] ));
  //Serial.print(text[Index]);
    //delay(1000);
    if( text[9] == '1' ){
      digitalWrite(13 , HIGH);
      digitalWrite(7 , LOW);
      digitalWrite(9 , LOW);
      Serial.print(" HIGH \t");
      Shivam.write("ATH\r");
   //   delay(1000);
      }
      
   Serial.print("text[6] -(" );      //text[0 ] = "A" , text[1] = "T" , text[2] = noting , text[3] = nothing , text[4] = "\n" , text[5] = "O" , text[9] = '1'
    Serial.print( text[9]);
    Serial.print(")\n"); 
    
   if(text[9] == '2'){
   digitalWrite(13 , LOW);
   digitalWrite(7 , LOW);
   digitalWrite(9 , HIGH);
    Serial.print("LOW\n");
    Shivam.write("ATH\r");
    }
    //delay(1000);
    //exit();
  }

  if(text[9] == '3'){
    digitalWrite(7 , HIGH);
    digitalWrite(9 , LOW);
    digitalWrite(13 , LOW);
    Shivam.write("ATH\r");
    }
    
    if(text[9] == '4'){
    digitalWrite(7 , LOW);
    digitalWrite(9 , LOW);
    digitalWrite(13 , LOW);
    Shivam.write("ATH\r");
    
    Shivam.write("AT+CMGF=1\r");
    delay(1000);
    Shivam.write("AT+CSCS=\"GSM\"\r");
    delay(1000);
    Serial.write("\n");
    Shivam.write("AT+CMGS=\"9923380771\"\r");
    delay(1000);
    Shivam.write("All lights are turned off,\nHave a Nice Day\n:D\r");
    delay(1000);
    Shivam.write((char)26);
    Serial.write("Message sent ");

    }
    
  
  
  Index = 0;}
}
