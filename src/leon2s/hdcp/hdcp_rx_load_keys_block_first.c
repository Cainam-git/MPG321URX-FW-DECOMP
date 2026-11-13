/* hdcp_rx_load_keys_block_first  (FUN_a00c0a88)
 *
 * Load the 5-byte key-selection value and the 282-byte key block into a receiver (first path).
 * Name basis: derived - 5 + 0x11A bytes with register 0xCF011674 switched around the load
 *
 * Matching notes
 * --------------
 * FUN_a00c0a88 (leon2s 0xa00c0a88-0xa00c0b48, 192 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: unsigned short loop counters; the second destination is a volatile word pointer that is
 * incremented; volatile only on the 0xcf... hardware registers.
 */
#define REG_674 (*(volatile unsigned int *)0xcf011674)
#define REG_780 (*(volatile unsigned int *)0xcf011780)

#define KSV_LENGTH       5                      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x11a                  /* bytes of the key block */

/*
 * Write a key set (5-byte key-selection value and 282-byte key block) into the registers of the hardware block
 * at 0xCF018D24 / 0xCF037800. The low byte of register 0xCF011674 is saved, bits 3 and 4 of it are set for the
 * time of the load, and the saved byte is written back at the end. Register 0xCF011780 is cleared after the key
 * block.
 *
 * Called from InitHDCP for the second key set, after hdcp_tx_hdmi_load_fixed_streams.
 *
 *   ksv        KSV_LENGTH bytes, one register each (0xCF018D24, 28, 2C, 30, 34)
 *   key_block  KEY_BLOCK_LENGTH bytes, one word each from 0xCF037800
 */
void hdcp_rx_load_keys_block_first(unsigned char *ksv, unsigned char *key_block)
{
    unsigned char saved = REG_674;
    unsigned short i;
    volatile unsigned int *dest;

    REG_674 |= 0x18;
    for (i = 0; i < KSV_LENGTH; i++)
        *(volatile unsigned int *)(((i + 0x6349) << 2) | 0xcf000000) = ksv[i];
    dest = (volatile unsigned int *)0xcf037800;
    for (i = 0; i < KEY_BLOCK_LENGTH; i++)
        *dest++ = key_block[i];
    REG_780 = 0;
    REG_674 = saved;
}
