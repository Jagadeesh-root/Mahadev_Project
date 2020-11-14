  byte Hours = 0;
  byte Mins = 0;
  byte Seconds = 5;

void setup() {
Serial.begin(9600);
}

void loop() {
StartTimer();

}

void PrintTime(){
CheckHourFormat();
Serial.print(Hours);
Serial.print(':');
CheckMinFormat();
Serial.print(Mins);
Serial.print(':');
CheckSecFormat();
Serial.println(Seconds);
delay(992);
ClearScreen();
}

void ClearScreen(){  
Serial.write(0x0C);
}

void CheckHourFormat(){

  if(Hours<=9)
  Serial.print('0');
}

void CheckMinFormat(){

  if(Mins<=9)
  Serial.print('0');
}


void CheckSecFormat(){

  if(Seconds<=9)
  Serial.print('0');
}


void StartTimer(){
  if(Hours == 0 && Mins == 0 && Seconds == 0){
    Serial.println("Time Reached");
    delay(1000);
  
  }else{
    while(Seconds > 0){
        Seconds--;
        PrintTime();
    }
    if(Seconds == 0 && Mins >0){
      Mins--;
      Seconds = 60;
    }
   if(Seconds == 0 && Mins == 0 && Hours>0){
     Hours--;
     Mins=60; 
   } 
  } 
}
