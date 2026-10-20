/* leon2m FUN_a012b418 @ 0xa012b418  MATCH (-mcpu=v8 -O2 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; swap lines 8; param param_2 char; selfassign idx#1; swap lines 10
 */
extern void FUN_a0137d08(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa0137d08 */

extern unsigned char DAT_a802d8ae[]; /* 0xa802d8ae */

void FUN_a012b418(unsigned int param_1, char param_2, unsigned int param_3,
                  unsigned int param_4, unsigned int param_5)
{
    unsigned int idx = (param_1 & 0xff) * 0x16;
    DAT_a802d8ae[idx + 8] = param_2;
    idx = idx;
    DAT_a802d8ae[idx + 0xa] = param_3;
    DAT_a802d8ae[idx + 0xb] = param_4;
    FUN_a0137d08(param_1 & 0xff, param_2 & 0xff, param_3 & 0xff, param_4 & 0xff, param_5 & 0xff);
}
