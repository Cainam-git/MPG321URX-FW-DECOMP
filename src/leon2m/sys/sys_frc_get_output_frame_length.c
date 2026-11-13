/* sys_frc_get_output_frame_length  (FUN_a010a9e8)
 *
 * Return the frame length of the converter's output timing.
 * Returns: lines per frame
 * Name basis: derived - sum of 0xCF011AE0..AF8 scaled by chip revision, or 0xCF011C38
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010a9e8 @ 0xa010a9e8, flags -mcpu=v8 -O3 -g.
 * Source form: the sum is kept in an unsigned short local (the firmware truncates to 16 bits); the first scaling
 * step is a conditional expression (n + n), the other two are shift statements; sys_get_chip_revision is called
 * again for each test. The four summed registers are 0xCF011AE0.. (not 0xCF011EE0..).
 */


extern int reg_read16_bytes(int);
extern unsigned char sys_get_chip_revision(void);
/*
 * Frame length of the converter's output timing, 16 bits.
 *
 * With bit 7 of 0xCF011A80 set it is the sum of four values read from 0xCF011AE0, 0xCF011AE8, 0xCF011AF0 and
 * 0xCF011AF8, scaled one after the other: doubled when the chip revision code is above 0x82 and bit 3 of
 * 0xCF011E40 is set, times 4 when the code is above 0x83 and bit 2 is set, times 8 on top of that when the code
 * is above 0x83 and bit 1 is set. With bit 7 clear it is the value at 0xCF011C38.
 * Called by drv_PanelLimitation (as "vtotal" on the converter path) and sys_fill_output_size_record.
 */
unsigned short sys_frc_get_output_frame_length(void)
{
  unsigned short n;
  if ((*((volatile unsigned int *) 0xcf011a80)) & 0x80)
  {
    n = reg_read16_bytes(0xcf011ae0);
    n += reg_read16_bytes(0xcf011ae8);
    n += reg_read16_bytes(0xcf011af0);
    n += reg_read16_bytes(0xcf011af8);
    n = ((sys_get_chip_revision() > 0x82) && ((*((volatile unsigned int *) 0xcf011e40)) & 8)) ? (n + n) : (n);
    if ((sys_get_chip_revision() > 0x83) && ((*((volatile unsigned int *) 0xcf011e40)) & 4))
    {
      n <<= 2;
    }
    if ((sys_get_chip_revision() > 0x83) && ((*((volatile unsigned int *) 0xcf011e40)) & 2))
    {
      n <<= 3;
    }
  }
  else
  {
    n = reg_read16_bytes(0xcf011c38);
  }
  return n;
}
