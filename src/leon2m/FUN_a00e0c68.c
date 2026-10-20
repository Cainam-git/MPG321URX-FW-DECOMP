/* leon2m FUN_a00e0c68 @ 0xa00e0c68-0xa00e0c88 (8 words).
 * Stores v into the word 0xa8025d08 when the word 0xa802b54c is 0. Leaf function that directly
 * follows FUN_a00e0bf0.
 */
extern unsigned int DAT_a802b54c;
extern unsigned int DAT_a8025d08;

void FUN_a00e0c68(unsigned int v)
{
    if (DAT_a802b54c == 0)
        DAT_a8025d08 = v;
}
