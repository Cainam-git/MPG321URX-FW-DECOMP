/* leon2m FUN_a014118c @ 0xa014118c-0xa01411c4 (14 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/14 mismatches.
 * Code facts: leaf sibcall FUN_a0118be4(&DAT_001a3668[i], &DAT_001a3648[i]) with i a u8: two ROM
 * tables with 30-byte and 32-byte records (i*15*2 and i<<5 plus each table's own sethi/or).
 * Fixes vs the autoc draft (50.00): the two addresses are SYMBOLS (each has its own sethi of the
 * same HIGH; constants would share one) as struct arrays. The word after the range is the usual
 * padding nop. Aids: none.
 */
struct RecA { unsigned char b[0x1e]; };
struct RecB { unsigned char b[0x20]; };
extern const struct RecA DAT_001a3668[];
extern const struct RecB DAT_001a3648[];
extern void FUN_a0118be4(const struct RecA *, const struct RecB *);

void FUN_a014118c(unsigned char i)
{
    FUN_a0118be4(&DAT_001a3668[i], &DAT_001a3648[i]);
}
