class SignalPassFilter {
  private:
    int count=0;
    String repeatWord="begin";
    String firstWord="begin";
    String secondWord="begin";
  
  public: 
  
    String filter(String word, int frequency) {
      if (repeatWord=="begin") {
        repeatWord=word;
      }
      if (firstWord=="begin") {
        firstWord=word;
        return repeatWord;
      }
      else {
        secondWord = word;
      }
        
      if (firstWord==secondWord) {
        count++;
        if (count==frequency) {
          count=0;
          repeatWord=secondWord;
        }
        return repeatWord;
      }
      else {
        count=0;
        firstWord=secondWord;
        return repeatWord;
      }
    }
};
