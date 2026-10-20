/* leon2m FUN_a009665c @ 0xa009665c-0xa0096704 (42 words), flags -mcpu=v8 -O3 -g.
 * Code facts: byte DAT_a802d290[0x8e] = DAT_a802d290[0x14]; byte DAT_a8025c56 = DAT_a802d290[0x11];
 * FUN_a00a8c88(); FUN_a00a8570(); FUN_a00a813c(1, DAT_a802d290[0x11] (reloaded), 0); word
 * DAT_a802afec = 0x6f; FUN_a00a9650(3, 0); FUN_a00a9650((u8)(DAT_a802afec - 0x6c) (reloaded), 1);
 * FUN_a00ab4bc(); FUN_a00a9468(2, 5); FUN_a00a9468(0, 0); FUN_a00a9468(1, 2);
 * FUN_a00b34d4(0, 1); tail call FUN_a00b344c(7). void, no params (i1..i5 are never read).
 * Fixes vs the autoc draft (83.33): BEHAVIOUR: the draft lost the d290[0x8e] = d290[0x14] copy,
 * called a8570 BEFORE a8c88 (fw: a8c88 first, both void(void)) and stored a8c88's result into
 * d31e; real base DAT_a802d290 (draft used d2a1). Source order: the 0x8e copy before the 5c56 store
 * (the other order loads 0x11 first). Aids: none.
 */
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802d290[];
extern unsigned int DAT_a802afec;
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a8570(void);
extern void FUN_a00a8c88(void);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00ab4bc(void);
extern void FUN_a00b344c(unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a009665c(void)
{
    DAT_a802d290[0x8e] = DAT_a802d290[0x14];
    DAT_a8025c56 = DAT_a802d290[0x11];
    FUN_a00a8c88();
    FUN_a00a8570();
    FUN_a00a813c(1, DAT_a802d290[0x11], 0);
    DAT_a802afec = 0x6f;
    FUN_a00a9650(3, 0);
    FUN_a00a9650(DAT_a802afec - 0x6c, 1);
    FUN_a00ab4bc();
    FUN_a00a9468(2, 5);
    FUN_a00a9468(0, 0);
    FUN_a00a9468(1, 2);
    FUN_a00b34d4(0, 1);
    FUN_a00b344c(7);
}
