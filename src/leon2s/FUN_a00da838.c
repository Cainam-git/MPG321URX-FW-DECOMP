/* leon2s FUN_a00da838 @ 0xa00da838-0xa00da960, -mcpu=v8 -Os -g.
 * void. rec = 0x30-byte record ARR_a8079c98[byte DAT_a80787fc], c = DAT_a8079c50[DAT_a80787fc].
 * k = (rec[0] >> 4) - 1, off = k / 2 rounded up (signed); n = rec[off + 1] & 0x3f. Copies n bytes
 * rec[off + 3 + i], one per 32-bit word, to the register block DAT_a807609c[byte DAT_a8078832] at word
 * off + 3 + i (c == 0) or word off + 0x33 + i (c != 0); table and index are reloaded on every pass.
 * Same record, flag and destination as FUN_a00da6ac (volatile register-block pointers).
 * Source form: off = h, then 'if (k & 1) off = h + 1' with h = k / 2 as an int.
 */
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8079c50[];
extern unsigned char ARR_a8079c98[][0x30];
extern volatile unsigned int *DAT_a807609c[];

void FUN_a00da838(void)
{
    unsigned char *rec;
    unsigned char c, i, n, off;
    int k, h;

    rec = ARR_a8079c98[DAT_a80787fc];
    k = (rec[0] >> 4) - 1;
    h = k / 2;
    c = DAT_a8079c50[DAT_a80787fc];
    off = h;
    if (k & 1)
        off = h + 1;
    n = rec[off + 1] & 0x3f;
    if (c == 0) {
        for (i = 0; i < n; i++)
            DAT_a807609c[DAT_a8078832][off + i + 3] = rec[off + i + 3];
    } else {
        for (i = 0; i < n; i++)
            DAT_a807609c[DAT_a8078832][off + i + 0x33] = rec[off + i + 3];
    }
}
