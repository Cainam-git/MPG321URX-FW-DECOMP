/* FUN_a00e0d18 (leon2m 0xa00e0d18-0xa00e0d30, 24 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores v to the word DAT_a802b550 and 1 to the word DAT_a802b53c. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a00e0d10 and switchdataD_a00e0d30. Source form:
 * two extern words (each store has its own sethi).
 */
extern unsigned int DAT_a802b550;
extern unsigned int DAT_a802b53c;

void FUN_a00e0d18(unsigned int v)
{
    DAT_a802b550 = v;
    DAT_a802b53c = 1;
}
