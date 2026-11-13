/* sys_ddr_run_bist_write  (FUN_a00e4538)
 *
 * Run the memory self-test for a write step.
 * Returns: result
 * Name basis: derived - register sequence, pattern toggle, then the result check
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g. Source form: the version == 1 and version == 2 branches are two separate, identical
 * branches; the build needs both. The extern declarations are old-style (no parameter list); the global toggle
 * is the word at 0xa802b72c; the loop counter is tested after it is incremented.
 */
extern int sys_ddr_check_arguments();
extern void sys_ddr_phy_write();
extern void sys_ddr_phy_update_bits();
extern void sys_ddr_phy_write_field();
extern int sys_ddr_get_bist_result();
extern unsigned int sys_ddr_bist_write_toggle; /* flips between 0 and 1 on every attempt; nothing reads it */

/*
 * Run the memory self-test for a write step on memory interface phy and return its result
 * (sys_ddr_get_bist_result: 0, 1, 2 or 3). Called by sys_ddr_train_write_deskew,
 * sys_ddr_write_deskew_coarse and sys_ddr_write_deskew_fine.
 *
 * The arguments and the retry rule are those of sys_ddr_run_bist_read: version and generation go to
 * sys_ddr_check_arguments, version picks how register 0x5a is set (0: write 7; 1 and 2: bits 0x81 under mask
 * 0x87), bit_mode goes to sys_ddr_get_bist_result, result 3 repeats the attempt, result 1 is returned at once
 * (the pulse of field 0x08 of register 0x54 never runs), any other result is returned.
 *
 * What differs from the read routine: the pattern registers 0x44..0x53 hold 0, 0, 0xff, 0xff repeated four
 * times (the read routine writes another pattern); the word sys_ddr_bist_write_toggle is flipped (xor 1) once per attempt
 * after the pattern is written; registers 0x40, 0x41 and 0x42 are written whole (3, 0, 0) instead of under
 * masks; register 0x43 is not touched.
 */
int sys_ddr_run_bist_write(int phy, int version, unsigned int generation, unsigned int bit_mode)
{
  int result;
  int attempts;
  
  attempts = 0;
  sys_ddr_check_arguments(phy, version, generation);
  for (;;) {
    sys_ddr_phy_write(phy, 0x44, 0);
    sys_ddr_phy_write(phy, 0x45, 0);
    sys_ddr_phy_write(phy, 0x46, 0xff);
    sys_ddr_phy_write(phy, 0x47, 0xff);
    sys_ddr_phy_write(phy, 0x48, 0);
    sys_ddr_phy_write(phy, 0x49, 0);
    sys_ddr_phy_write(phy, 0x4a, 0xff);
    sys_ddr_phy_write(phy, 0x4b, 0xff);
    sys_ddr_phy_write(phy, 0x4c, 0);
    sys_ddr_phy_write(phy, 0x4d, 0);
    sys_ddr_phy_write(phy, 0x4e, 0xff);
    sys_ddr_phy_write(phy, 0x4f, 0xff);
    sys_ddr_phy_write(phy, 0x50, 0);
    sys_ddr_phy_write(phy, 0x51, 0);
    sys_ddr_phy_write(phy, 0x52, 0xff);
    sys_ddr_phy_write(phy, 0x53, 0xff);
    sys_ddr_bist_write_toggle = sys_ddr_bist_write_toggle ^ 1;
    sys_ddr_phy_write(phy, 0x40, 3);
    sys_ddr_phy_write(phy, 0x41, 0);
    sys_ddr_phy_write(phy, 0x5b, 0x3c);
    sys_ddr_phy_write(phy, 0x5c, 0);
    sys_ddr_phy_write(phy, 0x42, 0);
    if (version == 0) {
      sys_ddr_phy_write(phy, 0x5a, 7);
    }
    else if (version == 1) {
      sys_ddr_phy_update_bits(phy, 0x5a, 0x87, 0x81);
    }
    else if (version == 2) {
      sys_ddr_phy_update_bits(phy, 0x5a, 0x87, 0x81);
    }
    sys_ddr_phy_write(phy, 0x2cd, 0x8f);
    sys_ddr_phy_write(phy, 0x2cd, 0x80);
    sys_ddr_phy_write(phy, 0x2cd, 0x8f);
    sys_ddr_phy_update_bits(phy, 0x6c, 0x20, 0);
    sys_ddr_phy_update_bits(phy, 0x6c, 0x20, 0x20);
    sys_ddr_phy_update_bits(phy, 0x40, 0x80, 0x80);
    result = sys_ddr_get_bist_result(phy, bit_mode);
    if (result == 1) {
      attempts = attempts + 1;
      if (0 < attempts) break;
      sys_ddr_phy_write_field(phy, 0x54, 8, 3, 1);
      sys_ddr_phy_write_field(phy, 0x54, 8, 3, 0);
    }
    else if (result == 3) {
      continue;
    }
    else {
      break;
    }
  }
  return result;
}
