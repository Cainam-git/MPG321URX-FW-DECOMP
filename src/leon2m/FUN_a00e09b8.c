/* leon2m FUN_a00e09b8 @ 0xa00e09b8 (-mcpu=v8 -O3 -g; also matches with -msoft-float)
 * mwb_from_phy (name from its error message): reads a byte with FUN_a00e0514(phy, reg, mask_phy) and writes it
 * into the bits mask_addr of the word at addr with FUN_a00df51c(addr, mask_addr, value).
 * When the masks differ, the byte is shifted by the distance (1..7) at which mask_phy shifted left (mask_addr larger)
 * or right (mask_addr smaller) equals mask_addr. If no such distance exists, it calls FUN_a00df80c and FUN_a00e0bc0,
 * prints "error: mwb_from_phy mask_addr(..)!<<= mask_phy(..)" (or "!>>=") and writes the byte unshifted.
 * The function name is a separate read-only object (fn_).
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e0514(unsigned char phy, unsigned short reg, unsigned char mask);
extern void FUN_a00df51c(unsigned int addr, unsigned int mask, unsigned int value);

static const char fn_[] = "mwb_from_phy";

void FUN_a00e09b8(unsigned int addr, unsigned char mask_addr, unsigned char phy, unsigned short reg,
                  unsigned char mask_phy)
{
    unsigned char v;
    unsigned char i;

    v = FUN_a00e0514(phy, reg, mask_phy);
    if (mask_addr == mask_phy) {
        FUN_a00df51c(addr, mask_addr, v);
        return;
    }
    if (mask_addr > mask_phy) {
        for (i = 1; i < 8; i++)
            if (mask_addr == (mask_phy << i))
                break;
        if (i == 8) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("error: %s mask_addr(0x%02x)!%s= mask_phy(0x%02x)\n", fn_, mask_addr, "<<", mask_phy);
            i = 0;
        }
        FUN_a00df51c(addr, mask_addr, v << i);
    } else {
        for (i = 1; i < 8; i++)
            if (mask_addr == (mask_phy >> i))
                break;
        if (i == 8) {
            FUN_a00df80c();
            FUN_a00e0bc0();
            FUN_a00df170("error: %s mask_addr(0x%02x)!%s= mask_phy(0x%02x)\n", fn_, mask_addr, ">>", mask_phy);
            i = 0;
        }
        FUN_a00df51c(addr, mask_addr, v >> i);
    }
}
