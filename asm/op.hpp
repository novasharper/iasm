#ifndef OP_H
#define OP_H
#include "asm_types.hpp"
// commands based on specifications for avr assembly language
//

/**
 *
 * format {command}{i?}{s?}{c?} {hexnumber [2char]}{, {hexnumber [2char]}?}
 * [string cmd]
 *
 * p <- -1
 * full <- false
 * immediate <- false
 * if cmd<len + p> == `c`,
 *  carry <- true
 *  p <- p - 1
 * if cmd<len + p> == `i`,
 *  immediate <- true
 *  p <- p - 1
 * if cmd<len + p> == `s`,
 *  full <- true
 * cmd.cut(p)
 *
 */

// add, addc, addiw
// extern void add(byte a1, byte a2, bool immediate, bool carry);
// extern void adds(byte a1, ushort a2, bool immediate, bool carry);
extern void op_add(object ar, ...);

// sub, subi, sbc, sbci, sbicw
// extern void sub(byte a1, byte a2, bool immediate, bool carry);
// extern void subs(byte a1, ushort a2, bool immediate, bool carry);
extern void op_sub(object ar, ...);

// and, andi
// extern void and(byte a1, byte a2, bool immediate);
// extern void ands(byte a1, ushort a2, bool immediate);
extern void op_and(object ar, ...);

// org, ori
// extern void or(byte a1, byte a2, bool immediate);
// extern void ors(byte a1, ushort a2, bool immediate);
extern void op_or(object ar, ...);

// xor
// extern void eor(byte a1, byte a2, bool immediate);
// extern void eors(byte a1, ushort a2, bool immediate);
extern void op_eor(object ar, ...);

// one's complement
// extern void com(byte a, bool full);
extern void op_com(object ar, ...);

// two's complement
// extern void neg(byte a, bool full);
extern void op_neg(object ar, ...);

// set bit(s) in register
// extern void sbr(byte a1, ushort a2, bool full);
extern void op_sbr(object ar, ...);

// clear bit(s) in register
// extern void cbr(byte a1, ushort a2, bool full);
extern void op_cbr(object ar, ...);

// increment register
// extern void inc(byte a, bool full);
extern void op_inc(object ar, ...);

// decrement register
// extern void dec(byte a, bool full);
extern void op_dec(object ar, ...);

// skipping tst

// clear register
// extern void clr(byte a, bool full);
extern void op_clr(object ar, ...);

// set register to FF
// extern void ser(byte a, bool full);
extern void op_ser(object ar, ...);

// multiply (registers) unsigned ?? see doc
// extern void mul(byte a1, byte a2, bool full);
extern void op_mul(object ar, ...);

// read in all or part of register
ushort op_reads(byte a);
byte op_readb(byte a, bool first);

#endif
