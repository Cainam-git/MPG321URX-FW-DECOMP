/* leon2m FUN_a010765c @ 0xa010765c-0xa01076bc (24 words).
 * When on is 1: clears bit 7 of hardware register 0xcf00ed14 and writes 0x33, 0x90 and 0x4e to the registers
 * 0xcf016828, 0xcf016838 and 0xcf016840. Otherwise writes 0 to 0xcf016828. The register addresses are set up before
 * the test (the compiler hoists them out of both arms).
 */
#define REG_cf00ed14 (*(volatile unsigned int *)0xcf00ed14)
#define REG_cf016828 (*(volatile unsigned int *)0xcf016828)
#define REG_cf016838 (*(volatile unsigned int *)0xcf016838)
#define REG_cf016840 (*(volatile unsigned int *)0xcf016840)

void FUN_a010765c(unsigned char on)
{
    if (on == 1) {
        REG_cf00ed14 &= ~0x80;
        REG_cf016828 = 0x33;
        REG_cf016838 = 0x90;
        REG_cf016840 = 0x4e;
    } else {
        REG_cf016828 = 0;
    }
}
