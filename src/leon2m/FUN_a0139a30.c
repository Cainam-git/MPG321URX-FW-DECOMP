/* leon2m FUN_a0139a30 @ 0xa0139a30  send the active panel row size to the Tensilica core and start it (hand;
 * BYTE-EXACT at -mcpu=v8 -O3 -g -msoft-float).
 *
 * Mailbox portal 2 (Tensilica, func_0x4008c5f8 = MailBox_Write, func_0x4008c4d0 = MailBox_Read): offset 0xA0 =
 * raw active row (0xA802E378) h08 << 16 + h0a; 0xA4 = 0xFFF; 0xA8 = 0x1001; 0xAC = 0xFF0101; 0xC0 = 8 words from
 * 0x1A5340; 0xE0 = 8 words from 0x1A5320. Then waits for offset 0x20 to read 0 (100 tries, 1 ms apart via
 * func_0x4008d1a0) and writes command 0x21000001 to it; gives up silently. Called after the output set-up
 * (FUN_a015373c). Reads the panel row: passes the row's +0x08/+0x0A size on.
 * BYTE-EXACT keys: 0x1001 / 0xFF0101 built from a variable (sethi + add, not a folded constant); the counter
 * decremented before the re-read (add + cmp, not addcc).
 */
struct RawRow { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
extern struct RawRow DAT_a802e378;
extern unsigned int DAT_001a5340[8], DAT_001a5320[8];
extern void func_0x4008c5f8(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void func_0x4008c4d0(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void func_0x4008d1a0(int);

void FUN_a0139a30(void)
{
    unsigned int v, st;
    unsigned int one = 1;
    int n;

    v = (DAT_a802e378.h08 << 16) + DAT_a802e378.h0a;
    func_0x4008c5f8(2, 0xa0, &v, 1);
    v = 0xfff;
    func_0x4008c5f8(2, 0xa4, &v, 1);
    v = (one << 12) + one;
    func_0x4008c5f8(2, 0xa8, &v, 1);
    v = (0xffu << 16) + (one << 8) + one;
    func_0x4008c5f8(2, 0xac, &v, 1);
    func_0x4008c5f8(2, 0xc0, DAT_001a5340, 8);
    func_0x4008c5f8(2, 0xe0, DAT_001a5320, 8);
    st = 0xffffffff;
    func_0x4008c4d0(2, 0x20, &st, 1);
    n = 100;
    if (st == 0) goto send;
    do {
        func_0x4008d1a0(1);
        n--;
        func_0x4008c4d0(2, 0x20, &st, 1);
        if (n == 0) goto check;
    } while (st != 0);
    goto send;
check:
    if (st != 0) return;
send:
    st = 0x21000001;
    func_0x4008c5f8(2, 0x20, &st, 1);
}
