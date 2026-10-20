/*
 * FUN_a008d70c (leon2s, 0xa008d70c-0xa008d800, 244 bytes), flags -mcpu=v8 -Os -g.
 * ROM table ARR_a00b4036 of {u16 a, u16 b} pairs (the FUN_a008d690 form). Group 0: u16 sum of .b over
 * entries 0..1, FUN_a008d2e0(entry0.a, sum, 0xa807d27a). Group 1: sum over 3..11,
 * FUN_a008d2e0(entry3.a, sum, 0xa807d289). Group 2: FUN_a008d2e0(entry14.a, entry14.b, 0xa807d3d1).
 * Then FUN_a008d490(dst, first, end) for the three groups (0,2), (3,0xc), (0xe,0xf), the last a sibcall.
 * u16 loop counter and sum (sll/srl 16).
 */
struct ent { unsigned short a; unsigned short b; };
extern struct ent ARR_a00b4036[];
extern unsigned char DAT_a807d27a[];
extern unsigned char DAT_a807d289[];
extern unsigned char DAT_a807d3d1[];
extern void FUN_a008d2e0(unsigned short, unsigned short, unsigned char *);
extern void FUN_a008d490(unsigned char *, unsigned int, unsigned int);

void FUN_a008d70c(void)
{
    unsigned short sum;
    unsigned short i;

    sum = 0;
    for (i = 0; i < 2; i++)
        sum += ARR_a00b4036[i].b;
    FUN_a008d2e0(ARR_a00b4036[0].a, sum, DAT_a807d27a);
    sum = 0;
    for (i = 3; i < 0xc; i++)
        sum += ARR_a00b4036[i].b;
    FUN_a008d2e0(ARR_a00b4036[3].a, sum, DAT_a807d289);
    FUN_a008d2e0(ARR_a00b4036[14].a, ARR_a00b4036[14].b, DAT_a807d3d1);
    FUN_a008d490(DAT_a807d27a, 0, 2);
    FUN_a008d490(DAT_a807d289, 3, 0xc);
    FUN_a008d490(DAT_a807d3d1, 0xe, 0xf);
}
