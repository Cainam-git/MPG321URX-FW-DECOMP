/* leon2m FUN_a009a5ac @ 0xa009a5ac (-mcpu=v8 -O2 -g)
 * **Explanation**: The key change is declaring `DAT_a802d290` as an array base at `0xa802d290` and accessing the byte at offset `0x1e1` (which is `0xa802d471`). This lets the compiler compute the base pointer once with `sethi`/`or` and use `[%l0 + 0x1e1]` for both the load and store, exactly matching the target. The function loads that byte, passes it to `FUN_a00a93bc`, copies `DAT_a8025c55` into it, calls `FUN_a00af44c(0x34, 3)`, stores `0xbe` to `_DAT_a802afec`, calls `FUN_a00a9650(3, 1)`, and clears `DAT_a8025c55`.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802d290[];
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern void FUN_a00af44c();

void FUN_a009a5ac(void)
{
    FUN_a00a93bc(DAT_a802d290[0x1e1]);
    DAT_a802d290[0x1e1] = DAT_a8025c55;
    FUN_a00af44c(0x34, 3);
    _DAT_a802afec = 0xbe;
    FUN_a00a9650(3, 1);
    DAT_a8025c55 = 0;
}
