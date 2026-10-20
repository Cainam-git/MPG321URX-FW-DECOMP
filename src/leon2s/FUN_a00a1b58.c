/* leon2s FUN_a00a1b58 @ 0xa00a1b58 (-mcpu=v8 -Os -g)
 * The function writes a marker byte (value 1) into a global array at index `param_1 * 400 + 3`, calls FUN_a00a1a80, and returns 0. The array is declared as `unsigned char` starting at 0xa807d7e0, matching the byte store at offset 3. The multiplication by 400 matches the `smul %i0, 0x190, %i0` instruction. The call takes no arguments (the delay slot stores the byte, not setting up call parameters). The return value is explicitly 0 as shown by `restore %g0, 0, %o0`.
 */
typedef unsigned char undefined1;
extern int FUN_a00a1a80();
extern unsigned char ARR_a807d7e0[];

unsigned int FUN_a00a1b58(int param_1)
{
    ARR_a807d7e0[param_1 * 400 + 3] = 1;
    FUN_a00a1a80();
    return 0;
}
