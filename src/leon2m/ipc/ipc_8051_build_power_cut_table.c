/* ipc_8051_build_power_cut_table  (FUN_a0133384)
 *
 * Fill the 18-byte power-cut table that is sent to the 8051.
 * Name basis: derived - four records of code, entry and delay; sent by ipc_8051_send_power_cut_table; its only
 *   caller sends the table as message type 10, which the 8051 program stores as its power-cut list
 *   (CutPwArray)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133384 @ 0xa0133384-0xa01334ec (90 words), -mcpu=v8 -O3 -g -msoft-float.
 * ipc_map_index_to_code_0x11 and ipc_pack_flag_and_bit_index are the routines of the same file, inlined here as
 * static copies, as in ipc_8051_build_fixed_wake_table.
 * Source forms the exact build depends on:
 *  - four copies of one block (code, entry, delay), each followed by the room test
 *    'if (pos + 2 >= sizeof(table)) return;'; pos is set to 0 after the clear loop and to 9 before the third
 *    record (GCC folds the positions and the tests);
 *  - the first two records stand in a 'while (1) { ...; break; }' block. The firmware stores record 2's entry
 *    (0xa0133448) after the table address and the value 5 are formed (0xa0133440, 0xa0133444) and keeps record 2's
 *    delay store (0xa013344c) in front of record 3's first instruction (0xa0133450). GCC 3.4 gives this order only
 *    when a loop statement ends between record 2's room test and 'pos = 9': the loop's notes are a scheduling
 *    barrier, the loop itself leaves no instruction. Without a loop GCC puts the entry store two instructions
 *    earlier; an 'if' there, a 'do { } while (0)' block, or room tests left by 'break' do not give the order.
 *    Not recoverable from the bytes: where the loop starts (around both records or only the second), whether it
 *    was written 'while (1)' or 'for (;;)', and why it was written; it is written here around the first group.
 */
#define POWER_CUT_TABLE_SIZE 18             /* six 3-byte records (code, entry, delay) */
#define GPIO_PORT_4          4

extern unsigned char ipc_8051_power_cut_table[POWER_CUT_TABLE_SIZE];

/* Code byte of a record: 0x10 + GPIO port for ports 1..13, 0x11 for port 18, 0 for every other port. */
static unsigned char ipc_map_index_to_code_0x11(unsigned char gpio_port)
{
    unsigned char code = 0;
    switch (gpio_port) {
    case 1:
        code = 0x11;
        break;
    case 2:
        code = 0x12;
        break;
    case 3:
        code = 0x13;
        break;
    case 4:
        code = 0x14;
        break;
    case 5:
        code = 0x15;
        break;
    case 6:
        code = 0x16;
        break;
    case 7:
        code = 0x17;
        break;
    case 8:
        code = 0x18;
        break;
    case 9:
        code = 0x19;
        break;
    case 10:
        code = 0x1a;
        break;
    case 11:
        code = 0x1b;
        break;
    case 12:
        code = 0x1c;
        break;
    case 13:
        code = 0x1d;
        break;
    case 18:
        code = 0x11;
        break;
    }
    return code & 0x1f;
}

/* Entry byte of a record: bit 4 = bit 0 of level, bits 0..3 = number of the highest set bit of pin_mask
   (8 when the mask is 0). */
static unsigned char ipc_pack_flag_and_bit_index(unsigned char pin_mask, unsigned char level)
{
    unsigned char entry;
    unsigned char bit;
    for (bit = 0; bit < 8; bit++)
        if ((pin_mask >> bit) == 1)
            break;
    entry = ((level & 1) << 4) | bit;
    return entry;
}

/*
 * Build ipc_8051_power_cut_table: six 3-byte records (code, entry, delay), of which four are filled.
 *
 * Called by ipc_8051_send_power_cut_table, which sends the table as message type 10. The 8051 stores it as its
 * power-cut list (CutPwArray, 0xA6AF) and power_apply_cut_list works through three records at a time: for each
 * one it sets (entry bit 4 = 1) or clears (0) pin 1 << (entry bits 0..3) in the output register of GPIO port
 * (code - 0x10) (gpio_set_port_bits), then waits delay * 10 ticks; a record whose code is not 0x10..0x1E ends
 * the run.
 *
 *   records 0..2 (power_setup_power_saving, power_off_sequence): set GPIO 4 pin 0x20, wait 50;
 *                set GPIO 4 pin 0x40, wait 50; record 2 empty.
 *   records 3..5 (power_leave_power_saving): clear GPIO 4 pin 0x40, wait 50; clear GPIO 4 pin 0x20, wait 20;
 *                record 5 empty.
 */
void ipc_8051_build_power_cut_table(void)
{
    unsigned char i, pos;

    for (i = 0; i < POWER_CUT_TABLE_SIZE; i++)
        ipc_8051_power_cut_table[i] = 0;
    pos = 0;
    /* First half: set the two pins. */
    while (1) {
        ipc_8051_power_cut_table[pos++] = ipc_map_index_to_code_0x11(GPIO_PORT_4);
        ipc_8051_power_cut_table[pos++] = ipc_pack_flag_and_bit_index(0x20, 1);
        ipc_8051_power_cut_table[pos++] = 5;
        if (pos + 2 >= sizeof(ipc_8051_power_cut_table))
            return;
        ipc_8051_power_cut_table[pos++] = ipc_map_index_to_code_0x11(GPIO_PORT_4);
        ipc_8051_power_cut_table[pos++] = ipc_pack_flag_and_bit_index(0x40, 1);
        ipc_8051_power_cut_table[pos++] = 5;
        if (pos + 2 >= sizeof(ipc_8051_power_cut_table))
            return;
        break;
    }
    /* Second half starts at record 3: clear the same pins, in the other order. */
    pos = 9;
    ipc_8051_power_cut_table[pos++] = ipc_map_index_to_code_0x11(GPIO_PORT_4);
    ipc_8051_power_cut_table[pos++] = ipc_pack_flag_and_bit_index(0x40, 0);
    ipc_8051_power_cut_table[pos++] = 5;
    if (pos + 2 >= sizeof(ipc_8051_power_cut_table))
        return;
    ipc_8051_power_cut_table[pos++] = ipc_map_index_to_code_0x11(GPIO_PORT_4);
    ipc_8051_power_cut_table[pos++] = ipc_pack_flag_and_bit_index(0x20, 0);
    ipc_8051_power_cut_table[pos++] = 2;
    if (pos + 2 >= sizeof(ipc_8051_power_cut_table))
        return;
}
