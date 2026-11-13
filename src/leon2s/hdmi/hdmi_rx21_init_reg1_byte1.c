/* hdmi_rx21_init_reg1_byte1  (FUN_a00a2a80)
 *
 * Set byte 1 of register 1 of both HDMI 2.1 receivers for a start-up mode.
 *   mode: 0 or 1
 * Returns: 0
 * Name basis: descriptive - mode 1 -> 0xFF, mode 0 -> 0x10; caller _hdmi21_Initialize (by register 0x1F0C bit
 *   8)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2a80 @ 0xa00a2a80, flags -mcpu=v8 -Os -g.
 * Source form: the row array with a pointer field; a plain for loop with a u8 counter; an int 0 return.
 */
/* One row of hdmi_rx21_reg_blocks (0x34 bytes per HDMI 2.1 receiver): word 0 points to register block 0 of the
   receiver (0xCE009000, +0x1000 for receiver 1), word 1 to block 1, and so on up to block 12 at +0x30. */
struct hdmi_rx21_reg_blocks { unsigned int *block0; unsigned char rest[0x30]; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];

/* Start-up step (called by _hdmi21_Initialize): set byte 1 of the word at offset 4 of block 0 in both HDMI 2.1
   receivers. mode 1 sets the byte to 0xFF, mode 0 sets it to 0x10, any other mode changes nothing.
   _hdmi21_Initialize calls it with 1 before and with 0 after its other register set-up, in both cases only
   when bit 8 of PHY register 0x1F0C is clear. Returns 0. */
int hdmi_rx21_init_reg1_byte1(unsigned char mode)
{
    unsigned char receiver;

    for (receiver = 0; receiver <= 1; receiver++) {
        if (mode == 1)
            ARR_a807db00[receiver].block0[1] |= 0xff00;
        else if (mode == 0)
            ARR_a807db00[receiver].block0[1] = (ARR_a807db00[receiver].block0[1] & 0xffff00ff) | 0x1000;
    }
    return 0;
}
