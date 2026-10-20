/* leon2m FUN_a0125568 @ 0xa0125568-0xa01255a0 (14 words).
 * Reads index byte ARR_a802d880[n] and returns byte +0xa of the 22-byte (0x16) record with that index in the table
 * at 0x001a42a8; an index of 0xff returns all ones (unsigned char -1). Same shape as FUN_a01254f8 (+8), FUN_a0125530 (+9) and FUN_a01255a0 (halfword +4).
 * The result is an int set to -1 and narrowed on return (mov -1, then the zero-extension).
 */
struct Rec16 {
    unsigned char b0[4];
    unsigned short h4;
    unsigned char b6, b7, b8, b9, ba;
    unsigned char rest[11];
};
extern unsigned char ARR_a802d880[];

unsigned char FUN_a0125568(unsigned char n)
{
    unsigned int i = ARR_a802d880[n];
    struct Rec16 *r = (struct Rec16 *)0x001a42a8 + i;
    int v = -1;

    if (i != 0xff)
        v = r->ba;
    return v;
}
