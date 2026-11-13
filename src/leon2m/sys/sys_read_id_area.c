/* sys_read_id_area  (FUN_a011ce80)
 *
 * Copy one of the five small identification fields into a buffer.
 * Name basis: descriptive - fields of 8, 8, 16, 16 and 40 bytes at 0x9F1B0600..0x9F1B0630
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011ce80, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the copy is a byte loop with an unsigned char counter (a static helper, inlined; the same loop as in
 *    sys_get_chip_revision);
 *  - the length is a separate unsigned char `len`, copied from the request before the limit test; len is
 *    declared and initialised before src.
 */
/* The five identification fields, read-only, one after the other. */
#define ID_FIELD_0_ADDR 0x9f1b0600      /* 8 bytes */
#define ID_FIELD_1_ADDR 0x9f1b0608      /* 8 bytes */
#define ID_FIELD_2_ADDR 0x9f1b0610      /* 16 bytes */
#define ID_FIELD_3_ADDR 0x9f1b0620      /* 16 bytes */
#define ID_FIELD_4_ADDR 0x9f1b0630      /* 40 bytes */

static void copy_bytes(unsigned char *dst, const unsigned char *src, unsigned char count)
{
    unsigned char i;
    for (i = 0; i < count; i++)
        dst[i] = src[i];
}

/*
 * Copy the start of one identification field into a buffer.
 *
 *   field    0..4: which field (sizes 8, 8, 16, 16 and 40 bytes); any other value copies nothing
 *   request  number of bytes wanted; cut down to the size of the field
 *   dst      buffer that receives the bytes
 *
 * Called from sys_read_id_record_byte, which reads 6 bytes of field 4.
 */
void sys_read_id_area(unsigned int field, unsigned char request, unsigned char *dst)
{
    unsigned char len = 0;
    const unsigned char *src = 0;

    switch (field) {
    case 0:
        len = request;
        if (request > 8)
            len = 8;
        src = (const unsigned char *)ID_FIELD_0_ADDR;
        break;
    case 1:
        len = request;
        if (request > 8)
            len = 8;
        src = (const unsigned char *)ID_FIELD_1_ADDR;
        break;
    case 2:
        len = request;
        if (request > 16)
            len = 16;
        src = (const unsigned char *)ID_FIELD_2_ADDR;
        break;
    case 3:
        len = request;
        if (request > 16)
            len = 16;
        src = (const unsigned char *)ID_FIELD_3_ADDR;
        break;
    case 4:
        len = request;
        if (request > 40)
            len = 40;
        src = (const unsigned char *)ID_FIELD_4_ADDR;
        break;
    }
    copy_bytes(dst, src, len);
}
