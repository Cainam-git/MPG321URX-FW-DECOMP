/* leon2m FUN_a00dd628 @ 0xa00dd628 (-mcpu=v8 -O2 -g)
 * FUN_a01393f0(p1 & 0xff, p2 & 0xff, (u16)p3), then prints "[DBG] Tensilica Cmd: 0x%02X_%02X_%04X" (0x198c30)
 * with p1, p2, p3 through FUN_a00df170.
 */
extern int FUN_a01393f0(unsigned int, unsigned int, unsigned short);
extern int FUN_a00df170();

void FUN_a00dd628(unsigned int param_1, unsigned int param_2, int param_3,
                  unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    unsigned short p3 = (unsigned short)(param_3 & 0xffff);
    unsigned int p1 = param_1 & 0xff;
    unsigned int p2 = param_2 & 0xff;

    FUN_a01393f0(p1, p2, p3);
    FUN_a00df170(0x198c30, param_1, param_2, param_3);
}
