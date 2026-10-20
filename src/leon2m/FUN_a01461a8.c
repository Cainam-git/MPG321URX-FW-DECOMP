/* leon2m FUN_a01461a8 @ 0xa01461a8-0xa01461dc (13 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/13 mismatches.
 * Code facts: copies an 8-byte message {u16 a, u16 b, u32 c} from *src onto the stack (lduh +0,
 * lduh +2, ld +4) and calls FUN_a011b4f0(&copy, id) with id a u8 (and 0xff). void.
 * Fixes vs the autoc draft (53.85): a struct with the field copies in ascending order a, b, c (sched
 * emits ld +4 first like the fw); void, the callee takes (struct *, u8). Aids: none.
 */
struct Msg { unsigned short a, b; unsigned int c; };
extern void FUN_a011b4f0(struct Msg *, unsigned char);

void FUN_a01461a8(struct Msg *src, unsigned char id)
{
    struct Msg m;

    m.a = src->a;
    m.b = src->b;
    m.c = src->c;
    FUN_a011b4f0(&m, id);
}
