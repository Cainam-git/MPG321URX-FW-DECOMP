/* panel_vx1_write_fixed_setup_alt  (FUN_a01111f4)
 *
 * Write the second set of fixed set-up values of the V-by-One output stage.
 * Name basis: derived - registers 0xCF01CC58..0xCF01CFAC, the block panel_vx1_setup_lanes programs together
 *   with the reset and lock registers next to the one 'ResetVx1' pulses; called by the panel power sequencer
 *
 * Matching notes
 * --------------
 * FUN_a01111f4 (leon2m 0xa01111f4-0xa01112c0, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: one volatile word store per statement, in the order of the firmware's stores.
 */
#define REG(address) (*(volatile unsigned int *)(address))

/*
 * Write 22 fixed values to word registers in the block 0xCF01CC58..0xCF01CFAC: 0 to eight registers
 * (0xCF01CD10 to 0xCF01CE9C), 0xFF to four, 0 to 0xCF01CCC0 and 0xCF01CFAC, 0x82 to 0xCF01CF94 and 0xCF01CF08,
 * 0x70 to 0xCF01CF9C and 0xCF01CF10, 0x22 to 0xCF01CC6C, 0xCF01CC70 and 0xCF01CC68, and 0 to 0xCF01CC58 last.
 * The order is that of the stores in the firmware. Called from panel_power_sequencer_task.
 */
void panel_vx1_write_fixed_setup_alt(void)
{
    REG(0xcf01cd10) = 0;
    REG(0xcf01cd9c) = 0;
    REG(0xcf01ce28) = 0;
    REG(0xcf01ceb4) = 0;
    REG(0xcf01ccf8) = 0;
    REG(0xcf01cd84) = 0;
    REG(0xcf01ce10) = 0;
    REG(0xcf01ce9c) = 0;
    REG(0xcf01cd28) = 0xff;
    REG(0xcf01cdb4) = 0xff;
    REG(0xcf01ce40) = 0xff;
    REG(0xcf01cecc) = 0xff;
    REG(0xcf01ccc0) = 0;
    REG(0xcf01cfac) = 0;
    REG(0xcf01cf94) = 0x82;
    REG(0xcf01cf08) = 0x82;
    REG(0xcf01cf9c) = 0x70;
    REG(0xcf01cf10) = 0x70;
    REG(0xcf01cc6c) = 0x22;
    REG(0xcf01cc70) = 0x22;
    REG(0xcf01cc68) = 0x22;
    REG(0xcf01cc58) = 0;
}
