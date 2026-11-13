/* osd_reset_layer  (FUN_a01195ac)
 *
 * Reset a menu layer: clear bit 7 of its first register, wait for a frame and restart it.
 * Name basis: descriptive - panel_wait_sync_pulse, register 0xCE = 0, bit 0 of register 0xCF, then a delay
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01195ac @ 0xa01195ac, flags -mcpu=v8 -O3 -g.
 * Source form: the helpers osd_update_reg_bits and wr8 are defined in this file because the compiler inlines
 * them at -O3; the final delay call is a tail call.
 */
/* Register n of the menu layers is the word at 0xCF000000 + 4 * n. */
#define R(a) (*(volatile unsigned int *)(0xcf000000 | ((a) << 2)))
#define REG_ENABLE        0                     /* first register of a layer; bit 7 is cleared by the reset */
#define REG_ENABLE_BIT    0x80
#define REG_CE            0xce                  /* written with 0 */
#define REG_CF            0xcf                  /* bit 0 is set */
#define RESET_DELAY       0x28                  /* argument of the final delay call */

extern unsigned short osd_layer_bases[2];       /* register number of the first register of each menu layer */
extern void panel_wait_sync_pulse(void);
extern void timer_sleep_ticks(int ms);

/* Set or clear the bits of mask in one register of a layer (no range check on the layer). */
void osd_update_reg_bits(unsigned char layer, unsigned char reg, unsigned int mask, unsigned char set)
{
    unsigned int value = R(osd_layer_bases[layer] + reg);
    if (set == 1) value |= mask; else value &= ~mask;
    R(osd_layer_bases[layer] + reg) = (unsigned char)value;
}

/* Write a byte to a register of a layer; a layer above 1 is treated as 0. */
static void wr8(unsigned char layer, unsigned char reg, unsigned char value)
{
    if (layer > 1) layer = 0;
    R(osd_layer_bases[layer] + reg) = value;
}

/*
 * Reset a menu layer (0 or 1) through its registers: clear bit 7 of its first register, wait for one sync
 * pulse of the panel, write 0 to register 0xCE, set bit 0 of register 0xCF, then wait with the delay call
 * given 0x28. Called by osd_api_reset_layer.
 */
void osd_reset_layer(unsigned char layer)
{
    osd_update_reg_bits(layer, REG_ENABLE, REG_ENABLE_BIT, 0);
    panel_wait_sync_pulse();
    wr8(layer, REG_CE, 0);
    osd_update_reg_bits(layer, REG_CF, 1, 1);
    timer_sleep_ticks(RESET_DELAY);
}
