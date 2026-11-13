/* hdmi_rx21_init_clear_reg2d_fields  (FUN_a00a2b98)
 *
 * Clear fields of control registers 0x2D and 0x2E of both HDMI 2.1 receivers.
 * Returns: 0
 * Name basis: descriptive - caller _hdmi21_Initialize
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2b98 @ 0xa00a2b98, flags -mcpu=v8 -Os -g.
 * Source form: a plain for loop with a u8 counter and a volatile block pointer; an int 0 return.
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): word 0 points to register block 0 of the
   receiver (0xCE009000, +0x1000 for receiver 1), word 1 to block 1, and so on up to block 12 at +0x30. */
struct hdmi_rx21_reg_blocks { volatile unsigned int *block0; unsigned char rest[0x30]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/* Start-up step (called by _hdmi21_Initialize): in block 0 of both HDMI 2.1 receivers clear the upper halfword
   of the word at offset 0xB4 and the low byte of the word at offset 0xB8. Returns 0. */
int hdmi_rx21_init_clear_reg2d_fields(void)
{
    unsigned char receiver;

    for (receiver = 0; receiver <= 1; receiver++) {
        volatile unsigned int *block0 = ARR_a807db00[receiver].block0;
        block0[0x2d] &= 0xffff;
        block0[0x2e] &= ~0xff;
    }
    return 0;
}
