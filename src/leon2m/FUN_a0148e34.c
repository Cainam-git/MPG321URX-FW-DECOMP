/* leon2m FUN_a0148e34 @ 0xa0148e34-0xa0148eb4 (32 words), flags -mcpu=v8 -O3 -g.
 * What it does: SYSAPI_ConfigSystemPostFRCLockMode(on). It logs "SYSAPI_ConfigSystemPostFRCLockMode
 * = %d" (s_001a6f48, FUN_a00df170) and then sets or clears bit 27 (0x8000000) of the
 * RAM config word DAT_a802e3d0: on != 0 AND the u16 at +0x0a of the transformed row
 * (*DAT_a802d6a4, the 2nd size value that FUN_a00fc044 passes to FUN_a00fb434 with h08) < 0x1000
 * -> bit set; otherwise (off, or that size >= 4096) -> bit cleared.
 * For a row with +0x0a < 4096 bit 27 follows 'on' only. The function reads no input timing at all.
 * Returns nothing (Ghidra's CONCAT44 return is not real). Source form: u8 param, the string as its symbol
 * s_001a6f48, the struct PanelParam row (the src/leon2m/FUN_a00fc044.c layout).
 * Aids: none. volatile: none (DAT_a802e3d0 is RAM).
 */
struct PanelParam { unsigned int w0; unsigned short h4; unsigned char b6, b7; unsigned short h08, h0a; };
extern struct PanelParam *DAT_a802d6a4;
extern unsigned int DAT_a802e3d0;
extern char s_001a6f48[];
extern int FUN_a00df170();

void FUN_a0148e34(unsigned char on)
{
    FUN_a00df170(s_001a6f48, on);
    if (on) {
        if (DAT_a802d6a4->h0a < 0x1000)
            DAT_a802e3d0 |= 0x8000000;
        else
            DAT_a802e3d0 &= ~0x8000000;
    } else
        DAT_a802e3d0 &= ~0x8000000;
}
