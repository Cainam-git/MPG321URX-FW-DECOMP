/* sys_ddr_speed_to_tccd_index  (FUN_a00ee188)
 *
 * Convert a DDR speed to its tCCD_L index 0..3.
 * Returns: index 0..3, or -1 for a speed above 2667
 * Name basis: proven - prints 'Error: Undefined MR6 tCCD_L for DDR speed = %d.' above 2667; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ee188 @ 0xa00ee188, flags -mcpu=v8 -O2 (no -g).
 * Source form: the decompiler's shape is kept: a chain of range tests that assigns the index as it goes, a second
 * unused parameter, and a return of CONCAT44(param_2, index), which truncates to the index.
 */
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern int dbg_printf();
extern int sys_ddr_print_step();
extern int sys_ddr_print_error_prefix();

/*
 * Convert a DDR speed to the tCCD_L index of mode register 6.
 *
 *   speed    up to 1333 gives 0, up to 1866 gives 1, up to 2400 gives 2, up to 2667 gives 3
 *   unused   not used
 *
 * A speed above 2667 prints "Error: Undefined MR6 tCCD_L for DDR speed" and returns -1.
 * Called by sys_ddr_set_vref (sys_ddr_set_vref).
 */
int sys_ddr_speed_to_tccd_index(int speed,unsigned int unused)

{
  unsigned int index;
  
  index = 0;
  if ((((0x535 < speed) && (index = 1, 0x74a < speed)) && (index = 2, 0x960 < speed)) &&
     (index = 3, 0xa6b < speed)) {
    index = 0xffffffff;
    sys_ddr_print_step();
    sys_ddr_print_error_prefix();
    dbg_printf("Error: Undefined MR6 tCCD_L for DDR speed = %d.\n",speed);
  }
  return CONCAT44(unused,index);
}
