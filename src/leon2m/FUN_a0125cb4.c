/* leon2m FUN_a0125cb4 @ 0xa0125cb4-0xa0125d58 (41 words, including the unreachable ret/restore tail at 0xa0125d50).
 * For m = 0..3 calls func_0x4008c86c(0xff, 8, x) twice, x being 0xfe or 1: m = 0 -> (0xfe, 0xfe), 1 -> (0xfe, 1),
 * 2 -> (1, 0xfe), 3 -> (1, 1); any other m does nothing. Called by FUN_a0080490.
 * Source form: an if/else-if chain with both calls written in every arm; GCC merges the call pairs into one shared
 * tail and keeps the argument moves in front of each compare.
 */
extern void func_0x4008c86c(int, int, int);

void FUN_a0125cb4(unsigned char m)
{
    if (m == 0) {
        func_0x4008c86c(0xff, 8, 0xfe);
        func_0x4008c86c(0xff, 8, 0xfe);
    } else if (m == 1) {
        func_0x4008c86c(0xff, 8, 0xfe);
        func_0x4008c86c(0xff, 8, 1);
    } else if (m == 2) {
        func_0x4008c86c(0xff, 8, 1);
        func_0x4008c86c(0xff, 8, 0xfe);
    } else if (m == 3) {
        func_0x4008c86c(0xff, 8, 1);
        func_0x4008c86c(0xff, 8, 1);
    }
}
