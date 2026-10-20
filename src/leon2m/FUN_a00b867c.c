/* leon2m FUN_a00b867c @ 0xa00b867c  (-mcpu=v8 -O3 -g)
 * Calls FUN_a0090fd8() when (FUN_a0146dfc(0) != 0 or FUN_a0146dfc(1) != 0) and FUN_a0143c14(0) != 10. Then stores
 * 0x72C to the halfword 0xA802B092 and 0 to 0xA802B094 and calls FUN_a0103808(0, 0, 0, 0). When DAT_a802d290
 * byte +0x1D5 is 0, halfword +0x1F6 is not 0x55AA and bit 14 of word +0 is clear, it returns if bit 10 of the
 * halfword 0xA802CFF8 is set and otherwise calls FUN_a00b7f9c(0x19). Finally, unless bit 10 of 0xA802CFF8 is set,
 * it tail-calls FUN_a014512c(1, 0).
 * Callers: FUN_a009e91c+0x78.
 * Data: DAT_a802cff4 is used as three halfwords (+4 = 0xA802CFF8).
 */
struct R290 {
    unsigned int w000;
    unsigned char pad[0x1d5 - 4]; unsigned char b1d5;
    unsigned char pad2[0x1f6 - 0x1d6]; unsigned short h1f6;
};
struct Scff4 { unsigned short h000; unsigned short h002; unsigned short h004; };
extern struct R290 DAT_a802d290;
extern struct Scff4 DAT_a802cff4;
extern unsigned short _DAT_a802b092;
extern unsigned short _DAT_a802b094;
extern unsigned char FUN_a0146dfc(int);
extern unsigned char FUN_a0143c14(int);
extern void FUN_a0090fd8(void);
extern void FUN_a0103808(int, int, int, int);
extern void FUN_a00b7f9c(int);
extern void FUN_a014512c(unsigned int, unsigned int);

void FUN_a00b867c(void)
{
    if ((FUN_a0146dfc(0) || FUN_a0146dfc(1)) && FUN_a0143c14(0) != 10)
        FUN_a0090fd8();
    _DAT_a802b092 = 0x72c;
    _DAT_a802b094 = 0;
    FUN_a0103808(0, 0, 0, 0);
    if (DAT_a802d290.b1d5 == 0 && DAT_a802d290.h1f6 != 0x55aa && !(DAT_a802d290.w000 & 0x4000)) {
        if (DAT_a802cff4.h004 & 0x400)
            return;
        FUN_a00b7f9c(0x19);
    }
    if (DAT_a802cff4.h004 & 0x400)
        return;
    FUN_a014512c(1, 0);
}
