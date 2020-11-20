#include <iostream>

class LeftWingPolitic {
public:
  virtual void leftWingSpeaker() {
    std::cout << "Left wing speaker" << std::endl;
  }
};

class RightWingPolitic {
public:
  void rightWingSpeaker() { std::cout << "Right wing speaker" << std::endl; }
};

class LeftWingSpeech {
public:
  void doSpeech(LeftWingPolitic *lwp) {
    std::cout << "Doing left wing speech by... ";
    lwp->leftWingSpeaker();
  }
};

class LeftWingPoliticAdapter : public LeftWingPolitic {
private:
  RightWingPolitic *rwp;

public:
  LeftWingPoliticAdapter(RightWingPolitic *_rwp) : rwp{_rwp} {}
  void leftWingSpeaker() override { rwp->rightWingSpeaker(); }
};

int main() {
  RightWingPolitic rwp;
  LeftWingPolitic lwp;

  LeftWingSpeech lws;
  lws.doSpeech(&lwp);

  LeftWingPoliticAdapter lwpa(&rwp);
  lws.doSpeech(&lwpa);
}
