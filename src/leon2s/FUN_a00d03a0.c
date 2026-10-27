/* leon2s FUN_a00d03a0 @ 0xa00d03a0-0xa00d0530, flags -mcpu=v8 -Os -g.
 * Leaf dispatcher: port = (u8)param; switches on byte 2 of the 24-byte record DAT_a8078bb0[port] (values
 * 0..0x4f through the 80-entry jump table at 0xa00d0260; the code addresses
 * it as 0x9f1c0260 and its entries are 0xF10000 below the load addresses, the link offset of this code) and tail-calls one handler with port (27 case labels, one handler
 * per listed value); values without a case return. Same shape as FUN_a00d0968 with other handlers.
 */
struct Rec24 {
    unsigned char b0;
    unsigned char b1;
    unsigned char state;
    unsigned char b3;
    unsigned char rest[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00c8a80(unsigned char);
extern void FUN_a00c8aec(unsigned char);
extern void FUN_a00c8b18(unsigned char);
extern void FUN_a00c8c64(unsigned char);
extern void FUN_a00c90b4(unsigned char);
extern void FUN_a00c91f8(unsigned char);
extern void FUN_a00c9334(unsigned char);
extern void FUN_a00c9398(unsigned char);
extern void FUN_a00ca8c4(unsigned char);
extern void FUN_a00cab10(unsigned char);
extern void FUN_a00cad8c(unsigned char);
extern void FUN_a00caee4(unsigned char);
extern void FUN_a00caf78(unsigned char);
extern void FUN_a00cb1d4(unsigned char);
extern void FUN_a00cb3e8(unsigned char);
extern void FUN_a00cb56c(unsigned char);
extern void FUN_a00cb7a0(unsigned char);
extern void FUN_a00cbb50(unsigned char);
extern void FUN_a00cc1d4(unsigned char);
extern void FUN_a00cc2f8(unsigned char);
extern void FUN_a00cc5f8(unsigned char);
extern void FUN_a00cc8d4(unsigned char);
extern void FUN_a00cc900(unsigned char);
extern void FUN_a00ccb04(unsigned char);
extern void FUN_a00ccd20(unsigned char);
extern void FUN_a00ccdb4(unsigned char);
extern void FUN_a00d01f4(unsigned char);

void FUN_a00d03a0(unsigned char port)
{
    switch (DAT_a8078bb0[port].state) {
    case 0:
        FUN_a00c8a80(port);
        break;
    case 1:
        FUN_a00ccd20(port);
        break;
    case 16:
        FUN_a00d01f4(port);
        break;
    case 17:
        FUN_a00ccdb4(port);
        break;
    case 18:
        FUN_a00c8aec(port);
        break;
    case 19:
        FUN_a00c8b18(port);
        break;
    case 20:
        FUN_a00c8c64(port);
        break;
    case 21:
        FUN_a00c90b4(port);
        break;
    case 22:
        FUN_a00c91f8(port);
        break;
    case 23:
        FUN_a00c9334(port);
        break;
    case 24:
        FUN_a00c9398(port);
        break;
    case 64:
        FUN_a00ccb04(port);
        break;
    case 65:
        FUN_a00ca8c4(port);
        break;
    case 66:
        FUN_a00cab10(port);
        break;
    case 67:
        FUN_a00cad8c(port);
        break;
    case 68:
        FUN_a00caee4(port);
        break;
    case 69:
        FUN_a00caf78(port);
        break;
    case 70:
        FUN_a00cb1d4(port);
        break;
    case 71:
        FUN_a00cb3e8(port);
        break;
    case 72:
        FUN_a00cb56c(port);
        break;
    case 73:
        FUN_a00cb7a0(port);
        break;
    case 74:
        FUN_a00cbb50(port);
        break;
    case 75:
        FUN_a00cc1d4(port);
        break;
    case 76:
        FUN_a00cc2f8(port);
        break;
    case 77:
        FUN_a00cc5f8(port);
        break;
    case 78:
        FUN_a00cc8d4(port);
        break;
    case 79:
        FUN_a00cc900(port);
        break;
    }
}
