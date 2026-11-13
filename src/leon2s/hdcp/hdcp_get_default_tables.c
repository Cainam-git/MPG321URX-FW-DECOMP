/* hdcp_get_default_tables  (FUN_a00c0ecc)
 *
 * Copy three built-in tables into the caller's buffers.
 * Name basis: descriptive - from the ROM data at 0x9F1B7148
 *
 * Matching notes
 * --------------
 * FUN_a00c0ecc (leon2s 0xa00c0ecc-0xa00c0f88, 47 words), flags -mcpu=v8 -Os -g.
 * Source forms: unsigned short counters. The third parameter is never read and stays in the signature (the
 * firmware reuses its register as a temporary); the second table is hdcp_default_table_block + 0x28, written as
 * [0x28 + i] on the same symbol.
 */
extern const unsigned char hdcp_default_table_block[];
extern const unsigned char hdcp_tx_engine_table_mode5[];

/*
 * Copy the built-in copy-protection tables out of the program image. Used by InitHDCP when the stored
 * 16-byte value is all zero.
 *
 *   value_out    16 bytes: bytes 0x13 down to 4 of hdcp_default_table_block (reverse order)
 *   table_out    0x20A bytes: hdcp_default_table_block from offset 0x28
 *   param_3      not used
 *   extra_out    0x80 bytes: hdcp_tx_engine_table_mode5
 */
void hdcp_get_default_tables(unsigned char *value_out, unsigned char *table_out, unsigned char *param_3,
                  unsigned char *extra_out)
{
    unsigned short i;

    for (i = 0; i <= 0xf; i++)
        value_out[i] = hdcp_default_table_block[0x13 - i];
    for (i = 0; i <= 0x209; i++)
        table_out[i] = hdcp_default_table_block[0x28 + i];
    for (i = 0; i <= 0x7f; i++)
        extra_out[i] = hdcp_tx_engine_table_mode5[i];
}
