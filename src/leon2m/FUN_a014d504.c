/* leon2m FUN_a014d504 @ 0xa014d504-0xa014d544 (16 words), flags -mcpu=v8 -O3 -g.
 * Code facts: returns 1 when FUN_a0108e54() (u8, no args) == 1 and bits 26..27 (mask 0xc000000) of
 * the word _DAT_a802e3d0 are both clear, else 0; u8 flag set per path, 'and 1' at each exit.
 * No parameter; the test is on the callee's return value. Source form: 'r = 0; if (...) r = 1;
 * return r & 1'. Aids: none.
 */
extern unsigned int _DAT_a802e3d0;
extern unsigned char FUN_a0108e54(void);

unsigned char FUN_a014d504(void)
{
    unsigned char r = 0;

    if (FUN_a0108e54() == 1 && (_DAT_a802e3d0 & 0xc000000) == 0)
        r = 1;
    return r & 1;
}
