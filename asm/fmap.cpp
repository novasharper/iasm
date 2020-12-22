#include <map>
#include "op.h"
#include "fmap.h"

map<string, functype> funcs;

void initFuncMap() {
	funcs["ADD"] = add;
	funcs["SUB"] = sub;
	funcs["AND"] = and;
	funcs["OR"] = or;
	funcs["EOR"] = eor;
	funcs["COM"] = com;
	funcs["NEG"] = neg;
	funcs["SBR"] = sbr;
	funcs["CBR"] = cbr;
	funcs["INC"] = inc;
	funcs["DEC"] = dec;
	funcs["CLR"] = clr;
	funcs["SER"] = ser;
	funcs["MUL"] = mul;
}