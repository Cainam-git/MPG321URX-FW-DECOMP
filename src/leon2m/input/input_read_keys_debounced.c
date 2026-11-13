/* input_read_keys_debounced  (FUN_a012621c)
 *
 * Scan the keys until the same code has been seen for 50 ticks and return it.
 * Returns: key code
 * Name basis: proven - repeats input_scan_keys; last code at 0xA802C9FC
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012621c @ 0xa012621c-0xa012629c (32 words), flags -mcpu=v8 -O3 -g.
 */
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern unsigned char input_scan_keys(void);
extern unsigned char input_last_key_code;

#define KEY_STABLE_TICKS 0x32       /* 50 ticks */

/*
 * Scan the keys with input_scan_keys until the same code has been seen for 50 ticks, and return it.
 * Whenever the scan differs from the last code (input_last_key_code) the code is stored and the 50 ticks start
 * again. When the first scan equals the stored code, it returns at once.
 */
unsigned char input_read_keys_debounced(void)
{
    unsigned short start = timer_get_ticks16();
    unsigned char wait = 0;
    unsigned char code;

    do {
        code = input_scan_keys();
        if (code != input_last_key_code) {
            input_last_key_code = code;
            start = timer_get_ticks16();
            wait = KEY_STABLE_TICKS;
        }
    } while (wait && timer_ticks_since(start) < wait);
    return input_last_key_code;
}
