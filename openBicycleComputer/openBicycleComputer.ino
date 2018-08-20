/*********************************************************************

Bike computer

Based on original code by Dave Darko: https://github.com/davedarko/OpenBikeComputer
*********************************************************************/



unsigned long wheelCircumference = 2240; 
unsigned long constant;
unsigned long time;
unsigned long start;
char output[11];
int pushButton = 7;

double currentSpeed = 0;

boolean is_pushed, is_released;
int is_pushed_old;

void setup(void) {
  Serial.begin(9600);
    pinMode(pushButton, INPUT_PULLUP);

  constant = get_constant();
  is_released = LOW;
}

void loop() {
  
  
  int is_pushed = digitalRead(pushButton);
  int a_read = analogRead(pushButton);
  
  if (is_pushed_old != is_pushed) {
  }
  is_pushed_old = is_pushed;
  
  if (is_pushed == LOW) {
    is_released = HIGH;
  }
  else {
    if (is_released == HIGH) {
      is_released = LOW;

      time = micros() - start;
      currentSpeed = get_mps(time);


      start = micros();
      Serial.println(currentSpeed);

;

      delay(10);
      
    }
  }
}


double get_mps (unsigned long mic_sec) {
  return (double) constant / (double) mic_sec;
}

unsigned long get_constant () {
    
  return wheelCircumference * 3600 ;
}

