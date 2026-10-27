/* FUN_a00f3a04 (leon2m 0xa00f3a04-0xa00f3a30, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Copies the 16-byte record *p (four words) to DAT_a802b79c. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00f39f8 and FUN_a00f3a30. Source form: a structure
 * assignment of a four-word structure (copied word by word).
 */
struct Q { unsigned int a, b, c, d; };
extern struct Q DAT_a802b79c;

void FUN_a00f3a04(const struct Q *p)
{
    DAT_a802b79c = *p;
}
