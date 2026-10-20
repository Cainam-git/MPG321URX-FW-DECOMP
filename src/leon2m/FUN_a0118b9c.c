/* FUN_a0118b9c: u8 flag e. e != 0: writes 1 to registers 0xcf012fd0 and 0xcf012f74 and 4 to 0xcf012f6c.
 * e == 0: writes 0 to 0xcf012f74, 0xcf012fd0 and 0xcf012f6c. No direct callers were found (the address may be
 * reached through a pointer). The function keeps a register window (save/restore) although it makes no call;
 * plain C at -O3 -g produces that frame.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0118b9c(unsigned char e)
{
    if (e) {
        R(0xcf012fd0) = 1;
        R(0xcf012f74) = 1;
        R(0xcf012f6c) = 4;
    } else {
        R(0xcf012f74) = 0;
        R(0xcf012fd0) = 0;
        R(0xcf012f6c) = 0;
    }
}
