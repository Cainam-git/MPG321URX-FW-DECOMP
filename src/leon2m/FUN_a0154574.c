/* leon2m FUN_a0154574
 * Does nothing and returns. Its only caller is FUN_a0154580, which calls it after the stores to 0xA802CF9C/9D.
 * Compiled unoptimised like its caller FUN_a0154580, so the empty body still gets its own register window
 * (save, ret, restore).
 */
void FUN_a0154574(void)
{
}
