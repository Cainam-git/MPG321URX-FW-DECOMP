/* pq_window_disable_stages  (FUN_a00f66a4)
 *
 * Switch off the picture stages named by a mask.
 * Name basis: derived - clears bits of 0xCF00EF00 / 0xCF00EF30; counterpart of pq_window_enable_stages
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f66a4 @ 0xa00f66a4-0xa00f67d0 (300 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a sequence of independent if statements; the final check reads R330 after the previous clears.
 */
/* The two registers that hold the picture stage enable bits: 0xCF00EF00 (STAGE_ENABLE_A) and 0xCF00EF30
   (also the level table control register). */
#define R300 (*(volatile unsigned int *)0xcf00ef00)
#define R330 (*(volatile unsigned int *)0xcf00ef30)

/* Mask bits: each bit names one picture stage. */
#define STAGE_0 0x01u
#define STAGE_1 0x02u
#define STAGE_2 0x04u
#define STAGE_3 0x08u
#define STAGE_4 0x10u
#define STAGE_5 0x20u
#define STAGE_6 0x40u
#define STAGE_7 0x80u

/* Bits cleared in R300 for stages 0..4. */
#define R300_BIT6 0x40u
#define R300_BIT5 0x20u
#define R300_BIT4 0x10u
#define R300_BIT3 0x08u
#define R300_BIT2 0x04u

/* Bits cleared in R330 for stages 5..7. */
#define R330_BIT7 0x80u
#define R330_BIT6 0x40u
#define R330_BIT4 0x10u

/* Bits 5..7 of R330, checked together. */
#define R330_BITS5_7 0xe0u

/* Bit 0 of R330, cleared when bits 5..7 are all clear. */
#define R330_BIT0 0x01u

/*
 * Switch off the picture stages named by the mask: the counterpart of pq_window_enable_stages.
 *
 * Mask bits 0..4 clear bits 6, 5, 4, 3, 2 of 0xCF00EF00; mask bits 5, 6, 7 clear bits 7, 6, 4 of 0xCF00EF30.
 * Then bit 0 of 0xCF00EF30 (set together with each of those three by pq_window_enable_stages) is cleared when
 * bits 5..7 of that register are all clear. The test covers bit 5, which no stage sets here, and not bit 4,
 * which stage 7 uses.
 *
 * Caller: pq_fga_handle_command.
 */
void pq_window_disable_stages(unsigned int mask)
{
    if (mask & STAGE_0)
        R300 &= ~R300_BIT6;
    if (mask & STAGE_1)
        R300 &= ~R300_BIT5;
    if (mask & STAGE_2)
        R300 &= ~R300_BIT4;
    if (mask & STAGE_3)
        R300 &= ~R300_BIT3;
    if (mask & STAGE_4)
        R300 &= ~R300_BIT2;
    if (mask & STAGE_5)
        R330 &= ~R330_BIT7;
    if (mask & STAGE_6)
        R330 &= ~R330_BIT6;
    if (mask & STAGE_7)
        R330 &= ~R330_BIT4;
    if ((R330 & R330_BITS5_7) == 0)
        R330 &= ~R330_BIT0;
}
