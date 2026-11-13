/* _Bfree  (FUN_a015cd28)
 *
 * Return a big-number buffer to the free list (number formatting).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015cd28 @ 0xa015cd28, flags -mcpu=v8 -O2 -g.
 * The state record is an int base address with a fixed byte displacement, which gives ld [%o0 + 0x4c].
 */
#define FREE_LISTS_OFFSET 0x4c          /* pointer to the table of free lists, in the state record */

/*
 * Put a big-number buffer back on its free list.
 *   reent  the C library state record; the pointer at +0x4C is a table of list heads
 *   node   the buffer: word 0 is the link to the next buffer, word 1 is the index of its list in the table.
 *          NULL does nothing.
 * The buffer becomes the new head of its list.
 */
void _Bfree(int reent, int *node)
{
    if (node != 0) {
        int list_index = node[1];
        int *lists = *(int **)(reent + FREE_LISTS_OFFSET);
        *node = lists[list_index];
        lists[list_index] = (int)node;
    }
}
