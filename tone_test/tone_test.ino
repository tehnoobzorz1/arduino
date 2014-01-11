#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

void setup()
{
  tone(11, NOTE_C4, 8000);
  delay(8000);
  for (int cur_note = 0; cur_note < 8; cur_note++)
  {
    int duration = 1000/noteDurations[cur_note];
    tone(11, melody[cur_note], duration);
    
    int pause = duration * 1.3;
    delay(pause);
    noTone(8);
  }
}

void loop()
{
  //only run once
}
