/* sys_frc_get_output_active_width  (FUN_a010a494)
 *
 * Read the converter's output timing value from the active register pair.
 * Returns: value
 * Name basis: derived - pair 0xCF011AD8 or 0xCF011C18, chosen by bit 7 of 0xCF011A80
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a494 @ 0xa010a494, flags -mcpu=v8 -O3 -g.
 * Source form: volatile only on the real hardware register 0xCF011A80; reg_read16_bytes reads two byte
 * registers and returns (p[1] << 8) | p[0].
 */
extern unsigned int reg_read16_bytes(volatile unsigned int *p);

/*
 * Return the 16-bit value of the register pair 0xCF011AD8 when bit 7 of the register 0xCF011A80 is set, else of
 * the pair 0xCF011C18. Both pairs are in the block of registers that FRCConfigPostFRC programs.
 *
 * Called by panel_output_setup_block4 (panel_output_setup_block4) and sys_fill_output_size_record (sys_fill_output_size_record).
 */
unsigned short sys_frc_get_output_active_width(void)
{
    if (*(volatile unsigned int *)0xcf011a80 & 0x80)
        return reg_read16_bytes((volatile unsigned int *)0xcf011ad8);
    return reg_read16_bytes((volatile unsigned int *)0xcf011c18);
}
