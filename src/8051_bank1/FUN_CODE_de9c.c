/* 8051_bank1 FUN_CODE_de9c @ 0xde9c  MATCH (OPTIMIZE(7,SPEED))
 * Returns carry set (bit 1) if the byte at XDATA 0xA46C is non-zero, carry clear otherwise. Both paths end in
 * their own RET; the `bit` return type maps the result to the carry flag.
 */
extern xdata unsigned char DAT_EXTMEM_a46c;  // 0xa46c

bit FUN_CODE_de9c(void) {
    if (DAT_EXTMEM_a46c == 0) {
        return 0;
    }
    return 1;
}
