/* leon2m FUN_a0094438 @ 0xa0094438-0xa00945a8 (92 words).
 * By byte DAT_a802d290+0x1a3: 0 and 1 store 0xe1 / 0xe6 to word 0xa802afec and call FUN_a00b5378(),
 * FUN_a00b4144(1, 1), FUN_a00b4144(1, 2), FUN_a00a7ce8(), FUN_a00ad02c(0, 0), FUN_a00a900c(3 / 4, 2),
 * FUN_a00b3108(), FUN_a00a9650(4, 2) and FUN_a00a9650(4, 1); 2 stores 0x41 and calls FUN_a00b5378(),
 * FUN_a00b4144(0, 1), FUN_a00b4144(0, 2), FUN_a00a7ce8(), FUN_a00aaaac(), FUN_a00a900c(1, 2), FUN_a00a8c88(),
 * FUN_a00a82c4(), FUN_a00a9650(2, 1), FUN_a00a9468(1, 2), FUN_a00b34d4(0, 1). Then always FUN_a00a45a8() and
 * DAT_a802b08e |= 2.
 */
struct R290 {
    unsigned char pad[0x1a3];
    unsigned char b1a3;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08e;
extern void FUN_a00b5378(void);
extern void FUN_a00b4144(unsigned char, int);
extern void FUN_a00a7ce8(void);
extern void FUN_a00ad02c(unsigned char, int);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00b3108(void);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00aaaac(void);
extern void FUN_a00a8c88(void);
extern void FUN_a00a82c4(void);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(int, int);
extern void FUN_a00a45a8(void);

void FUN_a0094438(void)
{
    if (DAT_a802d290.b1a3 == 0) {
        _DAT_a802afec = 0xe1;
        FUN_a00b5378();
        FUN_a00b4144(1, 1);
        FUN_a00b4144(1, 2);
        FUN_a00a7ce8();
        FUN_a00ad02c(0, 0);
        FUN_a00a900c(3, 2);
        FUN_a00b3108();
        FUN_a00a9650(4, 2);
        FUN_a00a9650(4, 1);
    } else if (DAT_a802d290.b1a3 == 1) {
        _DAT_a802afec = 0xe6;
        FUN_a00b5378();
        FUN_a00b4144(1, 1);
        FUN_a00b4144(1, 2);
        FUN_a00a7ce8();
        FUN_a00ad02c(0, 0);
        FUN_a00a900c(4, 2);
        FUN_a00b3108();
        FUN_a00a9650(4, 2);
        FUN_a00a9650(4, 1);
    } else if (DAT_a802d290.b1a3 == 2) {
        _DAT_a802afec = 0x41;
        FUN_a00b5378();
        FUN_a00b4144(0, 1);
        FUN_a00b4144(0, 2);
        FUN_a00a7ce8();
        FUN_a00aaaac();
        FUN_a00a900c(1, 2);
        FUN_a00a8c88();
        FUN_a00a82c4();
        FUN_a00a9650(2, 1);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    }
    FUN_a00a45a8();
    DAT_a802b08e |= 2;
}
