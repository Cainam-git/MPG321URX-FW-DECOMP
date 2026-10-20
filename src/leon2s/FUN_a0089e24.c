/* FUN_a0089e24 (leon2s 0xa0089e24-0xa0089e4c, 40 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Marks entry i of the 8-byte record array DAT_a807cd04: byte 0 = 1, bytes 4 and 1 = 0.
 * Compiler aid: 'for (;;) break;' before the last clear emits no instructions; it ends a scheduling region,
 * which keeps the stores in the firmware's order.
 */
struct Rec8 { unsigned char b0; unsigned char b1; unsigned char _2[2]; unsigned char b4; unsigned char _5[3]; };
extern struct Rec8 DAT_a807cd04[];

void FUN_a0089e24(unsigned char i)
{
    DAT_a807cd04[i].b0 = 1;
    DAT_a807cd04[i].b4 = 0;
    for (;;)
        break;
    DAT_a807cd04[i].b1 = 0;
}
