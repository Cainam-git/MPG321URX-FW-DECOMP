/* leon2m FUN_a0152e28
 * Runs a sequence of FUN_a0152a20(code, x, &st) calls on one status byte st (starts at 0) and returns st * 3.
 * When bit 31 of the word 0xA802E3D0 is set: codes 0x51, 0x61, then 0x81 and 0x71 when FUN_a012ad6c()
 * returns 1, else 0x71 and 0x81. Otherwise n = 1..4 from the byte 0xA802E1A7 (0: 1; 1, 2, 5: 2; 3, 6: 3; 4, 7: 4;
 * above 7: 1) and the codes FUN_a012fc70(i) for i = 0..n-1. Always a final FUN_a0152a20(0xFF, x, &st).
 * Called by FUN_a0135dc0.
 * Source form: bit 31 is tested as a 1-bit bit-field (a '< 0' test gives other branch predictions and places the
 * case blocks of the switch before the bit-31 arm); the two FUN_a012ad6c arms each make their own FUN_a0152a20 call
 * (a code variable is if-converted).
 */
struct E3d0 { unsigned int b31 : 1, rest : 31; };
extern struct E3d0 DAT_a802e3d0;
extern unsigned char DAT_a802e1a7;
extern unsigned char FUN_a012ad6c(void);
extern unsigned char FUN_a012fc70(unsigned char);
extern void FUN_a0152a20(unsigned char code, unsigned int x, unsigned char *st);

unsigned char FUN_a0152e28(unsigned int x)
{
    unsigned char st = 0;
    unsigned char n = 1;
    unsigned char i;

    if (DAT_a802e3d0.b31) {
        FUN_a0152a20(0x51, x, &st);
        FUN_a0152a20(0x61, x, &st);
        if (FUN_a012ad6c() == 1)
            FUN_a0152a20(0x81, x, &st);
        else
            FUN_a0152a20(0x71, x, &st);
        if (FUN_a012ad6c() == 1)
            FUN_a0152a20(0x71, x, &st);
        else
            FUN_a0152a20(0x81, x, &st);
    } else {
        switch (DAT_a802e1a7) {
        case 0: n = 1; break;
        case 1: case 2: case 5: n = 2; break;
        case 3: case 6: n = 3; break;
        case 4: case 7: n = 4; break;
        }
        for (i = 0; i < n; i++)
            FUN_a0152a20(FUN_a012fc70(i), x, &st);
    }
    FUN_a0152a20(0xff, x, &st);
    return st * 3;
}
