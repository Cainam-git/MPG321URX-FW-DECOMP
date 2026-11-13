/* hdmi_rx21_read_cvtem  (FUN_a00a0478)
 *
 * Read the compressed-video (CVTEM) packet fields of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver 0/1
 *   out: 5-byte block
 * Returns: 0 when read, 1 when absent
 * Name basis: derived - sixth packet read by FSM_Complete, failure prints 'No CVTEM'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0478, flags -mcpu=v8 -Os -g (section default).
 * Source form: the lib_memset block stands between the value selection and the stores and is reached by goto from
 * the hdmi_rx21_has_cvtem test; this gives the firmware's layout and the recomputed record address after the join.
 * Block 11 is read again at each use (volatile).
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    unsigned char block0_10[0x2c];
    volatile unsigned int *block11;     /* +0x2C: register block 11 of the receiver */
    unsigned char block12[0x34 - 0x30];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_has_cvtem(unsigned char);
extern void *lib_memset(unsigned char *, unsigned char, int);

#define CVTEM_CODE_NONE 0x10            /* value of out[0] when bits 20..23 of word 2 are 0 */

/*
 * Read the CVTEM fields of receiver `port` into the 5-byte block `out`.
 * Without a packet (hdmi_rx21_has_cvtem returns 0) the five bytes are cleared and 1 is returned. Otherwise
 * out[0] = bits 20..23 of word 2 of register block 11 (0x10 when they are all 0), out[1] = bit 27 of that word,
 * and 0 is returned. Called by DRV_HDMI_ModeDetect_FSM_Complete (the 'No CVTEM' print is its failure case).
 *   port  HDMI 2.1 receiver 0/1
 *   out   result block; out[0] and out[1] are set
 */
unsigned char hdmi_rx21_read_cvtem(unsigned char port, unsigned char *out)
{
    unsigned char code = CVTEM_CODE_NONE;

    if (hdmi_rx21_has_cvtem(port) == 0)
        goto fail;
    if ((ARR_a807db00[port].block11[2] >> 16) & 0xf0)
        code = (ARR_a807db00[port].block11[2] >> 20) & 0xf;
    goto store;
fail:
    lib_memset(out, 0, 5);
    return 1;
store:
    out[0] = code;
    out[1] = (ARR_a807db00[port].block11[2] >> 27) & 1;
    return 0;
}
