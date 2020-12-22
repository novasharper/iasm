/**
 * TODO:
 * 20101129:
 * MUST CLEAN UP CODE!!!
 * IT IS UGLY AND POTENTIALLY DANGEROUS!!!
 * 20101130:
 * IMPLEMENT NEW METHODS
 */

//TODO: Convert all params to void*

#include "registers.h"
//#include "memory.h"
#include "asm_types.h"
#include "op.h"

//add, addc, addiw
//void add(byte a1, byte a2, bool immediate, bool carry) {
void add(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r1 = getReg(a1);
		reg *r2;
		ushort a, b;
		r1->get(&a);
		if(!immediate) {
			r2 = getReg((byte)a2);
			r2->get(&b);
		} else {
			b = a2;
		}
		if(!full)
			r1->set((byte)(a + b));
		else
			r1->set((ushort)(a + b));
	}
}

//sub, subi, sbc, sbci, sbicw
//void sub(byte a1, byte a2, bool immediate, bool carry) {
void sub (object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r1 = getReg(a1);
		reg *r2;
		byte a, b;
		r1->get(&a);
		if(!immediate) {
			r2 = getReg((byte)a2);
			r2->get(&b);
		} else {
			b = a2;
		}
		if(!full)
			r1->set((byte)(a - b));
		else
			r1->set((ushort)(a - b));
	}
}

//and, andi
//void and(byte a1, byte a2, bool immediate) {
void and(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);
	
	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r1 = getReg(a1);
		reg *r2;
		byte a, b;
		r1->get(&a);
		if(!immediate) {
			r2 = getReg((byte)a2);
			r2->get(&b);
		} else {
			b = a2;
		}
		r1->set((byte)(a & b));
	}
}


//org, ori
//void or(byte a1, byte a2, bool immediate) {
void or(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r1 = getReg(a1);
		reg *r2;
		byte a, b;
		r1->get(&a);
		if(!immediate) {
			r2 = getReg((byte)a2);
			r2->get(&b);
		} else {
			b = a2;
		}
		r1->set((byte)(a | b));
	}
}

//xor
//void eor(byte a1, byte a2, bool immediate) {
void eor(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r1 = getReg(a1);
		reg *r2;
		byte a, b;
		r1->get(&a);
		if(!immediate) {
			r2 = getReg((byte)a2);
			r2->get(&b);
		} else {
			b = a2;
		}
		r1->set((byte)(a ^ b));
	}
}

//one's complement
//void com(byte a, bool full) {
void com(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)((byte)0xFF - a));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)((ushort)0xFFFF - a));
		}
	}
}

//two's complement
//void neg(byte a, bool full) {
void neg(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)((byte)0x00 - a));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)((ushort)0x0000 - a));
		}
	}
}

//set bit(s) in register
//void sbr(byte a1, ushort a2, bool full) {
void sbr(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)(a | (byte)a2));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)(a | a2));
		}
	}
}

//clear bit(s) in register
//void cbr(byte a1, ushort a2, bool full) {
void cbr(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && (a2 < REGSIZE || immediate)) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)(a & ((byte)0xFF - (byte)a2)));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)(a & ((ushort)0xFFFF - a2)));
		}
	}
}

//increment register
//void inc(byte a, bool full) {
void inc(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)(a + 1));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)(a + 1));
		}
	}
}

//decrement register
//void dec(byte a, bool full) {
void dec(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			byte a;
			r->get(&a);
			r->set((byte)(a - 1));
		} else {
			ushort a;
			r->get(&a);
			r->set((ushort)(a - 1));
		}
	}
}

//skipping tst

//clear register
//void clr(byte a, bool full) {
void clr(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			byte a1;
			r->get(&a1);
			r->set((byte)(a1 ^ a1));
		} else {
			ushort a1;
			r->get(&a1);
			r->set((ushort)(a1 ^ a1));
		}
	}
}

//set register to FF
//void ser(byte a, bool full) {
void ser(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE) {
		reg *r = getReg(a1);
		if(!full) {
			r->set((byte)0xFF);
		} else {
			r->set((ushort)0xFFFF);
		}
	}
}

//multiply (registers) unsigned ?? see doc
//void mul(byte a1, byte a2, bool full) {
void mul(object ar, ...) {
	va_list args;
	va_start(args, ar);
	byte a1 = *(byte*)ar;
	ushort a2 = *(ushort*)va_arg(args, object);
	bool full = *(bool*)va_arg(args, object);
	bool immediate = *(bool*)va_arg(args, object);
	bool carry = *(bool*)va_arg(args, object);
	va_end(args);

	if(a1 < REGSIZE && a2 < REGSIZE) {
		reg *r1 = getReg(a1);
		reg *r2 = getReg((byte)a2);
		if(!full) {
			byte a, b;
			r1->get(&a);
			r2->get(&b);
			r1->set((byte)(a * b));
		} else {
			ushort a, b;
			r1->get(&a);
			r2->get(&b);
			r1->set((ushort)(a * b));
		}
	}
}

//read in all or part of register
ushort reads(byte a) {
	if(a < REGSIZE) {
		reg *r = getReg(a);
		ushort ret;
		r->get(&ret);
		return ret;
	}
}

byte readb(byte a, bool first) {
	if(a < REGSIZE) {
		reg *r = getReg(a);
		byte ret;
		r->get(&ret, first);
		return ret;
	}
}