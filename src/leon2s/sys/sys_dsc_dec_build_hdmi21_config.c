/* sys_dsc_dec_build_hdmi21_config  (FUN_a00a63a8)
 *
 * Build a full DSC decoder set-up record for an HDMI 2.1 input.
 *   record: input code
 *   input_code: record
 * Name basis: derived - fixed fields plus sys_dsc_dec_fill_hdmi21_timing; caller sys_dsc_dec_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a63a8 @ 0xa00a63a8-0xa00a6428 (32 words), flags -mcpu=v8 -Os -g.
 * Source form: the source order is not the firmware's store order (the scheduler hoists the store whose chain
 * is longest). The +0x44 store is LAST in the source, and the '= 1' stores are in ascending offset order
 * (4, 0xc, 0xd, 0xe) before the halfword clears; this is the first of the possible orders of the first six
 * stores that builds exactly. Returns void (%i0 is left unchanged).
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void sys_dsc_dec_fill_hdmi21_timing(unsigned int, u16 *);

/* Build the set-up record of a decoder for an HDMI 2.1 input: the constant fields are set (offsets 4, 0xc, 0xd,
 * 0xe = 1; 5 = 2; 0x3f = 2; the halfwords at 0 and 2 and the bytes 6..0xb, 0xf, 0x3a..0x3e, 0x40 = 0),
 * sys_dsc_dec_fill_hdmi21_timing fills the timing fields for the input, and the word at +0x44 is the halfword
 * at +0x20 divided by 8. Called by sys_dsc_dec_run_state.
 *   record: the set-up record
 *   input_code: input code (0x51 / 0x61)
 */
void sys_dsc_dec_build_hdmi21_config(u16 *record, unsigned int input_code)
{
    u8 *bytes = (u8 *)record;
    bytes[4] = 1;
    bytes[0xc] = 1;
    bytes[0xd] = 1;
    bytes[0xe] = 1;
    record[0] = 0;
    record[1] = 0;
    bytes[5] = 2;
    bytes[6] = 0;
    bytes[7] = 0;
    bytes[8] = 0;
    bytes[9] = 0;
    bytes[0xa] = 0;
    bytes[0xb] = 0;
    bytes[0xf] = 0;
    sys_dsc_dec_fill_hdmi21_timing(input_code & 0xff, record);
    bytes[0x3f] = 2;
    bytes[0x3a] = 0;
    bytes[0x3b] = 0;
    bytes[0x3c] = 0;
    bytes[0x3d] = 0;
    bytes[0x3e] = 0;
    bytes[0x40] = 0;
    *(unsigned int *)(bytes + 0x44) = record[0x10] >> 3;
}
