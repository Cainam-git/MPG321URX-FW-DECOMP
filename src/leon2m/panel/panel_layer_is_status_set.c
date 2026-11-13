/* panel_layer_is_status_set  (FUN_a010b96c)
 *
 * Return whether a layer's status bit is set in either output half.
 * Returns: 0 or 1
 * Name basis: descriptive - status bit selected by the layer; unused
 *
 * Matching notes
 * --------------
 * FUN_a010b96c, flags -mcpu=v8 -O3 -g. Leaf. Nothing in the image calls or points to it.
 * Source form: a flag for channel > 2 (then channel -= 3), a switch for the low group, 'result != 0' as the return.
 */
/* Layer control registers (first and second output half) of the three channels, and of the fourth layer. */
#define LAYER_CTRL_HALF0   (*(volatile unsigned int *)0xd0030004)
#define LAYER_CTRL_HALF1   (*(volatile unsigned int *)0xd0038004)
#define LAYER4_CTRL_HALF0  (*(volatile unsigned int *)0xd0032000)
#define LAYER4_CTRL_HALF1  (*(volatile unsigned int *)0xd003a000)

/*
 * Return 1 when a status bit is set in the first or the second output half, else 0.
 *
 *   index 0, 1, 2   bit 1, 2 or 3 of the layer control registers (0xD0030004 / 0xD0038004)
 *   index 3 and up  bit 2 for index 4, bit 1 for every other index, of 0xD0032000 / 0xD003A000
 *
 * Bit 0 of the same registers is the on/off bit set by panel_layers_enable and panel_layer4_enable.
 * Nothing calls this routine.
 */
int panel_layer_is_status_set(unsigned char index)
{
    unsigned char fourth_layer = 0, found = 0;

    if (index > 2) {
        index -= 3;
        fourth_layer = 1;
    }
    if (fourth_layer) {
        if (index == 1) {
            if ((LAYER4_CTRL_HALF0 & 4) || (LAYER4_CTRL_HALF1 & 4))
                found = 1;
        } else {
            if ((LAYER4_CTRL_HALF0 & 2) || (LAYER4_CTRL_HALF1 & 2))
                found = 1;
        }
    } else {
        switch (index) {
        case 0:
            if ((LAYER_CTRL_HALF0 & 2) || (LAYER_CTRL_HALF1 & 2))
                found = 1;
            break;
        case 1:
            if ((LAYER_CTRL_HALF0 & 4) || (LAYER_CTRL_HALF1 & 4))
                found = 1;
            break;
        case 2:
            if ((LAYER_CTRL_HALF0 & 8) || (LAYER_CTRL_HALF1 & 8))
                found = 1;
            break;
        }
    }
    return found != 0;
}
