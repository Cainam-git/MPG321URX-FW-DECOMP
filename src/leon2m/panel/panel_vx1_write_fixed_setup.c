/* panel_vx1_write_fixed_setup  (FUN_a01223b0)
 *
 * Write the fixed set-up values of the V-by-One output stage.
 * Name basis: derived - registers 0xCF01CC58..0xCF01CF9C, the block panel_vx1_setup_lanes programs together
 *   with the reset and lock registers next to the one 'ResetVx1' pulses; called by the panel power sequencer
 *
 * Matching notes
 * --------------
 * FUN_a01223b0 (leon2m 0xa01223b0-0xa0122480, 208 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: one volatile word store per statement, in the order of the firmware's stores.
 */
#define REG(address) (*(volatile unsigned int *)(address))

/*
 * Write 22 fixed values to word registers in the block 0xCF01CC58..0xCF01CF9C: 0 to eight registers
 * (0xCF01CD10 to 0xCF01CEBC), 0x80 to four, 0xFF to four, 0x82 to 0xCF01CF94, 0x70 to 0xCF01CF9C, 0x22 to
 * 0xCF01CC6C, 0xCF01CC70 and 0xCF01CC68, and 0 to 0xCF01CC58 last. The order is that of the stores in the
 * firmware. Called from panel_power_sequencer_task. panel_vx1_write_fixed_setup_alt writes a similar set (with 0xFF,
 * 0x82 and 0x70 twice, no 0x80).
 */
void panel_vx1_write_fixed_setup(void)
{
    REG(0xcf01cd10) = 0;
    REG(0xcf01cd9c) = 0;
    REG(0xcf01ce28) = 0;
    REG(0xcf01ceb4) = 0;
    REG(0xcf01cd18) = 0;
    REG(0xcf01cda4) = 0;
    REG(0xcf01ce30) = 0;
    REG(0xcf01cebc) = 0;
    REG(0xcf01ccec) = 0x80;
    REG(0xcf01cd78) = 0x80;
    REG(0xcf01ce04) = 0x80;
    REG(0xcf01ce90) = 0x80;
    REG(0xcf01cd28) = 0xff;
    REG(0xcf01cdb4) = 0xff;
    REG(0xcf01ce40) = 0xff;
    REG(0xcf01cecc) = 0xff;
    REG(0xcf01cf94) = 0x82;
    REG(0xcf01cf9c) = 0x70;
    REG(0xcf01cc6c) = 0x22;
    REG(0xcf01cc70) = 0x22;
    REG(0xcf01cc68) = 0x22;
    REG(0xcf01cc58) = 0;
}
