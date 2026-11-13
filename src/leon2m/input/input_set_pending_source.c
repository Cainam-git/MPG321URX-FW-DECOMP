/* input_set_pending_source  (FUN_a00fd980)
 *
 * Store a non-zero source code as pending.
 * Returns: 1 when stored
 * Name basis: descriptive - byte at 0xA802C980; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd980 @ 0xa00fd980, 32 bytes, leaf, flags -mcpu=v8 -O2 -g.
 * Source form: an int result variable set to 0 and to 1 (returned through %g1).
 */
extern unsigned char input_pending_source;

/* Store a source code in the byte at 0xA802C980 when it is not zero and return 1; return 0 and store nothing
 * for a zero code. Nothing calls this routine. */
int input_set_pending_source(unsigned char code)
{
    int stored = 0;

    if (code != 0) {
        input_pending_source = code;
        stored = 1;
    }
    return stored;
}
