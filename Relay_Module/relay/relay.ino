
//5V 4 Channel Relay Module

void setup() {
  pinMode(7, OUTPUT);
}
void loop() {
  digitalWrite(7, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second

}
//General Operational Info.

//For IN4
  //LEFT and MIDDLE is NC
  //RIGHT and MIDDLE is NO
  //To activate the relay between RIGHT and MIDDLE we have to pass
  //LOW command to the IN4 input

//For IN3
  //LEFT and MIDDLE is NC
  //RIGHT and MIDDLE is NO
  //To activate the relay between RIGHT and MIDDLE we have to pass
  //LOW command to the IN3 input
  
//For IN2
  //LEFT and MIDDLE is NC
  //RIGHT and MIDDLE is NO
  //To activate the relay between RIGHT and MIDDLE we have to pass
  //LOW command to the IN2 input
  
//FOR IN1
    //BUT...its' exactly opposite in case of IN1
    //RIGHT and MIDDLE is NC
    //LEFT and MIDDLE is NO
    //to activate the relay between LEFT and MIDDLE we have to pass
    //LOW command to the IN1 input.

 //Which clearly means that this module is fault piece.
 //But whatever it is We can work with it.
    
