/* 8051_bank1 FUN_CODE_c278 @ 0xc278  OPTIMIZE(7,SPEED)
 * Clears bit 0 of one xdata register per set bit of param_1 (bit 0 -> 0xF040, 1 -> 0xF048, 2 -> 0xF090,
 * 3 -> 0xF098, 4 -> 0xF0A2, 5 -> 0xF0BF, 6 -> 0xF147, 7 -> 0xF01B). The parameter is copied to R5 and each bit is
 * tested in turn, followed by a read-modify-write of the matching register. 'param_1 & (1 << n)' and
 * '(param_1 >> n) & 1' compile to the same code.
 */
extern xdata unsigned char DAT_EXTMEM_f040;
extern xdata unsigned char DAT_EXTMEM_f048;
extern xdata unsigned char DAT_EXTMEM_f090;
extern xdata unsigned char DAT_EXTMEM_f098;
extern xdata unsigned char DAT_EXTMEM_f0a2;
extern xdata unsigned char DAT_EXTMEM_f0bf;
extern xdata unsigned char DAT_EXTMEM_f147;
extern xdata unsigned char DAT_EXTMEM_f01b;

void FUN_CODE_c278(unsigned char param_1)
{
    if (param_1 & 0x01)
        DAT_EXTMEM_f040 &= 0xfe;
    if (param_1 & 0x02)
        DAT_EXTMEM_f048 &= 0xfe;
    if (param_1 & 0x04)
        DAT_EXTMEM_f090 &= 0xfe;
    if (param_1 & 0x08)
        DAT_EXTMEM_f098 &= 0xfe;
    if (param_1 & 0x10)
        DAT_EXTMEM_f0a2 &= 0xfe;
    if (param_1 & 0x20)
        DAT_EXTMEM_f0bf &= 0xfe;
    if (param_1 & 0x40)
        DAT_EXTMEM_f147 &= 0xfe;
    if (param_1 & 0x80)
        DAT_EXTMEM_f01b &= 0xfe;
}
