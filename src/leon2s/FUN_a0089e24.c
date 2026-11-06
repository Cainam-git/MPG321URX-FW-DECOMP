/* FUN_a0089e24 (leon2s 0xa0089e24-0xa0089e4c, 40 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Marks entry i of the 8-byte record array DAT_a807cd04: byte 0 = 1, bytes 1 and 4 = 0.
 * Source form: the three stores in field order (b0, b1, b4); the compiler schedules them as b0, b4, b1.
 */
struct Rec8 { unsigned char b0; unsigned char b1; unsigned char _2[2]; unsigned char b4; unsigned char _5[3]; };
extern struct Rec8 DAT_a807cd04[];

void FUN_a0089e24(unsigned char i)
{
    DAT_a807cd04[i].b0 = 1;
    DAT_a807cd04[i].b1 = 0;
    DAT_a807cd04[i].b4 = 0;
}
