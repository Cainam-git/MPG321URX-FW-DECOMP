/*
 * FUN_a00735e8 (leon2s, 0xa00735e8-0xa0073638, 80 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: if u8 FUN_a0073520(port) != 0: returns bits 24..27 of register word 0x24 (+0x90) of the
 * register block whose pointer is at +0x18 of the 0x34-byte port record ARR_a807db00[port != 2]; else 0.
 * Aids: volatile on the register-block pointer target (fw full-word 'ld [%g1+0x90]' then srl/and; a plain
 * pointer narrows it to ldub): the MMIO class used for all ARR_a807db00 register pointers (+0/+4/+0x18).
 * Index in its own local 'i = port != 2' (the a007af04 form).
 */
struct Port34 { unsigned char pad[0x18]; volatile unsigned int *regs; unsigned char rest[0x34 - 0x1c]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a0073520(unsigned char);

unsigned int FUN_a00735e8(unsigned char param_1)
{
    unsigned int r = 0;

    if (FUN_a0073520(param_1) != 0) {
        unsigned int i = param_1 != 2;
        r = (ARR_a807db00[i].regs[0x24] >> 24) & 0xf;
    }
    return r;
}
