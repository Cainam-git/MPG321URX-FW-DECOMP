/* FUN_a0149064(ch, mode): mode goes through a switch on 0..4 (jump table at 0x000e34a0) whose cases assign the
 * same value back (0 -> 0 ... 4 -> 4); other values stay unchanged. ch 0 stores mode & 0xf in bits 24-27 and ch 1
 * in bits 20-23 of word +4 of the RAM record DAT_a802e3d0; every path ends with FUN_a0142418(ch, mode) (ch 1
 * passes the constant 1). Callers include FUN_a00d58d8, FUN_a00d58f8, FUN_a00db738, FUN_a00dbcf0.
 * Source form: switch (ch) where case 0 only stores and breaks to the shared final call, and case 1 stores, calls
 * FUN_a0142418(1, mode) itself and returns; the block-reorder pass copies the shared call into case 0.
 */
struct E3d0W4 { unsigned int b31_28 : 4, ch0 : 4, ch1 : 4, rest : 20; };
struct E3d0 { unsigned int w0; struct E3d0W4 w4; };
extern struct E3d0 DAT_a802e3d0;
extern void FUN_a0142418(unsigned char, unsigned char);

void FUN_a0149064(unsigned char ch, unsigned char mode)
{
    switch (mode) {
    case 0: mode = 0; break;
    case 1: mode = 1; break;
    case 2: mode = 2; break;
    case 3: mode = 3; break;
    case 4: mode = 4; break;
    }
    switch (ch) {
    case 0:
        DAT_a802e3d0.w4.ch0 = mode;
        break;
    case 1:
        DAT_a802e3d0.w4.ch1 = mode;
        FUN_a0142418(1, mode);
        return;
    }
    FUN_a0142418(ch, mode);
}
