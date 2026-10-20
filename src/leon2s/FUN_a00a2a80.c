/* leon2s FUN_a00a2a80 @ 0xa00a2a80-0xa00a2b08 (34 words), flags -mcpu=v8 -Os -g.
 * For both ports i = 0, 1 (u8): p = word 0 (a register-block pointer) of the 0x34-byte record
 * ARR_a807db00[i]; mode 1: p[1] |= 0xff00; mode 0: p[1] = (p[1] & 0xffff00ff) | 0x1000; other modes:
 * nothing. Returns 0.
 * Source form: the record array with a pointer field; a plain for loop; an int 0 return.
 */
struct Port34 { unsigned int *regs; unsigned char rest[0x30]; };
extern struct Port34 ARR_a807db00[];

int FUN_a00a2a80(unsigned char mode)
{
    unsigned char i;

    for (i = 0; i <= 1; i++) {
        if (mode == 1)
            ARR_a807db00[i].regs[1] |= 0xff00;
        else if (mode == 0)
            ARR_a807db00[i].regs[1] = (ARR_a807db00[i].regs[1] & 0xffff00ff) | 0x1000;
    }
    return 0;
}
