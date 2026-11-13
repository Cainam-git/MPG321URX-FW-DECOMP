/* sys_otp_check_records  (FUN_a008d490)
 *
 * Check the records of loaded factory data and reload or drop bad ones.
 *   buf: data buffer
 *   first: first record
 *   end: record after last
 * Name basis: descriptive - records 0xA0 = XOR-checked, 0xE0-class = reloaded; lengths from ROM table
 *   0xA00B4036
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: the header byte is held in the unsigned char 'header' and copied into the unsigned short
 * 'header_copy' (an 'and 0xff' copy, two places); 'id' is an unsigned char set in the for-loop init (from
 * 'header') and increment (from 'header_copy'); after the re-read the tests are
 * '(header_copy & 0xe0) != 0xe0 -> header_copy != 0xa0 -> break' and then 'header_copy != 0xa0 -> continue'.
 * The XOR loop is written out twice (initial record, re-read record).
 */
/* Record header bytes. */
#define RECORD_CHECKED        0xa0  /* byte 1 = data length, data from byte 2; the XOR of the data must be 0 */
#define RECORD_REDIRECT_CLASS 0xe0  /* top three bits of a header that names a record to read again */
#define REDIRECT_ID_MASK      0x1f  /* low five bits of such a header = id of the record to read */
#define REDIRECT_ID_LAST      0x17  /* highest id that is read */
#define REDIRECT_STORE_BASE   0xda0 /* a record with id n is read from store address 0xda0 + n * 8 */
#define REDIRECT_STORE_STRIDE 8
#define REDIRECT_MAX_RETRIES  3     /* the record is read at most 4 times */

/* ROM table, one entry per record number. */
struct otp_record_info {
    unsigned short store_address; /* where record n is read from (first argument of sys_otp_read_bytes) */
    unsigned short length;        /* size of record n in the buffer */
};
extern const struct otp_record_info ARR_a00b4036[];
extern void sys_otp_read_bytes(unsigned short, unsigned short, unsigned int);

/*
 * Check the records of the factory data that sys_otp_read_bytes has put into buf, and repair or invalidate
 * bad ones. The records lie one after the other in buf; record n takes ARR_a00b4036[n].length bytes. Records
 * first .. end - 1 are looked at.
 * A header byte of RECORD_CHECKED means a record with a length (byte 1) and data (from byte 2) whose bytes
 * must XOR to 0; if they do not, the header is set to 0 (record invalid).
 * A header whose top three bits are 0xe0 names, in its low five bits, another record (id): the record is read
 * again from store address 0xda0 + id * 8 over the same place in buf, and the new header is judged the same
 * way (again a redirect: read again, at most four reads; a checked record: XOR test; anything else: left
 * as read). If the header is still a redirect after the fourth read, it is set to 0. An id above 0x17 is
 * not read; the record stays as it is.
 * Headers of any other kind are skipped.
 *   buf:   address of the data buffer
 *   first: number of the first record
 *   end:   number after the last record
 * Caller: sys_otp_load_shared_data, with buf 0x9f1b0600 and records 0xc..0x10.
 */
void sys_otp_check_records(unsigned char *buf, unsigned char first, unsigned char end)
{
    unsigned short off = 0;   /* start of record n in buf */
    unsigned short n;

    for (n = first; n < end; n++) {
        if ((buf[off] & RECORD_REDIRECT_CLASS) != RECORD_REDIRECT_CLASS && buf[off] != RECORD_CHECKED) {
            off += ARR_a00b4036[n].length;
            continue;
        }
        {
            unsigned char header = buf[off];
            unsigned short header_copy = header;
            unsigned char len = buf[off + 1];
            unsigned char xor_sum = 0;
            unsigned char tries = 0;
            unsigned char id;
            unsigned short k;

            if (header_copy == RECORD_CHECKED) {
                for (k = 0; k < len; k++)
                    xor_sum ^= buf[k + off + 2];
            } else if ((header_copy & RECORD_REDIRECT_CLASS) == RECORD_REDIRECT_CLASS) {
                for (id = header & REDIRECT_ID_MASK; id <= REDIRECT_ID_LAST; id = header_copy & REDIRECT_ID_MASK) {
                    if (tries++ > REDIRECT_MAX_RETRIES) {
                        buf[off] = 0;
                        break;
                    }
                    sys_otp_read_bytes(id * REDIRECT_STORE_STRIDE + REDIRECT_STORE_BASE,
                                       ARR_a00b4036[n].length, (unsigned int)(buf + off));
                    header = buf[off];
                    header_copy = header;
                    if ((header_copy & RECORD_REDIRECT_CLASS) != RECORD_REDIRECT_CLASS) {
                        if (header_copy != RECORD_CHECKED)
                            break;
                    }
                    if (header_copy != RECORD_CHECKED)
                        continue;
                    len = buf[off + 1];
                    xor_sum = 0;
                    for (k = 0; k < len; k++)
                        xor_sum ^= buf[k + off + 2];
                    break;
                }
            }
            /* a checked record whose XOR is not 0 is invalidated */
            if (buf[off] == RECORD_CHECKED && xor_sum != 0)
                buf[off] = 0;
        }
        off += ARR_a00b4036[n].length;
    }
}
