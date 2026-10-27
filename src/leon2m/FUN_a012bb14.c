/* FUN_a012bb14 (leon2m 0xa012bb14-0xa012bb38, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to the word at +0x14 of 0x24-byte entry i of the array DAT_a802d8dc. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a012baf0 and FUN_a012bb38.
 */
struct Rec { unsigned char p0[0x14]; unsigned int w14; unsigned char p18[4]; unsigned short h1c; unsigned char p1e[6]; };
extern struct Rec DAT_a802d8dc[];

void FUN_a012bb14(unsigned char i, unsigned int v)
{
    DAT_a802d8dc[i].w14 = v;
}
