/* 8051_bank1 FUN_CODE_d095 @ 0xd095 (55 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Stores the 32-bit argument in XDATA 0xA70D (element 0 of the long array that FUN_CODE_cd8c reads) and prints it
 * with FUN_CODE_2820 (printf, tail jump) and the code string 0xC4CD "FE2P_SetLeon2BaseAddress %08lx\r\n".
 * LARGE model: the parameter lives at XDATA 0xA473 and is reloaded for each use; the printf argument block starts
 * at 0xA51A. Only caller FUN_CODE_3fe7 (0x408D).
 */
extern unsigned long xdata DAT_EXTMEM_a70d[];
extern void FUN_CODE_2820(void *fmt, ...) large;   /* printf */

void FUN_CODE_d095(unsigned long base)
{
    DAT_EXTMEM_a70d[0] = base;
    FUN_CODE_2820((void code *)0xc4cd /* "FE2P_SetLeon2BaseAddress %08lx\r\n" */, base);
}
