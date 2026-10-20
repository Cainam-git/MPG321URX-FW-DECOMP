/* leon2s FUN_a0091ac4 @ 0xa0091ac4  MATCH (-mcpu=v8 -Os -g)
 * 
 */
extern unsigned int ARR_a807d580[];

void FUN_a0091ac4(unsigned int param_1)
{
    unsigned int idx = param_1 & 0xff;
    unsigned int *p = &ARR_a807d580[idx * 7];

    if (idx > 1) {
        return;
    }
    p[1] |= 0x80000000;
}
