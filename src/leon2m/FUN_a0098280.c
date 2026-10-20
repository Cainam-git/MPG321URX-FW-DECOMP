/* leon2m FUN_a0098280 @ 0xa0098280 (-mcpu=v8 -O2 -g)
 * Sets DAT_a802b08f = 5 and DAT_a802d290[0x1A3] = 0 and calls FUN_a00b621c. Copies the byte DAT_a802d290[0x1E]
 * to DAT_a8025c55, then converts it three times with FUN_a01445fc, re-reading DAT_a802d290[0x1E] for the second
 * and third call: _DAT_a802afec = (first result & 0xFF) + 0xD4; FUN_a00a9650(second result & 0xFF, 0);
 * FUN_a00a9650(third result & 0xFF, 1) as a tail call (restore in the delay slot).
 */
extern unsigned char DAT_a8025c55;   // 0xa8025c55
extern unsigned char DAT_a802b08f;   // 0xa802b08f
extern unsigned char DAT_a802d290[]; // base 0xa802d290
extern unsigned int _DAT_a802afec;   // 0xa802afec

extern void FUN_a00b621c(void);      // 0xa00b621c
extern int FUN_a01445fc(unsigned char); // 0xa01445fc
extern void FUN_a00a9650(int, int);  // 0xa00a9650

void FUN_a0098280(void)
{
    unsigned char uVar1;

    DAT_a802b08f = 5;
    DAT_a802d290[0x1a3] = 0;
    FUN_a00b621c();
    uVar1 = DAT_a802d290[0x1e];
    DAT_a8025c55 = uVar1;
    uVar1 = FUN_a01445fc(uVar1);
    _DAT_a802afec = (uVar1 & 0xff) + 0xd4;
    uVar1 = FUN_a01445fc(DAT_a802d290[0x1e]);
    FUN_a00a9650(uVar1 & 0xff, 0);
    uVar1 = FUN_a01445fc(DAT_a802d290[0x1e]);
    FUN_a00a9650(uVar1 & 0xff, 1);
}
