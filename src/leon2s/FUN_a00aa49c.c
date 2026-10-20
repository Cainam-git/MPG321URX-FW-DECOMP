/* FUN_a00aa49c (leon2s 0xa00aa49c-0xa00aa538, 156 bytes), flags -mcpu=v8 -Os -g.
 * Calls FUN_a00a7bf8(port, 8, mask, set) twice, for mask 0x80 and then mask 0x40, with the set flags
 * chosen by mode (low byte): 3 -> (1, 1), 2 -> (1, 0), 1 -> (0, 1), any other value -> (0, 0).
 * The second call is a tail call.
 */
extern void FUN_a00a7bf8(unsigned int, unsigned short, unsigned int, unsigned int);

void FUN_a00aa49c(unsigned char port, unsigned char mode)
{
    if (mode == 3) {
        FUN_a00a7bf8(port, 8, 0x80, 1);
        FUN_a00a7bf8(port, 8, 0x40, 1);
    } else if (mode == 2) {
        FUN_a00a7bf8(port, 8, 0x80, 1);
        FUN_a00a7bf8(port, 8, 0x40, 0);
    } else if (mode == 1) {
        FUN_a00a7bf8(port, 8, 0x80, 0);
        FUN_a00a7bf8(port, 8, 0x40, 1);
    } else {
        FUN_a00a7bf8(port, 8, 0x80, 0);
        FUN_a00a7bf8(port, 8, 0x40, 0);
    }
}
