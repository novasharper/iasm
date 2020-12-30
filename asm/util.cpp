#include "util.hpp"
#include "fmap.hpp"
#include "op.hpp"
#include <string>
#include <vector>
using namespace std;

ushort parseInt(string number, bool isreg) {
  ushort num = 0;
  if (number == "")
    return (ushort)(-1);
  if (isreg) {
    if ((int)number[0] - 48 <= 9)
      num += 16 * ((int)number[0] - 48);
    else
      num += 16 * ((int)number[0] - 55);
    if ((int)number[1] - 48 <= 9)
      num += ((int)number[1] - 48);
    else
      num += ((int)number[1] - 55);
  } else {
    vector<char> v(number.begin(), number.end());
    int max = v.size() - 1;
    if (max > 4)
      max = 3;
    for (ushort i = 0; i < max; i++) {
      if ((int)v[i] - 48 <= 9)
        num += ((int)v[i] - 48);
      else
        num += ((int)v[i] - 55);
      num *= 16;
    }
    if ((int)v[max] - 48 <= 9)
      num += ((int)v[max] - 48);
    else
      num += ((int)v[max] - 55);
  }
  return num;
}
/*
void runC(string cmd, byte arg0, ushort arg1) {
        bool TRUE = true;
        bool FALSE = false;
        byte barg1 = (byte)arg1;
        if(cmd == "ADD") {
                add(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "ADDI") {
                add(&arg0, &barg1, &TRUE, &FALSE);
        } else if(cmd == "ADDS") {
                adds(&arg0, &arg1, &FALSE, &FALSE);
        } else if(cmd == "ADDSI") {
                adds(&arg0, &arg1, &TRUE, &FALSE);
        } else if(cmd == "SUB") {
                sub(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "SUBI") {
                sub(&arg0, &barg1, &TRUE, &FALSE);
        } else if(cmd == "SUBS") {
                subs(&arg0, &arg1, &FALSE, &FALSE);
        } else if(cmd == "SUBSI") {
                subs(&arg0, &arg1, &TRUE, &FALSE);
        } else if(cmd == "AND") {
                and(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "ANDI") {
                and(&arg0, &barg1, &TRUE, &FALSE);
        } else if(cmd == "ANDS") {
                ands(&arg0, &arg1, &FALSE, &FALSE);
        } else if(cmd == "ANDSI") {
                ands(&arg0, &arg1, &TRUE, &FALSE);
        } else if(cmd == "OR") {
                or(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "ORI") {
                or(&arg0, &barg1, &TRUE, &FALSE);
        } else if(cmd == "ORS") {
                or(&arg0, &arg1, &FALSE, &FALSE);
        } else if(cmd == "ORSI") {
                or(&arg0, &arg1, &TRUE, &FALSE);
        } else if(cmd == "EOR") {
                eor(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "EORI") {
                eor(&arg0, &barg1, &TRUE, &FALSE);
        } else if(cmd == "EORS") {
                eors(&arg0, &arg1, &FALSE, &FALSE);
        } else if(cmd == "EORSI") {
                eors(&arg0, &arg1, &TRUE, &FALSE);
        } else if(cmd == "COM") {
                com(&arg0, &FALSE);
        } else if(cmd == "COMS") {
                com(&arg0, &TRUE);
        } else if(cmd == "NEG") {
                neg(&arg0, &FALSE);
        } else if(cmd == "NEGS") {
                neg(&arg0, &TRUE);
        } else if(cmd == "SBR") {
                sbr(&arg0, &arg1, &FALSE);
        } else if(cmd == "SBRS") {
                sbr(&arg0, &arg1, &TRUE);
        } else if(cmd == "CBR") {
                cbr(&arg0, &arg1, &FALSE);
        } else if(cmd == "CBRS") {
                cbr(&arg0, &arg1, &TRUE);
        } else if(cmd == "INC") {
                inc(&arg0, &FALSE);
        } else if(cmd == "INCS") {
                inc(&arg0, &TRUE);
        } else if(cmd == "DEC") {
                dec(&arg0, &FALSE);
        } else if(cmd == "DECS") {
                dec(&arg0, &TRUE);
        } else if(cmd == "CLR") {
                clr(&arg0, &FALSE);
        } else if(cmd == "CLRS") {
                clr(&arg0, &TRUE);
        } else if(cmd == "SER") {
                ser(&arg0, &FALSE);
        } else if(cmd == "SERS") {
                ser(&arg0, &TRUE);
        } else if(cmd == "MUL") {
                mul(&arg0, &barg1, &FALSE, &FALSE);
        } else if(cmd == "MULS") {
                mul(&arg0, &barg1, &TRUE, &FALSE);
        } else {
        }
}/**/