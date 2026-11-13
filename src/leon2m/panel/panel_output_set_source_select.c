/* panel_output_set_source_select  (FUN_a01061c0)
 *
 * Write the source select value 0, 1, 2, 4 or 0x10 of the output stage.
 * Name basis: descriptive - register 0xCF00ED80 for selector 0..4
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01061c0, flags -mcpu=v8 -O3 -g. Jump table over the five cases.
 */
#define OUTPUT_SOURCE_SELECT_REG (*(volatile unsigned int *)0xcf00ed80)

/*
 * Write the register value that belongs to selector sel:
 *
 *   sel     0   1   2   3   4
 *   value   0   1   2   4   0x10
 *
 * Any other sel leaves the register unchanged. panel_output_get_source_select reads the same register back
 * as the selector. Called from sys_mode_restart_channel (with 0).
 */
void panel_output_set_source_select(unsigned char sel)
{
    switch (sel) {
    case 0:
        OUTPUT_SOURCE_SELECT_REG = 0;
        break;
    case 1:
        OUTPUT_SOURCE_SELECT_REG = 1;
        break;
    case 2:
        OUTPUT_SOURCE_SELECT_REG = 2;
        break;
    case 3:
        OUTPUT_SOURCE_SELECT_REG = 4;
        break;
    case 4:
        OUTPUT_SOURCE_SELECT_REG = 0x10;
        break;
    }
}
