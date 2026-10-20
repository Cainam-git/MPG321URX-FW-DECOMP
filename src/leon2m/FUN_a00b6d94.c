/* leon2m FUN_a00b6d94 @ 0xa00b6d94-0xa00b6e1c (34 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00961a4.
 * Toggles bit 4 of the word 0xa802d3ac (0xa802d290 + 0x11c); when the bit is set (it was clear) byte 0xa802d408
 * (+0x178) is also cleared. Then calls FUN_a00a9f30(1, bit 4) when FUN_a00d7d48() returns 0 and
 * FUN_a00a9f30(1, 0) otherwise, calls FUN_a00d4998 and sets bit 1 (0x02) of byte 0xa802b08e. Bit 4 is a 1-bit
 * bit-field. The non-zero result of FUN_a00d7d48 is the first if arm.
 */
struct R290 { unsigned char pad[0x11c]; unsigned int hi : 27, f4 : 1, lo : 4; unsigned char pad120[0x58];
              unsigned char b178; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08e;
extern int FUN_a00d7d48(void);
extern void FUN_a00a9f30(unsigned char, unsigned char);
extern void FUN_a00d4998(void);

void FUN_a00b6d94(void)
{
    if (DAT_a802d290.f4)
        DAT_a802d290.f4 = 0;
    else {
        DAT_a802d290.f4 = 1;
        DAT_a802d290.b178 = 0;
    }
    if (FUN_a00d7d48())
        FUN_a00a9f30(1, 0);
    else
        FUN_a00a9f30(1, DAT_a802d290.f4);
    FUN_a00d4998();
    DAT_a802b08e |= 2;
}
