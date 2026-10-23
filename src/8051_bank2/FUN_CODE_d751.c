/* 8051_bank2 FUN_CODE_d751 @ 0xd751 (127 B), OPTIMIZE(8,SPEED) LARGE. Callers: FUN_CODE_1000 and FUN_CODE_1e55 (10 sites).
 * Copies a saved position into the working variables. XDATA 0x041C == 2: the long at 0x03EE = the long at 0x0117 and
 * the word at 0x040A = the word at 0x011B (the struct Pos {blk, off} of FUN_CODE_a17e.c). Otherwise the five saved
 * values of the record at 0x03F2 {long a; char n; int p; long b; long c} go to 0x0414 (long), 0x0429 (byte),
 * 0x0150 (word), 0x01DE (long) and 0x0410 (long), the arguments that FUN_CODE_72b0 is given in FUN_CODE_a17e.c.
 */
struct Pos { unsigned long blk; unsigned int off; };
struct Ent { unsigned long a; unsigned char n; unsigned int p; unsigned long b; unsigned long c; };
extern struct Pos xdata DAT_EXTMEM_0117;
extern struct Ent xdata DAT_EXTMEM_03f2;
extern unsigned char xdata DAT_EXTMEM_041c;
extern unsigned long xdata DAT_EXTMEM_03ee;
extern unsigned int xdata DAT_EXTMEM_040a;
extern unsigned long xdata DAT_EXTMEM_0414;
extern unsigned char xdata DAT_EXTMEM_0429;
extern unsigned int xdata DAT_EXTMEM_0150;
extern unsigned long xdata DAT_EXTMEM_01de;
extern unsigned long xdata DAT_EXTMEM_0410;
void FUN_CODE_d751(void)
{
    if (DAT_EXTMEM_041c == 2) {
        DAT_EXTMEM_03ee = DAT_EXTMEM_0117.blk;
        DAT_EXTMEM_040a = DAT_EXTMEM_0117.off;
    } else {
        DAT_EXTMEM_0414 = DAT_EXTMEM_03f2.a;
        DAT_EXTMEM_0429 = DAT_EXTMEM_03f2.n;
        DAT_EXTMEM_0150 = DAT_EXTMEM_03f2.p;
        DAT_EXTMEM_01de = DAT_EXTMEM_03f2.b;
        DAT_EXTMEM_0410 = DAT_EXTMEM_03f2.c;
    }
}
