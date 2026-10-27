/* FUN_a00e0cb8 (leon2m 0xa00e0cb8-0xa00e0cd8, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to the word DAT_a802b550 when the word DAT_a802b53c is 0. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00e0cb0 and FUN_a00e0cd8.
 */
extern unsigned int DAT_a802b53c;
extern unsigned int DAT_a802b550;

void FUN_a00e0cb8(unsigned int v)
{
    if (DAT_a802b53c == 0)
        DAT_a802b550 = v;
}
