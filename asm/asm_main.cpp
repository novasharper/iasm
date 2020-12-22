#include "registers.h"
#include <iostream>
#include <string>
//#include "memory.h"
#include "fmap.h"
#include "op.h"
#include "stdio.h"
#include "util.h"
#include <boost/xpressive/xpressive.hpp>
#include <map>

using namespace std;
using namespace boost::xpressive;

int main(int argv[]) {
  initFuncMap();

  bool FALSE = false;
  bool TRUE = true;

  cout << "Welcome to iASM \n"
       << "Console Mode\n";

  string cmd("");

  sregex rex = sregex::compile(
      "([A-Za-z]+)(?:\\s+R([A-F0-9]{2}))(?:,\\s+([A-F0-9]+)){0,1}");
  smatch what;
  do {
    cmd.clear();
    cout << "> ";
    getline(cin, cmd);
    if (regex_match(cmd, what, rex)) {
      string command = what[1].str();
      transform(command.begin(), command.end(), command.begin(), toupper);
      cout << "Size " << what.size() << '\n';
      cout << "Whole " << what[0] << '\n'; // whole match
      cout << "1 " << what[1] << '\n';     // first capture
      cout << "2 " << what[2] << '\n';     // second capture
      cout << "2 " << parseInt(what[2].str(), true) << '\n';
      byte a = (byte)parseInt(what[2].str(), true);
      bool full, immediate, carry;
      full = immediate = carry = false;
      int p = 0;
      /*if(command[command.length() + p - 1] == 'C') {
              p--;
              carry = true;
      }/**/
      if (command[command.length() + p - 1] == 'I') {
        p--;
        immediate = true;
      }
      if (command[command.length() + p - 1] == 'S') {
        p--;
        full = true;
      }
      command.resize(command.length() + p);
      ushort b = 0;
      if (what.size() > 3 && what[3].str() != "") {
        cout << "3 " << what[3] << '\n'; // fourth capture
        cout << "3 " << parseInt(what[3].str(), !(full && immediate)) << '\n';
        b = parseInt(what[3].str(), !(full && immediate));
      }
      cout << (int)a << " " << (int)b << '\n';
      cout << command << '\n';

      funcs[command](&a, &b, &full, &immediate, &carry);
      reg *r = getReg(a);
      ushort ans;
      r->get(&ans);
      cout << (int)(ans) << '\n'; /**/
    }
  } while (cmd != "Ex");

  return 0;
}