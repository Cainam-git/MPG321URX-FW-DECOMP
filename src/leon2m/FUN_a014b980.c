/* FUN_a014b980: p == 0xfe: FUN_a0138c20(0x51, v), FUN_a0138c20(0x61, v), then FUN_a0138c20(0x81 when
 * FUN_a012ad6c() == 1, else 0x71, v), then FUN_a0138c20(0x71 when FUN_a012ad6c() == 1, else 0x81, v).
 * Otherwise k = FUN_a0142218(FUN_a0125198(p)) (u8) selects FUN_a0138c20(0x51 / 0x61 / 0x71 / 0x81, v) for
 * k 0..3; other k values do nothing. Caller: FUN_a00d99f8.
 */
extern int FUN_a0125198(unsigned char);
extern int FUN_a0142218(unsigned char);
extern unsigned char FUN_a012ad6c(void);
extern void FUN_a0138c20(unsigned char port, unsigned char v);

void FUN_a014b980(unsigned char p, unsigned char v)
{
    if (p == 0xfe) {
        FUN_a0138c20(0x51, v);
        FUN_a0138c20(0x61, v);
        if (FUN_a012ad6c() == 1)
            FUN_a0138c20(0x81, v);
        else
            FUN_a0138c20(0x71, v);
        if (FUN_a012ad6c() == 1)
            FUN_a0138c20(0x71, v);
        else
            FUN_a0138c20(0x81, v);
        return;
    }
    switch ((unsigned char)FUN_a0142218(FUN_a0125198(p))) {
    case 0:
        FUN_a0138c20(0x51, v);
        break;
    case 1:
        FUN_a0138c20(0x61, v);
        break;
    case 2:
        FUN_a0138c20(0x71, v);
        break;
    case 3:
        FUN_a0138c20(0x81, v);
        break;
    }
}
