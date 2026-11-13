/* sys_ddr_run_bist_read  (FUN_a00e4278)
 *
 * Run the memory self-test for a read step; result 3 repeats the attempt, any other is returned.
 * Returns: result
 * Note: Result 1 is returned at once: the retry pulse on field 8 of register 0x54 can never run.
 * Name basis: derived - pattern and control register sequence, then sys_ddr_get_bist_result
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Source form: the version == 1 and version == 2 branches are two
 * separate, identical branches; the build needs both. The extern declarations are old-style (no parameter
 * list); the infinite loop continues on result 3 and breaks on every other result.
 */
extern int sys_ddr_check_arguments();
extern void sys_ddr_phy_write();
extern void sys_ddr_phy_update_bits();
extern void sys_ddr_phy_write_field();
extern int sys_ddr_get_bist_result();

/*
 * Run the memory self-test for a read step on memory interface phy and return its result (sys_ddr_get_bist_result:
 * 0, 1, 2 or 3). Called by sys_ddr_find_read_eye and sys_ddr_find_write_window_lower_edge.
 *
 * version and generation are the values sys_ddr_check_arguments checks; version also picks how register 0x5a
 * is set (see below). bit_mode (0, 1 or 2) is passed on to sys_ddr_get_bist_result.
 *
 * One attempt: write the pattern registers 0x44..0x53, set up registers 0x40..0x43, 0x5a, 0x5b and 0x5c, write
 * 0x8f, 0x80, 0x8f to register 0x2cd, clear and set bit 0x20 of register 0x6c, set bit 0x80 of register 0x40 and
 * read the result. Version 0 writes 7 to register 0x5a; versions 1 and 2 set its bits 0x81 under mask 0x87.
 * Result 3 repeats the attempt without limit. Result 1 is counted; the code would pulse field 0x08 of register
 * 0x54 and try again only while the count is not above 0, but the count is already 1 on the first failure, so
 * result 1 is returned at once and the pulse never runs. Any other result is returned.
 * sys_ddr_run_bist_write is the same routine with a different pattern.
 */
int sys_ddr_run_bist_read(int phy,int version,unsigned int generation,unsigned int bit_mode)

{
  int result;
  int attempts;
  
  attempts = 0;
  sys_ddr_check_arguments(phy,version,generation);
  for (;;) {
    {
      sys_ddr_phy_write(phy,0x44,0xff);
      sys_ddr_phy_write(phy,0x45,0xf0);
      sys_ddr_phy_write(phy,0x46,0xff);
      sys_ddr_phy_write(phy,0x47,0xff);
      sys_ddr_phy_write(phy,0x48,0);
      sys_ddr_phy_write(phy,0x49,0);
      sys_ddr_phy_write(phy,0x4a,0);
      sys_ddr_phy_write(phy,0x4b,0);
      sys_ddr_phy_write(phy,0x4c,0xff);
      sys_ddr_phy_write(phy,0x4d,0xff);
      sys_ddr_phy_write(phy,0x4e,0xff);
      sys_ddr_phy_write(phy,0x4f,0);
      sys_ddr_phy_write(phy,0x50,0xff);
      sys_ddr_phy_write(phy,0x51,0xff);
      sys_ddr_phy_write(phy,0x52,0xff);
      sys_ddr_phy_write(phy,0x53,0xf);
      sys_ddr_phy_update_bits(phy,0x40,0x87,2);
      sys_ddr_phy_update_bits(phy,0x40,0x20,0x20);
      sys_ddr_phy_write(phy,0x41,3);
      sys_ddr_phy_write(phy,0x5b,0x3c);
      sys_ddr_phy_write(phy,0x5c,0);
      sys_ddr_phy_write(phy,0x42,0x28);
      sys_ddr_phy_update_bits(phy,0x43,3,0);
      if (version == 0) {
        sys_ddr_phy_write(phy,0x5a,7);
      }
      else if (version == 1) {
        sys_ddr_phy_update_bits(phy,0x5a,0x87,0x81);
      }
      else if (version == 2) {
        sys_ddr_phy_update_bits(phy,0x5a,0x87,0x81);
      }
      sys_ddr_phy_write(phy,0x2cd,0x8f);
      sys_ddr_phy_write(phy,0x2cd,0x80);
      sys_ddr_phy_write(phy,0x2cd,0x8f);
      sys_ddr_phy_update_bits(phy,0x6c,0x20,0);
      sys_ddr_phy_update_bits(phy,0x6c,0x20,0x20);
      sys_ddr_phy_update_bits(phy,0x40,0x80,0x80);
      result = sys_ddr_get_bist_result(phy,bit_mode);
      if (result == 1) {
        attempts = attempts + 1;
        if (0 < attempts) break;
        sys_ddr_phy_write_field(phy,0x54,8,3,1);
        sys_ddr_phy_write_field(phy,0x54,8,3,0);
      }
      else if (result == 3) continue;
      else break;
    }
  }
  return result;
}
