/* dbg_get_dithering_off_mode2_flag  (FUN_a00dd6b0)
 *
 * Return the flag that dbg_switch_dithering sets when it switched dithering off with mode 2.
 * Returns: byte
 * Name basis: derived - byte at 0xA802B0AE (dbg_dithering_off_mode2_flag); unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd6b0 @ 0xa00dd6b0-0xa00dd6bc, 12 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: a direct read of the extern symbol (sethi %hi + load with the %lo offset in the retl delay slot).
 */
extern unsigned char dbg_dithering_off_mode2_flag;

/* Return the byte dbg_dithering_off_mode2_flag. Nothing in the image calls this routine or stores its address. */
unsigned char dbg_get_dithering_off_mode2_flag(void)
{
    return dbg_dithering_off_mode2_flag;
}
