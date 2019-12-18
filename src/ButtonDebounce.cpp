#include "Arduino.h"
#include "ButtonDebounce.h"

ButtonDebounce::ButtonDebounce(unsigned long delay){
  _delay = delay;
  _lastDebounceTime = 0;
  _lastChangeTime = 0;
  _lastStateBtn = HIGH;
}

bool ButtonDebounce::isTimeToUpdate(){
  return (millis() - _lastDebounceTime) > _delay / 8;
}

void ButtonDebounce::update(int muxValue){
  if(!isTimeToUpdate()) return;
  _lastDebounceTime = millis();
  int btnState;
  if (muxValue > 1000) {
   btnState = HIGH;
  } else {
   btnState = LOW;
  }

  if(btnState == _lastStateBtn) {
        _lastChangeTime = millis();
	return;
  };
  if (millis() - _lastChangeTime < _delay)
   	return;

  // now at leat least 8 sample points in _delay time changed.
  // so that counts.

  _lastStateBtn = btnState;


}

int ButtonDebounce::state(){
  return _lastStateBtn;
}

int ButtonDebounce::getDelay(){
  return _delay;
}

void ButtonDebounce::setDelay(int delay){
 _delay = delay;
}