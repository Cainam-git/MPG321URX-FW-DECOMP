/* leon2s FUN_a00a93e4 @ 0xa00a93e4-0xa00a94f4, -mcpu=v8 -Os -g.
 * (u8 port), port 0 or 1 (other values: nothing). Condition: (FUN_a0091c38(0) == 0x51 and
 * FUN_a0091c5c(0) == 0) or (FUN_a0091c38(1) == 0x51 and FUN_a0091c5c(1) == 0). When it holds, bit 23 of
 * word +0xe8 of the block that the pointer at +0x30 of the 0x34-byte record ARR_a807db00[port] points to is
 * cleared; otherwise it is set.
 * Source form: a switch on port with the whole test written out in each case (constant record index).
 */
struct Port34 { unsigned char pad[0x30]; unsigned int *pk; };
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a0091c38(unsigned int);
extern unsigned char FUN_a0091c5c(unsigned int);

void FUN_a00a93e4(unsigned char port)
{
    switch (port) {
    case 0:
        if ((FUN_a0091c38(0) == 0x51 && FUN_a0091c5c(0) == 0) || (FUN_a0091c38(1) == 0x51 && FUN_a0091c5c(1) == 0))
            ARR_a807db00[0].pk[0xe8 / 4] &= ~0x800000;
        else
            ARR_a807db00[0].pk[0xe8 / 4] |= 0x800000;
        break;
    case 1:
        if ((FUN_a0091c38(0) == 0x51 && FUN_a0091c5c(0) == 0) || (FUN_a0091c38(1) == 0x51 && FUN_a0091c5c(1) == 0))
            ARR_a807db00[1].pk[0xe8 / 4] &= ~0x800000;
        else
            ARR_a807db00[1].pk[0xe8 / 4] |= 0x800000;
        break;
    }
}
