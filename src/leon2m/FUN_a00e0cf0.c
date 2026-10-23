/* FUN_a00e0cf0 (leon2m 0xa00e0cf0-0xa00e0d08, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores v to the word DAT_a802b554 and 1 to the word DAT_a802b548. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00e0cd8 and FUN_a00e0d08. Source form: two extern
 * words (each store has its own sethi).
 */
extern unsigned int DAT_a802b554;
extern unsigned int DAT_a802b548;

void FUN_a00e0cf0(unsigned int v)
{
    DAT_a802b554 = v;
    DAT_a802b548 = 1;
}
