/*
 * FUN_a00a2f70 (leon2s, 0xa00a2f70-0xa00a2fd0, 96 bytes, leaf with sibcalls), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/24.
 * Code facts: blk = the pointer at +0x30 of the 0x34-byte port record ARR_a807db00[port]. on != 0:
 * blk[2] low 6 bits = v (u8), then FUN_a00a73ac(7, &blk[2]); on == 0: FUN_a00a73d4(7, &blk[2]). Both
 * are leaf tail calls. The draft used the mid-record name DAT_a807db30. Aids: none.
 */
struct Port34 { unsigned char pad[0x30]; unsigned int *blk; };
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a73ac(unsigned int, unsigned int *);
extern void FUN_a00a73d4(unsigned int, unsigned int *);

void FUN_a00a2f70(unsigned char param_1, unsigned char param_2, unsigned char param_3)
{
    if (param_3 != 0) {
        ARR_a807db00[param_1].blk[2] = (ARR_a807db00[param_1].blk[2] & ~0x3f) | param_2;
        FUN_a00a73ac(7, ARR_a807db00[param_1].blk + 2);
    } else {
        FUN_a00a73d4(7, ARR_a807db00[param_1].blk + 2);
    }
}
