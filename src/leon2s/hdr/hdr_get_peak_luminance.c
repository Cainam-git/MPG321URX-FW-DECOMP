/* hdr_get_peak_luminance  (FUN_a00d3ef0)
 *
 * Return the stored peak luminance.
 * Returns: value
 * Name basis: derived - word at 0xA80779DC; read by hdr_init_hdr10plus
 *
 * Matching notes
 * --------------
 * FUN_a00d3ef0 (leon2s 0xa00d3ef0-0xa00d3efc, 12 bytes, leaf), flags -mcpu=v8 -Os -g.
 * It lies in the code range 0xa00d3eb0-0xa00d3fa0 that is followed by the unreferenced data 0xa00d3fa0-0xa00d649c
 * (byte tables and '[HDR]' format strings).
 */
extern unsigned short hdr_peak_luminance;

/* Return the peak luminance stored by hdr_set_peak_luminance. hdr_init_hdr10plus multiplies it by 10. */
unsigned short hdr_get_peak_luminance(void)
{
    return hdr_peak_luminance;
}
