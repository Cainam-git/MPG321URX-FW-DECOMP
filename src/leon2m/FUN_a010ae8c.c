/* leon2m FUN_a010ae8c @ 0xa010ae8c-0xa010af18 (35 words), flags -mcpu=v8 -O3 -g (autoc tagged -Os;
 * -O3 is right).
 * Code facts: dev = (u8)(ch << 4 | 4); FUN_a00f2e98(dev, off, len, data) (a block write); then if bit 7
 * of the hardware register 0xcf00eac0 is set (ld, btst 0x80) and off + (len >> 1) == 0x100, the last
 * two data bytes are copied into a 2-byte stack buffer {data[len-2], data[len-1]} and written again
 * with FUN_a00f2e98(dev, 0x100, 2, buf). void; ch is a full int (no entry 'and 0xff').
 * Fixes vs the autoc draft (54.29): FUN_a00f2e98 is VOID (its %i0 is only a scratch register at the
 * end; with an int return the argument moves are in another order), u8 param types, the buffer
 * stores in ascending order, 0xcf00eac0 as a constant volatile hardware address. Aids: none.
 */
#define REG_CF00EAC0 (*(volatile unsigned int *)0xcf00eac0)
extern void FUN_a00f2e98(unsigned char, unsigned short, unsigned short, unsigned char *);

void FUN_a010ae8c(unsigned int ch, unsigned short off, unsigned short len, unsigned char *data)
{
    unsigned char dev;
    unsigned char buf[2];

    dev = ch << 4 | 4;
    FUN_a00f2e98(dev, off, len, data);
    if (REG_CF00EAC0 & 0x80) {
        if (off + (len >> 1) == 0x100) {
            buf[0] = data[len - 2];
            buf[1] = data[len - 1];
            FUN_a00f2e98(dev, 0x100, 2, buf);
        }
    }
}
