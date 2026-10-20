/* leon2m FUN_a00d1e3c @ 0xa00d1e3c-0xa00d1ed8 (39 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Command handler taking a pointer to a received frame: byte 7 of the frame selects a value v (1 -> 2, 2 -> 0,
 * 3 -> 1, 4 -> 3); any other byte returns 0xe3. When byte 0xa802d2a1 (0xa802d290+0x11) differs from v it is set
 * to v, FUN_a00d9764() and FUN_a0089f10() run and FUN_a014aed0(0x30, 0xa802d290, 0, 0x1fc) saves the 0x1fc-byte
 * structure at 0xa802d290. Returns 0xe0.
 */
struct R290 { unsigned char p000[0x11]; unsigned char b011; unsigned char p012[0x1fc - 0x12]; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d9764(void);
extern void FUN_a0089f10(void);
extern int FUN_a014aed0(int, void *, int, int);

int FUN_a00d1e3c(unsigned char *p)
{
    unsigned char v;

    switch (p[7]) {
    case 1:
        v = 2;
        break;
    case 2:
        v = 0;
        break;
    case 3:
        v = 1;
        break;
    case 4:
        v = 3;
        break;
    default:
        return 0xe3;
    }
    if (DAT_a802d290.b011 != v) {
        DAT_a802d290.b011 = v;
        FUN_a00d9764();
        FUN_a0089f10();
        FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
    }
    return 0xe0;
}
