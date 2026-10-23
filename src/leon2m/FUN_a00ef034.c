/* FUN_a00ef034 (leon2m 0xa00ef034-0xa00ef048, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a to the halfword DAT_a802b74e and b to the halfword DAT_a802b74c. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a00eef7c and FUN_a00ef048. Source form: two
 * extern halfwords (each store has its own sethi).
 */
extern unsigned short DAT_a802b74e;
extern unsigned short DAT_a802b74c;

void FUN_a00ef034(unsigned short a, unsigned short b)
{
    DAT_a802b74e = a;
    DAT_a802b74c = b;
}
