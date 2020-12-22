#ifndef FMAP_H
#define FMAP_H
#include "asm_types.h"
#include <map>
#include <string>

using namespace std;

extern map<string, functype> funcs;

extern void initFuncMap();
#endif