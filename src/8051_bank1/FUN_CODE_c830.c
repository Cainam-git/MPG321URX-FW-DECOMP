/* 8051_bank1 FUN_CODE_c830 @ 0xc830 (79 B)  Byte-exact with OPTIMIZE(8,SPEED).
 * Stores t zero-extended in the long at XDATA 0xA62A, multiplies that long by 1000 in place (?C?LMUL), stores the
 * current FUN_CODE_d94a() count (IDATA 0x57) in the uint at 0xA5E9 and prints the long with FUN_CODE_2820 (printf,
 * tail jump) and the code string 0x991D "wakeup timer setup %08lx\r\n".
 * Only caller: the command switch FUN_CODE_224f, command 28 ("setWakeupTimer %04x").
 * The store and the multiplication are two statements: the firmware writes 0xA62A, reads it back and writes it again.
 */
extern unsigned long xdata DAT_EXTMEM_a62a;
extern unsigned int xdata DAT_EXTMEM_a5e9;
extern unsigned int FUN_CODE_d94a(void);
extern void FUN_CODE_2820(void *fmt, ...) large;   /* printf */

void FUN_CODE_c830(unsigned int t)
{
    DAT_EXTMEM_a62a = t;
    DAT_EXTMEM_a62a = DAT_EXTMEM_a62a * 1000;
    DAT_EXTMEM_a5e9 = FUN_CODE_d94a();
    FUN_CODE_2820((void code *)0x991d /* "wakeup timer setup %08lx\r\n" */, DAT_EXTMEM_a62a);
}
