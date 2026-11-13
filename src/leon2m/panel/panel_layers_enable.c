/* panel_layers_enable  (FUN_a010b8e8)
 *
 * Switch the layer stage of both output halves on.
 * Name basis: descriptive - bit 0 of 0xD0030004 / 0xD0038004; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b8e8, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
/* Layer stage control register of the first and second output half; bit 0 switches it on. */
#define LAYER_CTRL_HALF0 (*(volatile unsigned int *)0xd0030004)
#define LAYER_CTRL_HALF1 (*(volatile unsigned int *)0xd0038004)

/* Set bit 0 of the layer control register in both output halves. */
void panel_layers_enable(void)
{
    LAYER_CTRL_HALF0 |= 1;
    LAYER_CTRL_HALF1 |= 1;
}
