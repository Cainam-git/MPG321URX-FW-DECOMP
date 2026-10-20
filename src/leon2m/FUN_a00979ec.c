/* leon2m FUN_a00979ec @ 0xa00979ec-0xa0097ad0 (57 words).
 * Same sequence as FUN_a00978c8 with these differences: after FUN_a00976f8() the word 0xa802afec is set to
 * byte 0xa802d2bf (offset 0x2f of the block at 0xa802d290) + 0x7f, FUN_a00a813c(1, that byte, 0) is called and
 * FUN_a00a9650(word 0xa802afec - 127, 1) follows; at the end byte 0xa8025c54 is also set to that byte, and 0x10 instead of
 * 0xf is written to byte 0xa802b08f before the tail call FUN_a00d4998().
 */
extern unsigned char DAT_a8025c54;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d290[];
extern void FUN_a0097508(void);
extern void FUN_a00976f8(void);
extern void FUN_a00a813c(int, unsigned char, int);
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(int, int);
extern void FUN_a00acef4(void);
extern void FUN_a00d4998(void);

void FUN_a00979ec(void)
{
    unsigned char v;

    FUN_a00a8ee8(DAT_a8025c56);
    FUN_a00a813c(0, DAT_a8025c56, 0);
    FUN_a00a813c(0, DAT_a802d290[0x1f], 0);
    FUN_a00a900c(_DAT_a802afec - 35, 2);
    FUN_a0097508();
    FUN_a00976f8();
    _DAT_a802afec = DAT_a802d290[0x2f] + 0x7f;
    FUN_a00a813c(1, DAT_a802d290[0x2f], 0);
    v = _DAT_a802afec - 127;
    FUN_a00a9650(v, 1);
    v = DAT_a802d290[0x1f];
    if (v != DAT_a8025c56) {
        FUN_a00acef4();
        v = DAT_a802d290[0x1f];
    }
    DAT_a8025c56 = v;
    DAT_a8025c55 = DAT_a802d290[0x1a4];
    DAT_a8025c54 = DAT_a802d290[0x2f];
    DAT_a802b08f = 0x10;
    FUN_a00d4998();
}
