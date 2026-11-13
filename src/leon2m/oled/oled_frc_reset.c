/* oled_frc_reset  (FUN_a0129598)
 *
 * Reset the state of the OLED refresh-rate row handler.
 * Name basis: derived - state word at 0xA802D892 cleared, row index 0xFF
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0129598 @ 0xa0129598, flags -mcpu=v8 -O2 -g.
 * Source form: the state word is masked as a halfword, the row index is then written through an unsigned char
 * pointer to the second byte of it.
 */
/* The state of the OLED refresh-rate handler (oled_frc_task): a halfword and a time stamp. In the halfword the
   top 4 bits are the state, bit 0x800 is the "sent" flag, bit 0x400 the "send request" flag and the low byte the
   row index (oled_frc_get_row / oled_frc_set_row). */
struct FrcSm { unsigned short w; unsigned short t; };
extern struct FrcSm oled_frc_state;

#define FRC_STATE_KEEP_MASK 0x3ff   /* bits 0..9 stay; the state, the sent flag and the request flag are cleared */
#define FRC_ROW_INDEX_RESET 0xff

/*
 * Put the OLED refresh-rate handler back to its start: state 0, both flags cleared, row index 0xFF.
 * Called by App_CoolInitialize.
 */
void oled_frc_reset(void)
{
    oled_frc_state.w &= FRC_STATE_KEEP_MASK;
    ((unsigned char *)&oled_frc_state)[1] = FRC_ROW_INDEX_RESET;
}
