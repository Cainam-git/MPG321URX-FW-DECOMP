/* leon2m FUN_a0115584 @ 0xa0115584-0xa0115644 (48 words).
 * Reads 6 bytes with FUN_a011ce80(4, 6, buf) into a cleared buffer. The block is valid when the top three bits
 * of buf[0] are 101 (buf[0] & 0xe0 == 0xa0) and the XOR of the buf[1] bytes from buf[2] on is 0. Returns -1 for
 * an invalid block, else buf[3] for sel == 0, buf[4] for sel == 1 and buf[5] for any other sel.
 * Called by FUN_a00eecd0.
 * Source form: the XOR loop bound buf[1] is copied into a local first (the firmware tests it once before the loop
 * and compares 'i < n' at the bottom).
 */
extern void FUN_a011ce80(unsigned int, unsigned char, unsigned char *);

int FUN_a0115584(int sel)
{
    unsigned char buf[6] = { 0 };
    unsigned char err, cs, i, k, n;

    FUN_a011ce80(4, 6, buf);
    err = 0;
    if ((buf[0] & 0xe0) == 0xa0) {
        cs = 0;
        n = buf[1];
        for (i = 0; i < n; i++)
            cs ^= buf[2 + i];
        if (cs)
            err = 1;
    } else
        err = 1;
    if (sel == 0)
        k = 3;
    else if (sel == 1)
        k = 4;
    else
        k = 5;
    if (err)
        return -1;
    return buf[k];
}
