/* power_apply_cut_list  (FUN_CODE_a142)
 *
 * Switch the pins listed in the power-cut table for one phase.
 *   half: phase
 * Name basis: derived - entries 0xA6AF (CutPwArray, message type 10) through gpio_set_port_bits with delays;
 *   callers power-saving, power-off, resume
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a142 @ 0xa142 (188 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: i 0xA4B4, entry 0xA4B5..0xA4B6, delay 0xA4B7..0xA4B8, first 0xA4B9; port in R7.
 * volatile: the firmware reads entry[0] and entry[1] back after storing them (Keil does not keep a value read from
 *   a volatile object in A), as for the other standby tables.
 * Source form: the range test assigns port ('(port = entry[0] + 0xf0) < 0x0f'), the first call argument, and the
 *   entry is handled in the then-block with 'else break;'.
 */
/* One entry of the power-cut table (message type 10 from the main processor, 'CutPwArray'). */
struct cut_entry {
    unsigned char pin;     /* 0x10 + GPIO port; a value outside 0x10..0x1E ends the half */
    unsigned char bit_level;  /* bits 0..3: bit of the port, bit 4: level written */
    unsigned char delay;   /* wait after the write, in units of 10 ticks */
};
extern volatile struct cut_entry xdata power_cut_table[6];
void gpio_set_port_bits(unsigned char n, unsigned char mask, unsigned char v);
void timer_delay_ticks(unsigned int t);

#define CUT_LIST_FIRST_HALF  1     /* entries 0..2; any other value: entries 3..5 */
#define CUT_LIST_HALF        3
#define KEY_GPIO_BIT         0x0f
#define KEY_GPIO_LEVEL       0x10

/*
 * power_apply_cut_list - drive the pins of one half of the power-cut table, waiting after each.
 *   half  CUT_LIST_FIRST_HALF (1) = entries 0..2, else entries 3..5
 * Each entry sets its GPIO bit to its level, then waits delay * 10 ticks; an entry whose pin byte is not
 * 0x10..0x1E ends the half.
 * Callers: power_setup_power_saving and power_off_sequence (first half), power_leave_power_saving (second half).
 */
void power_apply_cut_list(unsigned char half)
{
    unsigned char i, entry[2];
    unsigned int delay;
    unsigned char first;
    unsigned char port;

    if (half == CUT_LIST_FIRST_HALF) first = 0;
    else first = CUT_LIST_HALF;
    for (i = first; i < first + CUT_LIST_HALF; i++) {
        entry[0] = power_cut_table[i].pin;
        if ((port = entry[0] + 0xf0) < 0x0f) {
            entry[1] = power_cut_table[i].bit_level;
            delay = power_cut_table[i].delay;
            gpio_set_port_bits(port, 1 << (entry[1] & KEY_GPIO_BIT), (entry[1] & KEY_GPIO_LEVEL) >> 4);
            timer_delay_ticks(delay * 10);
        } else break;
    }
}
