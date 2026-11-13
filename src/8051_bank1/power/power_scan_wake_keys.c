/* power_scan_wake_keys  (FUN_CODE_5a39)
 *
 * Look for a pressed wake-up key or ADC key from the standby table.
 * Returns: 1 when a key was found
 * Name basis: proven - prints 'Key%02X : %02X %02X', 'PWR_DPMS ADC key', 'ADC key'; entries 0xA5ED from
 *   FillKeyDetectList
 *
 * Matching notes
 * --------------
 * 8051_bank1 module FUN_CODE_5a39: power_scan_wake_keys @ 0x5a39 (461 B), then ipc_write_shared_byte @ 0xdb05 (19 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: i at XDATA 0xA474, key at 0xA475..0xA476, adc_value at 0xA477, found at 0xA478.
 * Source forms:
 *  - The code ranges are tested as '(unsigned char)(key[0] + 0xf0) < 0x0f' / '(unsigned char)(key[0] + 0xd0) < 9'.
 *  - The gpio_read_port_bit arguments go to locals first (gpio_port, bit_index) and the mask is '1 << bit_index'.
 *    The comparison is cast to unsigned char.
 *  - The three 'power_key_hit_ticks = timer_get_ticks()' arms after the loop are written out each (Keil merges their
 *    common code, which gives the firmware's 'JNZ / SJMP' pairs).
 *  - Common-entry block 0xDAFE (in front of ipc_write_shared_byte): 'MOV DPTR,#0A475H; MOVX A,@DPTR; MOV R7,A;
 *    MOV R5,#01H', Keil's OPTIMIZE(8) shared set-up of the three 'ipc_write_shared_byte(key[0], 1)' calls (key[0] is
 *    XDATA 0xA475), which the call sites enter with LCALL 0xDAFE.
 *  - ipc_write_shared_byte is defined after power_scan_wake_keys. Defined first, Keil knows that it leaves R5
 *    unchanged (it then sets R5 = 1 with 'INC R5') and also moves the preceding 'ipc_write_shared_byte(1, 0)' call
 *    into the block.
 */

void ipc_write_shared_byte(unsigned char value, unsigned char index);
extern unsigned char xdata power_key_table[6][2];
extern unsigned char xdata power_adc_key_tolerance, power_key_release_seen_flag;
extern unsigned int xdata power_key_hit_ticks;
extern void lib_printf517(void *fmt, ...) large;
bit gpio_read_port_bit(unsigned char port, unsigned char mask);
extern unsigned char gpio_read_adc(unsigned char channel);
extern unsigned int timer_get_ticks(void);

/* power_key_table: six entries {code, setting}, filled by FillKeyDetectList (mailbox message 8). */
#define KEY_TABLE_ENTRIES  6
#define KEY_CODE_GPIO      0x10   /* 0x10..0x1E: pin key on GPIO port code - 0x10 */
#define KEY_CODE_ADC       0x30   /* 0x30..0x38: ADC key on channel code - 0x30 */
#define KEY_GPIO_BIT       0x0f   /* GPIO setting bits 0..3: bit of the port */
#define KEY_GPIO_LEVEL     0x10   /* GPIO setting bit 4: the level that counts as pressed */
#define ADC_KEY_ANY        0xff   /* ADC setting 0xFF: any reading up to ADC_KEY_ANY_MAX */
#define ADC_KEY_ANY_MAX    0xf8
#define KEY_HOLD_TICKS     50

/* The hit as written to reg_ipc_shared_bytes. */
#define SHARED_KEY_FLAG    0      /* 1 */
#define SHARED_KEY_CODE    1      /* the entry's code */
#define SHARED_KEY_VALUE   2      /* GPIO: bit number; ADC: the reading */
#define SHARED_BYTES       0x10

