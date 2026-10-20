/* leon2m FUN_a00a2bdc @ 0xa00a2bdc-0xa00a2c04 (10 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00b50d8.
 * Calls FUN_a01461a8 twice: first with the 8-byte record at 0xa80241a8 and id 0, then (as a tail call) with the
 * record at 0xa80241a0 and id 1. FUN_a01461a8 copies the record {u16, u16, u32} onto its stack and passes it on to
 * FUN_a011b4f0 with the id.
 */
extern unsigned short DAT_a80241a8[], DAT_a80241a0[];
extern void FUN_a01461a8(unsigned short *, int);

void FUN_a00a2bdc(void)
{
    FUN_a01461a8(DAT_a80241a8, 0);
    FUN_a01461a8(DAT_a80241a0, 1);
}
