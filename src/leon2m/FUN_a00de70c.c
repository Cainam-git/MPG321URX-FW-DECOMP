/* leon2m FUN_a00de70c @ 0xa00de70c..0xa00de7c4 (46 words)  DataRam_CheckConfig: the Big chip checks its data-RAM
 * window registers against the linker's data start.
 * What it does (code facts): reads 0x9F020204 and 0x9F020200 through Reg_Read32 (func_0x4008c250 = FUN_a002c250, the
 * RAM copy at CPU 0xA002C250); counts the ZERO bits 0..23 of 0x9F020204 plus the ONE bits 27..4 of 0x9F020200 (n, a
 * byte); the data-RAM bottom is then 0xA803C000 - n * 4 KiB. If that is not the link address of the data segment
 * (the linker symbol at 0xA8024000, i.e. n == 24), it prints the firmware's own text "DataRam register config :
 * 0x%08X, ld config : 0x%08X" (rodata CPU 0x00198E70) with both values and HANGS in 'for (;;)' (no timeout, no reset).
 * FW.021 values: the 8051 helper writes 0x9F020200 = record +0x18 and 0x9F020204 = record +0x1C (FUN_CODE_4a85), and
 * the boot loader FUN_CODE_0003 sets both record fields to the constant 0 (XDATA 0xA024..0xA02B), so n = 24 + 0 and
 * the bottom is 0xA8024000: the check passes. By the firmware's own arithmetic the Big chip's data RAM
 * starts at 0xA8024000; its top is not computed here (stack top 0xA803FF50 in the reset code, 8051 fill up to AHB
 * 0x9F07C000 = 0xA8040000).
 * The same check is inlined twice in FUN_a00de7c4 (start-up step 2's clock/RAM set-up, called from FUN_a015266c).
 * Callers: none found by call scan (no PC-relative call, no stored pointer); the copy inside FUN_a00de7c4 is the one
 * that runs. Exact form: the compare written pointer-to-pointer, (char *)bottom != ld (an integer compare swaps the cmp operands).
 * The data start is a linker symbol (sethi + 'or %lo' = 0), not a constant: declared as DAT_a8024000.
 */
extern unsigned int func_0x4008c250(unsigned int addr);
extern int FUN_a00df170(const char *fmt, ...);
extern char s_00198e70[];
extern char DAT_a8024000[];

void FUN_a00de70c(void)
{
    unsigned int v;
    unsigned char i;
    unsigned char n;
    unsigned int bottom;
    char *ld = DAT_a8024000;

    n = 0;
    v = func_0x4008c250(0x9f020204);
    for (i = 0; i < 24; i++)
        if (!((v >> i) & 1))
            n++;
    v = func_0x4008c250(0x9f020200);
    for (i = 27; i > 3; i--)
        if ((v >> i) & 1)
            n++;
    bottom = 0xa803c000 - (n << 12);
    if ((char *)bottom != ld) {
        FUN_a00df170(s_00198e70, bottom, ld);
        for (;;)
            ;
    }
}
