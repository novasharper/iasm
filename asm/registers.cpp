#include "registers.h"

// enable interrupts
// bool iEnabled = true;

// register class
void reg::get(byte *h, byte *l) {
  *h = high;
  *l = low;
}

void reg::get(ushort *v) { *v = mem; }

void reg::get(byte *v, bool first) {
  if (first) {
    *v = low;
  } else {
    *v = high;
  }
}

void reg::set(ushort v) {
  high = (v >> 8) & 0xFF;
  low = v & 0xFF;
  mem = v;
}

void reg::set(byte v, bool first) {
  if (first) {
    low = v;
    mem = (high << 8) + v;
  } else {
    high = v;
    mem = (v << 8) + low;
  }
}

void reg::set(byte h, byte l) {
  high = h;
  low = l;
  mem = (h << 8) + l;
}

reg::reg() {
  high = 0;
  low = 0;
  mem = 0;
}

reg r[REGSIZE];
reg p; // dummy register

void flags::get() {}

void flags::get(char flag) {}

void flags::set(char flag, bool on) {}

flags::flags() {}

reg *getReg(byte addr) {
  if (addr < REGSIZE)
    return &r[addr];
  else
    return &p;
}