/* leon2m FUN_a00d8c1c @ 0xa00d8c1c-0xa00d8cd4 (46 words), flags -mcpu=v8 -O3 -g.
 * Returns at once when the word at 0xa802d290+0xb0 is nonzero and FUN_a00d8bd8(0, 1) returns nonzero. Otherwise
 * the byte m at +0x19 is limited to 3 and stored at +0x8f, +0x19 is set to 0 (m != 0) or to m (m == 0),
 * FUN_a014913c(5) is called and +0x19 is set from +0x8f again.
 * FUN_a00d8bd8 (FUN_a0145660(0, 1) / 10 passed to FUN_a0087458) is defined in the same file and inlined here.
 * Source form: the +0x8f store and the +0x19 clear go through a pointer q that is assigned p in both arms of the
 * limit test (two definitions reach those stores, so q stays a separate copy of p: 'mov %l1,%o5'); the m == 0
 * store goes through p and the restore after the call accesses the global directly.
 */
struct R290 {
    unsigned char pad0[0x19];
    unsigned char b19;
    unsigned char pad1a[0x8f - 0x1a];
    unsigned char b8f;
    unsigned char pad90[0xb0 - 0x90];
    unsigned int wb0;
};
extern struct R290 DAT_a802d290;
extern int FUN_a0087458();
extern int FUN_a0145660();
extern void FUN_a014913c(int);

unsigned int FUN_a00d8bd8(unsigned int param_1, unsigned int param_2)
{
    unsigned int t;

    t = FUN_a0145660(0, 1);
    return (FUN_a0087458((unsigned short)t / 10) != 0);
}

static int busy(void)
{
    if (DAT_a802d290.wb0 != 0 && FUN_a00d8bd8(0, 1))
        return 1;
    return 0;
}

void FUN_a00d8c1c(void)
{
    struct R290 *p = &DAT_a802d290, *q;
    unsigned char m = DAT_a802d290.b19;

    if (busy())
        return;
    if (m > 3) {
        m = 3;
        q = p;
    } else
        q = p;
    q->b8f = m;
    if (m != 0)
        q->b19 = 0;
    else
        p->b19 = m;
    FUN_a014913c(5);
    DAT_a802d290.b19 = DAT_a802d290.b8f;
}
