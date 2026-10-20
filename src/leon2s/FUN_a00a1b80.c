/* FUN_a00a1b80 (leon2s 0xa00a1b80-0xa00a1bb0, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * rec = 0x34-byte record (port) of ARR_a807db00; w = rec word 12 (offset +0x30) is a pointer; stores the
 * halfword v into both halves of word 12 (offset +0x30) of the register block at w: (v << 16) | v.
 * The block is accessed as volatile (hardware registers); the store stays out of the retl delay slot.
 */
extern unsigned char ARR_a807db00[];

void FUN_a00a1b80(unsigned char port, unsigned short v)
{
    unsigned int *base = (unsigned int *)(ARR_a807db00 + port * 0x34);

    ((volatile unsigned int *)base[12])[12] = (v << 16) | v;
}
