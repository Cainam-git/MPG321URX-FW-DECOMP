/* FUN_a00a7acc (leon2s 0xa00a7acc-0xa00a7b64, 152 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Reads one 8-bit register of a hardware block: banks 0..4 only (else returns 0). Register address =
 * ((u16 base table DAT_a00b4d70[bank] + (u16)reg) * 4) | 0xcf000000. For banks 1..4 and reg <= 0x5f it first
 * writes the page (bank - 1) into bits 6-7 of the block register at offset 0x60 (read-modify-write, low 6 bits
 * kept). Source forms as in FUN_a00a7940: the address uses ((u32)reg << 16) >> 16, taken after the page write,
 * and the compare (unsigned short)reg, which keeps two separate truncations; separate nested tests; the result is
 * an unsigned int masked to a byte at the read.
 */
extern unsigned short DAT_a00b4d70[];

unsigned char FUN_a00a7acc(unsigned char bank, short reg)
{
    unsigned int addr;
    unsigned int v = 0;

    if (bank <= 4) {
        if (bank != 0) {
            if ((unsigned short)reg <= 0x5f)
                *(volatile unsigned int *)(((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000) =
                    (*(volatile unsigned int *)(((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000) & 0x3f) | ((bank - 1) << 6);
        }
        addr = reg;
        addr = (addr << 16) >> 16;
        v = *(volatile unsigned int *)(((DAT_a00b4d70[bank] + addr) << 2) | 0xcf000000) & 0xff;
    }
    return v;
}
