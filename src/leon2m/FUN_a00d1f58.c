/* leon2m FUN_a00d1f58 @ 0xa00d1f58-0xa00d20a4.
 * Takes a pointer p to a received frame. Frame byte 6 selects component 0, 1 or 2 of a 3-byte entry of the table at
 * 0xa802e1f0; byte 0xa802d2a1 selects the entry (2 -> offset 6, 1 -> offset 9, 0 -> offset 0x12; other values store
 * nothing). Frame byte 7 is stored there, then passed to FUN_a013b42c / FUN_a013b44c / FUN_a013b46c (component 0 / 1
 * / 2); FUN_a0145360(0) follows and the function returns 0xe0. Other values of byte 6 return 0xe3.
 * Source form: switch cases in the order 0, 1, 2, each ending with its own 'FUN_a0145360(0); return 0xe0;'.
 */
struct Rgb { unsigned char c0, c1, c2; };
struct E1f0 { unsigned char p00[6]; struct Rgb s06; struct Rgb s09; unsigned char p0c[0x12 - 0xc]; struct Rgb s12; };
extern struct E1f0 DAT_a802e1f0;
extern unsigned char DAT_a802d2a1;
extern void FUN_a013b42c(unsigned short);
extern void FUN_a013b44c(unsigned short);
extern void FUN_a013b46c(unsigned short);
extern void FUN_a0145360(unsigned char);

int FUN_a00d1f58(unsigned char *p)
{
    switch (p[6]) {
    case 0:
        if (DAT_a802d2a1 == 2)
            DAT_a802e1f0.s06.c0 = p[7];
        else if (DAT_a802d2a1 == 1)
            DAT_a802e1f0.s09.c0 = p[7];
        else if (DAT_a802d2a1 == 0)
            DAT_a802e1f0.s12.c0 = p[7];
        FUN_a013b42c(p[7]);
        FUN_a0145360(0);
        return 0xe0;
    case 1:
        if (DAT_a802d2a1 == 2)
            DAT_a802e1f0.s06.c1 = p[7];
        else if (DAT_a802d2a1 == 1)
            DAT_a802e1f0.s09.c1 = p[7];
        else if (DAT_a802d2a1 == 0)
            DAT_a802e1f0.s12.c1 = p[7];
        FUN_a013b44c(p[7]);
        FUN_a0145360(0);
        return 0xe0;
    case 2:
        if (DAT_a802d2a1 == 2)
            DAT_a802e1f0.s06.c2 = p[7];
        else if (DAT_a802d2a1 == 1)
            DAT_a802e1f0.s09.c2 = p[7];
        else if (DAT_a802d2a1 == 0)
            DAT_a802e1f0.s12.c2 = p[7];
        FUN_a013b46c(p[7]);
        FUN_a0145360(0);
        return 0xe0;
    default:
        return 0xe3;
    }
}
