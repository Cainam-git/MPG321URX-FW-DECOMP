/* leon2m FUN_a0123744 @ 0xa0123744-0xa0123840 (63 words).
 * Hardware register sequence: 0x80 to 0xcf011f80; 0xcf03c780 bit 0 set, bit 1 cleared; the 16 port registers
 * 0xf190..0xf19f (address 0xcf000000 | n << 2) cleared; 0xcf03c780 bit 0 cleared, bit 1 set. Then
 * v = func_0x4008e46c(0x13) and its four bytes, most significant first, go to 0xcf03c670 / 674 / 678 / 67c;
 * 0xff to 0xcf03c664, 0x31 to 0xcf03c660, and it waits (no limit) while 0xcf03c660 reads 0x31.
 * Called by FUN_a0147bb0. volatile: all accesses are hardware registers.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

extern unsigned int func_0x4008e46c(unsigned int);

void FUN_a0123744(void)
{
    unsigned char i;
    unsigned int v;

    REG(0xcf011f80) = 0x80;
    REG(0xcf03c780) |= 1;
    REG(0xcf03c780) &= ~2;
    for (i = 0; i < 16; i++)
        PREG(0xf190 + i) = 0;
    REG(0xcf03c780) &= ~1;
    REG(0xcf03c780) |= 2;
    v = func_0x4008e46c(0x13);
    REG(0xcf03c670) = v >> 24;
    REG(0xcf03c674) = (v >> 16) & 0xff;
    REG(0xcf03c678) = (v >> 8) & 0xff;
    REG(0xcf03c67c) = v & 0xff;
    REG(0xcf03c664) = 0xff;
    REG(0xcf03c660) = 0x31;
    while (REG(0xcf03c660) == 0x31)
        ;
}
