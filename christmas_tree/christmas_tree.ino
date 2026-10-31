// Simple Arduino Christmas Tree by bzqp, 2021: https://www.youtube.com/c/bzqp1
volatile int flag=0; // flag to keep track of the current animation
int old_flag=0; // old flag value to break the animation correctly
unsigned long interrupt_time=0; // for switch debouncing
unsigned long last_interrupt_time=0;// for switch debouncing
int r=20; // initial red value
int g=4; // initial green value
int b=0; // initial blue value
int speed=6; // speed of the swipe animation

void setup() {
  pinMode(2, INPUT); //interrupt pin
  pinMode(A4, OUTPUT); //5V power for the switch
  digitalWrite(A4, HIGH); //power the awitch
  attachInterrupt(digitalPinToInterrupt(2),flagchange,RISING); //interrupt attached to the button
  pinMode(3, OUTPUT); //green
  pinMode(5, OUTPUT); //blue
  pinMode(6, OUTPUT); //red
  pinMode(9, OUTPUT); //green
  pinMode(10, OUTPUT); //blue
  pinMode(11, OUTPUT); //red
}

void loop() {
  // Night mode animation: static, dims the RGB lights to match the green LEDs
  if(flag==0){
  delay(100);
  r=20;
  g=4;
  b=0;

  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  }
  // Swipe animation - swipes through different colors. Lots of while loops and some break functions to detect the interrupts
  if(flag==1){
  old_flag=int(flag);
  r=80;
  g=16;
  b=0;


  while(r>0){
    if(flag!=old_flag){
      break;
    }
    r--;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);

  }
    while(g<255){
          if(flag!=old_flag){
      break;
    }
    g++;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(b<255){
          if(flag!=old_flag){
      break;
    }
    b++;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(g>0){
          if(flag!=old_flag){
      break;
    }
    g--;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(r<255){
          if(flag!=old_flag){
      break;
    }
    r++;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(b>0){
          if(flag!=old_flag){
      break;
    }
    b--;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
  delay(speed*50);
    while(g<255){
          if(flag!=old_flag){
      break;
    }
    g++;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
      while(r>0){
            if(flag!=old_flag){
      break;
    }
    r--;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(g>16){
    g--;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
    while(r<80){
          if(flag!=old_flag){
      break;
    }
    r++;
  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  delay(speed);
  }
  r=80;
  g=16;
  b=0;

  analogWrite(6, r);
  analogWrite(3, g);
  analogWrite(5, b);

  analogWrite(11, r);
  analogWrite(9, g);
  analogWrite(10, b);
  for(int i=0;i<speed*2;i++){
        if(flag!=old_flag){
      break;
    }
  delay(500);
  }

  }
  // Fire flicker animation. My personal favourite
  if (flag==2){

  analogWrite(6, random(50,255));
  delay(random(0,40));
  analogWrite(3, random(0,8));
  delay(random(0,40));
  analogWrite(5, random(0,3));
  delay(random(0,40));

  analogWrite(11, random(50,255));
  delay(random(0,40));
  analogWrite(9, random(0,8));
  delay(random(0,40));
  analogWrite(10, random(0,3));
  delay(random(0,40));

  }
}
// interrupt to detect the switch press
void flagchange(){
  last_interrupt_time=interrupt_time;
  interrupt_time=millis();
  // interrupt debouncer - stabilizes the button input
    if(interrupt_time-last_interrupt_time>200){
  flag++; // flag stores the current animation state
  if(flag>2){
    flag=0;
  }
  }
}
