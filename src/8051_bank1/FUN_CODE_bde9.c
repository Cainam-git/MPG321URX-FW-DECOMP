/* 8051_bank1 FUN_CODE_bde9 @ 0xbde9  OPTIMIZE(8,SPEED) LARGE
 * This function takes a bitmask in `sel` (R7) and a value in `val` (R5). It clears the LSB of `val` (keeping only bits 1-7), then for each set bit in `sel`, it writes `(current_value & 1) | val` to the corresponding XDATA register. The bit-to-register mapping is: bit 0 → 0xF040, bit 1 → 0xF048, bit 2 → 0xF090, bit 3 → 0xF098, bit 4 → 0xF0A2, bit 5 → 0xF0BF, bit 6 → 0xF147, bit 7 → 0xF01B. Keil copies the first parameter with `MOV R4,AR7`, as in the target.
 */
extern xdata unsigned char DAT_EXTMEM_f040;
extern xdata unsigned char DAT_EXTMEM_f048;
extern xdata unsigned char DAT_EXTMEM_f090;
extern xdata unsigned char DAT_EXTMEM_f098;
extern xdata unsigned char DAT_EXTMEM_f0a2;
extern xdata unsigned char DAT_EXTMEM_f0bf;
extern xdata unsigned char DAT_EXTMEM_f147;
extern xdata unsigned char DAT_EXTMEM_f01b;

void FUN_CODE_bde9(unsigned char sel, unsigned char val) 
{
    val &= 0xfe;
    
    if (sel & 0x01) {
        DAT_EXTMEM_f040 = (DAT_EXTMEM_f040 & 0x01) | val;
    }
    if (sel & 0x02) {
        DAT_EXTMEM_f048 = (DAT_EXTMEM_f048 & 0x01) | val;
    }
    if (sel & 0x04) {
        DAT_EXTMEM_f090 = (DAT_EXTMEM_f090 & 0x01) | val;
    }
    if (sel & 0x08) {
        DAT_EXTMEM_f098 = (DAT_EXTMEM_f098 & 0x01) | val;
    }
    if (sel & 0x10) {
        DAT_EXTMEM_f0a2 = (DAT_EXTMEM_f0a2 & 0x01) | val;
    }
    if (sel & 0x20) {
        DAT_EXTMEM_f0bf = (DAT_EXTMEM_f0bf & 0x01) | val;
    }
    if (sel & 0x40) {
        DAT_EXTMEM_f147 = (DAT_EXTMEM_f147 & 0x01) | val;
    }
    if (sel & 0x80) {
        DAT_EXTMEM_f01b = (DAT_EXTMEM_f01b & 0x01) | val;
    }
}
