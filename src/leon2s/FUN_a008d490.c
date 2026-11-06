/* FUN_a008d490 (leon2s 0xa008d490-0xa008d690, 512 bytes), flags -mcpu=v8 -Os -g.
 * void (buf = byte buffer address, unsigned char first, unsigned char end); called by FUN_a008d690 as
 * FUN_a008d490(0x9f1b0600, 0xc, 0x11). ARR_a00b4036 is the ROM table of 4-byte {u16 a; u16 b} records; b is the
 * length of record n in buf. For n = first .. end - 1 (u16) the u16 offset off walks the records (off += b of
 * record n). A record whose header byte h = buf[off] is neither 0xa0 nor (h & 0xe0) == 0xe0 is skipped.
 * h == 0xa0: x = xor of the len = buf[off + 1] bytes from buf[off + 2]. (h & 0xe0) == 0xe0: id = h & 0x1f;
 * while id <= 0x17: after four tries buf[off] = 0 and stop, else FUN_a008d2e0(0xda0 + id * 8, b of record n,
 * buf + off) reads the record again and h is read again: h neither 0xa0 nor (h & 0xe0) == 0xe0 stops,
 * (h & 0xe0) == 0xe0 retries with id = h & 0x1f, h == 0xa0 computes x as above and stops.
 * Finally buf[off] = 0 when buf[off] == 0xa0 and x != 0.
 * Source form: h is held in unsigned char b and copied into unsigned short c ('and 0xff' copy at 0xa008d4d8
 * and 0xa008d5b0); id is unsigned char and set in the for-loop init (from b) and increment (from c); after the
 * read the tests are '(c & 0xe0) != 0xe0 -> c != 0xa0 -> break' and then 'c != 0xa0 -> continue'.
 */
struct Pair { unsigned short a; unsigned short b; };
extern const struct Pair ARR_a00b4036[];
extern void FUN_a008d2e0(unsigned short, unsigned short, unsigned int);

void FUN_a008d490(unsigned char *buf, unsigned char first, unsigned char end)
{
    unsigned short off = 0;
    unsigned short n;

    for (n = first; n < end; n++) {
        if ((buf[off] & 0xe0) != 0xe0 && buf[off] != 0xa0) {
            off += ARR_a00b4036[n].b;
            continue;
        }
        {
            unsigned char b = buf[off];
            unsigned short c = b;
            unsigned char len = buf[off + 1];
            unsigned char x = 0;
            unsigned char tries = 0;
            unsigned char id;
            unsigned short k;

            if (c == 0xa0) {
                for (k = 0; k < len; k++)
                    x ^= buf[k + off + 2];
            } else if ((c & 0xe0) == 0xe0) {
                for (id = b & 0x1f; id <= 0x17; id = c & 0x1f) {
                    if (tries++ > 3) {
                        buf[off] = 0;
                        break;
                    }
                    FUN_a008d2e0(id * 8 + 0xda0, ARR_a00b4036[n].b, (unsigned int)(buf + off));
                    b = buf[off];
                    c = b;
                    if ((c & 0xe0) != 0xe0) {
                        if (c != 0xa0)
                            break;
                    }
                    if (c != 0xa0)
                        continue;
                    len = buf[off + 1];
                    x = 0;
                    for (k = 0; k < len; k++)
                        x ^= buf[k + off + 2];
                    break;
                }
            }
            if (buf[off] == 0xa0 && x != 0)
                buf[off] = 0;
        }
        off += ARR_a00b4036[n].b;
    }
}
