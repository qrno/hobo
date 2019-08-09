#ifndef __INFRA_RED_H
#define __INFRA_RED_H

#define DEFAULT_WM 45

struct IR {
  int port, whiteMAX;

  IR(int p, int w=DEFAULT_WM): port(p), whiteMAX(w) {
    pinMode(port, INPUT);
  }

  inline int readVal() {
    return analogRead(port);
  }

  inline bool isBlack() {
    return analogRead(port) > whiteMAX;
  }
};

#endif
