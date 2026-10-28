/* FUN_a008d2e0 (leon2s 0xa008d2e0-0xa008d490, 432 bytes), flags -mcpu=v8 -Os -g.
 * void (u16 start, u16 len, unsigned int out = byte buffer address, as the callers FUN_a008d690 and
 * FUN_a008d70c declare it). Saves the low bytes of the registers 0xcf0121c0 and 0xcf0121e0, writes
 * 0x35 / 0x80 to them, clears 0xcf012228 / 0xcf012240 / 0xcf012244, writes 2 to 0xcf01224c and the sequence
 * 0x61, 0x60, 0x40, 0x60, 0x70 to 0xcf012248 with FUN_a00b160c(5) / (1) / (1) / (1) between the writes.
 * ok = 1 when the low byte of FUN_a008d0b8(start) is 1. For k < len, with a = start + k (u16): when ok and the
 * low byte of FUN_a008d1d8(a) is 1, ((unsigned char *)out)[k] = FUN_a008d280(a); otherwise the low byte of a goes to
 * 0xcf012240, a >> 8 to 0xcf012244 and ((unsigned char *)out)[k] = the value read from 0xcf012200. Finally restores the two
 * saved bytes.
 * Source form: the register read is written twice (in the else arm of the FUN_a008d1d8 test and in the else
 * arm of the ok test); the low byte is '(unsigned char)a'.
 */
#define R21c0 (*(volatile unsigned int *)0xcf0121c0)
#define R21e0 (*(volatile unsigned int *)0xcf0121e0)
#define R2200 (*(volatile unsigned int *)0xcf012200)
#define R2228 (*(volatile unsigned int *)0xcf012228)
#define R2240 (*(volatile unsigned int *)0xcf012240)
#define R2244 (*(volatile unsigned int *)0xcf012244)
#define R2248 (*(volatile unsigned int *)0xcf012248)
#define R224c (*(volatile unsigned int *)0xcf01224c)
extern void FUN_a00b160c(unsigned int);
extern int FUN_a008d0b8(unsigned short);
extern int FUN_a008d1d8(unsigned short);
extern unsigned char FUN_a008d280(unsigned short);

void FUN_a008d2e0(unsigned short start, unsigned short len, unsigned int out)
{
    unsigned char s1 = R21c0;
    unsigned char s2 = R21e0;
    unsigned char ok;
    unsigned short k;
    unsigned short a;

    R21c0 = 0x35;
    R21e0 = 0x80;
    R2228 = 0;
    R2240 = 0;
    R2244 = 0;
    R224c = 2;
    R2248 = 0x61;
    FUN_a00b160c(5);
    R2248 = 0x60;
    FUN_a00b160c(1);
    R2248 = 0x40;
    FUN_a00b160c(1);
    R2248 = 0x60;
    FUN_a00b160c(1);
    R2248 = 0x70;
    ok = 0;
    if ((unsigned char)FUN_a008d0b8(start) == 1)
        ok = 1;
    for (k = 0; k < len; k++) {
        a = start + k;
        if (ok) {
            if ((unsigned char)FUN_a008d1d8(a) == 1)
                ((unsigned char *)out)[k] = FUN_a008d280(a);
            else {
                R2240 = (unsigned char)a;
                R2244 = a >> 8;
                ((unsigned char *)out)[k] = R2200;
            }
        } else {
            R2240 = (unsigned char)a;
            R2244 = a >> 8;
            ((unsigned char *)out)[k] = R2200;
        }
    }
    R21c0 = s1;
    R21e0 = s2;
}
