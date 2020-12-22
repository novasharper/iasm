#ifndef FMAP_H
#define FMAP_H
#include <string>
#include <map>
#include "asm_types.h"

using namespace std;

extern map<string, functype> funcs;

extern void initFuncMap();
#endif