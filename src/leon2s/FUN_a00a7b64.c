/* FUN_a00a7b64 (leon2s 0xa00a7b64-0xa00a7bf8, 148 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Write counterpart of FUN_a00a7acc: writes the byte val to one register of a hardware block, banks 0..4 only. Register address =
 * ((u16 base table DAT_a00b4d70[bank] + (u16)reg) * 4) | 0xcf000000. For banks 1..4 and reg <= 0x5f it first
 * writes (bank - 1) into bits 6-7 of the block register at offset 0x60 (read-modify-write, low 6 bits
 * kept). Source forms as in FUN_a00a7940: the address uses ((u32)reg << 16) >> 16, taken after that write,
 * and the compare (unsigned short)reg, which keeps two separate truncations; separate nested tests.
 */
extern unsigned short DAT_a00b4d70[];

void FUN_a00a7b64(unsigned char bank, short reg, unsigned char val)
{
    unsigned int addr;

    if (bank <= 4) {
        if (bank != 0) {
            if ((unsigned short)reg <= 0x5f)
                *(volatile unsigned int *)(((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000) =
                    (*(volatile unsigned int *)(((DAT_a00b4d70[bank] + 0x60) << 2) | 0xcf000000) & 0x3f) | ((bank - 1) << 6);
        }
        addr = reg;
        addr = (addr << 16) >> 16;
        *(volatile unsigned int *)(((DAT_a00b4d70[bank] + addr) << 2) | 0xcf000000) = val;
    }
}
