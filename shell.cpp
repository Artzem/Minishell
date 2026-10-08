using namespace std;
#include <iostream>
#include <sstream>
class shell {

   // create parser object

   void run() {
      string line;
      while (true) {
         cout << "Enter a command and arg \n";
         if (!getline(cin,line) || line == "exit") {
            break; // if error we exit
         }  // else we continue
      }
   }

};
