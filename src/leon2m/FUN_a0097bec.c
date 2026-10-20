/* leon2m FUN_a0097bec @ 0xa0097bec-0xa0097c54 (26 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/26 mismatches.
 * Code facts: DAT_a802b08f = 5; FUN_a00ab2a8(); with b = byte DAT_a802d290[0x31]: _DAT_a802afec =
 * 0xcf - b, DAT_a8025c55 = b, FUN_a00a9650((u8)(2 - b), 0), then b is re-read after the call and
 * sibcall FUN_a00a9650((u8)(2 - b), 1). void(void).
 * Fixes vs the autoc draft (50.00): real base DAT_a802d290 as a plain (non-volatile) byte array, the
 * re-read comes from the call clobber; a00a9650 takes 2 args. Aids: none.
 */
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern void FUN_a00ab2a8(void);
extern void FUN_a00a9650(unsigned char, int);

void FUN_a0097bec(void)
{
    DAT_a802b08f = 5;
    FUN_a00ab2a8();
    _DAT_a802afec = 0xcf - DAT_a802d290[0x31];
    DAT_a8025c55 = DAT_a802d290[0x31];
    FUN_a00a9650(2 - DAT_a802d290[0x31], 0);
    FUN_a00a9650(2 - DAT_a802d290[0x31], 1);
}
