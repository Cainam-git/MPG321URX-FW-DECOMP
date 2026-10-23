/* 8051_bank2 FUN_CODE_60b9 @ 0x60b9 (1159 bytes), OPTIMIZE(8,SPEED) LARGE. Called from FUN_CODE_b5b4 (0xb6a0, 0xb6a8).
 * Prints "device mode\r\n" (CODE 0x7DDB) with FUN_CODE_65ab, clears bit DAT_BIT_0000 and calls FUN_CODE_e004, then
 * programs the 32-bit registers read with FUN_CODE_9b91(reg) and written with FUN_CODE_b317(reg, value):
 * read-modify-writes of 0x80, 0x1C8 and 0x100, constant writes to 0x104..0x14C, [0x100] |= 0x10, a FUN_CODE_e44b(10)
 * wait and a return when bit 4 of [0x100] is still set; the same with [0x120] bit 3; then 0x1A0..0x1AC, 0x200 to
 * 0x160 + 4 i and 0x180 + 4 i (i = 0..7), and for i = 0..3 0x1000 to 0x1B0 + 4 i with a wait and a return when that
 * bit reads back set. Ends with a second register block, [0x100] |= 4, DAT_BIT_0000 = 1, FUN_CODE_e004, eleven
 * XDATA byte stores at 0x5005..0x513A, FUN_CODE_da02 and the word 0x40 at XDATA 0x09BD.
 * LARGE locals at XDATA 0x08E5 v, 0x08E9 i.
 * Compiler aid: the '|| 0' in the first bit-4 test emits no code; the logical-or form makes Keil drop the unused
 * clear of R6 after the AND and load the next argument with MOV R6,#1 instead of INC R6.
 */
extern bit DAT_BIT_0000;
extern unsigned int xdata DAT_EXTMEM_09bd;
extern unsigned char xdata DAT_EXTMEM_5005;
extern unsigned char xdata DAT_EXTMEM_5006;
extern unsigned char xdata DAT_EXTMEM_5008;
extern unsigned char xdata DAT_EXTMEM_500e;
extern unsigned char xdata DAT_EXTMEM_503a;
extern unsigned char xdata DAT_EXTMEM_5105;
extern unsigned char xdata DAT_EXTMEM_5106;
extern unsigned char xdata DAT_EXTMEM_5108;
extern unsigned char xdata DAT_EXTMEM_5109;
extern unsigned char xdata DAT_EXTMEM_510e;
extern unsigned char xdata DAT_EXTMEM_513a;
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_e004(void);
void FUN_CODE_da02(void);
extern void FUN_CODE_65ab(void *fmt, ...) large;

void FUN_CODE_60b9(void)
{
    unsigned long v;
    unsigned char i;
    FUN_CODE_65ab((void code *)0x7ddb);
    DAT_BIT_0000 = 0;
    FUN_CODE_e004();
    v = FUN_CODE_9b91(0x0080);
    v |= 0x400;
    v |= 0x10;
    FUN_CODE_b317(0x0080, v);
    v = FUN_CODE_9b91(0x01c8);
    v &= 0x7fffffff;
    FUN_CODE_b317(0x01c8, v);
    v = FUN_CODE_9b91(0x0100);
    v |= 0x20;
    v &= ~0x202;
    FUN_CODE_b317(0x0100, v);
    FUN_CODE_b317(0x0104, 0);
    FUN_CODE_b317(0x0124, 7);
    FUN_CODE_b317(0x00c4, 7);
    FUN_CODE_b317(0x0130, 7);
    FUN_CODE_b317(0x0134, 0x3f);
    FUN_CODE_b317(0x0138, 0x000f00ff);
    FUN_CODE_b317(0x013c, 0x7ff);
    FUN_CODE_b317(0x00c0, 7);
    FUN_CODE_b317(0x0140, 0);
    FUN_CODE_b317(0x0144, 0);
    FUN_CODE_b317(0x0148, 0);
    FUN_CODE_b317(0x014c, 0);
    v = FUN_CODE_9b91(0x0100);
    v |= 0x10;
    FUN_CODE_b317(0x0100, v);
    FUN_CODE_e44b(10);
    if ((FUN_CODE_9b91(0x0100) & 0x10) || 0) return;
    v = FUN_CODE_9b91(0x0120);
    v |= 8;
    FUN_CODE_b317(0x0120, v);
    FUN_CODE_e44b(10);
    if (FUN_CODE_9b91(0x0120) & 8) return;
    FUN_CODE_b317(0x01a0, 0x33221100);
    FUN_CODE_b317(0x01a4, 0);
    FUN_CODE_b317(0x01a8, 0x04030201);
    FUN_CODE_b317(0x01ac, 0);
    for (i = 0; i < 8; i++) {
        FUN_CODE_b317(0x0160 + i * 4, 0x200);
        FUN_CODE_b317(0x0180 + i * 4, 0x200);
    }
    for (i = 0; i < 4; i++) {
        FUN_CODE_b317(0x01b0 + i * 4, 0x1000);
        FUN_CODE_e44b(10);
        if (FUN_CODE_9b91(0x01b0 + i * 4) & 0x1000) return;
    }
    FUN_CODE_b317(0x00c4, 6);
    FUN_CODE_b317(0x00c0, 7);
    FUN_CODE_b317(0x0134, 6);
    FUN_CODE_b317(0x0138, 0x000f00ff);
    FUN_CODE_b317(0x013c, 0x7e0);
    FUN_CODE_b317(0x0130, 0);
    FUN_CODE_b317(0x0124, 7);
    v = FUN_CODE_9b91(0x0100);
    v |= 4;
    FUN_CODE_b317(0x0100, v);
    DAT_BIT_0000 = 1;
    FUN_CODE_e004();
    DAT_EXTMEM_5109 = 2;
    DAT_EXTMEM_5005 = 0x53;
    DAT_EXTMEM_500e = 0;
    DAT_EXTMEM_5008 = 6;
    DAT_EXTMEM_503a = 0x32;
    DAT_EXTMEM_5006 = 0x1c;
    DAT_EXTMEM_5105 = 0x53;
    DAT_EXTMEM_510e = 0;
    DAT_EXTMEM_5108 = 6;
    DAT_EXTMEM_513a = 0x32;
    DAT_EXTMEM_5106 = 0x1c;
    FUN_CODE_da02();
    DAT_EXTMEM_09bd = 0x40;
}
