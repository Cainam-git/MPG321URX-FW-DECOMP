/* leon2m FUN_a00dd5b8 @ 0xa00dd5b8-0xa00dd5e0 (10 words).
 * Prints "=====AT Prepare Timing Change %08X %08X %08X=====" with its three arguments and passes them on to
 * FUN_a0138fb8 (tail call).
 * The routine at 0xa00dd5e0 that follows it is a separate function (FUN_a00dd5e0).
 */
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a0138fb8(unsigned int a, unsigned int b, unsigned int c);

void FUN_a00dd5b8(unsigned int a, unsigned int b, unsigned int c)
{
    FUN_a00df170("=====AT Prepare Timing Change %08X %08X %08X=====\r\n", a, b, c);
    FUN_a0138fb8(a, b, c);
}
