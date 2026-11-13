/* hdmi_tx_select_source_port  (FUN_a008ed50)
 *
 * Connect or disconnect an input port as the source of an HDMI TX port.
 *   port: HDMI TX port
 *   code: input port code
 *   mode: 1 = connect
 * Name basis: descriptive - port bits of 0xCF011600 and neighbours under the hardware lock; input codes
 *   0x31..0x61; TX commands 5 and 6
 *
 * Matching notes
 * --------------
 * FUN_a008ed50 (leon2s 0xa008ed50-0xa008f270, 1312 bytes, leaf), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the lock take is a static inline helper (shared_lock_take, as in audio_set_shared_enable_bits);
 *  - the code switch has an explicit case INPUT_CODE_HDMI20_0 and a default (it sets the decision-tree pivot
 *    at 0x41);
 *  - the disconnect updates are written out in both outer else arms;
 *  - every register access is a read-modify-write of the volatile register (the value of CLOCK_REG_4754 in
 *    two writes).
 */
#define SHARED_LOCK    (*(volatile unsigned int *)0xcf03c840)   /* lock shared with the main processor */
#define LOCK_FREE      0
#define LOCK_BUSY      1        /* held by the other processor */
#define LOCK_HELD_HERE 2

#define REG_1600       (*(volatile unsigned int *)0xcf011600)   /* bit 4 port 0, bit 5 port 1: set on connect, cleared on disconnect */
#define reg_hdmi_tx_source_route (*(volatile unsigned int *)0xcf0116b4)  /* bit 0 port 0, bit 1 port 1 */
#define REG_17BC       (*(volatile unsigned int *)0xcf0117bc)   /* bit 0 port 0, bit 1 port 1 */
#define REG_24BC       (*(volatile unsigned int *)0xcf0124bc)   /* source number, see SOURCE_* */
#define CLOCK_REG_4754 (*(volatile unsigned int *)0xcf014754)   /* bits 0..1 port 0, bits 2..3 port 1 */

/* Input codes of the HDMI receivers (source_code of the TX channel record). */
#define INPUT_CODE_HDMI20_0 0x31
#define INPUT_CODE_HDMI20_1 0x41
#define INPUT_CODE_HDMI21_0 0x51
#define INPUT_CODE_HDMI21_1 0x61

/* Values written to REG_24BC for the four input codes. */
#define SOURCE_HDMI20_0 0
#define SOURCE_HDMI20_1 1
#define SOURCE_HDMI21_0 2
#define SOURCE_HDMI21_1 3

#define CONNECT 1

/* Take the shared lock: up to 0x10000 tries, each claiming it unless it reads LOCK_BUSY, until it reads
   LOCK_HELD_HERE; then it is claimed once more whatever the outcome. */
static inline void shared_lock_take(void)
{
    unsigned short tries = 0xffff;

    do {
        if (SHARED_LOCK != LOCK_BUSY)
            SHARED_LOCK = LOCK_HELD_HERE;
        if (SHARED_LOCK == LOCK_HELD_HERE)
            break;
        tries--;
    } while (tries != 0xffff);
    SHARED_LOCK = LOCK_HELD_HERE;
}

/*
 * Connect an HDMI receiver to an HDMI TX port as its source, or disconnect the port's source.
 *
 *   port  the HDMI TX port (0 or 1; any other value acts on the bits of both)
 *   code  the input code of the source (INPUT_CODE_*)
 *   mode  CONNECT (1) connects; any other value disconnects
 *
 * Called by hdmi_tx_run_step: in set-up step 5 (TX_STEP_CLOCK_SOURCE_TMDS) with mode = bit 0 of word 0 of the
 * TX channel record, and in step 6 (TX_STEP_CLOCK_SOURCE_FRL) with mode 0, before hdmi_tx_set_frl_clock.
 *
 * Connect, when code is one of the four HDMI receivers: clear the port's bit of reg_hdmi_tx_source_route, set
 * its bit of REG_1600 (under the shared lock) and of REG_17BC, and write 2 into its two bits of
 * CLOCK_REG_4754 (hdmi_tx_set_frl_clock sets the same two bits to 3). For a port other than 0 or 1 only bits
 * 4 and 5 of REG_1600 are cleared. Then the receiver's number (SOURCE_*) goes to REG_24BC.
 * Disconnect, or connect with another code: clear the port's bit of REG_1600 under the shared lock.
 */
void hdmi_tx_select_source_port(unsigned char port, unsigned char code, unsigned char mode)
{
    if (mode == CONNECT) {
        if (code == INPUT_CODE_HDMI20_0 || code == INPUT_CODE_HDMI20_1 || code == INPUT_CODE_HDMI21_0 || code == INPUT_CODE_HDMI21_1) {
            if (port == 0) {
                reg_hdmi_tx_source_route &= 0xfe;
                shared_lock_take();
                REG_1600 |= 0x10;
                SHARED_LOCK = LOCK_FREE;
                REG_17BC |= 1;
                CLOCK_REG_4754 &= 0xfc;
                CLOCK_REG_4754 |= 2;
            } else if (port == 1) {
                reg_hdmi_tx_source_route &= 0xfd;
                shared_lock_take();
                REG_1600 |= 0x20;
                SHARED_LOCK = LOCK_FREE;
                REG_17BC |= 2;
                CLOCK_REG_4754 &= 0xf3;
                CLOCK_REG_4754 |= 8;
            } else {
                shared_lock_take();
                REG_1600 &= ~0x30;
                SHARED_LOCK = LOCK_FREE;
            }
            switch (code) {
            case INPUT_CODE_HDMI20_0:
                REG_24BC = SOURCE_HDMI20_0;
                break;
            case INPUT_CODE_HDMI20_1:
                REG_24BC = SOURCE_HDMI20_1;
                break;
            case INPUT_CODE_HDMI21_0:
                REG_24BC = SOURCE_HDMI21_0;
                break;
            case INPUT_CODE_HDMI21_1:
                REG_24BC = SOURCE_HDMI21_1;
                break;
            default:
                REG_24BC = 0;
                break;
            }
        } else {
            if (port == 0) {
                shared_lock_take();
                REG_1600 &= ~0x10;
                SHARED_LOCK = LOCK_FREE;
            } else if (port == 1) {
                shared_lock_take();
                REG_1600 &= ~0x20;
                SHARED_LOCK = LOCK_FREE;
            } else {
                shared_lock_take();
                REG_1600 &= ~0x30;
                SHARED_LOCK = LOCK_FREE;
            }
        }
    } else {
        if (port == 0) {
            shared_lock_take();
            REG_1600 &= ~0x10;
            SHARED_LOCK = LOCK_FREE;
        } else if (port == 1) {
            shared_lock_take();
            REG_1600 &= ~0x20;
            SHARED_LOCK = LOCK_FREE;
        } else {
            shared_lock_take();
            REG_1600 &= ~0x30;
            SHARED_LOCK = LOCK_FREE;
        }
    }
}
