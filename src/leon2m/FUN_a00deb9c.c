/* leon2m FUN_a00deb9c @ 0xa00deb9c..0xa00dec90 (61 words)  Timer_Init: the Big chip's two hardware timers and their
 * interrupt handlers. Called once by FUN_a00de7c4 (start-up step 2, before WAIT 1) with the CPU
 * clock DAT_a8025c74 = 96000000.
 * What it does (code facts): only if the init flag byte 0xA802B0C4 is 0: word 0xA802D648 = 0, the 5 words at
 * 0xA802B0D0..0xA802B0E3 = 0 and word 0xA802B0E8 = 0; reload = clk / 8000 (96 MHz -> 12000); timer 0
 * 0xC00A0000 = reload, 0xC00A0004 = 0x83, 0xC00A0008 = 0; timer 1 0xC00A0040 = reload, 0xC00A0044 = 0x83,
 * 0xC00A0048 = 0 (Reg_Write32 func_0x4008c25c); flag = 1; prints "\nTimer Init %d\r\n" with 1 (0x00198F50);
 * registers FUN_a002cfb8 for interrupt 4 bit 0 and FUN_a002d174 for interrupt 4 bit 4 (func_0x4008a880, the
 * irq-handler registration entry in the RAM piece) and enables interrupt 4 mask 0x10 (tail call func_0x40089820).
 * FUN_a002d174 calls the hook word 0xA802B0E0 (cleared here) with 4.
 * It neither waits nor fails: register writes, one bounded clear loop, no read-back. The interrupts it enables are
 * taken only while traps are enabled, so none of them runs after the fatal trap path (ET = 0, FUN_a002d5ac).
 * Exact form: the 5-word clear as a counted loop over a local pointer (fw 'addcc -1; bpos'), u32 clock parameter.
 */
struct Tmr { unsigned char flag; unsigned char pad[11]; unsigned int w[5]; unsigned int x; unsigned int y; };
extern struct Tmr DAT_a802b0c4;
extern unsigned int DAT_a802d648;
extern char s_00198f50[];
extern void func_0x4008c25c(unsigned int, unsigned int);
extern int FUN_a00df170(const char *, ...);
extern void func_0x4008a880(int, int, void (*)(void));
extern void func_0x40089820(int, int);
extern void FUN_a002cfb8(void);
extern void FUN_a002d174(void);

void FUN_a00deb9c(unsigned int clk)
{
    unsigned int reload;
    int i;

    if (DAT_a802b0c4.flag != 0)
        return;
    DAT_a802d648 = 0;
    for (i = 0; i < 5; i++)
        DAT_a802b0c4.w[i] = 0;
    reload = clk / 8000;
    DAT_a802b0c4.y = 0;
    func_0x4008c25c(0xc00a0000, reload);
    func_0x4008c25c(0xc00a0004, 0x83);
    func_0x4008c25c(0xc00a0008, 0);
    func_0x4008c25c(0xc00a0040, reload);
    func_0x4008c25c(0xc00a0044, 0x83);
    func_0x4008c25c(0xc00a0048, 0);
    DAT_a802b0c4.flag = 1;
    FUN_a00df170(s_00198f50, 1);
    func_0x4008a880(4, 1, FUN_a002cfb8);
    func_0x4008a880(4, 0x10, FUN_a002d174);
    func_0x40089820(4, 0x10);
}
