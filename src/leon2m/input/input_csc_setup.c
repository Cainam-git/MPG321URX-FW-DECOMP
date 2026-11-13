/* input_csc_setup  (FUN_a01012a8)
 *
 * Work out the colour format of a port and program the conversion for it.
 * Name basis: derived - format code from the signal, then a 3x5 coefficient table and the mode registers
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01012a8 @ 0xa01012a8-0xa01016a4 (1020 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: input_block_get_capture_hstart / _vstart are declared with one
 * parameter and an unsigned short result (they return 12 and 11 masked bits); separate else-ifs for 0x71 and
 * 0x81 (and for 0x51/0x61 and 0x31/0x41) although they do the same; the 1920x1080 / 1280x720 test is written
 * out twice; the three tables are extern array symbols copied into three locals, and the 9-halfword matrix is
 * declared after the three copies.
 */
extern unsigned char input_csc_option_byte, input_csc_format_code;
extern unsigned int input_csc_selector;
extern unsigned char input_block_get_signal_code(unsigned char blk);
extern unsigned char input_get_routed_port_pair(void);
extern unsigned short input_block_get_capture_hstart(unsigned int);
extern unsigned short input_block_get_capture_vstart(unsigned int);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);
extern void input_csc_write_range_values(unsigned char port);
extern void input_csc_write_mode_regs(unsigned char blk);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void timer_sleep_ticks(int);
extern const unsigned short input_csc_table_first[], input_csc_table_second[], input_csc_table_third[];

#define SELECTOR_BY_SIGNAL  1       /* input_csc_selector: take the colour format code from the signal code */
#define SELECTOR_FIXED      2       /* input_csc_selector: colour format code 1 */

/* Capture block registers written here. */
#define CAPTURE_REG_1       0x01    /* 0x24 or 1 for signal code 0x21 */
#define CAPTURE_REG_F2      0xf2    /* bit 2: set at the end of the table load; bit 3 cleared before it */
#define CAPTURE_REG_F3      0xf3
#define CAPTURE_REG_F4      0xf4    /* row number of the table row written to registers 0xf5..0xfd */

#define TABLE_ROWS          3
#define TABLE_BYTES         0x1e    /* 3 rows of 5 halfwords */

/*
 * Choose the colour format code of a port's signal and program the colour conversion for it.
 *
 *   unused1, unused3  not read
 *   port              input block (and picture block) to program
 *   format_code_hint  the colour format code that the port record keeps for this port (byte 0x28 of the port
 *                     record, as passed by input_channel_bring_up_task through input_csc_setup_with_selector)
 *
 * Step 1: the format code (input_csc_format_code) is chosen by the selector input_csc_selector.
 *   Selector 1: by the signal code of the block (taken from input_get_routed_port_pair when the block's own code
 *   is 0xB1). The codes 0x31, 0x41, 0x51, 0x61, 0x71 and 0x81 take over format_code_hint. Code 0x21 sets
 *   capture register 1 to 0x24 when the capture start values are 0x780 / 0x438 or 0x500 / 0x2d0 (1920 / 1080
 *   and 1280 / 720 as numbers), otherwise to 1; after 0x14 ticks the format code is 9 for those two pairs and 3
 *   for all others. Every other signal code gives format code 1.
 *   Selector 2: format code 1.
 *   Any other selector: the format code is input_csc_option_byte.
 * Step 2: input_csc_write_range_values for ports 0..3 and input_csc_write_mode_regs for ports 0..4; then
 * capture registers 0xf2 and 0xf3 of the port are cleared.
 * Step 3: only for port 0 and format codes 0x1c..0x27: the first 3 x 5 table (input_csc_table_first) is loaded
 * into capture block 0 as three rows, each row written to registers 0xf5, 0xf7, 0xf9, 0xfb and 0xfd after its row
 * number in register 0xf4, between clearing bits 2 and 3 of register 0xf2 and setting bit 2 again. The second
 * and third table and the 9-halfword matrix are copied or initialised but not used.
 *
 * Called by input_csc_setup_with_selector.
 */
