#include <algorithm>
#include "registers.hpp"
#include <iostream>
#include <string>
#include "fmap.hpp"
#include "op.hpp"
#include "stdio.h"
#include "util.hpp"
#include <boost/xpressive/xpressive.hpp>
#include <map>

using namespace std;
using namespace boost::xpressive;

int main(int argc, char** argv) {
  initFuncMap();

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
      transform(command.begin(), command.end(), command.begin(),
                [](unsigned char c) -> unsigned char { return toupper(c); });
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
      }*/
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
