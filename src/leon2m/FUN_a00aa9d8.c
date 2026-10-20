/* leon2m FUN_a00aa9d8 @ 0xa00aa9d8  (-mcpu=v8 -O3 -g -msoft-float)
 * Calls FUN_a0146b50(0x92, 0) and FUN_a0146b6c(0, 0). For i = 0..2: when FUN_a00aa520(i) returns 0 it calls
 * FUN_a0146a80(0x14, i * 2 + 6, 0xF, 0x292, 0); then it calls FUN_a00a31a4(0, 0x14, i * 2 + 6, 1,
 * FUN_a00a3844(DAT_00188634, i * 29 + DAT_a802d290 byte +8), 0). Ends with a tail call of FUN_a00b6d58().
 * Callers: none by direct call.
 * Source form: the table at 0x188634 is an extern array symbol, not a cast integer constant; with a symbol the
 * compiler keeps only %hi of the table and of DAT_a802d290 in registers across the loop, as the firmware does.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern unsigned int DAT_00188634[];
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b6d58(void);

void FUN_a00aa9d8(void)
{
    unsigned char i;

    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);
    for (i = 0; i <= 2; i++) {
        if (!FUN_a00aa520(i))
            FUN_a0146a80(0x14, i * 2 + 6, 0xf, 0x292, 0);
        FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844(DAT_00188634, i * 29 + DAT_a802d290.b08), 0);
    }
    FUN_a00b6d58();
}
