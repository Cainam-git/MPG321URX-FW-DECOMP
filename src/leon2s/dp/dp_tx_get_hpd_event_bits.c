/* dp_tx_get_hpd_event_bits  (FUN_a0083710)
 *
 * Return the three event bits recorded for a link output.
 *   sel: output
 * Name basis: descriptive - 3-bit groups of the event word filled by dp_tx_update_hpd_status
 *
 * Matching notes
 * --------------
 * FUN_a0083710 (leon2s 0xa0083710-0xa0083870, leaf), flags -mcpu=v8 -Os -g.
 * The switch compiles to a jump table; the bits are tested one by one with the result built as 1, then | 2, then | 4.
 */
extern unsigned char dp_tx_output_map;
extern unsigned int dp_tx_hpd_event_bits;

/*
 * Return the hot-plug event bits recorded for one link output as a 3-bit value (bit 0 = first bit of the group,
 * bit 1 = second, bit 2 = third; groups 5 and 6 have two bits only).
 *
 *   sel  output number. 0 is read directly; 1..4 is first translated through dp_tx_output_map (2 bits per output,
 *        field value + 1), so the result of the translation is a group number 1..4; 5 and 6 are also groups.
 *        Any other value returns 0.
 *
 * The groups of dp_tx_hpd_event_bits: 0: bits 0..2, 1: bits 3..5, 2: bits 6..8, 3: bits 13..15, 4: bits 16..18,
 * 5: bits 9..10, 6: bits 11..12.
 */
unsigned char dp_tx_get_hpd_event_bits(int sel)
{
    unsigned char r = 0;

    /* Outputs 1..4 are looked up in the output map to find their group. */
    if ((unsigned int)(sel - 1) <= 3)
        sel = ((dp_tx_output_map >> (sel * 2 - 2)) & 3) + 1;
    switch (sel) {
    case 0:
        if (dp_tx_hpd_event_bits & 1)
            r = 1;
        if (dp_tx_hpd_event_bits & 2)
            r |= 2;
        if (dp_tx_hpd_event_bits & 4)
            r |= 4;
        break;
    case 1:
        if (dp_tx_hpd_event_bits & 8)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x10)
            r |= 2;
        if (dp_tx_hpd_event_bits & 0x20)
            r |= 4;
        break;
    case 2:
        if (dp_tx_hpd_event_bits & 0x40)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x80)
            r |= 2;
        if (dp_tx_hpd_event_bits & 0x100)
            r |= 4;
        break;
    case 3:
        if (dp_tx_hpd_event_bits & 0x2000)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x4000)
            r |= 2;
        if (dp_tx_hpd_event_bits & 0x8000)
            r |= 4;
        break;
    case 4:
        if (dp_tx_hpd_event_bits & 0x10000)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x20000)
            r |= 2;
        if (dp_tx_hpd_event_bits & 0x40000)
            r |= 4;
        break;
    case 5:
        if (dp_tx_hpd_event_bits & 0x200)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x400)
            r |= 2;
        break;
    case 6:
        if (dp_tx_hpd_event_bits & 0x800)
            r = 1;
        if (dp_tx_hpd_event_bits & 0x1000)
            r |= 2;
        break;
    }
    return r;
}
