/* sys_read_startup_key  (FUN_a008e650)
 *
 * Read the front keys at start-up, log them for the key test and set the start-up key option.
 * Note: When armed by bit 11 of 0xA802CFF4, key code 2 sets bit 14 of the settings word, any other clears it.
 * Name basis: derived - called once by App_CoolInitialize; same key-test logging as sys_scan_keys_post_event
 *
 * Matching notes
 * --------------
 * leon2m FUN_a008e650 @ 0xa008e650-0xa008e7a8 (86 words).
 * k = input_read_keys_debounced(). For nonzero k: byte 0xa802cffa = the second byte of the first of the six 2-byte entries at
 * 0x10053f whose first byte shares a bit with k (0 when none). When halfword 0xa802d486 is 0x55aa, byte 0xa802d284
 * has none of those bits and byte 0xa802d465 is 0, the bits are added to 0xa802d284 and SYSAPI_WriteEEPROM(0x30,
 * 0xa802d274, 0x2e0, 0x1c) is called. Then, when bit 11 of halfword 0xa802cff4 is set, bit 14 of word 0xa802d290 is
 * set for k 2 and cleared otherwise; bit 11 of 0xa802cff4 is cleared.
 */
/* A pair of the table at 0x10053F: a front-key input bit and the key bit it stands for. */
struct key_bit_entry { unsigned char input_bit, key_bit; };
/* The fields of the user settings record that this routine uses. */
struct user_settings_record { unsigned int word_0; unsigned char pad_4[0x1d1]; unsigned char burn_in_flag;
              unsigned char pad_1d6[0x20]; unsigned short factory_marker; };
/* The fields of the application state record that this routine uses. */
struct app_state_fields { unsigned short flags; unsigned char pad_2[4]; unsigned char startup_key_bit; };
extern const struct key_bit_entry sys_key_bit_table[6];
extern struct user_settings_record user_settings;
extern struct app_state_fields app_state_record;
extern unsigned char factory_record[];
extern unsigned char input_read_keys_debounced(void);
extern int SYSAPI_WriteEEPROM(unsigned char, void *, unsigned short, unsigned short);

#define FACTORY_MODE_MARKER      0x55aa /* user_settings +0x1F6 */
#define FACTORY_KEY_TEST_BITS    0x10   /* factory_record +0x10: one bit per front key passed in the key test */
#define APP_STATE_STARTUP_KEY    0x0800 /* app_state_record halfword +0: bit 11, cleared at the end */
#define SETTINGS_WORD0_BIT14     0x4000 /* user settings word +0, bit 14 */

/*
 * Read the front keys once at start-up. Called once, by App_CoolInitialize.
 *
 * With a key pressed, the first entry of sys_key_bit_table whose input bit is among the keys gives the key bit
 * (0 when none) and it is kept in app_state_record (byte +6). When the settings carry the factory marker, the
 * key bit is not yet in the key test bits of the factory record and the burn-in flag is 0, the bit is added and
 * the 0x1C-byte factory record is written with SYSAPI_WriteEEPROM(0x30, record, 0x2E0, 0x1C).
 *
 * When bit 11 of the first halfword of app_state_record is set, bit 14 of the first word of the settings is set
 * if the key read was 2 and cleared otherwise. That bit 11 is cleared in every case.
 */
void sys_read_startup_key(void)
{
    unsigned char keys, i, key_bit = 0;

    keys = input_read_keys_debounced();
    if (keys != 0) {
        for (i = 0; i < 6; i++) {
            if (sys_key_bit_table[i].input_bit & keys) {
                key_bit = sys_key_bit_table[i].key_bit;
                break;
            }
        }
        app_state_record.startup_key_bit = key_bit;
        if (user_settings.factory_marker == FACTORY_MODE_MARKER && !(factory_record[FACTORY_KEY_TEST_BITS] & app_state_record.startup_key_bit) && user_settings.burn_in_flag == 0) {
            factory_record[FACTORY_KEY_TEST_BITS] |= app_state_record.startup_key_bit;
            SYSAPI_WriteEEPROM(0x30, factory_record, 0x2e0, 0x1c);
        }
    }
    if (app_state_record.flags & APP_STATE_STARTUP_KEY) {
        if (keys == 2)
            user_settings.word_0 |= SETTINGS_WORD0_BIT14;
        else
            user_settings.word_0 &= ~SETTINGS_WORD0_BIT14;
    }
    app_state_record.flags &= ~APP_STATE_STARTUP_KEY;
}
