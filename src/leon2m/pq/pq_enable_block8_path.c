/* pq_enable_block8_path  (FUN_a01190b0)
 *
 * Switch the block-8 path on when the chip revision is above 0x83.
 * Name basis: descriptive - sets bit 5 of 0xCF011800/0xCF011A00, bit 0 of 0xCF012E00 and bit 1 of 0xCF012F74;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01190b0, flags -mcpu=v8 -O3 -g.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define FRC_CHANNEL_ON      0xcf011800
#define FRC_CTRL            0xcf011a00
#define BLOCK8_FRC_BIT      0x20            /* set in both by pq_block8_start, cleared by pq_block8_stop */
#define BLOCK8_E00          0xcf012e00      /* bit 0 set by pq_block8_start */
#define BLOCK8_F74          0xcf012f74
#define BLOCK8_F74_BIT1     0x2             /* while set, pq_block8_stop leaves the other three bits on */
#define CHIP_REVISION_83    0x83            /* sys_get_chip_revision returns 0x80..0x84 */

extern unsigned char sys_get_chip_revision(void);

/*
 * On chip revisions above 0x83 only: set the three bits pq_block8_start sets (without its wait and without
 * BLOCK8_E80), and bit 1 of 0xCF012F74. With that bit set, pq_block8_stop no longer clears the other three.
 * pq_clear_block8_bit1 clears it again.
 *
 * Nothing in the firmware calls this routine directly.
 */
void pq_enable_block8_path(void)
{
    if (sys_get_chip_revision() > CHIP_REVISION_83) {
        R(FRC_CHANNEL_ON) |= BLOCK8_FRC_BIT;
        R(FRC_CTRL) |= BLOCK8_FRC_BIT;
        R(BLOCK8_E00) |= 1;
        R(BLOCK8_F74) |= BLOCK8_F74_BIT1;
    }
}
