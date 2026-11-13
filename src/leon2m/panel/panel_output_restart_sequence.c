/* panel_output_restart_sequence  (FUN_a010b77c)
 *
 * Run the restart bit sequence of the output halves.
 * Name basis: descriptive - 0xCF00B800 and 0xD00300F0 with waits, then 0x100 to register 8 of both halves;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b77c, flags -mcpu=v8 -O3 -g. No direct callers (the same register sequence as startup_init_output_layers).
 */
#define CLOCK_REG_B800  (*(volatile unsigned int *)0xcf00b800)
#define CLOCK_REG_B844  (*(volatile unsigned int *)0xcf00b844)
#define CLOCK_REG_B870  (*(volatile unsigned int *)0xcf00b870)
#define OUTPUT_HALF0_REG_F0 (*(volatile unsigned int *)0xd00300f0)
#define OUTPUT_HALF1_REG_F0 (*(volatile unsigned int *)0xd00380f0)
#define OUTPUT_HALF0_REG_08 (*(volatile unsigned int *)0xd0030008)
#define OUTPUT_HALF1_REG_08 (*(volatile unsigned int *)0xd0038008)

#define CHIP_REVISION_LIMIT 0x81        /* revisions above this take the second branch below */

extern unsigned char sys_get_chip_revision(void);
extern void timer_sleep_ticks(int ticks);

/*
 * Run this register sequence (no input):
 *   - set bit 4 of 0xCF00B800;
 *   - in 0xD00300F0: clear bit 26, sleep 1 tick, set bit 26, set bit 4, sleep 2 ticks, clear bit 4;
 *   - chip revision 0x81 or lower: set bits 10 and 14 in 0xD00300F0 and 0xD00380F0;
 *   - chip revision above 0x81: set bit 6 of 0xCF00B844 and bit 7 of 0xCF00B870;
 *   - write 0x100 to 0xD0030008 and 0xD0038008.
 * Nothing calls this routine.
 */
void panel_output_restart_sequence(void)
{
    CLOCK_REG_B800 |= 0x10;
    OUTPUT_HALF0_REG_F0 &= ~0x4000000;
    timer_sleep_ticks(1);
    OUTPUT_HALF0_REG_F0 |= 0x4000000;
    OUTPUT_HALF0_REG_F0 |= 0x10;
    timer_sleep_ticks(2);
    OUTPUT_HALF0_REG_F0 &= ~0x10;
    if (sys_get_chip_revision() <= CHIP_REVISION_LIMIT) {
        OUTPUT_HALF0_REG_F0 |= 0x400;
        OUTPUT_HALF0_REG_F0 |= 0x4000;
        OUTPUT_HALF1_REG_F0 |= 0x400;
        OUTPUT_HALF1_REG_F0 |= 0x4000;
    }
    if (sys_get_chip_revision() > CHIP_REVISION_LIMIT) {
        CLOCK_REG_B844 |= 0x40;
        CLOCK_REG_B870 |= 0x80;
    }
    OUTPUT_HALF0_REG_08 = 0x100;
    OUTPUT_HALF1_REG_08 = 0x100;
}
