/* leon2m FUN_a01380c4 @ 0xa01380c4-0xa0138110 (19 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Returns 0xff when a is not 0. Otherwise sends the 4-byte buffer {a, b, 0, 0} with FUN_a01370dc(0x5d, 4, buf, 0),
 * runs FUN_a0137344(1) and returns byte 0xa802cba3. The buffer is an initialised 4-byte array (the word at %fp-16
 * is cleared before the test), as in FUN_a01381f0. The result is an int local set to -1 and returned as unsigned
 * char (mov -1; and 0xff).
 */
extern unsigned char DAT_a802cba3;
extern void FUN_a01370dc(int, int, unsigned char *, int);
extern void FUN_a0137344(int);

unsigned char FUN_a01380c4(unsigned char a, unsigned char b)
{
    unsigned char buf[4] = {0};
    int r = -1;

    if (a == 0) {
        buf[0] = a;
        buf[1] = b;
        FUN_a01370dc(0x5d, 4, buf, 0);
        FUN_a0137344(1);
        r = DAT_a802cba3;
    }
    return r;
}
