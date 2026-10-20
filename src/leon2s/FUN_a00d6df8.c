/* leon2s FUN_a00d6df8 @ 0xa00d6df8..0xa00d6e94 (156 bytes, 39 words)  BYTE-EXACT
 * Flags: -mcpu=v8 -Os -g.
 * Judge: jf 100.00 match=True; rawcmp_l2s.py 0 mismatches / 39 words (a00d6df8 a00d6e94).
 * What it does (code facts): n = (src[0] >> 4) - 1; k = n / 2 rounded up (n odd -> +1), as a
 * byte. From src[k + 3 .. k + 7] it fills dst: word 0 bits 24..30 = src[k+3] & 0x7f, word 0
 * bits 20..23 = src[k+4] >> 4 (bit 31 and bits 0..19 kept), word 1 = (src[k+4] & 0xf) << 16 |
 * src[k+5] << 8 | src[k+6], byte 8 = src[k+7].
 * Callers: FUN_a00d73b4.
 * Aids: none. Draft fix: the second mask is 0xff0fffff (fw andn sethi 0xf00000 = clear only
 * bits 20..23); the draft's 0x800fffff also cleared the bits 24..30 just written. Rest = draft.
 */
void FUN_a00d6df8(unsigned int *param_1, unsigned char *param_2)
{
    int uVar1;
    unsigned char uVar2;
    unsigned int uVar3;
    
    uVar1 = (*param_2 >> 4) - 1;
    uVar2 = (int)uVar1 / 2;
    if ((uVar1 & 1) != 0) {
        uVar2 = uVar2 + 1;
    }
    uVar2 = uVar2 & 0xff;
    *param_1 = (*param_1 & 0x80ffffff) | ((param_2[uVar2 + 3] & 0x7f) << 0x18);
    *param_1 = (*param_1 & 0xff0fffff) | ((param_2[uVar2 + 4] >> 4) << 0x14);
    param_1[1] = (param_2[uVar2 + 4] & 0xf) << 0x10 | (param_2[uVar2 + 5] << 8) |
                 param_2[uVar2 + 6];
    *(unsigned char *)(param_1 + 2) = param_2[uVar2 + 7];
    return;
}
