/* FUN_a00b0078 (leon2s 0xa00b0078-0xa00b00e0, 104 bytes), flags -mcpu=v8 -Os -g.
 * Maps the port through FUN_a00add48(port, func_0x9f1c6624(port)) to q and programs page-0 register bits of q
 * with FUN_a00a8400: en != 0 clears bit 7 and sets bit 3, en == 0 clears bit 3.
 * Same register access helpers as FUN_a00afdf4.
 */
extern unsigned int func_0x9f1c6624(unsigned char);
extern unsigned int FUN_a00add48(unsigned char, unsigned char);
extern void FUN_a00a8400(unsigned char, unsigned int, unsigned int, unsigned char);

void FUN_a00b0078(unsigned int port, unsigned char en)
{
    unsigned char q;

    port &= 0xff;
    q = FUN_a00add48(port, func_0x9f1c6624(port));
    if (en != 0) {
        FUN_a00a8400(q, 0, 0x80, 0);
        FUN_a00a8400(q, 0, 8, 1);
    } else {
        FUN_a00a8400(q, 0, 8, 0);
    }
}
