/* leon2m FUN_a0143700 @ 0xa0143700  register a callback in slot n. Flags: -mcpu=v8 -O3 -g (gcc 3.4.4).
 * Real size 0xDC (the function list's size field says 44; its end address is right).
 * Stores handler into the callback table at RAM 0xA802CC1C: n = 0..8 -> slot n, n = 10..15 -> slot n - 1; n = 9 and
 * n > 15 are ignored. Called by FUN_a008796c (main() init) for n = 2, 3, 6, 7, 8, 10, 11, 12, 14, 15.
 */
extern void (*DAT_a802cc1c[15])(void);
void FUN_a0143700(unsigned char n, void (*handler)(void))
{
    switch (n) {
    case 0: DAT_a802cc1c[0] = handler; break;
    case 1: DAT_a802cc1c[1] = handler; break;
    case 2: DAT_a802cc1c[2] = handler; break;
    case 3: DAT_a802cc1c[3] = handler; break;
    case 4: DAT_a802cc1c[4] = handler; break;
    case 5: DAT_a802cc1c[5] = handler; break;
    case 6: DAT_a802cc1c[6] = handler; break;
    case 7: DAT_a802cc1c[7] = handler; break;
    case 8: DAT_a802cc1c[8] = handler; break;
    case 10: DAT_a802cc1c[9] = handler; break;
    case 11: DAT_a802cc1c[10] = handler; break;
    case 12: DAT_a802cc1c[11] = handler; break;
    case 13: DAT_a802cc1c[12] = handler; break;
    case 14: DAT_a802cc1c[13] = handler; break;
    case 15: DAT_a802cc1c[14] = handler; break;
    }
}
