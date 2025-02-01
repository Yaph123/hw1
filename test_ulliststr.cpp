//#include <string>
//#include <vector>
//#include <iostream>
//#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr dat;
  std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};
    
    cout << content.size() << endl;

	for (int i = 0; i < content.size(); i++){
    dat.push_back(content[i]);

  }

  //dat.pop_back();

  cout << dat.get(9) << endl;





  cout << "==== I work" << endl;


  return 0;




}
