/* fwupd_svc_bus_handshake  (FUN_CODE_de50)
 *
 * Send the raw bus sequence that takes or releases the main chip's service bus.
 *   take: 1 take, 0 release
 * Name basis: derived - bytes 04 34 06 36 after repeated starts (take, twice after 10 start/stop pairs) or 04
 *   34 06 3C (release)
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC). One loop serves both cases: the last byte is a ?: on take and
 * the loop ends early with 'if (take != 1) break;'.
 */
void i2c_start(void);
void i2c_stop(void);
unsigned char i2c_write_byte(unsigned char b);

#define TAKE_LINK      1        /* take value of fwupd_svc_claim_link */
#define RESET_PAIRS    10       /* start / stop pairs sent before the take sequence */
#define TAKE_REPEATS   2

/* fwupd_svc_bus_handshake: send the byte sequence that fwupd_svc_claim_link uses to take or release the service
 * link, on the bit-banged bus.
 *
 * take: TAKE_LINK (1) = take; any other value = release.
 *
 * Take: first RESET_PAIRS start / stop pairs with nothing between them, then TAKE_REPEATS times the sequence
 * START 04, START 34, START 06, START 36, STOP. Release: the sequence once, with 3C as its last byte.
 * Every byte follows its own start condition, with no stop in between, and the acknowledge results are not used.
 * What the main chip does with the four bytes is not shown here.
 * Caller: fwupd_svc_claim_link. */
void fwupd_svc_bus_handshake(unsigned char take)
{
    unsigned char i;
    if (take == TAKE_LINK) {
        for (i = 0; i < RESET_PAIRS; i++) {
            i2c_start();
            i2c_stop();
        }
    }
    for (i = 0; i < TAKE_REPEATS; i++) {
        i2c_start();
        i2c_write_byte(0x04);
        i2c_start();
        i2c_write_byte(0x34);
        i2c_start();
        i2c_write_byte(0x06);
        i2c_start();
        i2c_write_byte(take == TAKE_LINK ? 0x36 : 0x3c);
        i2c_stop();
        if (take != TAKE_LINK) break;
    }
}
