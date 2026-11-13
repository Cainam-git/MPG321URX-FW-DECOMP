/* startup_init_output_layers  (FUN_a010b610)
 *
 * Run the start sequence of the two output halves.
 * Name basis: derived - revision-dependent bits, then a timed bit sequence on 0xD00300F0 and two bits set on
 *   0xD00380F0; called from System_Initialize
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b610, flags -mcpu=v8 -O3 -g.
 * Source form: one read-modify-write per bit, as written below.
 */
#define REG_cf00b844 (*(volatile unsigned int *)0xcf00b844)
#define REG_cf00b870 (*(volatile unsigned int *)0xcf00b870)
#define REG_d00300f0 (*(volatile unsigned int *)0xd00300f0)
#define REG_d00380f0 (*(volatile unsigned int *)0xd00380f0)

/* Chip revision codes run from 0x80 to 0x84 (sys_get_chip_revision). */
#define CHIP_REV_81 0x81

extern unsigned char sys_get_chip_revision(void);
extern void timer_sleep_ticks(int ms);

/*
 * For chip revisions above 0x81 set bit 6 of 0xCF00B844 and bit 7 of 0xCF00B870. Then, one bit at a time, on
 * 0xD00300F0: clear bit 26, wait 1 (timer_sleep_ticks), set bit 26, set bit 4, wait 2, clear bit 4, set bit 10,
 * set bit 14. Last, set bits 10 and 14 of 0xD00380F0. Called by System_Initialize.
 */
void startup_init_output_layers(void)
{
    if (sys_get_chip_revision() > CHIP_REV_81) {
        REG_cf00b844 |= 0x40;
        REG_cf00b870 |= 0x80;
    }
    REG_d00300f0 &= ~0x4000000;
    timer_sleep_ticks(1);
    REG_d00300f0 |= 0x4000000;
    REG_d00300f0 |= 0x10;
    timer_sleep_ticks(2);
    REG_d00300f0 &= ~0x10;
    REG_d00300f0 |= 0x400;
    REG_d00300f0 |= 0x4000;
    REG_d00380f0 |= 0x400;
    REG_d00380f0 |= 0x4000;
}
