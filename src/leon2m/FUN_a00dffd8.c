/* leon2m FUN_a00dffd8 @ 0xa00dffd8-0xa00e0040 (26 words).
 * Calls FUN_a00df8f4(id) (phy ID check, result unused), then FUN_a00df648(a, b, 1) for id 0 or 2 and
 * FUN_a00df648(a, b, 2) for id 1; other IDs return. The third argument is set in %o2 before each tail call
 * (FUN_a00df648 itself reads two). Flags -mcpu=v8 -O2 -g.
 */
extern int FUN_a00df8f4(unsigned int id);
extern void FUN_a00df648(int, int, int);

void FUN_a00dffd8(unsigned int id, int a, int b)
{
    FUN_a00df8f4(id);
    if (id == 0 || id == 2)
        FUN_a00df648(a, b, 1);
    else if (id == 1)
        FUN_a00df648(a, b, 2);
}
