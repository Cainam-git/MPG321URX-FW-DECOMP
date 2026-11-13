/* lib_copy_words  (FUN_a00b1508)
 *
 * Copy a number of 32-bit words.
 * Name basis: proven - word loop
 *
 * Matching notes
 * --------------
 * FUN_a00b1508 (leon2s 0xa00b1508), flags -mcpu=v8 -Os -g.
 * The while loop with i < count gives the target's cmp/bcc at the top and cmp/bcs at the bottom.
 */
/* Copy count 32-bit words from src to dest, front to back. */
void lib_copy_words(int *dest, int *src, unsigned int count)
{
    unsigned int i = 0;
    while (i < count) {
        dest[i] = src[i];
        i++;
    }
}
