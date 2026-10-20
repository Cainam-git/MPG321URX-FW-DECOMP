/* leon2m FUN_a01207f4 @ 0xa01207f4-0xa012082c (14 words).
 * Copies the three-word structure at src into entry n of the table of 12-byte entries at 0xa8027aac (word by word:
 * +0, +4, +8). FUN_a0121714 reads word 0 and FUN_a0120b38 / FUN_a0120c90 read word 4 of the same entries. Called four times from FUN_a015209c. Written as a plain structure assignment; the
 * entries have 4-byte alignment, so GCC copies them as three ld/st pairs.
 */
struct Rec12 { unsigned int w0, w4, w8; };
extern struct Rec12 DAT_a8027aac[];

void FUN_a01207f4(unsigned char n, struct Rec12 *src)
{
    DAT_a8027aac[n] = *src;
}
