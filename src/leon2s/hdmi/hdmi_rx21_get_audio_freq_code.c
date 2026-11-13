/* hdmi_rx21_get_audio_freq_code  (FUN_a009c4a4)
 *
 * Return the audio sample-rate code reported by an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: sample-rate code
 * Name basis: derived - codes 0/2/3/8/10/12/14 = IEC 60958 channel status 44.1/48/32/88.2/96/176.4/192 kHz;
 *   others give 2 (48 kHz)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009c4a4 @ 0xa009c4a4-0xa009c558 (180 bytes, 45 words)
 * Flags: -mcpu=v8 -Os -g.
 * The nibble is mapped by a switch (jump table, 15 entries); the cases set a u8 result that is returned at the end
 * (firmware 'mov 2' in the bgu delay slot plus the final 'and 0xf' = u8 nonzero-bits narrowing).
 * Source form: the register pointer target is volatile (a hardware register; the firmware does a full-word ld and
 * then extracts the field).
 * The firmware jump table is the 60 bytes 0xa009c468-0xa009c4a4, between the end of hdmi_rx21_audio_status_bit1 and this function.
 * Ours references a .rodata table by relocation.
 */
/* One entry of the table at 0xA807DB00 (0x34 bytes per receiver): the addresses of the register blocks. */
struct hdmi_rx21_reg_blocks { unsigned int block0; volatile unsigned int *block1; unsigned char rest[0x34 - 8]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned int hdmi_rx21_audio_status_bit1(unsigned char);

/*
 * Return the sample-rate code of the audio received by an HDMI 2.1 receiver. The code is a nibble of the first
 * register of block 1: bits 16..19 when hdmi_rx21_audio_status_bit1 is non-zero, else bits 24..27. The values 0, 3,
 * 8, 10, 12 and 14 are returned as they are; every other value gives 2.
 *   port: HDMI 2.1 receiver 0/1
 * Called by hdmi_rx21_read_audio_status.
 */
unsigned char hdmi_rx21_get_audio_freq_code(unsigned char port)
{
    unsigned int field;
    unsigned char code;

    if ((unsigned char)hdmi_rx21_audio_status_bit1(port) != 0)
        field = *ARR_a807db00[port].block1 >> 16;
    else
        field = *ARR_a807db00[port].block1 >> 24;
    switch (field & 0xf) {
    case 0: code = 0; break;
    case 8: code = 8; break;
    case 12: code = 12; break;
    case 10: code = 10; break;
    case 14: code = 14; break;
    case 3: code = 3; break;
    default: code = 2; break;
    }
    return code;
}
