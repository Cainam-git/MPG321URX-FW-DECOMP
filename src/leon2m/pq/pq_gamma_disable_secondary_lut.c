/* pq_gamma_disable_secondary_lut  (FUN_a010af50)
 *
 * Switch the secondary gamma look-up table off.
 * Name basis: derived - bit 3 of 0xCF00EAC8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010af50 @ 0xa010af50, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a single assignment that ANDs the register with 0xfffffff7.
 */
#define reg_pq_gamma_lut_control (*(volatile unsigned int *)0xcf00eac8)

#define SECONDARY_LUT_ENABLE_BIT 0x08   /* bit 3: secondary LUT on */

/*
 * Switch the secondary gamma look-up table off: clear bit 3 (SECONDARY_LUT_ENABLE_BIT) of the gamma LUT control
 * register (0xCF00EAC8). Bit 7 of the register is the primary LUT on bit, bit 6 an option, bit 0 the first
 * preset-curve stage.
 *
 * Callers: FGA_Init, pq_fga_handle_command, pq_load_gamma and pq_api_enable_secondary_gamma_lut.
 */
void pq_gamma_disable_secondary_lut(void)

{
  reg_pq_gamma_lut_control = reg_pq_gamma_lut_control & 0xfffffff7;
  return;
}
