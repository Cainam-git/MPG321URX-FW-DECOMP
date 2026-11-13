/* sys_ddr_set_vref  (FUN_a00ee964)
 *
 * Set the reference voltage through mode register 6.
 * Name basis: proven - prints 'Error: vref_op %d.%d%% is neither in MR6 range 1 ...'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ee964 @ 0xa00ee964-0xa00eec44, flags -mcpu=v8 -O3 (no -g: the exact build needs it).
 * Source form the exact build depends on: the speed chain is written in place with value as the temporary (value
 * is set again later) and 'tccd_index = value;' keeps the copy; 'vref_centre +/- step * 65' is written in each arm
 * of the up test, without a separate variable; the two helpers are static.
 */
struct vref_row { unsigned char mr6_byte, percent, hundredths; };
extern struct vref_row sys_ddr_vref_table[];
extern int sys_ddr_vref_low_indexes[], sys_ddr_vref_high_indexes[];
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_phy_write(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_delay(unsigned int);

static int vref_hundredths(struct vref_row *row)
{
    return row->percent * 100 + row->hundredths;
}

static int vref_to_mr6(int value)
{
    if ((unsigned int)(value - 6000) <= 3250)
        return (value - 6000) / 65;
    if ((unsigned int)(value - 4500) <= 3250)
        return (value - 4500) / 65 | 0x40;
    return 0xff;
}

/*
 * Move the reference voltage of a memory interface to its trained centre plus or minus a number of steps and
 * send the result to the memory chips in mode register 6.
 *
 *   unit    memory interface number
 *   unused1, unused2, unused3   not used here
 *   speed   DDR speed: up to 1333 gives tCCD_L index 0, up to 1866 index 1, up to 2400 index 2, up to 2667
 *           index 3 (the same mapping as sys_ddr_speed_to_tccd_index); a larger speed prints
 *           "Undefined MR6 tCCD_L" and returns -1
 *   up      non-zero: add the steps to the centre, 0: subtract them
 *   step    number of steps, each 0.65 percent (65 hundredths of a percent)
 *
 * Returns 0, or -1 after printing the step and an error message.
 *
 * The centre is the mean of the percentages in sys_ddr_vref_table at the low and the high end of the passing
 * window that sys_ddr_train_vref stored for this interface (sys_ddr_vref_low_indexes / _high_indexes). Both the
 * centre and the shifted value must fall in mode register 6 range 1 (60 to 92.5 percent) or range 2 (45 to 77.5
 * percent, flagged by 0x40); otherwise register 0x28E is set to 0xFF and the "vref_op" error is printed. The
 * accepted value is also written to register 0x28E (with bit 7). The mode register 6 command is sent three times:
 * tCCD_L index with bit 7, then with the value and bit 7, then with the value alone, with a delay of 1 after the
 * first and the last.
 */
int sys_ddr_set_vref(unsigned int unit, unsigned int unused1, unsigned int unused2, unsigned int unused3, int speed, int up, int step)
{
    int tccd_index, vref_centre, value, mr6_value;

    /* Which tCCD_L index the speed gives. */
    if (speed <= 1333)
        value = 0;
    else if (speed <= 1866)
        value = 1;
    else if (speed <= 2400)
        value = 2;
    else if (speed <= 2667)
        value = 3;
    else {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: Undefined MR6 tCCD_L for DDR speed = %d.\n", speed);
        return -1;
    }
    tccd_index = value;
    /* The centre of the passing window, in hundredths of a percent. */
    vref_centre = (vref_hundredths(&sys_ddr_vref_table[sys_ddr_vref_low_indexes[unit]]) + vref_hundredths(&sys_ddr_vref_table[sys_ddr_vref_high_indexes[unit]])) >> 1;
    if (up)
        value = vref_centre + step * 65;
    else
        value = vref_centre - step * 65;
    /* The shifted value as a mode register 6 field; 0xFF means it is in neither range. */
    mr6_value = vref_to_mr6(value);
    if (mr6_value == 0xff) {
        sys_ddr_phy_write(unit, 0x28e, 0xff);
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: vref_op %d.%d%% is neither in MR6 range 1 (60%% - 92.5%%), nor in MR6 range 2 (45%% - 77.5%%).\n", value / 100, value % 100);
        return -1;
    }
    if (vref_to_mr6(vref_centre) == 0xff) {
        sys_ddr_phy_write(unit, 0x28e, 0xff);
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: vref_op %d.%d%% is neither in MR6 range 1 (60%% - 92.5%%), nor in MR6 range 2 (45%% - 77.5%%).\n", vref_centre / 100, vref_centre % 100);
        return -1;
    }
    /* Record the value in register 0x28E, then send the three mode register 6 commands. */
    sys_ddr_phy_write(unit, 0x28e, mr6_value | 0x80);
    sys_ddr_send_mode_register(unit, 6, 6, (tccd_index << 10) | 0x80);
    sys_ddr_delay(1);
    sys_ddr_send_mode_register(unit, 6, 6, (tccd_index << 10) | mr6_value | 0x80);
    sys_ddr_send_mode_register(unit, 6, 6, (tccd_index << 10) | mr6_value);
    sys_ddr_delay(1);
    return 0;
}
