/* leon2s FUN_a00d77c4 @ 0xa00d77c4  MATCH (-mcpu=v8 -Os -g)
 * Copies a length-prefixed record from param_1 to param_2: byte 0 & 0x7F, byte 1 & 0x0F, the count byte 2, then
 * count payload bytes from offset 3. The loop counter is a byte that is masked with 0xFF after each increment.
 */
typedef unsigned char byte;

void FUN_a00d77c4(byte *param_1, byte *param_2)
{
    byte bVar1;
    byte bVar2;
    
    *param_2 = *param_1 & 0x7f;
    param_2[1] = param_1[1] & 0xf;
    param_2[2] = param_1[2];
    
    bVar2 = 0;
    if (param_1[2] != 0) {
        do {
            param_2[bVar2 + 3] = param_1[bVar2 + 3];
            bVar2++;
            bVar2 = bVar2 & 0xff;
        } while (bVar2 < param_1[2]);
    }
    return;
}
