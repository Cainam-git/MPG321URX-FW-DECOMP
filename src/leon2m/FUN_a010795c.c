/* leon2m FUN_a010795c @ 0xa010795c-0xa01079c0 (25 words).
 * When on is 1: sets bit 6 of hardware register 0xcf016acc, clears bits 3 and 4 of 0xcf00ed18 and writes 0x33 and
 * 0x90 to the registers 0xcf016aa8 and 0xcf016ab8. Otherwise writes 0 to 0xcf016aa8. The register addresses are set
 * up before the test. Variant of FUN_a010765c.
 */
#define REG(a) (*(volatile unsigned int *)(a))

void FUN_a010795c(unsigned char on)
{
    if (on == 1) {
        REG(0xcf016acc) |= 0x40;
        REG(0xcf00ed18) &= ~0x18;
        REG(0xcf016aa8) = 0x33;
        REG(0xcf016ab8) = 0x90;
    } else {
        REG(0xcf016aa8) = 0;
    }
}
