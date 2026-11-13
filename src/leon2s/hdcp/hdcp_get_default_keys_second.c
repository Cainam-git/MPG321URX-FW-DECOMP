/* hdcp_get_default_keys_second  (FUN_a00c0c78)
 *
 * Copy the second built-in key-selection value and key block into the caller's buffers.
 * Name basis: derived - 5 bytes and a block from the ROM data area
 *
 * Matching notes
 * --------------
 * FUN_a00c0c78 (leon2s 0xa00c0c78-0xa00c0dfc), flags -mcpu=v8 -Os -g.
 * Source form: plain array loops with an unsigned short index.
 */
extern unsigned char hdcp_default_ksv_second[];
extern unsigned char hdcp_default_keys_second[];

#define KSV_LENGTH       5                      /* bytes of the key-selection value */
#define KEY_BLOCK_LENGTH 0x11a                  /* bytes of the key block */

/*
 * Copy the built-in second key set out of the program image: the 5-byte key-selection value into ksv and the
 * 282-byte key block into key_block. Used by InitHDCP when the stored second key-selection value is all
 * zero. The first key set is copied by hdcp_get_default_keys_first.
 */
void hdcp_get_default_keys_second(unsigned char *ksv, unsigned char *key_block)
{
    unsigned short i;
    for (i = 0; i < KSV_LENGTH; i++)
        ksv[i] = hdcp_default_ksv_second[i];
    for (i = 0; i < KEY_BLOCK_LENGTH; i++)
        key_block[i] = hdcp_default_keys_second[i];
}
