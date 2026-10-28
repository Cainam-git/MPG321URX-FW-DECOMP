/* FUN_a00c6968 (leon2s 0xa00c6968-0xa00c6c74, 780 bytes), flags -mcpu=v8 -Os -g.
 * int (u8 sel). Fills the 0x20a-byte stack buffer buf with func_0xa0f9d2e0(start, count, buf) blocks and
 * returns 1 when the 24-bit value (buf[2] << 16) + (buf[1] << 8) + buf[0] of the first block equals sum + neg:
 * for every byte b of the following blocks, b < 0x80 adds b to sum, b >= 0x80 adds (u8)~b and counts neg.
 * sel 1: value from (0x142, 3), bytes of (0x20, 0x118) and (0x138, 5). sel 2: value from (0x58a, 3), bytes of
 * (0x270, 0x10), (0x280, 0x20a), (0x48a, 0x80) and (0x50a, 0x80). Other sel: returns 0.
 * Source form: each loop reads the byte into the unsigned char c and tests the buffer byte itself,
 * 'c = buf[i]; if ((signed char)buf[i] >= 0) sum += c; else { sum += (unsigned char)~c; neg++; }'.
 */
extern void func_0xa0f9d2e0(unsigned short, unsigned short, void *);

int FUN_a00c6968(unsigned char sel)
{
    unsigned char buf[0x20a];
    unsigned int sum = 0;
    unsigned short neg = 0;
    unsigned short i;
    unsigned char c;
    unsigned int expect;

    if (sel == 1) {
        func_0xa0f9d2e0(0x142, 3, buf);
        expect = ((buf[2] << 8) + buf[1] << 8) + buf[0];
        func_0xa0f9d2e0(0x20, 0x118, buf);
        for (i = 0; i < 0x118; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
        func_0xa0f9d2e0(0x138, 5, buf);
        for (i = 0; i < 5; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
    } else if (sel == 2) {
        func_0xa0f9d2e0(0x58a, 3, buf);
        expect = ((buf[2] << 8) + buf[1] << 8) + buf[0];
        func_0xa0f9d2e0(0x270, 0x10, buf);
        for (i = 0; i < 0x10; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
        func_0xa0f9d2e0(0x280, 0x20a, buf);
        for (i = 0; i < 0x20a; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
        func_0xa0f9d2e0(0x48a, 0x80, buf);
        for (i = 0; i < 0x80; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
        func_0xa0f9d2e0(0x50a, 0x80, buf);
        for (i = 0; i < 0x80; i++) {
            c = buf[i];
            if ((signed char)buf[i] >= 0)
                sum += c;
            else {
                sum += (unsigned char)~c;
                neg++;
            }
        }
    } else
        return 0;
    return expect == sum + neg;
}
