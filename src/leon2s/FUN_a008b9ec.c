/* FUN_a008b9ec (leon2s, 0xa008b9ec-0xa008bc44, 150 words). Flags -mcpu=v8 -Os -g.
 Code facts: u8 port; id = 4 (needs DAT_a807a824[0x50] == 5) or, for port 1, 6 (needs [0x64] == 5), else return. now = FUN_a008b838(port).
 If the port bit of DAT_a8078b54 is set or |now - ARR_a8078b3c[port]| > 0x14: if b8d4(port) == 1 and b8f4(port) == 1: if (u16)89f98(id) != 0
 and bit 0x40 of the u16 at +0x62 of the 0x14-byte record port of DAT_a807a824: ++DAT_a8078b38[port] > 3 -> clear it, b75c(a040(id), 1),
 b9b0(port,1), print 'DP fifo mute off %d' (port), port 0 and 9f1c6694(0) == 1 -> a6c98(0,0x50,0x10,1), 86bd8(), b8ac(port),
 b54 = (b54 & ~bit) | (0x10 << port), b3c[port] = now, b48[port] = 1; failed 89f98/0x40 test -> b38[port] = 0. Else if the b54 bit is clear and
 the b31 bit is set: b934(port), clear the b31 bit. Finally: b54 bit clear and b48[port] == 1 -> b48[port] = 0.
 Fixes vs draft (draft did not compile cleanly): BEHAVIOUR b75c's 1st arg is a040(id)'s u8 return (draft passed id); real base DAT_a807a824;
 abs as an inline (s ^ v) - s helper inside the || ; the record pointer is formed inside the && (comma expression) so the +0x62 is not
 folded into the symbol. Aids: none (static inline helper iabs).
 */
extern unsigned char DAT_a807a824[];
extern unsigned char DAT_a8078b38[];
extern unsigned int ARR_a8078b3c[];
extern unsigned char DAT_a8078b48[];
extern unsigned char DAT_a8078b31;
extern unsigned char DAT_a8078b54;
extern char s_a0068d20[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a0086bd8(void);
extern unsigned short FUN_a0089f98(unsigned char);
extern unsigned char FUN_a008a040(unsigned char);
extern void FUN_a008b75c(unsigned char, unsigned char);
extern unsigned int FUN_a008b838(unsigned char);
extern void FUN_a008b8ac(unsigned char);
extern unsigned char FUN_a008b8d4(unsigned int);
extern unsigned char FUN_a008b8f4(unsigned int);
extern void FUN_a008b934(unsigned char);
extern void FUN_a008b9b0(unsigned char, unsigned char);
extern int FUN_a00a6c98(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned char func_0x9f1c6694(unsigned int);

static inline int iabs(int v)
{
    int s = v >> 31;

    return (s ^ v) - s;
}

void FUN_a008b9ec(unsigned char port)
{
    unsigned char id;
    unsigned int now;
    unsigned char *r;

    if (port != 1) {
        id = 4;
        if (DAT_a807a824[0x50] != 5)
            return;
    } else {
        id = 6;
        if (DAT_a807a824[0x64] != 5)
            return;
    }
    now = FUN_a008b838(port);
    if ((DAT_a8078b54 & (1 << port)) == (1 << port) || iabs(now - ARR_a8078b3c[port]) > 0x14) {
        if (FUN_a008b8d4(port) == 1 && FUN_a008b8f4(port) == 1) {
            if (FUN_a0089f98(id) != 0 &&
                (r = DAT_a807a824 + port * 0x14, *(unsigned short *)(r + 0x62) & 0x40) != 0) {
                if (++DAT_a8078b38[port] > 3) {
                    DAT_a8078b38[port] = 0;
                    FUN_a008b75c(FUN_a008a040(id), 1);
                    FUN_a008b9b0(port, 1);
                    FUN_a0073044(s_a0068d20, port);
                    if (port == 0 && func_0x9f1c6694(0) == 1)
                        FUN_a00a6c98(0, 0x50, 0x10, 1);
                    FUN_a0086bd8();
                    FUN_a008b8ac(port);
                    DAT_a8078b54 = (DAT_a8078b54 & ~(1 << port)) | (0x10 << port);
                    ARR_a8078b3c[port] = now;
                    DAT_a8078b48[port] = 1;
                }
            } else {
                DAT_a8078b38[port] = 0;
            }
        }
    } else if (((DAT_a8078b54 >> port) & 1) == 0 && ((DAT_a8078b31 >> port) & 1) != 0) {
        FUN_a008b934(port);
        DAT_a8078b31 &= ~(1 << port);
    }
    if (((DAT_a8078b54 >> port) & 1) == 0 && DAT_a8078b48[port] == 1)
        DAT_a8078b48[port] = 0;
}
