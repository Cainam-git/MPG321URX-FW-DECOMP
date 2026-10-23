/* 8051_bank2 FUN_CODE_a6fa @ 0xa6fa..0xa8a3 (425 B; functions.json splits it at 0xa799 into a6fa + a799, and a799 is
 * only the second half: it has no caller of its own). OPTIMIZE(8,SPEED) LARGE; parameter n at XDATA 0x08EB.
 * Callers: FUN_CODE_6e16 (0x6e1b), FUN_CODE_b5b4 (x6).
 * XDATA 0x075B is an index (0 or 1) into three per-index tables: 0x0858[] (records of 0x2E bytes, current copy at
 * 0x082A), 0x0783[] (records of 0x27 bytes, current copy at 0x075C) and the byte arrays 0x08D0[], 0x08D2[], 0x08D4[]
 * (current values at 0x08CD, 0x08CE, 0x08CF). The function saves the current copies into the slot of the old index
 * (?C?COPY for the records), sets 0x075B = n and loads the current copies from the slot of the new index. Then:
 * 0x08B8 = index * 0x380 (?C?LIMUL), 0x07D5 = 0x08C9 + 0x08B8, and in the structure at 0x08BC (byte, three
 * unsigned longs a / b / c at 0x08BD / 0x08C1 / 0x08C5): a = 0x07D5 + 0x280, b = a + 0x20, c = b + 8; finally
 * 0x08B4 = a + 0x80 (tail LJMP ?C?LSTXDATA).
 * Source forms the bytes depend on: '(unsigned long)index * 0x380' (?C?LIMUL; a long constant gives ?C?LMUL); b and c
 * in one structure with a (INC DPTR from 0x08C0 to 0x08C1). No aids.
 */
struct rec2e { unsigned char b[0x2e]; };
struct rec27 { unsigned char b[0x27]; };
struct addrs { unsigned char k; unsigned long a; unsigned long b; unsigned long c; };
extern unsigned char xdata DAT_EXTMEM_075b;
extern struct rec27 xdata DAT_EXTMEM_075c;
extern struct rec27 xdata DAT_EXTMEM_0783[2];
extern struct rec2e xdata DAT_EXTMEM_082a;
extern struct rec2e xdata DAT_EXTMEM_0858[2];
extern unsigned char xdata DAT_EXTMEM_08cd;
extern unsigned char xdata DAT_EXTMEM_08ce;
extern unsigned char xdata DAT_EXTMEM_08cf;
extern unsigned char xdata DAT_EXTMEM_08d0[2];
extern unsigned char xdata DAT_EXTMEM_08d2[2];
extern unsigned char xdata DAT_EXTMEM_08d4[2];
extern unsigned long xdata DAT_EXTMEM_07d5;
extern unsigned long xdata DAT_EXTMEM_08b4;
extern unsigned long xdata DAT_EXTMEM_08b8;
extern struct addrs xdata DAT_EXTMEM_08bc;
extern unsigned long xdata DAT_EXTMEM_08c9;
void FUN_CODE_a6fa(unsigned char n)
{
    DAT_EXTMEM_0858[DAT_EXTMEM_075b] = DAT_EXTMEM_082a;
    DAT_EXTMEM_0783[DAT_EXTMEM_075b] = DAT_EXTMEM_075c;
    DAT_EXTMEM_08d0[DAT_EXTMEM_075b] = DAT_EXTMEM_08cd;
    DAT_EXTMEM_08d2[DAT_EXTMEM_075b] = DAT_EXTMEM_08ce;
    DAT_EXTMEM_08d4[DAT_EXTMEM_075b] = DAT_EXTMEM_08cf;
    DAT_EXTMEM_075b = n;
    DAT_EXTMEM_082a = DAT_EXTMEM_0858[DAT_EXTMEM_075b];
    DAT_EXTMEM_075c = DAT_EXTMEM_0783[DAT_EXTMEM_075b];
    DAT_EXTMEM_08cd = DAT_EXTMEM_08d0[DAT_EXTMEM_075b];
    DAT_EXTMEM_08ce = DAT_EXTMEM_08d2[DAT_EXTMEM_075b];
    DAT_EXTMEM_08cf = DAT_EXTMEM_08d4[DAT_EXTMEM_075b];
    DAT_EXTMEM_08b8 = (unsigned long)DAT_EXTMEM_075b * 0x380;
    DAT_EXTMEM_07d5 = DAT_EXTMEM_08c9 + DAT_EXTMEM_08b8;
    DAT_EXTMEM_08bc.a = DAT_EXTMEM_07d5 + 0x280;
    DAT_EXTMEM_08bc.b = DAT_EXTMEM_08bc.a + 0x20;
    DAT_EXTMEM_08bc.c = DAT_EXTMEM_08bc.b + 8;
    DAT_EXTMEM_08b4 = DAT_EXTMEM_08bc.a + 0x80;
}
