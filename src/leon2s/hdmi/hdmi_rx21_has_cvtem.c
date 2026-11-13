/* hdmi_rx21_has_cvtem  (FUN_a00a03c8)
 *
 * Return whether a valid compressed-video (CVTEM) packet is present on an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when present
 * Name basis: derived - five header tests of the EMP block; result selects the DSC timing path and gates
 *   hdmi_rx21_read_cvtem ('No CVTEM')
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a03c8, flags -mcpu=v8 -Os -g (section default).
 * Source forms: block 11 is read through a volatile pointer, because every test reads r[0] and r[1] again; all
 * five tests are one '||' condition with a single 'return 0'.
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char block0_10[0x2c];
    volatile unsigned int *block11;     /* +0x2C: register block 11 of the receiver */
    unsigned char block12[0x34 - 0x30];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/*
 * Return 1 when the first two words of register block 11 of receiver `port` pass all of these tests, else 0:
 *   word 0: bits 4 and 5 clear; byte 2 equals 1; byte 3 * 0x100 + word 1 byte 0 equals 2;
 *   word 1: byte 1 * 0x100 + byte 2 is not 0; byte 3 is not 0.
 * Callers use the result as "a CVTEM packet is present" (see hdmi_rx21_read_cvtem and the 'No CVTEM' print).
 *   port  HDMI 2.1 receiver 0/1
 */
unsigned char hdmi_rx21_has_cvtem(unsigned char port)
{
    volatile unsigned int *words = ARR_a807db00[port].block11;

    if ((words[0] & 0x30) || ((words[0] >> 16) & 0xff) != 1 || (words[0] >> 24) * 0x100 + (words[1] & 0xff) != 2 ||
        ((words[1] >> 8) & 0xff) * 0x100 + ((words[1] >> 16) & 0xff) == 0 || (words[1] >> 24) == 0)
        return 0;
    return 1;
}
