/* sys_get_chip_revision  (FUN_a011cf88)
 *
 * Return the chip revision code 0x80..0x84.
 * Returns: revision code
 * Name basis: derived - derived from register 0xCF011444 and flag 0xCF011440; callers compare it with 0x82 and
 *   0x83
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011cf88 @ 0xa011cf88-0xa011d0a8 (72 words), flags -mcpu=v8 -O3 -g.
 * Source form: both registers are read fresh at every test (volatile). The 8-byte copy is an inlined static
 * helper copy_bytes(dst, src, n) with a u8 counter (the same loop is in sys_get_chip_model_code): it keeps the
 * firmware's [idx + base] addressing and the 'cmp 8; bcs,a' loop test; an open-coded loop gives a
 * strength-reduced induction variable.
 */
#define CHIP_ID_REG    (*(volatile unsigned int *)0xcf011444)  /* ID register tested below */
#define CHIP_ID_VALID  (*(volatile unsigned int *)0xcf011440)  /* flag: must read 1 for the ID to count */

#define CHIP_ID_A      0x16     /* revision code 0x80 or 0x81, told apart by byte 6 of the identification field */
#define CHIP_ID_B      0x1e     /* revision code 0x82 */
#define CHIP_ID_C      0x1f     /* revision code 0x83 */
#define CHIP_ID_D      0x17     /* revision code 0x84 */
#define ID_FIELD_ADDR  0x9f1b0600       /* 8-byte identification field */

static void copy_bytes(unsigned char *dst, const unsigned char *src, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

/*
 * Return the chip revision code, 0x80 to 0x84.
 *
 *   ID 0x16 (and the flag reads 1): copies the 8-byte identification field to a local buffer;
 *          0x81 when byte 6 is 1, else 0x80
 *   ID 0x1e: 0x82      ID 0x1f: 0x83      ID 0x17: 0x84
 *   any other ID, or the flag not 1: 0x84
 *
 * Callers compare the code with 0x82 and 0x83. input_channel_bring_up_task sends the HDMI 2.1 port mask only for
 * codes above 0x82, and caps a rate limit by the vfreq_max of the active panel row only up to 0x82 (above it the
 * limit is 0). sys_frc_get_output_frame_length and sys_frc_get_output_active_height scale their result from
 * code 0x83 and 0x84 on.
 */
unsigned char sys_get_chip_revision(void)
{
    unsigned char buf[8] = {0};
    unsigned char i;
    unsigned char r;

    r = 0x84;
    if (CHIP_ID_REG == CHIP_ID_A && CHIP_ID_VALID == 1) {
        copy_bytes(buf, (const unsigned char *)ID_FIELD_ADDR, 8);
        r = buf[6] == 1 ? 0x81 : 0x80;
    } else if (CHIP_ID_REG == CHIP_ID_B && CHIP_ID_VALID == 1) {
        r = 0x82;
    } else if (CHIP_ID_REG == CHIP_ID_C && CHIP_ID_VALID == 1) {
        r = 0x83;
    } else if (CHIP_ID_REG == CHIP_ID_D && CHIP_ID_VALID == 1) {
        r = 0x84;
    }
    return r;
}
