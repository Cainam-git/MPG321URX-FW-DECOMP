/* leon2s FUN_a00c7a4c @ 0xa00c7a4c-0xa00c7b60, -mcpu=v8 -Os -g.
 * (u8 port, u8 flag). Initialises the 24-byte record DAT_a8078bb0[port]: word 0 bit 31 = 1, bits 30, 29,
 * 28 = 0, bits 16..17 = 1, bits 24..27 = 5; byte +2 = 1, halfword +0x16 = 100, byte +9 = 0xff. When the
 * byte DAT_a807d636 equals port it is set to 0xff. flag != 0: bit 18 = 1, bits 23 and 19 = 0, bytes
 * +3..+8 = 0. Then bit 22 = 1, byte +0x14 = 0x1f, words +0xc and +0x10 = 0, bits 20 and 21 = 0.
 * Source form: bit-fields of word 0 (big-endian, first field = bit 31); GCC merges each group of field
 * writes into one load and store.
 */
struct Rec18 {
    unsigned int b31 : 1;
    unsigned int b30 : 1;
    unsigned int b29 : 1;
    unsigned int b28 : 1;
    unsigned int f24 : 4;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int f16 : 2;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char b7;
    unsigned char b8;
    unsigned char b9;
    unsigned char pad_a[2];
    unsigned int wc;
    unsigned int w10;
    unsigned char b14;
    unsigned char pad_15;
    unsigned short h16;
};
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807d636;

void FUN_a00c7a4c(unsigned char port, unsigned char flag)
{
    DAT_a8078bb0[port].b31 = 1;
    DAT_a8078bb0[port].b30 = 0;
    DAT_a8078bb0[port].b29 = 0;
    DAT_a8078bb0[port].f16 = 1;
    DAT_a8078bb0[port].b28 = 0;
    DAT_a8078bb0[port].f24 = 5;
    DAT_a8078bb0[port].b2 = 1;
    DAT_a8078bb0[port].h16 = 100;
    DAT_a8078bb0[port].b9 = 0xff;
    if (DAT_a807d636 == port)
        DAT_a807d636 = 0xff;
    if (flag) {
        DAT_a8078bb0[port].b18 = 1;
        DAT_a8078bb0[port].b23 = 0;
        DAT_a8078bb0[port].b19 = 0;
        DAT_a8078bb0[port].b3 = 0;
        DAT_a8078bb0[port].b4 = 0;
        DAT_a8078bb0[port].b5 = 0;
        DAT_a8078bb0[port].b6 = 0;
        DAT_a8078bb0[port].b7 = 0;
        DAT_a8078bb0[port].b8 = 0;
    }
    DAT_a8078bb0[port].b22 = 1;
    DAT_a8078bb0[port].b14 = 0x1f;
    DAT_a8078bb0[port].wc = 0;
    DAT_a8078bb0[port].w10 = 0;
    DAT_a8078bb0[port].b20 = 0;
    DAT_a8078bb0[port].b21 = 0;
}
