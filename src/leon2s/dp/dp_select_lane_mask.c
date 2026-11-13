/* dp_select_lane_mask  (FUN_a00af764)
 *
 * Select the lane mask of a port from its lane mapping.
 * Name basis: descriptive - mask 1, 2, 4 or 8 by the mapped pair; revision-dependent extra step
 *
 * Matching notes
 * --------------
 * FUN_a00af764 (leon2s, 0xa00af764-0xa00af858, 61 words). Flags -mcpu=v8 -Os -g.
 * Source form: the revision test is on the unsigned char return of sys_get_chip_revision (<= 0x81); unsigned
 * char prototypes; void: the only caller (DP_GetClrSpace) overwrites %o0 right after the call, and a version
 * returning the mask gives the same bytes.
 */
extern unsigned char sys_get_chip_revision(void);
extern unsigned char dp_map_port_lane_unit(unsigned char, unsigned char);
extern void audio_flag_dp_resync(unsigned int);
extern void timer_delay_long_units(unsigned int);
extern unsigned char dp_get_reg9f_field(unsigned char);

#define LANE_UNIT_REG (*(volatile unsigned int *)0xcf0124b8)    /* bits 0..3 are pulsed */

/*
 * Get the receiver unit of the port (dp_map_port_lane_unit with the port's field from register 0x9F). Units
 * 0-1 give mask 1, 2-3 give mask 2, 4-5 give mask 4, 6-7 give mask 8; other units give no mask. On a chip
 * revision of 0x81 or lower, for port 0 with register 0x9F field 0, also call audio_flag_dp_resync(1). When
 * there is a mask, set its bit in the register at 0xCF0124B8, wait one delay unit and clear the bit again.
 *   port: DP receiver (0 or 1)
 * Called from dp_run_link_state.
 */
void dp_select_lane_mask(unsigned char port)
{
    unsigned char unit;
    unsigned int mask;
    unsigned char mask_byte;

    unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));
    mask = 0xffffffff;
    if (unit < 2) {
        mask = 1;
    } else if ((unsigned char)(unit - 2) < 2) {
        mask = 2;
    } else if ((unsigned char)(unit - 4) < 2) {
        mask = 4;
    } else if ((unsigned char)(unit - 6) < 2) {
        mask = 8;
    }
    if (sys_get_chip_revision() <= 0x81 && port == 0 && dp_get_reg9f_field(0) == 0)
        audio_flag_dp_resync(1);
    mask_byte = mask;
    if (mask_byte != 0xff) {
        LANE_UNIT_REG = LANE_UNIT_REG | mask_byte;
        timer_delay_long_units(1);
        LANE_UNIT_REG = LANE_UNIT_REG & ~mask_byte;
    }
}
