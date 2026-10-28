/* 8051_bank1 FUN_CODE_a142 @ 0xa142 (188 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_a142(sel): s = 0 for sel 1, else 3; for i = s .. s + 2 over the 3-byte entries of XDATA 0xA6AF: stops
 * when (unsigned char)(entry byte 0 - 0x10) >= 0x0F, else FUN_CODE_5f73(byte 0 - 0x10, 1 << (byte 1 & 0x0F),
 * (byte 1 & 0x10) >> 4) and FUN_CODE_d44e(byte 2 * 10). Same layout as FUN_CODE_b881 / FUN_CODE_a085 (2-byte
 * entries there). Caller: FUN_CODE_b06f (0xB071).
 * LARGE locals: i at XDATA 0xA4B4, e at 0xA4B5..0xA4B6, w at 0xA4B7..0xA4B8, s at 0xA4B9; n and c in registers
 *   (R7, R5).
 * volatile: the firmware reads e[0] and e[1] back after storing them (Keil does not keep a value read from a
 *   volatile object in A), as for the tables of FUN_CODE_b881, FUN_CODE_a085 and FUN_CODE_5a39.
 * Source form: the range test assigns n ('(n = e[0] + 0xf0) >= 0x0f'), which is the first call argument; the
 *   value 1 is written to ACC (reg51.h) and the mask is 'ACC << c', so Keil loads A ('MOV A,#01H') before the
 *   count ('MOV R0,AR5').
 * Compiler aid: the call sits under 'if (ACC == 1)'. Keil knows A = 1 there and emits no test; inside an if block
 *   n and c stay in registers (as a plain call statement in this loop Keil places them in XDATA).
 */
#include <reg51.h>
struct ent3 { unsigned char a, b, c; };
extern volatile struct ent3 xdata DAT_EXTMEM_a6af[6];
void FUN_CODE_5f73(unsigned char n, unsigned char mask, unsigned char v);
void FUN_CODE_d44e(unsigned int t);

void FUN_CODE_a142(unsigned char sel)
{
    unsigned char i, e[2];
    unsigned int w;
    unsigned char s;
    unsigned char n, c;

    if (sel == 1) s = 0;
    else s = 3;
    for (i = s; i < s + 3; i++) {
        e[0] = DAT_EXTMEM_a6af[i].a;
        if ((n = e[0] + 0xf0) >= 0x0f) break;
        e[1] = DAT_EXTMEM_a6af[i].b;
        w = DAT_EXTMEM_a6af[i].c;
        c = e[1] & 0x0f;
        ACC = 1;
        if (ACC == 1) FUN_CODE_5f73(n, ACC << c, (e[1] & 0x10) >> 4);
        FUN_CODE_d44e(w * 10);
    }
}
