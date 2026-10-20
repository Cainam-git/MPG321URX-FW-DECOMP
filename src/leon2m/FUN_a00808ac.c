/* leon2m FUN_a00808ac @ 0xa00808ac-0xa0080978 (51 words).
 * Sets byte 0xa802af60 + n to 0xff, or all four bytes 0xa802af60..0xa802af63 for n 4. When f is 1 it also sets bit n
 * of byte 0xa802af45 (n 0..3), or bits 0..3 for n 4.
 */
extern unsigned char DAT_a802af60[4];
extern unsigned char DAT_a802af45;

void FUN_a00808ac(unsigned char n, unsigned char f)
{
    if (n == 4) {
        DAT_a802af60[0] = 0xff;
        DAT_a802af60[1] = 0xff;
        DAT_a802af60[2] = 0xff;
        DAT_a802af60[3] = 0xff;
        if (f == 1)
            DAT_a802af45 |= 0xf;
    } else {
        DAT_a802af60[n] = 0xff;
        if (f == 1) {
            if (n == 0)
                DAT_a802af45 |= 1;
            else if (n == 1)
                DAT_a802af45 |= 2;
            else if (n == 2)
                DAT_a802af45 |= 4;
            else if (n == 3)
                DAT_a802af45 |= 8;
        }
    }
}
