#ifndef __US_H
#define __US_H

#define usECHO 342
#define usTRIG 432

#include <Ultrasonic.h>

Ultrasonic us(usECHO, usTRIG);

int getDistance(Ultrasonic u, int rep=7, int d=3) {
  int s = 0;
  for (int i = 0; i < rep; i++)
    s += us.read(), delay(d);
  return int(s/rep);
}

#endif
