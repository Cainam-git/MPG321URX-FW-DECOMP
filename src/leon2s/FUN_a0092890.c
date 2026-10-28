/* leon2s FUN_a0092890 @ 0xa0092890-0xa0092944, -mcpu=v8 -Os -g.
 * (u8 p, u8 on). on != 0: writes the two bytes of the halfword at +0x18 of the 0x1c-byte record ARR_a807d580[p]
 * (low byte to register 1, high byte to register 2 of group 3, FUN_a00a8054), then FUN_a00a80cc(p, 3, 0xbd, 1, 1),
 * FUN_a00a80cc(p, 3, 0xbe, 1, 0) and FUN_a00927a0(p, 1, 0). on == 0: FUN_a00a80cc(p, 3, 0xbe, 1, 1) and
 * FUN_a00927a0(p, 0, 0). Group-3 counterpart of FUN_a009270c.
 */
struct rec { unsigned char pad[0x18]; unsigned short h18; unsigned char pad2[2]; };
extern struct rec ARR_a807d580[];
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00927a0(unsigned char, unsigned char, unsigned char);
void FUN_a0092890(unsigned char p, unsigned char on)
{
    if (on) {
        FUN_a00a8054(p, 3, 1, ARR_a807d580[p].h18);
        FUN_a00a8054(p, 3, 2, ARR_a807d580[p].h18 >> 8);
        FUN_a00a80cc(p, 3, 0xbd, 1, 1);
        FUN_a00a80cc(p, 3, 0xbe, 1, 0);
        FUN_a00927a0(p, 1, 0);
    } else {
        FUN_a00a80cc(p, 3, 0xbe, 1, 1);
        FUN_a00927a0(p, 0, 0);
    }
}
