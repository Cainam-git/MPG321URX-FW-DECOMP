/* sys_read_id_record_byte  (FUN_a0115584)
 *
 * Read the six-byte identification record, check it and return one of its bytes.
 * Returns: byte or -1
 * Name basis: derived - 0xA0 header and XOR check; byte 3, 4 or 5 by selector
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0115584 @ 0xa0115584-0xa0115644 (48 words), flags -mcpu=v8 -O3 -g.
 * Source form: the XOR loop bound buf[1] is copied into a local first (the firmware tests it once before the loop
 * and compares 'i < length' at the bottom). The byte index is chosen before the validity test.
 */
extern void sys_read_id_area(unsigned int, unsigned char, unsigned char *);

#define ID_RECORD_AREA   4      /* area number given to sys_read_id_area */
#define ID_RECORD_SIZE   6      /* bytes read */
#define ID_HEADER_MASK   0xe0   /* the top three bits of byte 0 must read 101 */
#define ID_HEADER_VALUE  0xa0

/*
 * Read the identification record and return one of its bytes, or -1 when the record is not valid.
 *
 * selector  0 returns byte 3, 1 returns byte 4, any other value returns byte 5
 *
 * Record layout as the check uses it: byte 0 is a header (top three bits 101), byte 1 is a length, and the
 * `length` bytes from byte 2 on must XOR to 0. Called by sys_ddr_setup_phy.
 */
int sys_read_id_record_byte(int selector)
{
    unsigned char buf[ID_RECORD_SIZE] = { 0 };
    unsigned char invalid, checksum, i, index, length;

    sys_read_id_area(ID_RECORD_AREA, ID_RECORD_SIZE, buf);
    invalid = 0;
    if ((buf[0] & ID_HEADER_MASK) == ID_HEADER_VALUE) {
        checksum = 0;
        length = buf[1];
        for (i = 0; i < length; i++)
            checksum ^= buf[2 + i];
        if (checksum)
            invalid = 1;
    } else
        invalid = 1;
    if (selector == 0)
        index = 3;
    else if (selector == 1)
        index = 4;
    else
        index = 5;
    if (invalid)
        return -1;
    return buf[index];
}
