/* leon2s FUN_a00b229c @ 0xa00b229c-0xa00b22fc (24 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/24 mismatches.
 * Code facts: deferred-call runner: if the byte DAT_a807de92 is set, for each of the 16 24-byte task
 * records DAT_a80793b8[i] whose byte +5 is set, clear it and call the function pointer at +0x14 (no
 * args); then clear de92. The fw counts a down counter 15..0 (addcc; bpos) next to the 0x18 stride.
 * Fixes vs the autoc draft (53.85): real base DAT_a80793b8 as a struct array (the draft used two
 * mid-record names), a plain for loop over i (loop.c makes the down counter). void(void). Aids: none.
 */
struct Task { unsigned char pad[5]; unsigned char pending; unsigned char pad2[0x14 - 6]; void (*fn)(void); };
extern struct Task DAT_a80793b8[16];
extern unsigned char DAT_a807de92;

void FUN_a00b229c(void)
{
    int i;

    if (DAT_a807de92 != 0) {
        for (i = 0; i < 16; i++) {
            if (DAT_a80793b8[i].pending != 0) {
                DAT_a80793b8[i].pending = 0;
                DAT_a80793b8[i].fn();
            }
        }
        DAT_a807de92 = 0;
    }
}
