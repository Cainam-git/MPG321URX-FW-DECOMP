/* FUN_a0079ac4 (leon2s 0xa0079ac4-0xa0079b84, 192 bytes), flags -mcpu=v8 -Os -g.
 * For idx 0..3 reads two registers of port through FUN_a00a7314 (register numbers from the halfword tables
 * DAT_a00b3af4 and DAT_a00b3aec at index idx) and keeps bits 8..12 of each (both 0 for other idx). Each value
 * has bit 4 flipped and m is the smaller of the two. Returns 4 (m >= 0x17) or 8 for mode 6, 2 for mode 5,
 * otherwise 0, masked with 0xe.
 * Source form: the mode 6 value is written m >= 0x17 ? 4 : 8 (gives the subx/and/add sequence).
 */
extern unsigned int FUN_a00a7314(unsigned int param_1, unsigned short param_2);
extern const unsigned short DAT_a00b3aec[];
extern const unsigned short DAT_a00b3af4[];

unsigned char FUN_a0079ac4(unsigned char port, unsigned char idx, unsigned char mode)
{
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char m;
    unsigned char r = 0;

    if (idx <= 3) {
        a = (FUN_a00a7314(port, DAT_a00b3af4[idx]) & 0x1f00) >> 8;
        b = (FUN_a00a7314(port, DAT_a00b3aec[idx]) & 0x1f00) >> 8;
    }
    a ^= 0x10;
    b ^= 0x10;
    m = a > b ? b : a;
    if (mode == 6)
        r = m >= 0x17 ? 4 : 8;
    else if (mode == 5)
        r = 2;
    return r & 0xe;
}
