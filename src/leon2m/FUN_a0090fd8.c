/* leon2m FUN_a0090fd8 @ 0xa0090fd8-0xa0091034 (23 words), flags -mcpu=v8 -O3 -g. Called from many functions
 * (FUN_a008ef48, FUN_a00b0f48, FUN_a00c1d54 and others).
 * When bit 15 of the halfword 0xa802cff8 (0xa802cff4 + 4) is set, sets bit 10 (0x400) of that halfword and calls
 * FUN_a00808ac(4, 0). In both cases word 0xa802afec is then cleared and FUN_a00b5080 is tail-called. The halfword is a union of
 * a plain halfword (for the | 0x400) and a bit-field view (bit 15).
 */
union H { unsigned short h; struct { unsigned short b15 : 1, rest : 15; } f; };
struct Rcff4 { unsigned char pad[4]; union H w4; };
extern struct Rcff4 DAT_a802cff4;
extern unsigned int DAT_a802afec;
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);

void FUN_a0090fd8(void)
{
    if (DAT_a802cff4.w4.f.b15) {
        DAT_a802cff4.w4.h |= 0x400;
        FUN_a00808ac(4, 0);
    }
    DAT_a802afec = 0;
    FUN_a00b5080();
}
