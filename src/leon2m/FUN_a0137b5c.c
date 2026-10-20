/* leon2m FUN_a0137b5c @ 0xa0137b5c-0xa0137bb0 (21 words), flags -mcpu=v8 -O3 -g.
 * Code facts: sends a 4-byte message through the inter-processor mailbox FUN_a01370dc(cmd 0x16, length 4, buf, 1):
 * buf = { code, a, b, 0 } with code 2 for ch 0, 3 for ch 1, else 0xff. Callers: dc6c (channel bring-up) and
 * FUN_a012f43c. Which processor reads command 0x16 and what it does with it is not shown here.
 * Aids: none (the switch writes straight into m[0], the form of the twin FUN_a0137920; no for (;;) break;
 * barrier is needed).
 */
extern void FUN_a01370dc(int cmd, int len, unsigned char *buf, int flag);

void FUN_a0137b5c(unsigned char ch, unsigned char a, unsigned char b)
{
    unsigned char m[4] = { 0, 0, 0, 0 };

    switch (ch) {
    case 0: m[0] = 2; break;
    case 1: m[0] = 3; break;
    default: m[0] = 0xff; break;
    }
    m[1] = a;
    m[2] = b;
    FUN_a01370dc(0x16, 4, m, 1);
}
