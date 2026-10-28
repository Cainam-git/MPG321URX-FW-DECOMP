/* leon2m FUN_a00d23b8 @ 0xa00d23b8-0xa00d24d8 (72 words), flags -mcpu=v8 -O3 (no -g). No direct callers (reached
 * through a table).
 * Command handler taking a pointer to a received frame: copies one 3-byte entry of the table at 0xa802e1f0 to
 * another. Frame byte 6 selects the source and frame byte 7 the destination (1 -> offset 6, 2 -> 0x12, 3 -> 9,
 * 5 -> 0x21); any other value returns 0xe3. Then FUN_a0145360(0) runs and the function returns 0xe0.
 * Source form: the three bytes are copied through three byte locals (a structure copy goes through the stack);
 * the case order of the two switches decides the base registers.
 */
struct Rgb { unsigned char c0, c1, c2; };
struct E1f0 { unsigned char p00[6]; struct Rgb s06; struct Rgb s09; unsigned char p0c[0x12 - 0xc]; struct Rgb s12;
              unsigned char p15[0x21 - 0x15]; struct Rgb s21; };
extern struct E1f0 DAT_a802e1f0;
extern void FUN_a0145360(unsigned char);

int FUN_a00d23b8(unsigned char *p)
{
    unsigned char c0, c1, c2;

    switch (p[6]) {
    case 1:
        c0 = DAT_a802e1f0.s06.c0;
        c1 = DAT_a802e1f0.s06.c1;
        c2 = DAT_a802e1f0.s06.c2;
        break;
    case 3:
        c0 = DAT_a802e1f0.s09.c0;
        c1 = DAT_a802e1f0.s09.c1;
        c2 = DAT_a802e1f0.s09.c2;
        break;
    case 2:
        c0 = DAT_a802e1f0.s12.c0;
        c1 = DAT_a802e1f0.s12.c1;
        c2 = DAT_a802e1f0.s12.c2;
        break;
    case 5:
        c0 = DAT_a802e1f0.s21.c0;
        c1 = DAT_a802e1f0.s21.c1;
        c2 = DAT_a802e1f0.s21.c2;
        break;
    default:
        return 0xe3;
    }
    switch (p[7]) {
    case 1:
        DAT_a802e1f0.s06.c0 = c0;
        DAT_a802e1f0.s06.c1 = c1;
        DAT_a802e1f0.s06.c2 = c2;
        break;
    case 3:
        DAT_a802e1f0.s09.c0 = c0;
        DAT_a802e1f0.s09.c1 = c1;
        DAT_a802e1f0.s09.c2 = c2;
        break;
    case 2:
        DAT_a802e1f0.s12.c0 = c0;
        DAT_a802e1f0.s12.c1 = c1;
        DAT_a802e1f0.s12.c2 = c2;
        break;
    case 5:
        DAT_a802e1f0.s21.c0 = c0;
        DAT_a802e1f0.s21.c1 = c1;
        DAT_a802e1f0.s21.c2 = c2;
        break;
    default:
        return 0xe3;
    }
    FUN_a0145360(0);
    return 0xe0;
}
