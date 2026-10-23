/* FUN_a00e0cd8 (leon2m 0xa00e0cd8-0xa00e0cf0, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores v to the word DAT_a8025d08 and 1 to the word DAT_a802b54c. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00e0cb8 and FUN_a00e0cf0. Source form: two extern
 * words (each store has its own sethi).
 */
extern unsigned int DAT_a8025d08;
extern unsigned int DAT_a802b54c;

void FUN_a00e0cd8(unsigned int v)
{
    DAT_a8025d08 = v;
    DAT_a802b54c = 1;
}
