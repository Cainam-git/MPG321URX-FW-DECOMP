/* sys_frc_get_output_active_height  (FUN_a010a8f0)
 *
 * Read the converter's output timing value, scaled by chip revision.
 * Returns: value
 * Name basis: derived - pair 0xCF011C30, or 0xCF011AF8 shifted by 1, 2 or 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a8f0 @ 0xa010a8f0-0xa010a9e8 (62 words), flags -mcpu=v8 -O3 -g.
 * Source form: early returns per test (an if/else chain into one unsigned short local gives other code);
 * sys_get_chip_revision is called again for each test, as in the firmware. reg_read16_bytes takes the register
 * address as a pointer here.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern unsigned int reg_read16_bytes(volatile unsigned int *p);
extern unsigned char sys_get_chip_revision(void);
/*
 * Read a 16-bit output timing value of the converter (the routine is named active height after the way its
 * callers use it).
 *
 * With bit 7 of 0xCF011A80 clear it is the value at 0xCF011C30. With bit 7 set it is the value at 0xCF011AF8,
 * shifted left by 1 (chip revision code above 0x82 and bit 3 of 0xCF011E40), else by 2 (code above 0x83 and
 * bit 2), else by 3 (code above 0x83 and bit 1), else not shifted. The shift depends only on the chip revision
 * code and those bits of 0xCF011E40.
 * Called by panel_output_setup_block4 and sys_fill_output_size_record.
 */
unsigned short sys_frc_get_output_active_height(void)
{
    if (!(R(0xcf011a80) & 0x80))
        return reg_read16_bytes((volatile unsigned int *)0xcf011c30);
    if (sys_get_chip_revision() > 0x82 && (R(0xcf011e40) & 8))
        return reg_read16_bytes((volatile unsigned int *)0xcf011af8) << 1;
    if (sys_get_chip_revision() > 0x83 && (R(0xcf011e40) & 4))
        return reg_read16_bytes((volatile unsigned int *)0xcf011af8) << 2;
    if (sys_get_chip_revision() > 0x83 && (R(0xcf011e40) & 2))
        return reg_read16_bytes((volatile unsigned int *)0xcf011af8) << 3;
    return reg_read16_bytes((volatile unsigned int *)0xcf011af8);
}
