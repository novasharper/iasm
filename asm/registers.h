#ifndef _REGISTERS_H
#define _REGISTERS_H
#include "asm_types.h"

#define REGSIZE 32

class reg {
private: 
	byte low;
	byte high;
	ushort mem;
public:
	void get(byte *l, byte *h);
	void get(ushort *v);
	void get(byte *v, bool first = true);
	void set(byte l, byte h);
	void set(ushort v);
	void set(byte v, bool first = true);
	reg();
};

class flags {
private:
	bool c; //carry
	bool n; //negative
	bool z; //zero
	bool s; //signed test???
	bool v; //two's complement (overflow???)
	bool t; //???
	bool h; //half-carry
public:
	void get();
	void get(char flag);
	void set(char flag, bool on);
	flags();
};

//extern bool iEnabled; //global interrupts enabled/disabled

extern reg *getReg(byte addr);
#endif