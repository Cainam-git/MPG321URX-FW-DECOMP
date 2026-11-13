/* sys_register_callback  (FUN_a0143700)
 *
 * Store a callback in one of the fifteen slots of the callback table.
 * Name basis: proven - table at 0xA802CC1C; called ten times from startup_register_app_callbacks
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143700 @ 0xa0143700, flags -mcpu=v8 -O3 -g (gcc 3.4.4).
 * Real size 0xDC (the function list's size field says 44; its end address is right).
 * Source form: one switch case per slot, each a plain store.
 */
extern void (*sys_callback_table[15])(void);

/* Store handler in the callback table. Numbers n = 0..8 go to slot n and n = 10..15 go to slot n - 1;
 * n = 9 and anything above 15 are ignored. */
void sys_register_callback(unsigned char n, void (*handler)(void))
{
    switch (n) {
    case 0: sys_callback_table[0] = handler; break;
    case 1: sys_callback_table[1] = handler; break;
    case 2: sys_callback_table[2] = handler; break;
    case 3: sys_callback_table[3] = handler; break;
    case 4: sys_callback_table[4] = handler; break;
    case 5: sys_callback_table[5] = handler; break;
    case 6: sys_callback_table[6] = handler; break;
    case 7: sys_callback_table[7] = handler; break;
    case 8: sys_callback_table[8] = handler; break;
    case 10: sys_callback_table[9] = handler; break;
    case 11: sys_callback_table[10] = handler; break;
    case 12: sys_callback_table[11] = handler; break;
    case 13: sys_callback_table[12] = handler; break;
    case 14: sys_callback_table[13] = handler; break;
    case 15: sys_callback_table[14] = handler; break;
    }
}
