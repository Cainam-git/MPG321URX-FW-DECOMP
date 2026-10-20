/* FUN_a00cc9f8 (leon2s, 0xa00cc9f8-0xa00cca38, 64 bytes, 16 words).
 * Flags: -mcpu=v8 -Os -g.
 * port = (u8)param_1; FUN_a00c9798(port, buf) fills a 2-byte stack buffer; if bit 3 (0x08) of buf[1] is set:
 * FUN_a00c7a4c(port, 0) and r = 1, else r = 0; returns r as a u8 (firmware: final 'and %i0,1,%i0' = u8
 * return extension narrowed by nonzero-bits).
 * Source form: u8 return type and one return of r (two int returns give no final and).
 */
extern int FUN_a00c9798(unsigned int, unsigned char *);
extern int FUN_a00c7a4c(unsigned int, int);

unsigned char FUN_a00cc9f8(unsigned int param_1)
{
    unsigned char buf[2];
    unsigned char r;
    param_1 &= 0xff;
    FUN_a00c9798(param_1, buf);
    r = 0;
    if (buf[1] & 0x08) {
        FUN_a00c7a4c(param_1, 0);
        r = 1;
    }
    return r;
}
