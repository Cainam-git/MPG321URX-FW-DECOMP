/* FUN_a014aa7c (leon2m 0xa014aa7c-0xa014aaa0, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v & 1 to bit 19 of the word DAT_a802e3d0 (read-modify-write). Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a014aa48 and FUN_a014aaa0. Source form: a one-bit
 * bit-field (12 bits above it in the big-endian word).
 */
struct B19 { unsigned int hi:12, b19:1, lo:19; };
extern struct B19 DAT_a802e3d0;

void FUN_a014aa7c(unsigned int v)
{
    DAT_a802e3d0.b19 = v;
}
