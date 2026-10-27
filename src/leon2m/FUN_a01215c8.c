/* FUN_a01215c8 (leon2m 0xa01215c8-0xa01215e8, 32 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns the first word of 12-byte entry i of the array DAT_a8027aac. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a01213a4 and FUN_a01215e8.
 */
struct W3 { unsigned int w0, w4, w8; };
extern struct W3 DAT_a8027aac[];

unsigned int FUN_a01215c8(unsigned char i)
{
    return DAT_a8027aac[i].w0;
}
