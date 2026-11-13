/* input_next_source_code_same_group  (FUN_a012f31c)
 *
 * Return the next entry of the source code table that belongs to the same group.
 * Returns: index
 * Note: The four codes in the table all differ in their top six bits, so the result is always the index of the
 *   code itself. Nothing calls it.
 * Name basis: descriptive - same bits 2..7; no caller
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f31c @ 0xa012f31c, flags -mcpu=v8 -O3 -g.
 * Source form: the search of input_find_source_code_index is a static helper inlined here; the result is an int, k an
 * unsigned int.
 */
extern const unsigned char input_source_code_table[];   /* four source codes: 0x61, 0x51, 0x81, 0x71 */

#define SOURCE_GROUP_MASK 0xfc          /* the top six bits of a source code */

static unsigned char find_code_index(unsigned char code)
{
    unsigned char i;
    for (i = 0; i < 4; i++) {
        unsigned char entry = input_source_code_table[i];
        if (code == entry)
            return i;
    }
    return 0xff;
}

/*
 * Return the index in input_source_code_table of the next code (searching on from the code at byte 10 of `record`,
 * wrapping round) that has the same top six bits as that code; return the index of the code itself when there is
 * none. The four codes in the table all differ in their top six bits, so with this table the result is always
 * the index of the code itself.
 *
 *   record  a record whose byte 10 holds a source code
 */
int input_next_source_code_same_group(const unsigned char *record)
{
    unsigned char index = find_code_index(record[10]);
    unsigned char step;
    unsigned int next;
    for (step = 1; step <= 4; step++) {
        next = (index + step) & 3;
        if ((input_source_code_table[next] & SOURCE_GROUP_MASK) == (input_source_code_table[index] & SOURCE_GROUP_MASK))
            return next;
    }
    return index;
}
