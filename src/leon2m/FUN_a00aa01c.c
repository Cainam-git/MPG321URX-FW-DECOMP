/* leon2m FUN_a00aa01c @ 0xa00aa01c-0xa00aa0e8 (204 bytes), flags -mcpu=v8 -O3 -g.
 * row = sel * 2 + 6. For any sel other than 4: FUN_a00b34d4(0, 4) (tail call). For sel 4 a flag is 1 when bit 9 of
 * the word 0xa802d290 is set, else 0; v = 0x742 (mode 1) or 0x792 (other modes) when the flag is 1, 0x200 less
 * otherwise; FUN_a00b32e4(1, 1, v, 0x22, row, 3, k) with k = 0x37 for v 0x742 and 0x792, else 0x34; then
 * FUN_a00b34d4(0, 2) (tail call).
 * Same form as FUN_a00aa258 for the single selector 4. Source form: the FUN_a00b32e4 call written once per k value
 * in an if/else on the v test (the two calls are merged by cross-jumping into one call after a branch that selects
 * k).
 */
extern unsigned int DAT_a802d290;
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a00aa01c(unsigned char sel, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short v;

    row = sel * 2 + 6;
    if (sel == 4) {
        on = 1;
        if (!(DAT_a802d290 & 0x200))
            on = 0;
    }
    if (sel == 4) {
        if (mode == 1)
            v = on == 1 ? 0x742 : 0x542;
        else
            v = on == 1 ? 0x792 : 0x592;
        if (v == 0x742 || v == 0x792)
            FUN_a00b32e4(1, 1, v, 0x22, row, 3, 0x37);
        else
            FUN_a00b32e4(1, 1, v, 0x22, row, 3, 0x34);
        FUN_a00b34d4(0, 2);
    } else
        FUN_a00b34d4(0, 4);
}
