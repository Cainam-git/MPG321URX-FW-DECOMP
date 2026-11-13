/* oled_power_reset_state  (FUN_a0127898)
 *
 * Clear the state record of the OLED power state machine.
 * Name basis: derived - record at 0xA802D896; byte +0x0F = 2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0127898 @ 0xa0127898-0xa01278e4 (19 words).
 * Source form: the fields are members of one structure (one base register for all stores). The order of the
 * stores (+0x16 last) decides the scheduler's order and which store fills the return delay slot.
 */
/* The state record of oled_power_task. Only the fields this routine touches are named by their offsets. */
struct oled_power_record {
    unsigned char state;                                   /* +0x00 */
    unsigned char step;                                    /* +0x01 */
    unsigned char byte_0x02, byte_0x03;
    unsigned short half_0x04, half_0x06;
    unsigned char byte_0x08, byte_0x09, byte_0x0a, byte_0x0b, byte_0x0c, byte_0x0d, byte_0x0e, byte_0x0f;
    unsigned char byte_0x10, byte_0x11, byte_0x12, byte_0x13;
    unsigned short half_0x14;
    unsigned char byte_0x16;
};
extern struct oled_power_record oled_power_state;

/*
 * Put the state record of the OLED power state machine (oled_power_task) back to its start values: state and
 * step 0, byte +0x0F = 2, every other field this routine knows 0. The fields +0x02..+0x05, +0x08 and +0x0E are
 * left as they are.
 */
void oled_power_reset_state(void)
{
    oled_power_state.state = 0;
    oled_power_state.byte_0x0f = 2;
    oled_power_state.step = 0;
    oled_power_state.byte_0x09 = 0;
    oled_power_state.byte_0x0a = 0;
    oled_power_state.byte_0x0b = 0;
    oled_power_state.half_0x06 = 0;
    oled_power_state.byte_0x0c = 0;
    oled_power_state.byte_0x0d = 0;
    oled_power_state.byte_0x10 = 0;
    oled_power_state.byte_0x12 = 0;
    oled_power_state.byte_0x11 = 0;
    oled_power_state.byte_0x13 = 0;
    oled_power_state.half_0x14 = 0;
    oled_power_state.byte_0x16 = 0;
}