void input_csc_setup(unsigned int unused1, unsigned char port, unsigned int unused3, unsigned char format_code_hint)
{
    unsigned char signal_code;
    unsigned short hstart, vstart;
    unsigned char row;
    unsigned short table_first[3][5];
    unsigned short table_second[3][5];
    unsigned short table_third[3][5];

    signal_code = input_block_get_signal_code(port);
    if (signal_code == 0xb1)
        signal_code = input_get_routed_port_pair();
    if (input_csc_selector == SELECTOR_BY_SIGNAL) {
        if (signal_code == 0x31 || signal_code == 0x41)
            input_csc_format_code = format_code_hint;
        else if (signal_code == 0x51 || signal_code == 0x61)
            input_csc_format_code = format_code_hint;
        else if (signal_code == 0x21) {
            hstart = input_block_get_capture_hstart(port);
            vstart = input_block_get_capture_vstart(port);
            if ((hstart == 0x780 && vstart == 0x438) || (hstart == 0x500 && vstart == 0x2d0))
                input_capture_write8(port, CAPTURE_REG_1, 0x24);
            else
                input_capture_write8(port, CAPTURE_REG_1, 1);
            timer_sleep_ticks(0x14);
            if ((hstart == 0x780 && vstart == 0x438) || (hstart == 0x500 && vstart == 0x2d0))
                input_csc_format_code = 9;
            else
                input_csc_format_code = 3;
        } else if (signal_code == 0x71)
            input_csc_format_code = format_code_hint;
        else if (signal_code == 0x81)
            input_csc_format_code = format_code_hint;
        else
            input_csc_format_code = 1;
    } else if (input_csc_selector == SELECTOR_FIXED)
        input_csc_format_code = 1;
    else
        input_csc_format_code = input_csc_option_byte;
    if (port < 4)
        input_csc_write_range_values(port);
    if (port < 5)
        input_csc_write_mode_regs(port);
    input_capture_write8(port, CAPTURE_REG_F2, 0);
    input_capture_write8(port, CAPTURE_REG_F3, 0);
    /* format codes 0x1c..0x21 and 0x22..0x27 */
    if (port == 0 && ((unsigned char)(input_csc_format_code - 0x22) < 6 || input_csc_format_code == 0x1c || input_csc_format_code == 0x1d
                      || input_csc_format_code == 0x1e || input_csc_format_code == 0x1f || input_csc_format_code == 0x20
                      || input_csc_format_code == 0x21)) {
        memcpy(table_first, input_csc_table_first, TABLE_BYTES);
        memcpy(table_second, input_csc_table_second, TABLE_BYTES);
        memcpy(table_third, input_csc_table_third, TABLE_BYTES);
        unsigned short unused_matrix[9] = {0x1000, 0, 0, 0x4633, 0x1799, 0x4166, 0, 0, 0x1000};
        input_capture_update_bits(0, CAPTURE_REG_F2, 4, 0);
        input_capture_update_bits(0, CAPTURE_REG_F2, 8, 0);
        input_capture_write8(0, CAPTURE_REG_F2, 1);
        input_capture_write8(0, CAPTURE_REG_F3, 1);
        for (row = 0; row < TABLE_ROWS; row++) {
            input_capture_write8(0, CAPTURE_REG_F4, row);
            input_capture_write16(0, 0xf5, table_first[row][0]);
            input_capture_write16(0, 0xf7, table_first[row][1]);
            input_capture_write16(0, 0xf9, table_first[row][2]);
            input_capture_write16(0, 0xfb, table_first[row][3]);
            input_capture_write16(0, 0xfd, table_first[row][4]);
        }
        input_capture_update_bits(0, CAPTURE_REG_F2, 4, 1);
    }
}
