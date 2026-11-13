/* pq_block8_stop  (FUN_a011855c)
 *
 * Stop picture block 8 before its settings are changed.
 * Name basis: descriptive - writes 0 to 0xCF012E80 and, by chip revision, clears three enable bits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011855c, flags -mcpu=v8 -O3 -g.
 * Source form: the store of 0 to BLOCK8_E80 is written in both arms.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define FRC_CHANNEL_ON      0xcf011800
#define FRC_CTRL            0xcf011a00
#define BLOCK8_FRC_BIT      0x20            /* set in both by pq_block8_start, cleared here */
#define BLOCK8_E00          0xcf012e00      /* bit 0 set by pq_block8_start */
#define BLOCK8_E80          0xcf012e80      /* 0 here, 1 in pq_block8_start */
#define BLOCK8_F74          0xcf012f74
#define BLOCK8_F74_BIT1     0x2             /* set by pq_enable_block8_path, cleared by pq_clear_block8_bit1 */
#define CHIP_REVISION_83    0x83            /* sys_get_chip_revision returns 0x80..0x84 */

extern unsigned char sys_get_chip_revision(void);

/*
 * Write 0 to BLOCK8_E80. On chip revisions up to 0x83, and on later ones while bit 1 of 0xCF012F74 is clear,
 * also clear bit 0 of 0xCF012E00 and bit 5 of the two frame-rate converter registers; pq_block8_start sets
 * those three bits again. With a later revision and bit 1 set (pq_enable_block8_path) they stay on.
 *
 * Called by sys_frc_disable_channels, sys_frc_switch_mode, sys_api_config, pq_api_set_response_level and the
 * memory test routines (dbg_ddr_*).
 */
void pq_block8_stop(void)
{
    if (sys_get_chip_revision() <= CHIP_REVISION_83 || !(R(BLOCK8_F74) & BLOCK8_F74_BIT1)) {
        R(BLOCK8_E80) = 0;
        R(BLOCK8_E00) &= ~1;
        R(FRC_CTRL) &= ~BLOCK8_FRC_BIT;
        R(FRC_CHANNEL_ON) &= ~BLOCK8_FRC_BIT;
    } else {
        R(BLOCK8_E80) = 0;
    }
}
