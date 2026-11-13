/* ipc_8051_build_wake_table  (FUN_a0132e1c)
 *
 * Fill the table of wake-up sources that is sent to the 8051 before standby.
 * Name basis: derived - up to six code/entry pairs in the 12-byte table at 0xA802D9B8; part of the standby
 *   table message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0132e1c @ 0xa0132e1c-0xa0133238 (263 words), flags -mcpu=v8 -O3 -g.
 * ipc_map_index_to_code_0x11 (jump table 0xa0132ac0) and ipc_pack_flag_and_bit_index are the routines of the same
 * file, inlined here as static copies. The channel count switch uses jump table 0xa0132b0c.
 * Source forms the exact build depends on:
 *  - the four fixed pairs are four copies of one block (code, entry, position test) with their own position
 *    variable fixed_pos, initialised in its declaration; GCC folds the first two position tests and keeps the third
 *    (constant 6 in a register), as in the firmware;
 *  - the main path uses pos, set to 0 before the sys_config bit 31 test;
 *  - sys_get_channel_signal_code is called with the loop counter; the channel count is a switch with grouped case
 *    labels.
 */
/* One entry of port_entries (0x12 bytes); only the field read here. */
struct port_entry {
    unsigned char pad[0x10];
    unsigned char bus_id;                   /* +0x10: index into the port table */
    unsigned char pad11;
};

#define WAKE_TABLE_SIZE     12              /* six (code, entry) byte pairs */
#define PORT_ENTRY_COUNT    7               /* a larger index falls back to entry 0 */

extern unsigned char ipc_8051_wake_table[WAKE_TABLE_SIZE];
extern unsigned int sys_config;
extern unsigned char device_settings_pip_mode;
extern struct port_entry port_entries[];
extern int gpio_read_pin(int, int);
extern unsigned char sys_get_channel_signal_code(unsigned char);
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern unsigned char input_port_table_get_detect_port(unsigned int);
extern unsigned char input_port_table_get_detect_mask(unsigned int);

/* Code byte of a pair: 0x10 + GPIO port for ports 1..13, 0x11 for port 18, 0 for every other port. */
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

/* Entry byte of a pair: bit 4 = bit 0 of level, bits 0..3 = number of the highest set bit of pin_mask
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
 * Build ipc_8051_wake_table: up to six (code, entry) byte pairs, each naming one GPIO pin and its level.
 * The code byte gives the GPIO port (0x10 + port), the entry byte the pin's bit number and, in bit 4, the inverted
 * level the pin reads now (1 = the pin reads low; gpio_read_pin gives 1 for high). Unused pairs stay 0.
 *
 * Called by ipc_8051_send_wake_key_table, which also builds ipc_8051_fixed_wake_table and sends this table as
 * bytes 36..47 of the 60-byte message type 8; the 8051 stores the message at 0xA5ED (FillKeyDetectList).
 *
 * Phases:
 *   1. Clear the table.
 *   2. When bit 31 of sys_config word 0 is set: four fixed pins (port 3 mask 4, port 3 mask 8, port 11 mask 2,
 *      port 2 mask 0x10), then return.
 *   3. Otherwise the number of channels to look at follows device_settings_pip_mode: 1 for mode 0, 2 for modes
 *      1, 2 and 5, 3 for modes 3 and 6, 4 for modes 4 and 7 (1 for any other value).
 *   4. For each of those channels: the port entry of its signal code (entry 0 when the index is 7 or more), the
 *      detect pin of that entry's port table row, its pair; a pair already in the table is not added again. It
 *      stops when the table is full.
 */
void ipc_8051_build_wake_table(void)
{
    unsigned char channel, entry_index, detect_port, detect_mask, code, entry, j, found, pos;
    unsigned char fixed_pos = 0;
    unsigned char i = 0;
    unsigned char channel_count = 1;

    /* Phase 1. */
    for (; i < WAKE_TABLE_SIZE; i++)
        ipc_8051_wake_table[i] = 0;
    pos = 0;

    /* Phase 2: the fixed set. */
    if (sys_config >> 31) {
        ipc_8051_wake_table[fixed_pos++] = ipc_map_index_to_code_0x11(3);
        ipc_8051_wake_table[fixed_pos++] = ipc_pack_flag_and_bit_index(0x4, ~gpio_read_pin(3, 0x4));
        if (fixed_pos > WAKE_TABLE_SIZE - 1)
            return;
        ipc_8051_wake_table[fixed_pos++] = ipc_map_index_to_code_0x11(3);
        ipc_8051_wake_table[fixed_pos++] = ipc_pack_flag_and_bit_index(0x8, ~gpio_read_pin(3, 0x8));
        if (fixed_pos > WAKE_TABLE_SIZE - 1)
            return;
        ipc_8051_wake_table[fixed_pos++] = ipc_map_index_to_code_0x11(11);
        ipc_8051_wake_table[fixed_pos++] = ipc_pack_flag_and_bit_index(0x2, ~gpio_read_pin(11, 0x2));
        if (fixed_pos > WAKE_TABLE_SIZE - 1)
            return;
        ipc_8051_wake_table[fixed_pos++] = ipc_map_index_to_code_0x11(2);
        ipc_8051_wake_table[fixed_pos++] = ipc_pack_flag_and_bit_index(0x10, ~gpio_read_pin(2, 0x10));
        if (fixed_pos > WAKE_TABLE_SIZE - 1)
            return;
        return;
    }

    /* Phase 3: channels in use. */
    switch (device_settings_pip_mode) {
    case 0:
        channel_count = 1;
        break;
    case 1:
    case 2:
    case 5:
        channel_count = 2;
        break;
    case 3:
    case 6:
        channel_count = 3;
        break;
    case 4:
    case 7:
        channel_count = 4;
        break;
    }

    /* Phase 4: the detect pin of each channel's input. */
    for (channel = 0; channel < channel_count; channel++) {
        entry_index = input_port_id_to_entry_index(sys_get_channel_signal_code(channel));
        if (entry_index >= PORT_ENTRY_COUNT)
            entry_index = 0;
        detect_port = input_port_table_get_detect_port(port_entries[entry_index].bus_id);
        detect_mask = input_port_table_get_detect_mask(port_entries[entry_index].bus_id);
        code = ipc_map_index_to_code_0x11(detect_port);
        entry = ipc_pack_flag_and_bit_index(detect_mask, ~gpio_read_pin(detect_port, detect_mask));
        /* Skip a pair that is already in the table. */
        found = 0;
        for (j = 0; j < WAKE_TABLE_SIZE; j += 2) {
            if (ipc_8051_wake_table[j] == code && ipc_8051_wake_table[j + 1] == entry) {
                found = 1;
                break;
            }
        }
        if (!found) {
            ipc_8051_wake_table[pos++] = code;
            ipc_8051_wake_table[pos++] = entry;
            if (pos > WAKE_TABLE_SIZE - 1)
                return;
        }
    }
}
