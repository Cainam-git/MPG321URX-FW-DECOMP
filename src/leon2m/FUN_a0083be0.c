/* FUN_a0083be0 (leon2m 0xa0083be0-0xa0083c20, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a00d3dbc() as a tail call when bit 11 (0x800) of the word at DAT_a802d290 + 0xa8 is set and the byte at
 * DAT_a802d290 + 0x181 is 7. It lies between FUN_a0083b60 and FUN_a0083c20.
 */
struct R290 { unsigned char p0[0xa8]; unsigned int wa8; unsigned char pac[0x181 - 0xac]; unsigned char b181; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d3dbc(void);

void FUN_a0083be0(void)
{
    if ((DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 7)
        FUN_a00d3dbc();
}
