/*
  ButtonDebounce.h - Library for Button Debounce.
  Created by Maykon L. Capellari, September 30, 2017.
  Released into the public domain.
*/
#ifndef ButtonDebounce_h
#define ButtonDebounce_h

#include "Arduino.h"

class ButtonDebounce{
  private:
    unsigned long _delay;
    unsigned long _lastDebounceTime;
    unsigned long _lastChangeTime;
    int _lastStateBtn;
    bool isTimeToUpdate();
  public:
    ButtonDebounce(unsigned long delay);
    void update(int muxValue);
    int state();
    int getDelay();
    void setDelay(int delay);
};

#endif
