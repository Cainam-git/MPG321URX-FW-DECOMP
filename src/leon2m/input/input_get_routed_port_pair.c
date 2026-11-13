/* input_get_routed_port_pair  (FUN_a00fe6c8)
 *
 * Return which pair of port codes the routing bits select.
 * Returns: port code
 * Name basis: descriptive - 0x51/0x61 or 0x71/0x81 from three register bits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fe6c8 @ 0xa00fe6c8, flags -mcpu=v8 -O3 -g.
 * Source form: one result variable, with the "bits clear" case tested first (== 0).
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Return the signal code that the routing registers select: 0x51 or 0x61 when bits 1 and 4 of 0xCF02DC04 are
 * both clear (bit 0 of 0xCF011750 chooses, 0 = 0x51), otherwise 0x71 or 0x81 (bit 0 of 0xCF011674 chooses,
 * 0 = 0x71). These are the registers input_setup_route_for_source writes. Called by input_csc_setup (where it
 * replaces the code 0xB1) and by input_port_list_append. */
unsigned char input_get_routed_port_pair(void)
{
    unsigned char code;

    if ((R(0xcf02dc04) & 0x12) == 0)
        code = ((R(0xcf011750) & 1) << 4) + 0x51;
    else
        code = ((R(0xcf011674) & 1) << 4) + 0x71;
    return code;
}
