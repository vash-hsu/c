#ifndef TIGER_BLUE_H_INCLUDED
#define TIGER_BLUE_H_INCLUDED

using namespace std;

class TigerBlue: public ::testing::Test
{
  protected:
    string  usecase;
  TigerBlue()
  {
    usecase = string("N/A");
  }
  ~TigerBlue()
  {
  }
  void itshowtime()
  {
    cout<< "[ Use Case ] " << usecase << endl;
  }
  string whyfail()
  {
    return string("Why Fail: ") + usecase + "\n";
  }
  string tell_me_why(const char* csz)
  {
    return string("Why Fail: ") + csz + "\n";
  }

};

#endif // TIGER_BLUE_H_INCLUDED
