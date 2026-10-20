/* leon2m FUN_a009e154 @ 0xa009e154  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a009e0bc: same code, constants swapped; byte-exact.
 * See FUN_a009e0bc for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a93bc(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern unsigned char FUN_a00aad30(unsigned char);

void FUN_a009e154(void)
{
    int r;

    FUN_a00a93bc(DAT_a802afec + 0x3d);
    do {
        r = ((unsigned short)DAT_a802afec - 0xc2) % 2;
        DAT_a802afec = r + 0xc3;
    } while (FUN_a00aad30(r) != 1);
    FUN_a00a9650(DAT_a802afec + 0x3d, 1);
    if (DAT_a802afec - 0xc3 == DAT_a8025c56)
        FUN_a00a813c(1, DAT_a8025c56, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56, 1);
}
