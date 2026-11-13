/* __sinit  (FUN_a015b558)
 *
 * Initialise the standard I/O state of a reentrancy structure.
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015b558 @ 0xa015b558, flags -mcpu=v8 -O2 -g.
 * The last call to std is a tail call ('restore %g0, 2, %o2').
 */
extern unsigned char libc_cleanup_r_entry[];
extern void std(void *param_1, int param_2, int param_3, void *param_4);

/*
 * Initialise the C library state record at reent. Sets the record's fields +0x3C (the address
 * libc_cleanup_r_entry), +0x38 (1), +0x2E4 (3), +0x2E8 (the address reent + 0x2EC) and +0x2E0 (0), then calls
 * std on the three stream records whose pointers are at +4, +8 and +0xC of the record, with the argument pairs
 * (6, 0), (0xA, 1) and (0xA, 2).
 */
void __sinit(void *reent)
{
    *(unsigned int *)((char *)reent + 0x3c) = libc_cleanup_r_entry;
    *(unsigned int *)((char *)reent + 0x38) = 1;
    *(unsigned int *)((char *)reent + 0x2e4) = 3;
    *(unsigned int *)((char *)reent + 0x2e8) = (unsigned int)((char *)reent + 0x2ec);
    *(unsigned int *)((char *)reent + 0x2e0) = 0;

    std(*(void **)((char *)reent + 4), 6, 0, reent);
    std(*(void **)((char *)reent + 8), 0xa, 1, reent);
    std(*(void **)((char *)reent + 0xc), 0xa, 2, reent);
}
