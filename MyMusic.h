class MyMusic {
  
  private:
    //int melody[] = {262, 196,196, 220, 196,0, 247, 262}; //Low
    //int melody[] = {524, 392, 392, 440, 392, 0, 494, 524}; //Medium
    int melody[8] = {1048, 784, 784, 880, 784, 0, 988, 1048}; //High
    // note durations: 4 = quarter note, 8 = eighth note, etc.:
    int noteDurations[8] = {4, 8, 8, 4,4,4,4,4 };
  
  public:
    void errorSound(int buzzer) {
      for (int i=0; i<3; i++) {
        tone(buzzer, i*1000, 500);
        delay(500);
      }
    }
    void melodySound(int buzzer) {
      for (int thisNote = 0; thisNote < 8; thisNote++) {
        int noteDuration = 1000/noteDurations[thisNote];
        tone(buzzer, melody[thisNote],noteDuration);
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        noTone(buzzer);
      }
    }
};
