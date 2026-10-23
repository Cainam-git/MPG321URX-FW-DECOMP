/* leon2m FUN_a012b418 @ 0xa012b418 (-mcpu=v8 -O2 -g)
 * Stores p2, p3 and p4 in bytes +8, +0xa and +0xb of the 22-byte (0x16) entry (p1 & 0xff) of the table at 0xA802D8AE,
 * then calls FUN_a0137d08(p1, p2, p3, p4, p5) with the low byte of each argument (tail call). Same table as
 * FUN_a012b328 (byte +3).
 */
extern void FUN_a0137d08(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa0137d08 */

extern unsigned char DAT_a802d8ae[]; /* 0xa802d8ae */

void FUN_a012b418(unsigned int param_1, char param_2, unsigned int param_3,
                  unsigned int param_4, unsigned int param_5)
{
    unsigned int idx = (param_1 & 0xff) * 0x16;
    DAT_a802d8ae[idx + 8] = param_2;
    DAT_a802d8ae[idx + 0xa] = param_3;
    DAT_a802d8ae[idx + 0xb] = param_4;
    FUN_a0137d08(param_1 & 0xff, param_2 & 0xff, param_3 & 0xff, param_4 & 0xff, param_5 & 0xff);
}
