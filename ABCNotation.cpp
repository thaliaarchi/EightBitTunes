#include "ABCNotation.h"

Parser::Parser() {
  
}

Note::Note(int freq, int dur) {
  frequency = freq;
  duration = dur;
}

int Note::getFrequency() const { return frequency; }
int Note::getDuration() const { return duration; }
