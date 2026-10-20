/* leon2s FUN_a006fb3c @ 0xa006fb3c (-mcpu=v8 -Os -g)
 * Byte-XOR checksum: clears the top byte of param_1[0], XORs all four bytes of each of the first (param_2 & 0xFF)
 * words and stores the result in the top byte of param_1[0]. The operand order `uVar4 ^ uVar3` gives the target's
 * xor %o5, %o4, %o4.
 */
void FUN_a006fb3c(unsigned int *param_1, unsigned int param_2)
{
    unsigned int uVar3 = 0;
    unsigned int i = 0;
    *param_1 &= 0xffffff;
    if ((param_2 & 0xff) != 0) {
        do {
            unsigned int uVar4 = param_1[i & 0xff];
            uVar3 = uVar4 ^ uVar3 ^ (uVar4 >> 8) ^ (uVar4 >> 16) ^ (uVar4 >> 24);
            i++;
        } while ((i & 0xff) < (param_2 & 0xff));
    }
    *param_1 |= uVar3 << 24;
}
