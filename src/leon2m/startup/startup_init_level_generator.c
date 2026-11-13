/* startup_init_level_generator  (FUN_a0129b44)
 *
 * Load the table and start values of the level generator block.
 * Name basis: descriptive - 0x80-byte table from 0x1A3128, divider for 0x3C0, then the start level; called
 *   from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129b44 @ 0xa0129b44, flags -mcpu=v8 -O3 -g.
 * Source form: a straight call sequence; the last call, panel_level_gen_clear_ctrl_bit0, is a tail call.
 */
extern unsigned char panel_level_gen_levels[];
extern unsigned char panel_level_gen_level;
extern unsigned char panel_level_gen_target;
extern unsigned char panel_level_gen_min_level;
extern int panel_level_gen_set_ctrl_bit0();
extern int panel_level_gen_clear_ctrl_bit0();
extern int panel_level_gen_load_table();
extern void panel_level_gen_set_frequency();
extern void panel_level_gen_set_reg_104();
extern int panel_level_gen_set_reg_0c4();
extern int panel_level_gen_set_cc_bit5();
extern int panel_level_gen_set_d8_low4();
extern int panel_level_gen_set_level_pair();
extern int panel_level_gen_set_reg_108();
extern int panel_level_gen_set_f4_lower_field();
extern int panel_level_gen_set_fields_10c();
extern int panel_level_gen_set_reg_110();
extern int panel_level_gen_set_reg_114();
extern int panel_level_gen_set_bit6();
extern int panel_wait_sync_pulse();

/* Level generator settings written at start-up (the other registers are named by address in their routines). */
#define LEVEL_GEN_FREQUENCY 0x3c0           /* 960: frequency argument of panel_level_gen_set_frequency */
#define LEVEL_GEN_MODE      3               /* its mode argument */

/*
 * Bring the panel's level generator to its start state. Called once at start-up (System_Initialize).
 * Order:
 *   1. load the 128-byte table of rising level steps from ROM (panel_level_gen_levels);
 *   2. set the divider for frequency 960 with mode 3, then the fixed field values of the registers
 *      0xCF016104 (8, 0), 0xCF0160C4 (4, 1), bit 5 of 0xCF0160CC (0) and the low 4 bits of 0xCF0160D8 (0xF);
 *   3. start the RAM level (panel_level_gen_level) at the target (panel_level_gen_target) and write the level
 *      pair: the level register gets the byte at 0xA802CA03 (always 0x7E), its companion register 0xCF0160DC
 *      the target;
 *   4. set the remaining fields: 0xCF016108 (5, 5), the field of 0xCF0160F4 (2), 0xCF01610C (0, 1),
 *      0xCF016110 (0), 0xCF016114 (0) and the control register bit 6 (1);
 *   5. set bit 0 of the first control register, wait for one sync pulse of the panel, clear the bit again.
 * Nothing here can fail or wait except the one sync pulse wait at the end.
 */
void startup_init_level_generator(void)
{
  panel_level_gen_load_table(panel_level_gen_levels);
  panel_level_gen_set_frequency(LEVEL_GEN_FREQUENCY, LEVEL_GEN_MODE);
  panel_level_gen_set_reg_104(8,0);
  panel_level_gen_set_reg_0c4(4,1);
  panel_level_gen_set_cc_bit5(0);
  panel_level_gen_set_d8_low4(0xf);
  /* The RAM level starts at the target; the level register itself gets the fixed byte at 0xA802CA03. */
  panel_level_gen_level = panel_level_gen_target;
  panel_level_gen_set_level_pair(panel_level_gen_min_level, panel_level_gen_target);
  panel_level_gen_set_reg_108(5,5);
  panel_level_gen_set_f4_lower_field(2);
  panel_level_gen_set_fields_10c(0,1);
  panel_level_gen_set_reg_110(0);
  panel_level_gen_set_reg_114(0);
  panel_level_gen_set_bit6(1);
  /* Bit 0 of the first control register is high for exactly one sync pulse. */
  panel_level_gen_set_ctrl_bit0();
  panel_wait_sync_pulse();
  panel_level_gen_clear_ctrl_bit0();
  return;
}
