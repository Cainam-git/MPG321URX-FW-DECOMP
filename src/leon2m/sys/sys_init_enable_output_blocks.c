/* sys_init_enable_output_blocks  (FUN_a015202c)
 *
 * Run the output-block reset and enable the twelve sub-blocks.
 * Name basis: descriptive - startup_reset_output_blocks, then twelve setters with argument 1; called from
 *   System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015202c @ 0xa015202c (-mcpu=v8 -O2 -g, the section default).
 * Source form: the decompiler's type names and the six parameters are kept; the last call passes the five
 * parameters after the first on.
 */
typedef unsigned int undefined4;

extern int startup_reset_output_blocks();
extern int sys_enable_unit_e9e8();
extern int sys_enable_unit_e9e8_with_bit4();
extern int sys_enable_unit_6800_n0();
extern int sys_enable_unit_6800_n1();
extern int sys_enable_unit_6800_n2();
extern int sys_enable_unit_6800_n3();
extern int sys_enable_unit_6800_n4();
extern int sys_enable_unit_7400_n0();
extern int sys_enable_unit_7400_n1();
extern int sys_enable_unit_7400_n2();
extern int sys_enable_unit_7400_n3();
extern int sys_enable_unit_6a80();

/*
 * Write the fixed start values of the output block registers (startup_reset_output_blocks), then switch on, with
 * argument 1, the four units at 0xCF017400, the five units at 0xCF016800, the unit at 0xCF00E9E8 (both forms) and
 * the unit at 0xCF016A80.
 *
 * Called from System_Initialize (System_Initialize). The parameters are not used here; the last one of the calls gets
 * parameters 2 to 6.
 */
void sys_init_enable_output_blocks(undefined4 unused_1,undefined4 unused_2,undefined4 unused_3,undefined4 unused_4,
                 undefined4 unused_5,undefined4 unused_6)

{
  startup_reset_output_blocks();
  sys_enable_unit_7400_n0(1);
  sys_enable_unit_7400_n1(1);
  sys_enable_unit_7400_n2(1);
  sys_enable_unit_7400_n3(1);
  sys_enable_unit_6800_n0(1);
  sys_enable_unit_6800_n1(1);
  sys_enable_unit_6800_n2(1);
  sys_enable_unit_6800_n3(1);
  sys_enable_unit_6800_n4(1);
  sys_enable_unit_e9e8(1);
  sys_enable_unit_e9e8_with_bit4(1);
  sys_enable_unit_6a80(1,unused_2,unused_3,unused_4,unused_5,unused_6);
  return;
}
