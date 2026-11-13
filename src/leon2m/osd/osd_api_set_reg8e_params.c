/* osd_api_set_reg8e_params  (FUN_a01465a0)
 *
 * Program the parameter registers 0x8E/0x8F of a menu layer.
 * Name basis: descriptive - forwards to osd_set_reg8e_params; fifth argument limited to 1..3, else 0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01465a0 @ 0xa01465a0-0xa0146648 (42 words), flags -mcpu=v8 -O3 -g.
 * The firmware tests the mode with a compare tree (== 2, > 2, == 1) and has three copies of the tail call
 * sequence: one shared by e = 2 and e = 0, one for e = 3 and one for e = 1. The last word is the nop the compiler
 * places behind such a call sequence.
 * Source form: a switch with the cases in the order 3, 2, 1 and a default (cases in ascending order put 'mov 3'
 * after the '== 3' test instead of into the delay slot of the '> 2' branch; 'default' written first gives the same
 * bytes as this order); e is an unsigned char and the call masks it with & 3 (the firmware keeps 'and %g1, 3' in
 * each copy).
 */
extern void osd_set_reg8e_params(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e,
                         unsigned char layer);

/* Pass the five values and the menu layer (0 or 1) on to osd_set_reg8e_params. The fifth value, mode, is cut down
 * to 1, 2 or 3; any other value becomes 0. osd_set_reg8e_params ORs it into bits 6..7 of register 0xCF.
 * Nothing calls this routine and no stored address points at it. */
void osd_api_set_reg8e_params(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char mode,
                  unsigned char layer)
{
    unsigned char e;

    switch (mode) {
    case 3:
        e = 3;
        break;
    case 2:
        e = 2;
        break;
    case 1:
        e = 1;
        break;
    default:
        e = 0;
        break;
    }
    osd_set_reg8e_params(a, b, c, d, e & 3, layer);
}
