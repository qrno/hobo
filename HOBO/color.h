#ifndef __COLOR_H
#define __COLOR_H

struct Color {
  int r, g, b;
  Color (int r=0, int g=0, int b=0) :
    r(r), g(g), b(b) {};

  Color operator +(Color a) {
    return Color(r+a.r, g+a.g, b+a.b);
  }
};

struct Sensor {
  int s[4];
  int out;
  
  Sensor(int _s[4], int _out) {
    out = _out; 
    pinMode(out, INPUT);
    
    for (int i = 0; i < 4; i++) {
      s[i] = _s[i];
      pinMode(s[i], OUTPUT);
    }

    digitalWrite(s[0], HIGH);
    digitalWrite(s[1], LOW);
  }

  void setSensors(int a, int b) {
    digitalWrite(s[2], a);
    digitalWrite(s[3], b);
  }

  Color getColor(bool wantRed=true, bool wantGreen=true, bool wantBlue=true) {
    int R, G, B;
    R = G = B = -1;
    
    if (wantRed) {
      setSensors(LOW, LOW);
      R = pulseIn(out, LOW);
      delay(10);
    }
    if (wantGreen) {
      setSensors(HIGH, HIGH);
      G = pulseIn(out, LOW);
      delay(10);
    }
    if (wantBlue) {
      setSensors(LOW, HIGH);
      B = pulseIn(out, LOW);
      delay(10);
    }

    return Color(R, G, B);
  }
};

int ls[] = {4, 5, 6, 7};
int rs[] = {1, 2, 3, 9};

Sensor leftSensor(ls, 8);
Sensor rightSensor(rs, 0);

#endif
