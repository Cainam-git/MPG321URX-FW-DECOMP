/* FUN_a008996c (leon2s 0xa008996c-0xa0089a38, 196 bytes), flags -mcpu=v8 -Os -g.
 * Returns unless bit 0 of FUN_a00a78b4(port, 0x7b) is set. Works on the 8-byte record port of DAT_a807cd04
 * (bytes a at +1 and b at +4, halfwords ta at +2 and tb at +6) with the value t of FUN_a00b2064(). When b is
 * set and t - tb > 100: FUN_a00a78b4(port, 0x73) and tb = FUN_a00b2064(). When b is clear, a is set and
 * t - ta > 40: FUN_a00a78fc(port, 0x73, FUN_a00a78b4(port, 0x73)), b = 1, a = 0, tb = FUN_a00b2064().
 * Source form: each arm stores tb itself (GCC merges the two tails); one shared store after the if/else
 * schedules the arguments of the first FUN_a00a78b4(port, 0x73) call in the other order.
 */
struct rec {
    unsigned char f0;
    unsigned char a;
    unsigned short ta;
    unsigned char b;
    unsigned char f5;
    unsigned short tb;
};

extern struct rec DAT_a807cd04[];
extern unsigned int FUN_a00a78b4(unsigned char, unsigned short);
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00b2064(void);

void FUN_a008996c(unsigned char port)
{
    struct rec *r;

    if (!(FUN_a00a78b4(port, 0x7b) & 1))
        return;
    r = &DAT_a807cd04[port];
    if (r->b) {
        if (FUN_a00b2064() - r->tb <= 100)
            return;
        FUN_a00a78b4(port, 0x73);
        r->tb = FUN_a00b2064();
    } else {
        if (!r->a)
            return;
        if (FUN_a00b2064() - r->ta <= 40)
            return;
        FUN_a00a78fc(port, 0x73, FUN_a00a78b4(port, 0x73));
        r->b = 1;
        r->a = 0;
        r->tb = FUN_a00b2064();
    }
}
