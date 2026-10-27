/* FUN_a00e0c88 (leon2m 0xa00e0c88-0xa00e0ca8, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores v to the word DAT_a802b554 when the word DAT_a802b548 is 0. It lies between FUN_a00e0c68 and FUN_a00e0ca8.
 */
extern unsigned int DAT_a802b548;
extern unsigned int DAT_a802b554;

void FUN_a00e0c88(unsigned int v)
{
    if (DAT_a802b548 == 0)
        DAT_a802b554 = v;
}
