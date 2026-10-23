/* leon2s FUN_a00a33f4 @ 0xa00a33f4-0xa00a3578, -mcpu=v8 -Os -g.
 * (u8 port, const u8 *e), void; e = a 512-byte buffer of 128-byte blocks. blk = the last of the blocks 1..3
 * whose first byte is 2 (0 when none: return). Searches bytes blk*0x80 .. blk*0x80 + 0x7b for the sequence
 * d8 5d c4 01 at i; on the first hit: m = (e[i - 1] == 0x6d); with j = (u8)(i + 4): DAT_a80791e0[port] = 1
 * when e[j + 1] has bit 7 set, else 0; DAT_a80791d8[port] = e[j + 2] >> 4; when m: DAT_a80791b8[port] =
 * e[j + 6], DAT_a80791c8[port] = e[j + 7] >> 4, DAT_a80791c0[port] = e[j + 7] & 0xf, else those three = 0;
 * then return.
 * Source form: blk = 0 then 'if (e[0x80] == 2) blk = 1'; m = 0 at its declaration; u16 loop index.
 */
extern unsigned char DAT_a80791e0[];
extern unsigned char DAT_a80791d8[];
extern unsigned char DAT_a80791b8[];
extern unsigned char DAT_a80791c8[];
extern unsigned char DAT_a80791c0[];

void FUN_a00a33f4(unsigned char port, unsigned char *e)
{
    unsigned char m = 0;
    unsigned char blk, j;
    unsigned short i, end;

    blk = 0;
    if (e[0x80] == 2)
        blk = 1;
    if (e[0x100] == 2)
        blk = 2;
    if (e[0x180] == 2)
        blk = 3;
    if (blk == 0)
        return;
    end = blk * 0x80 + 0x7c;
    for (i = blk * 0x80; i < end; i++) {
        if (e[i] == 0xd8 && e[i + 1] == 0x5d && e[i + 2] == 0xc4 && e[i + 3] == 1) {
            if (e[i - 1] == 0x6d)
                m = 1;
            j = i + 4;
            if ((signed char)e[j + 1] < 0)
                DAT_a80791e0[port] = 1;
            else
                DAT_a80791e0[port] = 0;
            DAT_a80791d8[port] = e[j + 2] >> 4;
            if (m) {
                DAT_a80791b8[port] = e[j + 6];
                DAT_a80791c8[port] = e[j + 7] >> 4;
                DAT_a80791c0[port] = e[j + 7] & 0xf;
            } else {
                DAT_a80791b8[port] = 0;
                DAT_a80791c8[port] = 0;
                DAT_a80791c0[port] = 0;
            }
            return;
        }
    }
}
