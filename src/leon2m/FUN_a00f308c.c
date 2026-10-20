/* leon2m FUN_a00f308c @ 0xa00f308c  write a 16-bit value to two consecutive byte registers
 * byte-exact). r[0] = bits 0..7, r[1] = bits 8..15 (word-spaced hardware registers); the write counterpart of
 * FUN_a00f30a8. Used by the output path set-up FUN_a0106d64 for the 0xCF00B81C.. register pairs. */
void FUN_a00f308c(volatile unsigned int *r, unsigned int v)
{
    r[0] = v & 0xff;
    r[1] = (v >> 8) & 0xff;
}
