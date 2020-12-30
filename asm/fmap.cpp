#include "fmap.hpp"
#include "op.hpp"
#include <map>

map<string, functype> funcs;

void initFuncMap() {
  funcs["ADD"] = op_add;
  funcs["SUB"] = op_sub;
  funcs["AND"] = op_and;
  funcs["OR"] = op_or;
  funcs["EOR"] = op_eor;
  funcs["COM"] = op_com;
  funcs["NEG"] = op_neg;
  funcs["SBR"] = op_sbr;
  funcs["CBR"] = op_cbr;
  funcs["INC"] = op_inc;
  funcs["DEC"] = op_dec;
  funcs["CLR"] = op_clr;
  funcs["SER"] = op_ser;
  funcs["MUL"] = op_mul;
}
