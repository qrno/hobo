#ifndef __MOTOR_H
#define __MOTOR_H

#define MOTOR_DELAY 2000
#define REG_TIMES 30
#define TURN_TIMES 80

#define FRONT 1542
#define LEFT 3254
#define RIGHT 5217
#define BACK 5454

int portsL[] = {22, 24, 26, 28};
int portsR[] = {29, 27, 25, 23};

void setupMotors() {
  for (int i = 0; i < 4; i++) {
    pinMode(portsL[i], OUTPUT);
    pinMode(portsR[i], OUTPUT);
  }
}

void drive(int dir=FRONT, int times=REG_TIMES, int d=MOTOR_DELAY) {
  if ((dir == RIGHT) || (dir == LEFT)) times == TURN_TIMES;
  while (times--) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int onL = ( ((dir==FRONT) || (dir==RIGHT)) ? i : 3-i);
        int onR = ( ((dir==FRONT) || (dir==LEFT)) ? i : 3-i);
        digitalWrite(portsL[j], (j == onL ? HIGH : LOW));
        digitalWrite(portsR[j], (j == onR ? HIGH : LOW));
      }
      delayMicroseconds(d);
    }
  }
 // if ((dir == RIGHT) || (dir == LEFT)) drive(BACK, MOTOR_DELAY, 15);
}

#endif
