/* leon2m FUN_a0125198 @ 0xa0125198-0xa0125230 (38 words, leaf), flags -mcpu=v8 -O3 -g.
 * Searches the 8 records of 0x16 bytes at DAT_001a42a8 for byte +0 == id and returns the record index. When no
 * record matches it returns 0xfc for id 0x12, 0xfd for id 0x13, 0xfe for id 0x14 and 0xff otherwise (r is a
 * signed char -1 / -4 / -3 / -2 returned as unsigned char).
 * Source form: the index is stored into r inside the loop before the break; after the loop 'if (i > 7)' selects
 * the id switch (the found path keeps its own i > 7 test and a copy of the first compare node, as in the code).
 */
struct rec { unsigned char b00; unsigned char b01[0x15]; };
extern const struct rec DAT_001a42a8[];

unsigned char FUN_a0125198(unsigned char id)
{
    unsigned char i;
    signed char r = -1;

    for (i = 0; i <= 7; i++)
        if (DAT_001a42a8[i].b00 == id) {
            r = i;
            break;
        }
    if (i > 7)
        switch (id) {
        case 0x12:
            r = -4;
            break;
        case 0x13:
            r = -3;
            break;
        case 0x14:
            r = -2;
            break;
        }
    return r;
}
