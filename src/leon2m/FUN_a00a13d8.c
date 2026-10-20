/* leon2m FUN_a00a13d8 @ 0xa00a13d8-0xa00a14bc (57 words).
 * Calls FUN_a00a900c(selection word 0xa802afec - 52, 2). Then, for selection 0x38, 0x39 or 0x3a, the selection
 * becomes 0xc0, 0xc1 or 0xc2 and byte 0xa8025c56 is set from byte 0xa802d478, 0xa802d47a or 0xa802d47c; other values
 * leave both unchanged. Finally FUN_a00a9650(byte 0xa8025c56, 1) and FUN_a00a813c(1, byte 0xa8025c56, 0).
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern unsigned char DAT_a802d478, DAT_a802d47a, DAT_a802d47c;
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a00a13d8(void)
{
    FUN_a00a900c(_DAT_a802afec - 52, 2);
    switch (_DAT_a802afec) {
    case 0x38:
        _DAT_a802afec = 0xc0;
        DAT_a8025c56 = DAT_a802d478;
        break;
    case 0x39:
        DAT_a8025c56 = DAT_a802d47a;
        _DAT_a802afec = 0xc1;
        break;
    case 0x3a:
        _DAT_a802afec = 0xc2;
        DAT_a8025c56 = DAT_a802d47c;
        break;
    }
    FUN_a00a9650(DAT_a8025c56, 1);
    FUN_a00a813c(1, DAT_a8025c56, 0);
}
