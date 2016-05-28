#ifndef ABCNOTATION_H
#define ABCNOTATION_H

#include "Arduino.h"

namespace ABCNotation {
  class Parser {
    public:
      ABCParser();
      void reset();
      void getNextNote(Stream* str, int* freq, int* dur);
    private:
      void skipCharacters(Stream* stream, char* input, char* skipChars);
      void skipCharactersUntil(Stream* stream, char* input, char* skipUntil);
      int getIntegerFromStream(Stream* stream, char* previewedChar);
      double delayTimeInMilliseconds(double noteLength, float bpm);
      int getFrequency(Stream* stream, char* input);
      int getDuration(Stream* stream, char* input);
  };

  class Note {
    public:
      int getFrequency() const { return frequency; }
      int getDuration() const { return duration; }
      void play() const;
    private:
      int frequency;
      int duration;
  };

  class Rest : public Note {

  };
};
using namespace ABCNotation;

/*// This allows sketches to use SDLib::File with other libraries (in the
// sketch you must use SDFile instead of File to disambiguate)
typedef ABCNotation::File    SDFile;
typedef ABCNotation::SDClass SDFileSystemClass;
#define SDFileSystem ABCNotation::SD*/

#endif
