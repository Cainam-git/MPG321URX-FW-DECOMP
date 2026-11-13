/* dp_update_reg46_bit2  (FUN_a00b0138)
 *
 * Compare hactive and the 0x8B/0x8C value with two listed pairs and update bit 2 of register 0x46.
 * Returns: 0 or 1
 * Name basis: descriptive - loop with one shared result
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0138 @ 0xa00b0138-0xa00b0248 (68 words), flags -mcpu=v8 -Os -g.
 * Source form: one shared return of 'changed' (early returns let gcse fold changed = 0 into each exit; the
 * firmware keeps the value live and returns it ANDed with 1 in three delay slots); an int parameter with an
 * unsigned char copy 'port'; the clear arm still uses the masked unsigned int parameter ('and %i0,0xff,%i0');
 * unsigned char callee prototypes; lib_memcpy declared returning void *.
 */
extern const unsigned short dp_lane_table_defaults[];   /* two pairs {hactive, divider}: {0x2D0, 0x240}, {0xFFFF, 0xFFFF} */
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned short dp_get_hactive(unsigned char);
extern unsigned short dp_get_vactive(unsigned char);
extern void *lib_memcpy(void *, const void *, unsigned int);

#define LANE_TABLE_ENTRIES 2

/*
 * Compare the horizontal active width (dp_get_hactive) and the 16-bit clock registers 0x8B / 0x8C
 * (dp_get_vactive) of the port with the two pairs in dp_lane_table_defaults. When they equal one pair,
 * clear bit 2 of register 0x46 if it is set; when they equal none, set bit 2 of register 0x46 if it is clear.
 * Return 1 when register 0x46 was changed, else 0.
 *   port_arg: DP receiver (0 or 1)
 * Called from dp_run_link_state, which goes back to the power-on state when the result is 1.
 */
unsigned char dp_update_reg46_bit2(unsigned int port_arg)
{
    unsigned short table[4];
    unsigned char port;
    unsigned short hactive, divider;
    unsigned char changed;
    unsigned char found;
    unsigned char i;

    lib_memcpy(table, dp_lane_table_defaults, 8);
    port = port_arg;
    hactive = dp_get_hactive(port);
    divider = dp_get_vactive(port);
    changed = 0;
    found = 0;
    for (i = 0; i <= LANE_TABLE_ENTRIES - 1; i++) {
        if (hactive == table[i * 2] && divider == table[i * 2 + 1]) {
            found = 1;
            break;
        }
    }
    if (found == 1) {
        if (dp_reg_read8(port, 0x46) & 4) {
            dp_reg_update_bits(port, 0x46, 4, 0);
            changed = 1;
        }
    } else if (found == 0) {
        if ((dp_reg_read8(port_arg, 0x46) & 4) == 0) {
            dp_reg_update_bits(port_arg, 0x46, 4, 1);
            changed = 1;
        }
    }
    return changed & 1;
}
