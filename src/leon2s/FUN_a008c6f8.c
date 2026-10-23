/* FUN_a008c6f8 (leon2s 0xa008c6f8-0xa008c8b0, 440 bytes), flags -mcpu=v8 -Os -g.
 * Local array ids = {4, 6, 8, 10, 12, 14} (initialiser bytes at DAT_a00b4030, copied with memcpy), m = FUN_a008bc44(), and
 * for each selector s with FUN_a0089f98(s) != 0: s 4/6 uses k = (s != 4) and the 20-byte record
 * ARR_a807a824[k + 4] (only when bit k of m is set), s 8/10/12/14 uses k = 0..3 and ARR_a807a824[k]; when the
 * record's byte 0 is 5, f = bit 6 of its halfword +0x12 (k and f keep their values across selectors). Then
 * s > 7: FUN_a008b5d0(FUN_a008a040(s), f); otherwise FUN_a008b75c(FUN_a008a040(s), f) and
 * FUN_a008c5d8(s, FUN_a008a040(s)).
 * Source form: switch on s (GCC emits bit tests 0x50 / 0x5500) with an if chain for k in the 8..14 case; memcpy is
 * the firmware's FUN_a00b15d8, declared by its link name.
 */
struct Rec { unsigned char b0; unsigned char pad[0x11]; unsigned short h12; };
extern struct Rec ARR_a807a824[];
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern unsigned char FUN_a008bc44(void);
extern unsigned short FUN_a0089f98(unsigned char);
extern unsigned int FUN_a008a040(unsigned char);
extern void FUN_a008b5d0(unsigned char port, unsigned char en);
extern void FUN_a008b75c(unsigned char port, unsigned char en);
extern void FUN_a008c5d8(unsigned char sel, unsigned char port);

void FUN_a008c6f8(void)
{
    unsigned char ids[6] = {4, 6, 8, 10, 12, 14};
    unsigned char m;
    unsigned char k = 0;
    unsigned char f = 0;
    unsigned char i;
    unsigned char s;

    m = FUN_a008bc44();
    for (i = 0; i < 6; i++) {
        s = ids[i];
        if (FUN_a0089f98(s) == 0)
            continue;
        switch (s) {
        case 4:
        case 6:
            k = s != 4;
            if (ARR_a807a824[k + 4].b0 == 5 && ((m >> k) & 1))
                f = (ARR_a807a824[k + 4].h12 >> 6) & 1;
            break;
        case 8:
        case 10:
        case 12:
        case 14:
            if (s == 8)
                k = 0;
            else if (s == 10)
                k = 1;
            else if (s == 12)
                k = 2;
            else if (s == 14)
                k = 3;
            if (ARR_a807a824[k].b0 == 5)
                f = (ARR_a807a824[k].h12 >> 6) & 1;
            break;
        }
        if (s > 7)
            FUN_a008b5d0(FUN_a008a040(s), f);
        else {
            FUN_a008b75c(FUN_a008a040(s), f);
            FUN_a008c5d8(s, FUN_a008a040(s));
        }
    }
}
