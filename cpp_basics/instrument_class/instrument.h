using namespace std;

class Instrument{
public:
  // constructor
  Instrument(string sound);
  // destructor
  ~Instrument();
  // play function
  string play();
private:
  string sound;
};
