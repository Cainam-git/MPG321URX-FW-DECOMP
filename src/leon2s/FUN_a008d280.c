/* FUN_a008d280 (leon2s 0xa008d280-0xa008d2e0, 96 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Computes v = DAT_a8078c01 * 3 + 4, plus 0x800 when n > 0x7ff, writes its low byte to register 0xcf012240
 * and bits 8..15 to 0xcf012244, and returns the low byte of register 0xcf012200.
 * Compiler aid: 'base++; base--;' emits no instructions; it hides the known value range of base from GCC,
 * so the high byte is extracted with the firmware's sll 16 / srl 24 instead of a plain srl 8.
 */
#define R2200 (*(volatile unsigned int *)0xcf012200)
#define R2240 (*(volatile unsigned int *)0xcf012240)
#define R2244 (*(volatile unsigned int *)0xcf012244)
extern unsigned char DAT_a8078c01;

unsigned char FUN_a008d280(unsigned short n)
{
    unsigned int base = 0;
    unsigned int v;

    if (n > 0x7ff)
        base = 0x800;
    base++;
    base--;
    v = DAT_a8078c01 * 3 + base + 4;
    R2240 = v & 0xff;
    R2244 = (unsigned short)v >> 8;
    return R2200;
}
