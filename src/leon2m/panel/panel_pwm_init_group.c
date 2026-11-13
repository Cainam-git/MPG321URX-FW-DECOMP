/* panel_pwm_init_group  (FUN_a011e6dc)
 *
 * Write the fixed start values of the grouped PWM channels.
 * Name basis: derived - fixed writes to 0xCF016480..0xCF0164F4; called before the blur-reduction set-up
 *
 * Matching notes
 * --------------
 * FUN_a011e6dc: the read-back of 0xcf016408 is written as '|= 0' (a volatile read-modify-write that GCC keeps as
 * ld/st).
 */
#define REG(address) (*(volatile unsigned int *)(address))

/*
 * Write fixed start values to the registers of the grouped PWM channels (block 0xCF016480..0xCF0164F4):
 *   0x22 to 0xCF016480, 484, 488 and 48C; bits 0..3 set in 0xCF016490;
 *   0x0A, 0xC3, 0x00, 0x10, 0x04, 0x22 to 0xCF0164E0 .. 0xCF0164F4 (step 4);
 *   bit 2 set in 0xCF0164C0; bits 6 and 7 cleared in 0xCF0164C4;
 *   0xCF016408 read and written back unchanged; 0x20 to 0xCF01640C.
 * Called from SetPSMMixMode and panel_blurfree_configure.
 */
void panel_pwm_init_group(void)
{
    REG(0xcf016480) = 0x22;
    REG(0xcf016484) = 0x22;
    REG(0xcf016488) = 0x22;
    REG(0xcf01648c) = 0x22;
    REG(0xcf016490) |= 0xf;
    REG(0xcf0164e0) = 0xa;
    REG(0xcf0164e4) = 0xc3;
    REG(0xcf0164e8) = 0;
    REG(0xcf0164ec) = 0x10;
    REG(0xcf0164f0) = 4;
    REG(0xcf0164f4) = 0x22;
    REG(0xcf0164c0) |= 4;
    REG(0xcf0164c4) &= ~0xc0;
    REG(0xcf016408) |= 0;
    REG(0xcf01640c) = 0x20;
}
