/* power_find_wake_entry  (FUN_CODE_d27f)
 *
 * Return the setting byte of the wake-source table entry of this type.
 *   key: wake source type
 * Returns: entry byte 2, 0xFF when absent
 * Name basis: derived - ten 3-byte entries ended by type 0x1F, the table the standby wake check walks (types
 *   7..10 = DP wake)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d27f @ 0xd27f (53 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Source form: the entry is a 3-byte struct; Keil indexes it with 'MUL AB' by 3 and adds the member offset to the
 * base.
 */
/* Entry of the wake-up port table; the low five bits of byte 0 are the key, 0x1f ends the table. */
struct wake_entry { unsigned char byte_0, byte_1, byte_2; };
extern struct wake_entry xdata power_wake_port_table[10];

/* The key is the low five bits of byte 0; the key value 0x1f ends the table. */
#define WAKE_KEY_MASK  0x1f
#define WAKE_TABLE_END 0x1f

/*
 * Look up 'key' in the ten-entry table power_wake_port_table: entries are
 * compared in order on the low five bits of byte 0; the value WAKE_TABLE_END
 * ends the search. Returns byte 2 of the first entry whose key matches, or
 * 0xFF when there is none. Callers: the code at 0x52BE and 0x883D (four
 * calls each).
 */
unsigned char power_find_wake_entry(unsigned char key)
{
    unsigned char i, entry_key;

    for (i = 0; i < 10; i++) {
        entry_key = power_wake_port_table[i].byte_0 & WAKE_KEY_MASK;
        if (entry_key == WAKE_TABLE_END) break;
        if (entry_key == key) return power_wake_port_table[i].byte_2;
    }
    return 0xff;
}
