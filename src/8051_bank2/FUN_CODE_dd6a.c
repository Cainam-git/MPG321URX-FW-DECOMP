/* 8051_bank2 FUN_CODE_dd6a @ 0xdd6a  update agent: switch one scaler control bit on / off by a descriptor
 * (byte-exact with OPTIMIZE(8,SPEED) LARGE).
 * The descriptor in XDATA 0x064A..0x0651 (filled from the flash-chip record, see FUN_CODE_0003) gives the scaler
 * register (0x064A = high byte, 0x064F = low byte), the bit mask (0x0650) and the polarity (0x0651: 0 = active
 * high). Reads the register over the service bus (FUN_CODE_e105), sets / clears the masked bits according to `on`
 * and polarity, writes it back (FUN_CODE_da8a, tail call). FUN_CODE_a8a3 calls it with 0 before and 1 after the
 * partial-update steps when bit 3 of the mask is set.
 */
extern unsigned char xdata DAT_EXTMEM_064a, DAT_EXTMEM_064f, DAT_EXTMEM_0650, DAT_EXTMEM_0651;
unsigned char FUN_CODE_e105(unsigned int reg);
unsigned char FUN_CODE_da8a(unsigned int reg, unsigned char val);

void FUN_CODE_dd6a(bit on)
{
    unsigned int reg;
    unsigned char v;
    reg = (DAT_EXTMEM_064a << 8) | DAT_EXTMEM_064f;
    v = FUN_CODE_e105(reg);
    if (on) {
        if (DAT_EXTMEM_0651 == 0) v |= DAT_EXTMEM_0650;
        else v &= DAT_EXTMEM_0650;
    } else {
        if (DAT_EXTMEM_0651 == 0) v &= ~DAT_EXTMEM_0650;
        else v |= ~DAT_EXTMEM_0650;
    }
    FUN_CODE_da8a(reg, v);
}
