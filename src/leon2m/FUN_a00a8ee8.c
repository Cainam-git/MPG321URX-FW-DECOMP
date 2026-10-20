/* leon2m FUN_a00a8ee8 @ 0xa00a8ee8  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: [walk]; return unsigned int; param param_1 unsigned int; sink uVar2 into arms; return void; param param_1 unsigned char
 */
extern void func_0x4008e2a4(void);                          // 0x4008e2a4
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char); // 0xa0146a80
extern void FUN_a0146b20(unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char); // 0xa0146b20
extern void FUN_a00b3ed0(unsigned char, unsigned char, unsigned int, unsigned int); // 0xa00b3ed0
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned char, unsigned char, unsigned char, unsigned int); // 0xa00b32e4

void FUN_a00a8ee8(unsigned char param_1) {
    unsigned char uVar2;
    unsigned char uVar3;
    unsigned short temp;
    
    if (param_1 > 6) {
        uVar2 = (unsigned short)(param_1 * 2);
        uVar2 = (unsigned short)(uVar2 - 9);
    } else {
        uVar2 = (unsigned short)(param_1 * 2);
        uVar2 = (unsigned short)(uVar2 + 5);
    }
    uVar3 = uVar2 & 0xff;
    
    func_0x4008e2a4();
    FUN_a0146a80(0x14, uVar3, 0x11, 0x792, 0);
    
    temp = (unsigned short)(uVar3 + 2);
    FUN_a0146a80(0x14, temp, 0x11, 0x792, 0);
    
    FUN_a0146b20(0, 0x14, uVar3, 0x11, 0, 0);
    FUN_a0146b20(0, 0x14, temp, 0x11, 0, 0);
    
    FUN_a00b3ed0(0, 0, 0, 0);
    
    func_0x4008e2a4();
    
    FUN_a0146a80(0x14, (unsigned short)(uVar3 + 1), 0x11, 0x792, 0);
    
    FUN_a00b32e4(0, 0, 0x792, 0x13, uVar3, 3, 0);
    FUN_a00b32e4(0, 0, 0x792, 0x25, uVar3, 3, 0);
}
