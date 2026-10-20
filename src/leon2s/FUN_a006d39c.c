/* FUN_a006d39c (leon2s 0xa006d39c-0xa006d3c8, 44 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Sets byte 0 (state) of the 20-byte records 0..6 of DAT_a807a824 to 2. Called from FUN_a006d3c8.
 * Seven separate stores in ascending order; GCC schedules the last one first.
 */
struct Rec20 { unsigned char state; unsigned char rest[19]; };
extern struct Rec20 DAT_a807a824[];

void FUN_a006d39c(void)
{
    DAT_a807a824[0].state = 2;
    DAT_a807a824[1].state = 2;
    DAT_a807a824[2].state = 2;
    DAT_a807a824[3].state = 2;
    DAT_a807a824[4].state = 2;
    DAT_a807a824[5].state = 2;
    DAT_a807a824[6].state = 2;
}
