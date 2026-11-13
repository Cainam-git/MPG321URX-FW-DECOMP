/* sys_get_chip_revision  (FUN_a008d800)
 *
 * Return the chip revision code (0x80..0x84) from the ID registers.
 * Returns: revision code
 * Name basis: derived - 0xCF011440/0xCF011444 map to 0x80..0x84; callers switch code paths with '> 0x81' / '>
 *   0x82' tests
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008d800 @ 0xa008d800-0xa008d8d8 (54 words), flags -mcpu=v8 -Os -g.
 * 0x9f1b0606 is declared as a symbol (simm13 ldub form; a constant cast gives or + ldub [reg]). volatile only
 * on the hardware registers 0xcf0114xx / 0x9f1b0606.
 * Source form: register 0xcf011444 is re-read for each test; the 0x81/0x80 pick is a ?: on '== 1' (a
 * '-0x7f - (b != 1)' form folds differently; the ?: keeps the firmware's mov -127 + subx).
 */
#define REG_CHIP_ID_A (*(volatile unsigned int *)0xcf011444)
#define REG_CHIP_ID_B (*(volatile unsigned int *)0xcf011440)
extern volatile unsigned char DAT_9f1b0606;   /* hw byte, symbol form (simm13 ldub) */

/* Revision codes returned. */
#define CHIP_REV_80 0x80
#define CHIP_REV_81 0x81
#define CHIP_REV_82 0x82
#define CHIP_REV_83 0x83
#define CHIP_REV_84 0x84

/* Return the chip revision code, 0x80..0x84, from two ID registers. Register 0xcf011440 must read 1 in every
 * case; register 0xcf011444 then selects: 0x16 gives 0x81 when the byte at 0x9f1b0606 is 1 and 0x80 otherwise,
 * 0x1e gives 0x82, 0x1f gives 0x83, 0x17 gives 0x84. Any other combination also gives 0x84.
 * Callers test it against 0x81 (dp_select_lane_mask: <= 0x81) and 0x82 (hdmi_rx21_enable_sync_events: > 0x82).
 */
unsigned char sys_get_chip_revision(void)
{
    unsigned char revision;

    revision = CHIP_REV_84;
    if (REG_CHIP_ID_A == 0x16 && REG_CHIP_ID_B == 1) {
        revision = (DAT_9f1b0606 == 1) ? CHIP_REV_81 : CHIP_REV_80;
    } else if (REG_CHIP_ID_A == 0x1e && REG_CHIP_ID_B == 1) {
        revision = CHIP_REV_82;
    } else if (REG_CHIP_ID_A == 0x1f && REG_CHIP_ID_B == 1) {
        revision = CHIP_REV_83;
    } else if (REG_CHIP_ID_A == 0x17 && REG_CHIP_ID_B == 1) {
        revision = CHIP_REV_84;
    }
    return revision;
}
