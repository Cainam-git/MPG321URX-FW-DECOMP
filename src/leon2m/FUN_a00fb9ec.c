/* leon2m FUN_a00fb9ec @ 0xa00fb9ec  MATCH (-mcpu=v8 -O3 -g)
 * Calls FUN_a00f9a00() and FUN_a00f9bbc(), then FUN_a00fb434(id, &value, DAT_a802d67a, DAT_a802d678) for the ids
 * 0xC..0x11 with the stack values 0, 1, 0, 0x80, 0x80 and 0x100, and returns 1. No direct callers found.
 * Source form: six separate locals; the order of their assignments decides the store schedule.
 */
extern void FUN_a00f9a00(void);
extern void FUN_a00f9bbc(void);
extern unsigned int FUN_a00fb434(unsigned int id, unsigned int *v, unsigned int w, unsigned int h);
extern unsigned short DAT_a802d67a;
extern unsigned short DAT_a802d678;

int FUN_a00fb9ec(void)
{
    unsigned int v11, v10, vf, ve, vd, vc;
    vf = 0x80;
    vd = 1;
    v10 = 0x80;
    v11 = 0x100;
    vc = 0;
    ve = 0;

    FUN_a00f9a00();
    FUN_a00f9bbc();
    FUN_a00fb434(0xc, &vc, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xd, &vd, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xe, &ve, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0xf, &vf, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0x10, &v10, DAT_a802d67a, DAT_a802d678);
    FUN_a00fb434(0x11, &v11, DAT_a802d67a, DAT_a802d678);
    return 1;
}
