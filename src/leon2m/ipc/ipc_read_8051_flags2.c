/* ipc_read_8051_flags2  (FUN_a002c218)
 *
 * Return the shared 8051 byte at XDATA 0xF225.
 * Returns: byte value
 * Note: Register 0xCF03C894; nothing calls it.
 * Name basis: descriptive - 8051 window mapping; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c218 (leon2m 0xa002c218-0xa002c22c, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: a volatile word read returned as unsigned char (the 'and 0xff' sits in the return delay slot).
 */
#define R (*(volatile unsigned int *)0xcf03c894)

/*
 * Read the shared port event register at 0xCF03C894 (one bit per port; the input processor sets bits in it) and
 * return its low byte. Nothing calls this routine.
 */
unsigned char ipc_read_8051_flags2(void)
{
    return R;
}