/*
 * power_scan_wake_keys - test the keys of the standby key table once.
 * Goes through the six entries of power_key_table and stops at the first one that reads as pressed:
 *   pin key (code 0x10..0x1E)  pressed when gpio_read_port_bit for the port and bit reads the level in bit 4 of
 *                              the setting; prints 'Key%02X : %02X %02X'.
 *   ADC key (code 0x30..0x38)  setting 0xFF: pressed when the reading is 0xF8 or below ('PWR_DPMS ADC key').
 *                              Otherwise pressed when the reading lies within power_adc_key_tolerance of the
 *                              setting (above setting - tolerance, below setting + tolerance; with the setting
 *                              under the tolerance only the upper bound counts) ('ADC key').
 * A hit is written to reg_ipc_shared_bytes as {1, code, bit number or reading}.
 * Returns 1 for a hit. While power_key_release_seen_flag is set, a hit counts only after the key has read as pressed
 * for KEY_HOLD_TICKS ticks: power_key_hit_ticks is restarted on every scan without a hit and on every counted hit.
 * The flag is set by sys_scan_keys_and_ir, the only caller, after a scan in which nothing was found, and cleared by
 * sys_restart_key_scan_timer.
 */
unsigned char power_scan_wake_keys(void)
{
    unsigned char i;
    unsigned char key[2];
    unsigned char adc_value;
    unsigned char found;
    unsigned char gpio_port, bit_index;

    found = 0;
    for (i = 0; i < KEY_TABLE_ENTRIES; i++) {
        key[0] = power_key_table[i][0];
        key[1] = power_key_table[i][1];
        if ((unsigned char)(key[0] + 0xf0) < 0x0f) {
            /* Pin key. */
            gpio_port = key[0] + 0xf0;
            bit_index = key[1] & KEY_GPIO_BIT;
            if ((unsigned char)(gpio_read_port_bit(gpio_port, 1 << bit_index) == ((key[1] & KEY_GPIO_LEVEL) >> 4))) {
                lib_printf517((void code *)0x98d2, i, key[0], key[1]);
                ipc_write_shared_byte(1, SHARED_KEY_FLAG);
                ipc_write_shared_byte(key[0], SHARED_KEY_CODE);
                ipc_write_shared_byte(key[1] & KEY_GPIO_BIT, SHARED_KEY_VALUE);
                found = 1;
                break;
            }
        } else if ((unsigned char)(key[0] + 0xd0) < 9) {
            /* ADC key. */
            adc_value = gpio_read_adc(key[0] + 0xd0);
            if (key[1] == ADC_KEY_ANY) {
                if (adc_value <= ADC_KEY_ANY_MAX) {
                    lib_printf517((void code *)0x98e8, adc_value, power_key_table[i][1], power_adc_key_tolerance);
                    ipc_write_shared_byte(1, SHARED_KEY_FLAG);
                    ipc_write_shared_byte(key[0], SHARED_KEY_CODE);
                    ipc_write_shared_byte(adc_value, SHARED_KEY_VALUE);
                    found = 1;
                    break;
                }
            } else if ((adc_value < key[1] + power_adc_key_tolerance && key[1] < power_adc_key_tolerance) || (adc_value < key[1] + power_adc_key_tolerance && adc_value > (unsigned char)(key[1] - power_adc_key_tolerance))) {
                lib_printf517((void code *)0x9907, adc_value, key[1], power_adc_key_tolerance);
                ipc_write_shared_byte(1, SHARED_KEY_FLAG);
                ipc_write_shared_byte(key[0], SHARED_KEY_CODE);
                ipc_write_shared_byte(adc_value, SHARED_KEY_VALUE);
                found = 1;
                break;
            }
        }
    }
    /* Hold time: see above. */
    if (found == 0) {
        power_key_hit_ticks = timer_get_ticks();
    } else if (power_key_release_seen_flag == 0) {
        power_key_hit_ticks = timer_get_ticks();
    } else if (timer_get_ticks() - power_key_hit_ticks < KEY_HOLD_TICKS) {
        found = 0;
    } else {
        power_key_hit_ticks = timer_get_ticks();
    }
    return found;
}

extern unsigned char xdata reg_ipc_shared_bytes[];

/* ipc_write_shared_byte - store value in byte index (0..15) of reg_ipc_shared_bytes; a larger index is ignored. */
void ipc_write_shared_byte(unsigned char value, unsigned char index)
{
    if (index < SHARED_BYTES) reg_ipc_shared_bytes[index] = value;
}
