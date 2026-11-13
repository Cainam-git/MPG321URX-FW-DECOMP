/* ipc_8051_build_fixed_wake_table  (FUN_a0133238)
 *
 * Fill the second wake-up table with its four fixed entries.
 * Name basis: derived - 12-byte table at 0xA802DA60; part of the standby table message
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0133238 @ 0xa0133238-0xa0133384 (83 words), -mcpu=v8 -O3 -g.
 * ipc_map_index_to_code_0x11 and ipc_pack_flag_and_bit_index are the routines of the same file, inlined here as
 * static copies, as in ipc_8051_build_wake_table.
 * Source form: four copies of one block (code, entry, position test 'if (pos > 0xb) return;') with pos set to 0
 * after the clear loop; GCC folds the positions and tests.
 */
#define WAKE_TABLE_SIZE     12              /* room for six (code, entry) byte pairs */

extern unsigned char ipc_8051_fixed_wake_table[WAKE_TABLE_SIZE];

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
 * Build ipc_8051_fixed_wake_table: four fixed (code, entry) byte pairs, each naming one GPIO pin, in the same
 * form as ipc_8051_build_wake_table uses (code = 0x10 + GPIO port, entry = bit 4 flag | pin bit number):
 *   GPIO 5 pin mask 0x10 and 5 / 0x20 with bit 4 set, then 6 / 0x02 and 6 / 0x01 with bit 4 clear.
 * Here bit 4 is a constant; ipc_8051_build_wake_table puts the inverted level the pin reads at the time there.
 * The last four bytes stay 0.
 *
 * Called by ipc_8051_send_wake_key_table, which sends this table as bytes 48..59 of the 60-byte message type 8
 * to the 8051 (FillKeyDetectList stores the message at 0xA5ED).
 */
void ipc_8051_build_fixed_wake_table(void)
{
    unsigned char i, pos;

    for (i = 0; i < WAKE_TABLE_SIZE; i++)
        ipc_8051_fixed_wake_table[i] = 0;
    pos = 0;
    ipc_8051_fixed_wake_table[pos++] = ipc_map_index_to_code_0x11(5);
    ipc_8051_fixed_wake_table[pos++] = ipc_pack_flag_and_bit_index(0x10, 1);
    if (pos > WAKE_TABLE_SIZE - 1)
        return;
    ipc_8051_fixed_wake_table[pos++] = ipc_map_index_to_code_0x11(5);
    ipc_8051_fixed_wake_table[pos++] = ipc_pack_flag_and_bit_index(0x20, 1);
    if (pos > WAKE_TABLE_SIZE - 1)
        return;
    ipc_8051_fixed_wake_table[pos++] = ipc_map_index_to_code_0x11(6);
    ipc_8051_fixed_wake_table[pos++] = ipc_pack_flag_and_bit_index(0x2, 0);
    if (pos > WAKE_TABLE_SIZE - 1)
        return;
    ipc_8051_fixed_wake_table[pos++] = ipc_map_index_to_code_0x11(6);
    ipc_8051_fixed_wake_table[pos++] = ipc_pack_flag_and_bit_index(0x1, 0);
    if (pos > WAKE_TABLE_SIZE - 1)
        return;
}
