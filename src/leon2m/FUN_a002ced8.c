/* leon2m FUN_a002ced8 @ 0xa002ced8..0xa002cf04 (11 words, RAM copy: CPU 0x4008ced8), flags -mcpu=v8 -O3 -g
 * (also -O2). Copies the 32-bit register 0xCF03C810 to 0xCF03C820 and 0xCF03C900 to 0xCF03C910.
 * The 8051 XDATA register window XDATA 0xF000 + n = AHB 0xCF03C000 + 4 n maps the ring bytes of the 8051
 * "SYSTEM CRASH" check FUN_CODE_7b5a onto the addresses used here and in the Small chip loop: ring 1 'stbc cnt' F204 -> 'main cnt' F208 and ring 2 F240 -> F244; the Small chip main loop (leon2s 0xA00608D8)
 * copies 0xCF03C820 -> 0xCF03C830 (F208 -> 'sub_cnt' F20C), which FUN_CODE_7b5a compares with F204.
 * Callers: main-loop task FUN_a0153018 -> FUN_a0154580 (unconditional last call), FUN_a014512c, GPIO-I2C FUN_a002b3e4
 * and others (16 in all). While no caller runs (fatal trap path with traps off, error mode, or any endless
 * wait outside these callers) F208 stops changing and FUN_CODE_7b5a stops both Leon2 cores after its
 * 15000-tick limit. volatile: these are hardware registers.
 */
void FUN_a002ced8(void)
{
    *(volatile unsigned int *)0xCF03C820 = *(volatile unsigned int *)0xCF03C810;
    *(volatile unsigned int *)0xCF03C910 = *(volatile unsigned int *)0xCF03C900;
}
