/* power_reset_wake_table  (FUN_CODE_ccc2)
 *
 * Restart the wake-up table scan, optionally clearing the table.
 *   clear_table: 1 = clear the table
 * Name basis: derived - 0xA64D = 0x1F; m == 1 resets the ten 0xA62F entries to 1F FF FF; callers command 0x16
 *   and sys_main
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ccc2 @ 0xccc2 (69 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Source form: the loop counter reuses R7 (the mask is dead after the test); 'XRL A,#1 / JNZ' leaves A = 0 for
 * 'i = 0'.
 */
/* Entry of the wake-up port table; the low five bits of byte 0 are the key, 0x1f ends the table (power_find_wake_entry). */
struct wake_entry { unsigned char byte_0, byte_1, byte_2; };
extern struct wake_entry xdata power_wake_port_table[10];
extern unsigned char xdata power_wake_table_index;

/* Value of the key bits that marks the end of the table. */
#define WAKE_TABLE_END 0x1f

/*
 * Restart the wake-up table scan: power_wake_table_index = 0x1F. When
 * clear_table is 1 all ten entries of the table are also reset to
 * {0x1F, 0xFF, 0xFF}, which is an empty table. Callers: start-up
 * (clear_table = 1) and command 0x16 of the command switch (clear_table = 0).
 */
void power_reset_wake_table(unsigned char clear_table)
{
    unsigned char i;

    power_wake_table_index = WAKE_TABLE_END;
    if (clear_table == 1) {
        for (i = 0; i < 10; i++) {
            power_wake_port_table[i].byte_0 = WAKE_TABLE_END;
            power_wake_port_table[i].byte_1 = 0xff;
            power_wake_port_table[i].byte_2 = 0xff;
        }
    }
}
