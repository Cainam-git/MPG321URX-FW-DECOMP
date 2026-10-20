/* leon2s FUN_a00862e4 @ 0xa00862e4  MATCH (-mcpu=v8 -Os -g)
 * Up to 10 attempts: FUN_a0086030(p1 & 0xff, p2 & 0xff, p3, p4, p5), then FUN_a0086154(p1 & 0xff, p2 & 0xff, p4,
 * p5); stops as soon as FUN_a0086154 returns 0. Returns 1 when an attempt succeeded, 0 when all 10 failed (count
 * != 10, emitted as addx %g0, 0, %i0). param_4 is passed sign-extended.
 */
extern void FUN_a0086030();
extern unsigned char FUN_a0086154();

int FUN_a00862e4(unsigned int param_1, unsigned int param_2, unsigned int param_3, char param_4, unsigned int param_5)
{
    unsigned char bVar2 = 0;
    unsigned int uVar1;

    do {
        uVar1 = param_1 & 0xff;
        FUN_a0086030(uVar1, param_2 & 0xff, param_3, (int)param_4, param_5);
        if (FUN_a0086154(uVar1, param_2 & 0xff, (int)param_4, param_5) == 0)
            break;
        bVar2 = bVar2 + 1;
    } while (bVar2 < 10);

    return (bVar2 != 10) ? 1 : 0;
}
