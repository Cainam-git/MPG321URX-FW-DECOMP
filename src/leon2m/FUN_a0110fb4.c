/* leon2m FUN_a0110fb4 @ 0xa0110fb4-0xa0111028 (29 words).
 * Prints "\nProfile_Load_Table\r\n" through FUN_a00df170, writes 0x81 to hardware register 0xcf011f80, takes
 * v = func_0x4008e46c(0x14), passes (0xb7080160, v << 5) to func_0x4008c25c, then calls
 * FUN_a0113eb4(entry i, v + i, 1, 1) for the 0x400 entries of 0x20 bytes of the table at 0x0019af00.
 * Callers: FUN_a014dbf4 and FUN_a015209c. The entry count is held in a variable n: with a literal bound GCC
 * emits cmp 0x3ff / bleu instead of the firmware's cmp 0x400 / bcs.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int func_0x4008e46c(unsigned int);
extern void func_0x4008c25c(unsigned int addr, unsigned int value);
extern void FUN_a0113eb4(const unsigned char *p, unsigned int addr, unsigned char n, unsigned char mode);
extern const unsigned char DAT_0019af00[0x400][0x20];

void FUN_a0110fb4(void)
{
    unsigned int v;
    unsigned int i, n = 0x400;

    FUN_a00df170("\nProfile_Load_Table\r\n");
    R(0xcf011f80) = 0x81;
    v = func_0x4008e46c(0x14);
    func_0x4008c25c(0xb7080160, v << 5);
    for (i = 0; i < n; i++)
        FUN_a0113eb4(DAT_0019af00[i], i + v, 1, 1);
}
