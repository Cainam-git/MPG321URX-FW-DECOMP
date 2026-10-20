/* leon2m FUN_a015b558 @ 0xa015b558  MATCH (-mcpu=v8 -O2 -g)
 * Initialises the structure at param_1 (+0x3C = 0xFB5C4, +0x38 = 1, +0x2E4 = 3, +0x2E8 = param_1 + 0x2EC,
 * +0x2E0 = 0) and calls FUN_a015b468(word +4, 6, 0, param_1), FUN_a015b468(word +8, 0xA, 1, param_1) and, as a tail
 * call, FUN_a015b468(word +0xC, 0xA, 2, param_1) ('restore %g0, 2, %o2'). Returns void.
 */
extern void FUN_a015b468(void *param_1, int param_2, int param_3, void *param_4);

void FUN_a015b558(void *param_1)
{
    *(unsigned int *)((char *)param_1 + 0x3c) = 0xfb5c4;
    *(unsigned int *)((char *)param_1 + 0x38) = 1;
    *(unsigned int *)((char *)param_1 + 0x2e4) = 3;
    *(unsigned int *)((char *)param_1 + 0x2e8) = (unsigned int)((char *)param_1 + 0x2ec);
    *(unsigned int *)((char *)param_1 + 0x2e0) = 0;

    FUN_a015b468(*(void **)((char *)param_1 + 4), 6, 0, param_1);
    FUN_a015b468(*(void **)((char *)param_1 + 8), 0xa, 1, param_1);
    FUN_a015b468(*(void **)((char *)param_1 + 0xc), 0xa, 2, param_1);
}
