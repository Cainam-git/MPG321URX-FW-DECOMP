/* panel_output_set_window_mode  (FUN_a0106294)
 *
 * Write 9 or 0 to the output window mode register.
 * Name basis: descriptive - register 0xCF00EC00; unused
 *
 * Matching notes
 * --------------
 * FUN_a0106294, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
#define OUTPUT_WINDOW_MODE_REG (*(volatile unsigned int *)0xcf00ec00)

/* Write 9 to register 0xcf00ec00 when on is 1, otherwise 0. */
void panel_output_set_window_mode(unsigned char on)
{
    if (on == 1)
        OUTPUT_WINDOW_MODE_REG = 9;
    else
        OUTPUT_WINDOW_MODE_REG = 0;
}
