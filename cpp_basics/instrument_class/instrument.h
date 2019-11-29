using namespace std;

class Instrument{
public:
  Instrument(string sound);
  ~Instrument();
  string play();
private:
  string sound;
};
