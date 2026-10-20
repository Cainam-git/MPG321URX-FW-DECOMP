/* FUN_a0099610 (leon2s 0xa0099610-0xa009967c, 108 bytes), flags -mcpu=v8 -Os -g.
 * In the 0xb0-byte record port of DAT_a807d680: clears bytes 0xaa, 0xab, 0xad, 0xae, 0xaf, sets byte 0xac to
 * 100 / DAT_a8078630 (signed int division), then tail-calls FUN_a00b15ac(record + 0x96, 0, 0x14) to clear the
 * 20 bytes from 0x96. Source form: record struct, stores in this order (GCC schedules the division first).
 */
struct RecB0 { unsigned char _0[0x96]; unsigned char hist[20]; unsigned char aa, ab, ac, ad, ae, af; };
extern struct RecB0 DAT_a807d680[];
extern unsigned char DAT_a8078630;
extern void *FUN_a00b15ac(void *, int, unsigned int);

void FUN_a0099610(unsigned char port)
{
    DAT_a807d680[port].aa = 0;
    DAT_a807d680[port].ab = 0;
    DAT_a807d680[port].ad = 0;
    DAT_a807d680[port].ae = 0;
    DAT_a807d680[port].af = 0;
    DAT_a807d680[port].ac = 100 / DAT_a8078630;
    FUN_a00b15ac(DAT_a807d680[port].hist, 0, 0x14);
}
