/* leon2m FUN_a00c0c74 @ 0xa00c0c74-0xa00c0cf8 (33 words), flags -mcpu=v8 -O3 -g.
 * Code facts: v = byte 0xa802d049 (port 2) / 0xa802d0a1 (port 3) / 0xa802d0d9 (other); d = v - '0';
 * if (u8)d <= 4: byte 0xa802cffd = d, FUN_a00baa6c(port), FUN_a00ba950(port), FUN_a00bab80(port, 6), return 0;
 * else return 0xff (one exit, result in %g1).
 * Fix vs the autoc draft (76.47): BEHAVIOUR - the range test is d <= 4 (draft: <= 1), the store goes
 * to 0xa802cffd (draft: 0xa802d47e) and there is no FUN_a00b88cc call; d is an int with a u8 test (fw keeps
 * the u8 v re-extended with 'and 0xff' and stores the unmasked d); single return. Aids: none.
 */
extern unsigned char DAT_a802d049, DAT_a802d0a1, DAT_a802d0d9;
extern unsigned char DAT_a802cffd;
extern void FUN_a00baa6c(unsigned char);
extern void FUN_a00ba950(unsigned char);
extern void FUN_a00bab80(unsigned char, int);

int FUN_a00c0c74(unsigned char port)
{
    unsigned char v;
    int d;
    int r;

    if (port == 2)
        v = DAT_a802d049;
    else if (port == 3)
        v = DAT_a802d0a1;
    else
        v = DAT_a802d0d9;
    d = v - 0x30;
    r = 0xff;
    if ((unsigned char)d <= 4) {
        DAT_a802cffd = d;
        FUN_a00baa6c(port);
        FUN_a00ba950(port);
        FUN_a00bab80(port, 6);
        r = 0;
    }
    return r;
}
