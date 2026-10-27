/* leon2s FUN_a00d0968 @ 0xa00d0968-0xa00d0af8, flags -mcpu=v8 -Os -g.
 * Leaf dispatcher: port = (u8)param; switches on byte 2 of the 24-byte record DAT_a8078bb0[port] (values
 * 0..0x4f through the 80-entry jump table at 0xa00d0828; the code addresses
 * it as 0x9f1c0828 and its entries are 0xF10000 below the load addresses, the link offset of this code) and tail-calls one handler with port (27 case labels, one handler
 * per listed value); values without a case return. Same shape as FUN_a00d03a0 with other handlers.
 */
struct Rec24 {
    unsigned char b0;
    unsigned char b1;
    unsigned char state;
    unsigned char b3;
    unsigned char rest[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00ccf0c(unsigned char);
extern void FUN_a00ccfa8(unsigned char);
extern void FUN_a00cd2f0(unsigned char);
extern void FUN_a00cd31c(unsigned char);
extern void FUN_a00cd4fc(unsigned char);
extern void FUN_a00cd5e4(unsigned char);
extern void FUN_a00cdb0c(unsigned char);
extern void FUN_a00cdc40(unsigned char);
extern void FUN_a00cdc74(unsigned char);
extern void FUN_a00cdcdc(unsigned char);
extern void FUN_a00cdde0(unsigned char);
extern void FUN_a00ce420(unsigned char);
extern void FUN_a00ce4cc(unsigned char);
extern void FUN_a00ce66c(unsigned char);
extern void FUN_a00ce864(unsigned char);
extern void FUN_a00cea60(unsigned char);
extern void FUN_a00cec18(unsigned char);
extern void FUN_a00cef6c(unsigned char);
extern void FUN_a00cf6bc(unsigned char);
extern void FUN_a00cf7b4(unsigned char);
extern void FUN_a00cf954(unsigned char);
extern void FUN_a00cf980(unsigned char);
extern void FUN_a00cfb40(unsigned char);
extern void FUN_a00cfd38(unsigned char);
extern void FUN_a00d00e0(unsigned char);
extern void FUN_a00d0550(unsigned char);
extern void FUN_a00d0798(unsigned char);

void FUN_a00d0968(unsigned char port)
{
    switch (DAT_a8078bb0[port].state) {
    case 0:
        FUN_a00d0798(port);
        break;
    case 1:
        FUN_a00ccf0c(port);
        break;
    case 16:
        FUN_a00d00e0(port);
        break;
    case 17:
        FUN_a00ccfa8(port);
        break;
    case 18:
        FUN_a00cd2f0(port);
        break;
    case 19:
        FUN_a00cd31c(port);
        break;
    case 20:
        FUN_a00cd4fc(port);
        break;
    case 21:
        FUN_a00cd5e4(port);
        break;
    case 22:
        FUN_a00cdb0c(port);
        break;
    case 23:
        FUN_a00cdc40(port);
        break;
    case 24:
        FUN_a00cdc74(port);
        break;
    case 64:
        FUN_a00d0550(port);
        break;
    case 65:
        FUN_a00cfd38(port);
        break;
    case 66:
        FUN_a00cdcdc(port);
        break;
    case 67:
        FUN_a00cdde0(port);
        break;
    case 68:
        FUN_a00ce420(port);
        break;
    case 69:
        FUN_a00ce4cc(port);
        break;
    case 70:
        FUN_a00ce66c(port);
        break;
    case 71:
        FUN_a00ce864(port);
        break;
    case 72:
        FUN_a00cea60(port);
        break;
    case 73:
        FUN_a00cec18(port);
        break;
    case 74:
        FUN_a00cef6c(port);
        break;
    case 75:
        FUN_a00cf6bc(port);
        break;
    case 76:
        FUN_a00cf7b4(port);
        break;
    case 77:
        FUN_a00cfb40(port);
        break;
    case 78:
        FUN_a00cf954(port);
        break;
    case 79:
        FUN_a00cf980(port);
        break;
    }
}
