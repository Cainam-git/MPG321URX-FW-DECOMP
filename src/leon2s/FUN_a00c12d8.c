/* leon2s FUN_a00c12d8 @ 0xa00c12d8  MATCH (-mcpu=v8 -Os -g)
 * Copies the 16 bytes at 0x9F1C1E38 into param_1 in reverse order (param_1[i] = src[15 - i]). The source is a
 * plain (non-volatile) extern array, matching the target's ldub. The 16-bit index is copied before the increment
 * and compared after it.
 */
extern unsigned char DAT_9f1c1e38[];

void FUN_a00c12d8(unsigned char *param_1) {
    unsigned short uVar1 = 0;
    do {
        unsigned short uVar2 = uVar1;
        uVar1 = uVar1 + 1;
        param_1[uVar2] = DAT_9f1c1e38[0xf - uVar2];
    } while (uVar1 <= 0xf);
}
