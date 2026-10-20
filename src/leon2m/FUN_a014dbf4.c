/* FUN_a014dbf4: tail-calls FUN_a0132a40(0) when sel == 1 and FUN_a0132a40(1) otherwise.
 * Callers: FUN_a00875ec, FUN_a008767c. Written as an if/else of two calls (GCC merges them into one call with
 * the argument picked by a branch, as in the firmware).
 */
extern void FUN_a0132a40(unsigned int on);

void FUN_a014dbf4(unsigned char sel)
{
    if (sel == 1)
        FUN_a0132a40(0);
    else
        FUN_a0132a40(1);
}
