/* leon2s FUN_a006cfac @ 0xa006cfac-0xa006cfe8 (15 words), flags -mcpu=v8 -Os -g.
 * Stores the 4-word record DAT_a80787e4 = {a, b, c, d} (params 1..4), the byte DAT_a80787e0 = mode
 * (5th param, u8) and the byte flag DAT_a80787f4 = 1; then sibcall FUN_a006fedc() (no arguments, returns
 * nothing). Three separate symbols (each byte store has its own sethi; the words go through one base).
 * Source form: the record as a struct, and the store order a, mode, b, c, d, flag.
 */
struct Req { unsigned int a, b, c, d; };
extern struct Req DAT_a80787e4;
extern unsigned char DAT_a80787e0;
extern unsigned char DAT_a80787f4;
extern void FUN_a006fedc(void);

void FUN_a006cfac(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned char mode)
{
    DAT_a80787e4.a = a;
    DAT_a80787e0 = mode;
    DAT_a80787e4.b = b;
    DAT_a80787e4.c = c;
    DAT_a80787e4.d = d;
    DAT_a80787f4 = 1;
    FUN_a006fedc();
}
