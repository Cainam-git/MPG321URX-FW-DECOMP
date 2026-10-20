/* leon2m FUN_a0097814 @ 0xa0097814-0xa00978c8 (45 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls FUN_a00a8ee8(byte 0xa8025c56), FUN_a00a813c(0, byte 0xa8025c56, 0), FUN_a00a900c(afec - 35, 0),
 * FUN_a0097508, FUN_a00976f8 and FUN_a00a813c(0, byte 0xa802d2af, 1) (0xa802d290 + 0x1f); sets word 0xa802afec to
 * 7; calls FUN_a00b4144(5, 1), FUN_a00a9468(1, 2) and FUN_a00b34d4(0, 1). When byte 0xa802d2af differs from byte
 * 0xa8025c56 it tail-calls FUN_a00acef4.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a8025c56;
extern unsigned int DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a0097508(void);
extern void FUN_a00976f8(void);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00acef4(void);

void FUN_a0097814(void)
{
    FUN_a00a8ee8(DAT_a8025c56);
    FUN_a00a813c(0, DAT_a8025c56, 0);
    FUN_a00a900c(DAT_a802afec - 35, 0);
    FUN_a0097508();
    FUN_a00976f8();
    FUN_a00a813c(0, DAT_a802d290[0x1f], 1);
    DAT_a802afec = 7;
    FUN_a00b4144(5, 1);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    if (DAT_a802d290[0x1f] != DAT_a8025c56)
        FUN_a00acef4();
}
