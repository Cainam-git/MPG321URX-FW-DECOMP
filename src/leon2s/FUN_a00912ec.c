/* leon2s FUN_a00912ec @ 0xa00912ec-0xa0091388 (39 words).
 * Writes registers 0x4b, 0x4c and 0x4d of port p with FUN_a00a65c4: 0x4b = 0x80 when FUN_a008fea8(p) is non-zero
 * (else 0), 0x4c = 0, and 0x4d = 0x80 only when, in addition, bits 5..7 of register 0x144 (FUN_a00a657c(p, 0x144))
 * are not 011 (else 0).
 * Source form: each outcome writes all three registers in its own arm (nested ifs, the 0x144 test inside the
 * FUN_a008fea8 arm); the compiler shares the common call tails.
 */
extern unsigned char FUN_a008fea8(unsigned char);
extern unsigned int FUN_a00a657c(unsigned int, unsigned short);
extern void FUN_a00a65c4(unsigned int, unsigned short, unsigned int);

void FUN_a00912ec(unsigned char p)
{
    if (FUN_a008fea8(p)) {
        if ((FUN_a00a657c(p, 0x144) & 0xe0) == 0x60) {
            FUN_a00a65c4(p, 0x4b, 0x80);
            FUN_a00a65c4(p, 0x4c, 0);
            FUN_a00a65c4(p, 0x4d, 0);
        } else {
            FUN_a00a65c4(p, 0x4b, 0x80);
            FUN_a00a65c4(p, 0x4c, 0);
            FUN_a00a65c4(p, 0x4d, 0x80);
        }
    } else {
        FUN_a00a65c4(p, 0x4b, 0);
        FUN_a00a65c4(p, 0x4c, 0);
        FUN_a00a65c4(p, 0x4d, 0);
    }
}
