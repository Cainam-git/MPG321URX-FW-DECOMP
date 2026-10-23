/* FUN_a00d9d50 (leon2s 0xa00d9d50-0xa00d9e44, 244 bytes), flags -mcpu=v8 -Os -g.
 * Scans the 0x30-byte records ARR_a8079c98 with 4-bit indices, starting at index DAT_a80787fc. The count n is
 * DAT_a80787fd - DAT_a80787fc, or 0x10 - (DAT_a80787fc - DAT_a80787fd) when DAT_a80787fd is smaller; equal
 * bytes return 0xff. For i = 0 .. n - 1 and idx = (DAT_a80787fc + i) & 0xf: h = (record byte 0 >> 4) - 1 (int),
 * k = h / 2, plus 1 when h is odd; the scan stops at the first record whose byte k + 2 has bit 6 set.
 * Returns (DAT_a80787fc + i) & 0xf for that record (DAT_a80787fc read again), or 0xff when none has the bit.
 * Source form: both record reads index ARR_a8079c98[idx] directly (a record pointer local moves the address
 * add); the final test and sum use an unsigned int copy of i and an unsigned int copy of the reloaded
 * DAT_a80787fc (unsigned char operands give the reversed add operand order and other registers).
 */
extern unsigned char DAT_a80787fc;
extern unsigned char DAT_a80787fd;
extern unsigned char ARR_a8079c98[][0x30];

unsigned char FUN_a00d9d50(void)
{
    unsigned char wr = DAT_a80787fd;
    unsigned char rd = DAT_a80787fc;
    unsigned char n;
    unsigned char i;
    unsigned char idx;
    unsigned char k;
    int h;
    unsigned int pos;
    unsigned int first;

    if (wr < rd)
        n = 0x10 - (rd - wr);
    else if (wr == rd)
        return 0xff;
    else
        n = wr - rd;
    for (i = 0; i < n; i++) {
        idx = (DAT_a80787fc + i) & 0xf;
        h = (ARR_a8079c98[idx][0] >> 4) - 1;
        k = h / 2;
        if (h & 1)
            k++;
        if (ARR_a8079c98[idx][k + 2] & 0x40)
            break;
    }
    pos = i;
    if (pos < n) {
        first = DAT_a80787fc;
        return (first + pos) & 0xf;
    }
    return 0xff;
}
