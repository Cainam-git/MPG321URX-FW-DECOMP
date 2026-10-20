/* leon2s FUN_a00a29b0 @ 0xa00a29b0-0xa00a29d8 (10 words), flags -mcpu=v8 -Os -g.
 * Returns 1 when FUN_a00a20a8(port) (u8, btst 0xff) is non-zero, else 0 (not the callee value), as a u8
 * flag set per path with 'and 1' at the join ('return r & 1', the leon2m FUN_a0146dfc form).
 */
extern unsigned char FUN_a00a20a8(unsigned char);

unsigned char FUN_a00a29b0(unsigned char port)
{
    unsigned char r = 0;

    if (FUN_a00a20a8(port) != 0)
        r = 1;
    return r & 1;
}
