/* panel_layer4_enable  (FUN_a010d874)
 *
 * Switch the fourth layer on in both output halves.
 * Name basis: descriptive - bit 0 of 0xD0032000 / 0xD003A000; unused
 *
 * Matching notes
 * --------------
 * FUN_a010d874, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 */
/* Fourth-layer control register of the first and second output half; bit 0 switches it on. */
#define LAYER4_CTRL_HALF0 (*(volatile unsigned int *)0xd0032000)
#define LAYER4_CTRL_HALF1 (*(volatile unsigned int *)0xd003a000)

/* Set bit 0 of the fourth-layer control register in both output halves. */
void panel_layer4_enable(void)
{
    LAYER4_CTRL_HALF0 |= 1;
    LAYER4_CTRL_HALF1 |= 1;
}
