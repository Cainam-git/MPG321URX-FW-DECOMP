/* leon2m FUN_a00ad02c @ 0xa00ad02c  (-mcpu=v8 -O3 -g -msoft-float)
 * Redraws a menu page. When force is non-zero and DAT_a802b08d already equals page, nothing is done. Otherwise
 * DAT_a802b08d = page, func_0x4008e2a4() is called, rows 5..0x14 are cleared (FUN_a0146b20(0, 0x13, row, 0x13,
 * 0, 0) and FUN_a0146a80(0x13, row, 0x13, 0x792, 0)), then FUN_a0146b20(0, 0x1C, 0x15, 2, 0, 0),
 * FUN_a0146c40(5, 0, 0), FUN_a0146b50(0x92, 0) and FUN_a0146b6c(0, 0). For page 0 it draws seven items i = 0..6
 * at row i * 2 + 6: when FUN_a00aa520(i) returns 0 the field is first painted with FUN_a0146a80(0x14, row, 0xD,
 * 0x292, 0); the text is entry i * 29 + DAT_a802d290 byte +8 of the table at 0x188DA0 (FUN_a00a3844,
 * FUN_a00a31a4). Then FUN_a00b6994, FUN_a00b69d0 and FUN_a00b6b68 are called.
 * Callers: FUN_a0091a68, FUN_a0091b94, FUN_a0094438, FUN_a00b0034, FUN_a00b1004 and others.
 * Source form: a pointer to DAT_a802d290 declared inside the page-0 block; with direct accesses or a pointer at
 * function scope the compiler also keeps the table address in a register across the loop.
 */
struct R290 { unsigned char pad[8]; unsigned char b08; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b08d;
extern void func_0x4008e2a4(void);
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146b50(int, int);
extern void FUN_a0146b6c(int, int);
extern unsigned char FUN_a00aa520(unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, unsigned int, unsigned char);
extern void FUN_a00b6994(void);
extern void FUN_a00b69d0(void);
extern void FUN_a00b6b68(void);

void FUN_a00ad02c(unsigned char page, unsigned char force)
{
    unsigned char i;

    if (force && DAT_a802b08d == page)
        return;
    DAT_a802b08d = page;
    func_0x4008e2a4();
    for (i = 5; i <= 0x14; i++) {
        FUN_a0146b20(0, 0x13, i, 0x13, 0, 0);
        FUN_a0146a80(0x13, i, 0x13, 0x792, 0);
    }
    FUN_a0146b20(0, 0x1c, 0x15, 2, 0, 0);
    FUN_a0146c40(5, 0, 0);
    FUN_a0146b50(0x92, 0);
    FUN_a0146b6c(0, 0);
    if (page == 0) {
        struct R290 *p = &DAT_a802d290;
        for (i = 0; i <= 6; i++) {
            if (!FUN_a00aa520(i))
                FUN_a0146a80(0x14, i * 2 + 6, 0xd, 0x292, 0);
            FUN_a00a31a4(0, 0x14, i * 2 + 6, 1, FUN_a00a3844((unsigned int *)0x188da0, i * 29 + p->b08), 0);
        }
        FUN_a00b6994();
        FUN_a00b69d0();
        FUN_a00b6b68();
    }
}
