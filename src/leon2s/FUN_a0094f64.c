/* FUN_a0094f64 (leon2s 0xa0094f64-0xa0094fb0, 76 bytes), flags -mcpu=v8 -Os -g.
 * For one port calls FUN_a00a80cc(port, 0, 8, 0x10, 1) and FUN_a00a80cc(port, 0, 8, 0x20, 1), then tail-calls
 * FUN_a00a8054(port, 0, 0x130, 10).
 */
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);

void FUN_a0094f64(unsigned char port)
{
    FUN_a00a80cc(port, 0, 8, 0x10, 1);
    FUN_a00a80cc(port, 0, 8, 0x20, 1);
    FUN_a00a8054(port, 0, 0x130, 10);
}
