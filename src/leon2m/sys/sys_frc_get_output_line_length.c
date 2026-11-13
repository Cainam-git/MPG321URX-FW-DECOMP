/* sys_frc_get_output_line_length  (FUN_a010a884)
 *
 * Return the line length of the converter's output timing.
 * Returns: pixels per line
 * Name basis: derived - sum of 0xCF011AC0..AD8 or 0xCF011C20
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a884 @ 0xa010a884, flags -mcpu=v8 -O2 -g (section default; -O3 -g builds the same bytes).
 * Source form: the sum is kept in an unsigned short local, as the firmware truncates to 16 bits; the register
 * reads go through reg_read16_bytes with the address as an int.
 */

extern int reg_read16_bytes(int);

/*
 * Line length of the converter's output timing, 16 bits.
 *
 * With bit 7 of 0xCF011A80 set it is the sum of four values read from 0xCF011AC0, 0xCF011AC8, 0xCF011AD0 and
 * 0xCF011AD8; with bit 7 clear it is the value at 0xCF011C20. Twin of sys_frc_get_output_frame_length.
 * Called by drv_PanelLimitation (as "htotal" on the converter path) and sys_fill_output_size_record.
 */
unsigned short sys_frc_get_output_line_length(void)
{
    unsigned short sum;

    if (*(volatile unsigned int *)0xcf011a80 & 0x80) {
        sum = reg_read16_bytes(0xcf011ac0);
        sum += reg_read16_bytes(0xcf011ac8);
        sum += reg_read16_bytes(0xcf011ad0);
        sum += reg_read16_bytes(0xcf011ad8);
    } else {
        sum = reg_read16_bytes(0xcf011c20);
    }
    return (unsigned short)sum;
}
