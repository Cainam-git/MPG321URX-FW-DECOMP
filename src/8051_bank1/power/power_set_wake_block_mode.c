/* power_set_wake_block_mode  (FUN_CODE_9bde)
 *
 * Program the wake block for one input kind of the wake-up table.
 *   kind: entry kind 0..12
 * Name basis: descriptive - mode 0..12 -> wake block registers 4, 3, 0x54 (reg_write_wake_block_byte); caller
 *   power_apply_wake_block_mode
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_9bde @ 0x9bde .. 0x9ca9, OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 * REGFILE(R.ORC) is needed (Keil then knows reg_write_wake_block_byte keeps R5/R7: 'DEC R7' for register 3 after
 * register 4; without it 235 bytes). Keil switch: CJNE A,#0DH / JC, 3-byte LJMP table at 0x9bee; the equal case
 * tails are cross-jumped. The size recorded for the routine (17) is the code before the table; the checked span
 * is 0x9bde..0x9caa (204 bytes).
 */
extern unsigned char xdata DAT_EXTMEM_6043;
extern unsigned char xdata DAT_EXTMEM_dcf0;
void reg_write_wake_block_byte(unsigned char reg, unsigned char val);
void reg_update_wake_block_bits(unsigned char reg, unsigned char mask, unsigned char on);

#define WAKE_KIND_DP0_A    7   /* entry kinds of the wake-up port table (as power_check_wake_entry) */
#define WAKE_KIND_DP0_B    8
#define WAKE_KIND_DP1_A    9
#define WAKE_KIND_DP1_B    10

/*
 * power_set_wake_block_mode - program the wake block for one entry kind of the wake-up port table.
 *   kind  0..12; other kinds write nothing
 * Every kind writes register 4 (0x80..0x8E), register 3 (0x80, 0x08 or 0x28) and register 0x54 (0x20 or 0x90).
 * Kind 0 also clears XDATA 0x6043. Kinds 7..10 (the DP receiver kinds) first set or clear bit 0 of register 3
 * and of XDATA 0xDCF0: 7 clear / clear, 8 set / set, 9 clear / set, 10 set / clear. What the values select is
 * not shown in this program.
 * Only caller: power_apply_wake_block_mode.
 */
void power_set_wake_block_mode(unsigned char kind)
{
    switch (kind) {
    case 0:
        reg_write_wake_block_byte(4, 0x80);
        reg_write_wake_block_byte(3, 0x80);
        reg_write_wake_block_byte(0x54, 0x20);
        DAT_EXTMEM_6043 = 0;
        break;
    case 1: reg_write_wake_block_byte(4, 0x82); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 2: reg_write_wake_block_byte(4, 0x86); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 3: reg_write_wake_block_byte(4, 0x86); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 4: reg_write_wake_block_byte(4, 0x86); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 5: reg_write_wake_block_byte(4, 0x8a); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 6: reg_write_wake_block_byte(4, 0x8e); reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case WAKE_KIND_DP0_A:
        reg_write_wake_block_byte(4, 0x83); reg_update_wake_block_bits(3, 1, 0); DAT_EXTMEM_dcf0 &= 0xfe;
        reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case WAKE_KIND_DP0_B:
        reg_write_wake_block_byte(4, 0x83); reg_update_wake_block_bits(3, 1, 1); DAT_EXTMEM_dcf0 |= 0x01;
        reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case WAKE_KIND_DP1_A:
        reg_write_wake_block_byte(4, 0x83); reg_update_wake_block_bits(3, 1, 0); DAT_EXTMEM_dcf0 |= 0x01;
        reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case WAKE_KIND_DP1_B:
        reg_write_wake_block_byte(4, 0x83); reg_update_wake_block_bits(3, 1, 1); DAT_EXTMEM_dcf0 &= 0xfe;
        reg_write_wake_block_byte(3, 0x08); reg_write_wake_block_byte(0x54, 0x90); break;
    case 11: reg_write_wake_block_byte(4, 0x82); reg_write_wake_block_byte(3, 0x28); reg_write_wake_block_byte(0x54, 0x90); break;
    case 12: reg_write_wake_block_byte(4, 0x82); reg_write_wake_block_byte(3, 0x28); reg_write_wake_block_byte(0x54, 0x90); break;
    }
}
