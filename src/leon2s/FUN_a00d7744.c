/* leon2s FUN_a00d7744 @ 0xa00d7744 (-mcpu=v8 -Os -g)
 * The function copies a small header (3 bytes) from `param_1` to `param_2` with masking on the first two bytes, then copies a variable-length payload starting at offset 3. The loop uses a byte counter (`bVar2`) and compares it against `param_1[2]` with a carry-less unsigned compare. The main uncertainty is the exact loop counter type (byte vs. short) and whether the compiler will emit the same `inc`/`and` sequence; the structure (masked header, zero-check, do-while loop) is clear.
 */
extern void *memcpy(void *dest, const void *src, unsigned int n); // not used, but for reference

void FUN_a00d7744(unsigned char *param_1, unsigned char *param_2)
{
    unsigned char bVar2;
    unsigned char uVar1;

    *param_2 = *param_1 & 0x7f;
    param_2[1] = param_1[1] & 0xf;
    param_2[2] = param_1[2];

    if (param_1[2] != 0) {
        bVar2 = 0;
        do {
            param_2[(unsigned char)bVar2 + 3] = param_1[(unsigned char)bVar2 + 3];
            bVar2 = bVar2 + 1;
            uVar1 = (unsigned short)bVar2;
        } while ((unsigned char)uVar1 < param_1[2]);
    }
}
