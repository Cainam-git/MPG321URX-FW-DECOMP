/* leon2s FUN_a00d24ac @ 0xa00d24ac-0xa00d25f4, -mcpu=v8 -Os -g.
 * Returns 1. For the registers 0xd0013f18, 0xd0013f1c, 0xd0013f20, 0xd0013f24 (ROM helpers outside the image):
 * local = func_0xa0f71528(reg); func_0xa0f714b8(&local, 0xf, 0, w[2k]); func_0xa0f714b8(&local, 0x1f, 0x10,
 * w[2k + 1]); func_0xa0f71534(reg, local), with w = the word table DAT_a80779e0. Register 0xd0013f28 gets
 * only the (0xf, 0, w[8]) step. Same read-modify-write form as FUN_a00d27fc.
 * Source form: the word local is initialised to 0 at its declaration (the firmware clears it first).
 */
extern unsigned int DAT_a80779e0[];
extern unsigned int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned int);
extern void func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d24ac(void)
{
    unsigned int local = 0;

    local = func_0xa0f71528(0xd0013f18);
    func_0xa0f714b8(&local, 0xf, 0, DAT_a80779e0[0]);
    func_0xa0f714b8(&local, 0x1f, 0x10, DAT_a80779e0[1]);
    func_0xa0f71534(0xd0013f18, local);
    local = func_0xa0f71528(0xd0013f1c);
    func_0xa0f714b8(&local, 0xf, 0, DAT_a80779e0[2]);
    func_0xa0f714b8(&local, 0x1f, 0x10, DAT_a80779e0[3]);
    func_0xa0f71534(0xd0013f1c, local);
    local = func_0xa0f71528(0xd0013f20);
    func_0xa0f714b8(&local, 0xf, 0, DAT_a80779e0[4]);
    func_0xa0f714b8(&local, 0x1f, 0x10, DAT_a80779e0[5]);
    func_0xa0f71534(0xd0013f20, local);
    local = func_0xa0f71528(0xd0013f24);
    func_0xa0f714b8(&local, 0xf, 0, DAT_a80779e0[6]);
    func_0xa0f714b8(&local, 0x1f, 0x10, DAT_a80779e0[7]);
    func_0xa0f71534(0xd0013f24, local);
    local = func_0xa0f71528(0xd0013f28);
    func_0xa0f714b8(&local, 0xf, 0, DAT_a80779e0[8]);
    func_0xa0f71534(0xd0013f28, local);
    return 1;
}
