/* FUN_a0113810 (leon2m 0xa0113810-0xa01138fc, 236 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Acquires the word register 0xcf03c840 (writes 1 unless it reads 2, until it reads 1 or 0x10000 tries are used,
 * then writes 1), sets (on non-zero) or clears bit 0 of the word register 0xcf013428, then writes 0 to 0xcf03c840.
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a01136a0 and FUN_a01138fc. Source form: static lock/unlock helpers inlined in both arms; the retry loop is a
 * do/while (t--) with an unsigned short counter.
 */
#define R40 (*(volatile unsigned int *)0xcf03c840)
#define R428 (*(volatile unsigned int *)0xcf013428)
static void lock(void)
{
    unsigned short t = 0xffff;
    do {
        if (R40 != 2)
            R40 = 1;
        if (R40 == 1)
            break;
    } while (t--);
    R40 = 1;
}
static void unlock(void)
{
    R40 = 0;
}
void FUN_a0113810(unsigned char on)
{
    if (on) {
        lock();
        R428 |= 1;
        unlock();
    } else {
        lock();
        R428 &= ~1u;
        unlock();
    }
}
