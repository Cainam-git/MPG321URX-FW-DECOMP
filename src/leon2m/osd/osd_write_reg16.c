/* osd_write_reg16  (FUN_a011919c)
 *
 * Write a 16-bit value to a register pair of menu layer 0 or 1.
 * Name basis: derived - low and high byte to two registers; layer base addresses from the table at 0xA8027AA8
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011919c @ 0xa011919c (-mcpu=v8 -O3 -g).
 * Source form: the two byte writes are in a static helper wr16 written as an inline helper; that gives the
 * original register order (plain inline code allocates the registers differently).
 */
/* Register n of the menu layers is the word at 0xCF000000 + 4 * n. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
extern unsigned short osd_layer_bases[2];       /* register number of the first register of each menu layer */

/* Write a 16-bit value as two registers: the low byte to register a, the high byte to register a + 1. */
static void wr16(unsigned int a, unsigned short v) { R(a) = (unsigned char)v; R(a + 1) = (unsigned char)(v >> 8); }

/*
 * Write a 16-bit value into registers (base + reg) and (base + reg + 1) of a menu layer, low byte first.
 *
 *   layer  0 or 1; any larger value is treated as 0
 *   reg    register number relative to the layer's base (osd_layer_bases[layer])
 *   value  the 16-bit value
 *
 * Callers: the output timing apply routine (panel_output_apply_timing, register 0x62, both layers) and FRCConfigPostFRC
 * (register 0x44, both layers).
 */
void osd_write_reg16(unsigned char layer, unsigned char reg, unsigned short value)
{
    if (layer > 1) layer = 0;
    wr16(osd_layer_bases[layer] + reg, value);
}
