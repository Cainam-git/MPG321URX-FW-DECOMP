/* sys_get_chip_model_code  (FUN_a011d0a8)
 *
 * Return a code 1..7 for the chip model, or 0.
 * Returns: model code
 * Name basis: descriptive - maps bytes 4-5 of the first identification field: 0x500, 0x501, 0x502, 0x504,
 *   0x550, 0x551, 0x552
 *
 * Matching notes
 * --------------
 * FUN_a011d0a8 (leon2m), flags -mcpu=v8 -O3 -g.
 * Source form: the 8-byte copy is a static helper copy_bytes with a u8 counter, the same as in
 * sys_get_chip_revision. The 16-bit value is formed as buf[4] * 0x100 + buf[5], narrowed to unsigned short for
 * the switch; the result is masked with 7 on return.
 */
#define ID_FIELD_ADDR  0x9f1b0600       /* 8-byte identification field */

static void copy_bytes(unsigned char *dst, const unsigned char *src, unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++)
        dst[i] = src[i];
}

/*
 * Return a model code for the chip, from bytes 4 and 5 of the 8-byte identification field at 0x9F1B0600.
 *
 * Bytes 4 and 5 read as a 16-bit value (byte 4 high): 0x500 gives 1, 0x501 gives 2, 0x502 gives 3,
 * 0x504 gives 4, 0x550 gives 5, 0x551 gives 6, 0x552 gives 7; any other value gives 0.
 * Called by sys_refresh_status_and_signal_alive.
 */
unsigned char sys_get_chip_model_code(void)
{
    unsigned char buf[8] = {0};
    unsigned char code;

    copy_bytes(buf, (const unsigned char *)ID_FIELD_ADDR, 8);
    switch ((unsigned short)(buf[4] * 0x100 + buf[5])) {
    case 0x500: code = 1; break;
    case 0x501: code = 2; break;
    case 0x502: code = 3; break;
    case 0x504: code = 4; break;
    case 0x550: code = 5; break;
    case 0x551: code = 6; break;
    case 0x552: code = 7; break;
    default: code = 0; break;
    }
    return code & 7;
}
