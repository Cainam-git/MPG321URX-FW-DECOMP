/* 8051_bank2 FUN_CODE_d059 @ 0xd059  update agent: wait for the scaler's ready line (byte-exact with
 * OPTIMIZE(8,SPEED) LARGE).
 * Timeout counter = t * 0xFFFF (32-bit, Keil long library), wait 2 units, then: if input P1.1 is already high ->
 * result 0; otherwise poll P1.1 with 1-unit waits (FUN_CODE_e44b) until it goes high or the counter runs out ->
 * result 1 when it went high in time, 0 on timeout. Always ends with a 1-unit wait. Every service command waits here
 * after its packet (t = 100, or 0x0FA0 for the flash status writes and the SPI start), so P1.1 behaves as a
 * busy-low / done-high handshake line from the scaler.
 */
sfr P1 = 0x90;
sbit P1_1 = P1 ^ 1;
void FUN_CODE_e44b(unsigned char n);

unsigned char FUN_CODE_d059(unsigned int t)
{
    unsigned char ok;
    unsigned long cnt;
    ok = 1;
    cnt = 0xffff;
    cnt = t * cnt;
    FUN_CODE_e44b(2);
    if (!P1_1) {
        while (cnt > 0 && !P1_1) {
            FUN_CODE_e44b(1);
            cnt--;
        }
        if (cnt == 0) ok = 0; else ok = 1;
    } else ok = 0;
    FUN_CODE_e44b(1);
    return ok;
}
