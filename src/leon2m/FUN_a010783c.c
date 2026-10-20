/* leon2m FUN_a010783c @ 0xa010783c-0xa0107884 (18 words).
 * Sets bit 0 of hardware register 0xcf01744c. Then, when on is 1, writes 0x33 to register 0xcf017428 and 0x90 to
 * 0xcf017438; otherwise writes 0 to 0xcf017428. The register addresses are set up before the test.
 */
#define REG_cf01744c (*(volatile unsigned int *)0xcf01744c)
#define REG_cf017428 (*(volatile unsigned int *)0xcf017428)
#define REG_cf017438 (*(volatile unsigned int *)0xcf017438)

void FUN_a010783c(unsigned char on)
{
    REG_cf01744c |= 1;
    if (on == 1) {
        REG_cf017428 = 0x33;
        REG_cf017438 = 0x90;
    } else {
        REG_cf017428 = 0;
    }
}
