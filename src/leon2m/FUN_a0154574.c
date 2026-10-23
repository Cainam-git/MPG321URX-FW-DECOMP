/* leon2m FUN_a0154574
 * Does nothing and returns. Its only caller is FUN_a0154580, which calls it when word 0xA802CF98 is non-zero and
 * the high nibble of byte 0xA802CF9C is 8.
 * Compiled unoptimised like its caller FUN_a0154580, so the empty body still gets its own register window
 * (save, ret, restore).
 */
void FUN_a0154574(void)
{
}
