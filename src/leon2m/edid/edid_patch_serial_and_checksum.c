/* edid_patch_serial_and_checksum  (FUN_a012ccf0)
 *
 * Copy ten identification bytes into an EDID block and recompute its checksum.
 * Name basis: derived - bytes 8..17 of the 128-byte block from the device settings, checksum in byte 0x7F;
 *   unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012ccf0 @ 0xa012ccf0-0xa012cd68 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: plain for loops with unsigned char counters and sum; the checksum is formed in a separate local.
 */
#define BLOCK_ID_FIRST       8                  /* block bytes 8..17 are replaced */
#define BLOCK_ID_COUNT       10
#define SETTINGS_ID_OFFSET   0x22              /* the ten source bytes: device_settings[0x22..0x2b] */
#define BLOCK_CHECKSUM_INDEX 0x7f               /* last byte of the 128-byte block */

extern unsigned char device_settings[];

/*
 * Copy the ten bytes device_settings[0x22..0x2b] to bytes 8..17 of the 128-byte block, then set the last byte
 * of the block (0x7f) to the value that makes the sum of all 128 bytes 0 modulo 256 (0 when the sum of the other
 * 127 bytes is 0). Nothing in the image calls this routine or stores its address.
 */
void edid_patch_serial_and_checksum(unsigned char *block)
{
    unsigned char i;
    unsigned char sum;
    unsigned char checksum;

    sum = 0;
    for (i = 0; i < BLOCK_ID_COUNT; i++)
        block[i + BLOCK_ID_FIRST] = device_settings[i + SETTINGS_ID_OFFSET];
    for (i = 0; i < BLOCK_CHECKSUM_INDEX; i++)
        sum += block[i];
    checksum = 0;
    if (sum != 0)
        checksum = -sum;
    block[BLOCK_CHECKSUM_INDEX] = checksum;
}
