/* panel_layers_are_enabled  (FUN_a010b948)
 *
 * Return whether the layer stage is switched on.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 0 of 0xD0030004; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b948, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: r = 0; if (bit set) r = 1; return r & 1 (the 'and 1' sits in the return delay slot).
 */
/* Layer stage control register of the first output half; bit 0 is the on/off bit. */
#define LAYER_CTRL_HALF0 (*(volatile unsigned int *)0xd0030004)

/* Return bit 0 of the first half's layer control register (the second half is not read). */
unsigned char panel_layers_are_enabled(void)
{
    unsigned char enabled = 0;

    if (LAYER_CTRL_HALF0 & 1)
        enabled = 1;
    return enabled & 1;
}
