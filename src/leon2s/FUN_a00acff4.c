/* leon2s FUN_a00acff4 @ 0xa00acff4-0xa00ad054 (24 words), flags -mcpu=v8 -Os -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp_l2s 0 mismatches / 24 words.
 * Code facts: hardware register 0xcf0132c0 |= 2; FUN_a00b1794(1); register &= ~2; if byte +0x11f of port record
 * ARR_a807dc18[0] or [1] (300-byte records, as in FUN_a00ac66c) == 1: byte 0xa8079316 = 0. void.
 * Fix vs the autoc draft (79.17): real base ARR_a807dc18 as 300-byte records (the draft named mid-record words
 * DAT_a807dd37 / DAT_a807de63 and compared them as ints); the register pointer is volatile (real 0xcf... hardware
 * register, read-modify-written twice). Aids: none.
 */
struct Port { unsigned char pad[0x11f]; unsigned char b11f; unsigned char rest[0x12c - 0x120]; };
extern struct Port ARR_a807dc18[];
extern unsigned char DAT_a8079316;
extern void FUN_a00b1794(int);

void FUN_a00acff4(void)
{
    volatile unsigned int *reg = (volatile unsigned int *)0xcf0132c0;

    *reg |= 2;
    FUN_a00b1794(1);
    *reg &= ~2;
    if (ARR_a807dc18[0].b11f == 1 || ARR_a807dc18[1].b11f == 1)
        DAT_a8079316 = 0;
}
