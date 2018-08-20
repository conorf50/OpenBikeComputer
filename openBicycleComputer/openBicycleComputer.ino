/*********************************************************************

Bike computer

Based on original code by Dave Darko: https://github.com/davedarko/OpenBikeComputer
*********************************************************************/



unsigned long wheel = 2240; 
unsigned long constant;
unsigned long time;
unsigned long start;
char output[11];
int pushButton = 7;
boolean is_pushed, is_released;
int is_pushed_old;

void setup(void) {
  Serial.begin(9600);
    pinMode(pushButton, INPUT_PULLUP);

  constant = get_constant();
  is_released = LOW;
}

  double abc = 0;
void loop() {
  
  
  int is_pushed = digitalRead(pushButton);
  int a_read = analogRead(pushButton);
  
  if (is_pushed_old != is_pushed) {
 //   Serial.println(a_read);
  }
  is_pushed_old = is_pushed;
  
  if (is_pushed == LOW) {
    is_released = HIGH;
  }
  else {
    if (is_released == HIGH) {
      is_released = LOW;

      time = micros() - start;
      abc = get_mps(time);
//     String output_string;
//      dtostrf(abc,1,1,output);
//      output_string.toCharArray( output, 11);
      start = micros();
      Serial.println(abc);
//      Keyboard.print(abc);

;

      delay(10);
      
    }
  }
}


double get_mps (unsigned long mic_sec) {
  return (double) constant / (double) mic_sec;
}

unsigned long get_constant () {
    
  return wheel * 3600 ;
}

