/* hdcp_rx_dp_load_keys  (FUN_a00c1318)
 *
 * Load the key-selection value and the key block into the DisplayPort input.
 * Name basis: derived - 5 bytes to registers 0x280.. and 0x11A bytes through the block's data port; registers
 *   saved and restored
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c1318 @ 0xa00c1318, flags -mcpu=v8 -Os -g (the section default).
 * Source form: each arm of the port test holds its complete call; the | 8 is applied at the read of
 * register 0x32; the saved values are unsigned chars.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned int);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);

#define R(a) (*(volatile unsigned int *)(a))

#define KSV_LENGTH       5      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x11a  /* bytes of the key block */

/*
 * Load the key-selection value and the key block into one DisplayPort receiver.
 *
 *   port  the receiver, 0 or 1 (the register helpers take the receiver number)
 *   key   the 5-byte key-selection value
 *   buf   the 0x11A-byte key block
 *
 * Called by InitHDCP for ports 0 and 1. The routine changes a number of registers for the time of the
 * load and puts every one of them back at the end, so the receiver is left as it was found, except that
 * register 0x32 comes back with bit 3 set.
 *
 * Order: save 0xCF011674, 0xCF011438, register 0x487, 0xCF01143C, register 0x32 (| 8) and 0xCF00F21C; clear
 * bits 3-4 of 0xCF00F21C; set bits 3-4 of 0xCF011674, bit 2 of 0xCF011438 and bit 0 of register 0x487; clear
 * bit 0 of 0xCF01143C; clear bits 4-5 of register 0x32 for port 0 and set them for port 1. Then the key-selection value goes to registers 0x280..0x284, 0xF is written to register 0xE9 and
 * polled until its low nibble reads 0, and the same five bytes are written one after another to register
 * 0xE8. Last, with 6 in 0xCF011780 (saved first) and 0xCF011784, 0xCF011788 and 0xCF00BFCC cleared, the key
 * block is written byte by byte to 0xCF01178C. The saved values go back in the order 0xCF011780, 0xCF011674,
 * 0xCF011438, register 0x487, 0xCF01143C, register 0x32, 0xCF00F21C. The poll on register 0xE9 has no limit.
 */
void hdcp_rx_dp_load_keys(unsigned int port, unsigned char *key, unsigned char *buf)
{
    unsigned char saved_cf011674, saved_cf011438, saved_reg_0x487, saved_cf01143c, saved_reg_0x32, saved_cf00f21c, saved_cf011780;
    unsigned short k;

    port &= 0xff;
    saved_cf011674 = R(0xcf011674);
    saved_cf011438 = R(0xcf011438);
    saved_reg_0x487 = dp_reg_read8(port, 0x487);
    saved_cf01143c = R(0xcf01143c);
    saved_reg_0x32 = dp_reg_read8(port, 0x32) | 8;
    saved_cf00f21c = R(0xcf00f21c);
    R(0xcf00f21c) &= ~0x18;
    R(0xcf011674) |= 0x18;
    R(0xcf011438) |= 4;
    dp_reg_update_bits(port, 0x487, 1, 1);
    R(0xcf01143c) &= ~1;
    if (port == 0)
        dp_reg_update_bits(port, 0x32, 0x30, 0);
    else
        dp_reg_update_bits(port, 0x32, 0x30, 1);
    for (k = 0; k < KSV_LENGTH; k++)
        dp_reg_write8(port, 0x280 + k, key[k]);
    dp_reg_write8(port, 0xe9, 0xf);
    while (dp_reg_read8(port, 0xe9) & 0xf)
        ;
    for (k = 0; k < KSV_LENGTH; k++)
        dp_reg_write8(port, 0xe8, key[k]);
    saved_cf011780 = R(0xcf011780);
    R(0xcf011780) = 6;
    R(0xcf011784) = 0;
    R(0xcf011788) = 0;
    R(0xcf00bfcc) = 0;
    for (k = 0; k < KEY_BLOCK_LENGTH; k++)
        R(0xcf01178c) = buf[k];
    R(0xcf011780) = saved_cf011780;
    R(0xcf011674) = saved_cf011674;
    R(0xcf011438) = saved_cf011438;
    dp_reg_write8(port, 0x487, saved_reg_0x487);
    R(0xcf01143c) = saved_cf01143c;
    dp_reg_write8(port, 0x32, saved_reg_0x32);
    R(0xcf00f21c) = saved_cf00f21c;
}
