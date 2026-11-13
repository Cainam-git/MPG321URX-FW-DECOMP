/* hdmi_rx21_init_ctrl_bits_20_21  (FUN_a00a2a28)
 *
 * Set control bits 20 and 21 of both HDMI 2.1 receivers at start-up.
 * Returns: 0
 * Name basis: descriptive - caller _hdmi21_Initialize
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2a28 @ 0xa00a2a28, flags -mcpu=v8 -Os -g.
 * Source form: a plain for loop with a u8 counter; the block pointer is reloaded for the second call; the
 * routine returns int 0.
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): word 0 points to register block 0 of the
   receiver (0xCE009000, +0x1000 for receiver 1), word 1 to block 1, and so on up to block 12 at +0x30. */
struct hdmi_rx21_reg_blocks { unsigned int pad0; unsigned int *block1; unsigned char rest[0x2c]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern void reg_set_bit(unsigned int, unsigned int *);

/* Start-up step (called by _hdmi21_Initialize): set bits 20 and 21 of the word at offset 0x34 of block 1 of
   both HDMI 2.1 receivers. Returns 0. */
int hdmi_rx21_init_ctrl_bits_20_21(void)
{
    unsigned char receiver;

    for (receiver = 0; receiver <= 1; receiver++) {
        struct hdmi_rx21_reg_blocks *row = &ARR_a807db00[receiver];
        reg_set_bit(20, row->block1 + 13);
        reg_set_bit(21, row->block1 + 13);
    }
    return 0;
}
