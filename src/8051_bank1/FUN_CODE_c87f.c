/* 8051_bank1 FUN_CODE_c87f @ 0xc87f (78 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Selects one XDATA register by the one-hot value sel (0x01 -> 0xF01C, 0x02 -> 0xF01E, 0x04 -> 0xF085,
 * 0x08 -> 0xF087, 0x10 -> 0xF099, 0x20 -> 0xF0A3, 0x40 -> 0xF076) and rewrites it as (reg & 0xBC) | v, where
 * v = 0x40 when on == 1 and 0 otherwise. Any other sel changes nothing. Only caller: the command switch FUN_CODE_224f (command 31 with bytes 1 and 2).
 * v must be a '?:' (an if/else puts it in a memory location instead of R6). Keil shares the read-modify-write
 * tail of the seven cases and tests sel in the order 2, 4, 8, 0x10, 0x20, 0x40, 1.
 */
extern unsigned char xdata DAT_EXTMEM_f01c, DAT_EXTMEM_f01e, DAT_EXTMEM_f085, DAT_EXTMEM_f087;
extern unsigned char xdata DAT_EXTMEM_f099, DAT_EXTMEM_f0a3, DAT_EXTMEM_f076;

void FUN_CODE_c87f(unsigned char sel, unsigned char on)
{
    unsigned char v;

    v = (on == 1) ? 0x40 : 0;
    switch (sel) {
    case 0x01: DAT_EXTMEM_f01c = (DAT_EXTMEM_f01c & 0xbc) | v; break;
    case 0x02: DAT_EXTMEM_f01e = (DAT_EXTMEM_f01e & 0xbc) | v; break;
    case 0x04: DAT_EXTMEM_f085 = (DAT_EXTMEM_f085 & 0xbc) | v; break;
    case 0x08: DAT_EXTMEM_f087 = (DAT_EXTMEM_f087 & 0xbc) | v; break;
    case 0x10: DAT_EXTMEM_f099 = (DAT_EXTMEM_f099 & 0xbc) | v; break;
    case 0x20: DAT_EXTMEM_f0a3 = (DAT_EXTMEM_f0a3 & 0xbc) | v; break;
    case 0x40: DAT_EXTMEM_f076 = (DAT_EXTMEM_f076 & 0xbc) | v; break;
    }
}
