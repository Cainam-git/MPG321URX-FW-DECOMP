/* leon2m FUN_a00de7c4 @ 0xa00de7c4..0xa00de970 (107 words)  Big chip core/RAM/timer set-up + data-RAM config check
 * Called once from start-up step 2 FUN_a015266c (0xA01527AC), before the 3 boot waits, i.e. long
 * before FUN_a0141964 -> FUN_a015373c -> FUN_a0106d64.
 * What it does (code facts, in order):
 *  1. Reg_Write32 (func_0x4008c25c = FUN_a002c25c, RAM copy) 0x9F0200E0 = 0xC0; five nops; 0x9F000014 = 0x210003;
 *     busy wait 1024 x nop; 0xC0000000 = 0x21; busy wait 0xFA00 x 2 nops; 0xC0000000 = 0.
 *  2. 0x9F020320 = 5, 0x9F020324 = 0xA803E400 (an address inside the Big data RAM); registers FUN_a002cea8 as
 *     handler 1 / bit 0x10 through func_0x4008a880 (same three calls as FUN_a00de6d4).
 *  3. DAT_a8025c74 = 96000000; FUN_a00dedc8(96000000); FUN_a00deb9c(DAT_a8025c74).
 *  4. DataRam config check (same code as FUN_a00de70c, inlined): n = zero bits 0..23 of 0x9F020204 + one bits 4..27 of
 *     0x9F020200; if 0xA803C000 - n * 4 KiB differs from the linker data start (symbol at 0xA8024000) print "DataRam
 *     register config : 0x%08X, ld config : 0x%08X" and hang forever. FW.021: the 8051 writes both registers = 0
 *     (FUN_CODE_4a85 from the boot loader's constant record fields), n = 24, bottom 0xA8024000: passes.
 *  5. FUN_a00dd8ac(); func_0x40089858(); prints "NT68500 Leon2M system compiled under Linux\r\n%s" with the
 *     version string "version: 5e5d1dc6407-master commit: 2020-07-31 ..." (tail call of FUN_a00df170).
 * Data RAM: this is the only Big chip code that reads the data-RAM window registers; it fixes the Big chip's data
 * RAM bottom at 0xA8024000 (top 0xA8040000 by the 8051 copy/fill window, stack top 0xA803FF50). The Big chip's code
 * never addresses 0xA8040000..0xA80FFFFF; no memory window the firmware configures or checks for the Big chip covers
 * that range.
 * Form: the 0xFA00 x 2-nop wait is a static delay helper delay_loops(n) called with 1 and inlined (gcc keeps the
 *   'cmp j, 1; bcs' outer test only when the bound arrives through inlining; a literal 'j < 1' folds to j == 0).
 *   Verified: at -mcpu=v8 -O3 -g.
 * Nops are real firmware instructions (inline asm nop, as in FUN_a00de65c / FUN_a00de604).
 */
extern void func_0x4008c25c(unsigned int addr, unsigned int value);
extern unsigned int func_0x4008c250(unsigned int addr);
extern int func_0x4008a880();
extern int FUN_a002cea8();
extern void FUN_a00dedc8(unsigned int f);
extern void FUN_a00deb9c(unsigned int f);
extern void FUN_a00dd8ac(void);
extern void func_0x40089858(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int DAT_a8025c74;
extern char s_00198e70[], s_00198eb8[], s_00198f18[];
extern char DAT_a8024000[];

static void delay_loops(unsigned int n)
{
    unsigned int j, k;
    for (j = 0; j < n; j++)
        for (k = 0; k <= 0xf9ff; k++) {
            __asm__ __volatile__("nop");
            __asm__ __volatile__("nop");
        }
}

void FUN_a00de7c4(void)
{
    int i;
    unsigned int v;
    unsigned char b;
    unsigned char n;
    unsigned int bottom;
    char *ld;

    func_0x4008c25c(0x9f0200e0, 0xc0);
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    __asm__ __volatile__("nop");
    func_0x4008c25c(0x9f000014, 0x210003);
    i = 0x3ff;
    do {
        __asm__ __volatile__("nop");
    } while (--i >= 0);
    func_0x4008c25c(0xc0000000, 0x21);
    delay_loops(1);
    func_0x4008c25c(0xc0000000, 0);
    func_0x4008c25c(0x9f020320, 5);
    func_0x4008c25c(0x9f020324, 0xa803e400);
    func_0x4008a880(1, 0x10, FUN_a002cea8);
    DAT_a8025c74 = 96000000;
    FUN_a00dedc8(96000000);
    FUN_a00deb9c(DAT_a8025c74);
    ld = DAT_a8024000;
    n = 0;
    v = func_0x4008c250(0x9f020204);
    for (b = 0; b < 24; b++)
        if (!((v >> b) & 1))
            n++;
    v = func_0x4008c250(0x9f020200);
    for (b = 27; b > 3; b--)
        if ((v >> b) & 1)
            n++;
    bottom = 0xa803c000 - (n << 12);
    if ((char *)bottom != ld) {
        FUN_a00df170(s_00198e70, bottom, ld);
        for (;;)
            ;
    }
    FUN_a00dd8ac();
    func_0x40089858();
    FUN_a00df170(s_00198f18, s_00198eb8);
}
