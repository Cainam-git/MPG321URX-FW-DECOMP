/* hdcp_rx_dp_calculate_v  (FUN_a00ca130)
 *
 * Hash the DisplayPort receiver's KSV list, Binfo and M0; write the 20 result bytes to its registers.
 *   receiver: DisplayPort receiver number, 0 or 1
 * Note: The parameter is the DisplayPort receiver number (port - 4); the hash runs in the block at 0xCF018E00.
 * Name basis: proven - prints 'Calculate V', 'KSV : ', 'Binfo : %02X%02X', 'M0 : ' and 'VH%d, 0x%02X'; all
 *   dp_reg accesses go to the receiver given by the caller hdcp_rx_dp_poll_v_calculation
 *
 * Matching notes
 * --------------
 * FUN_a00ca130 (leon2s, 0xa00ca130-0xa00ca4e8, 952 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: the first loop counter i is reused for the length value; the printed 0x2aa value is read into an
 * unsigned int; the later loops share a second counter j (u16); the byte writes of the length use
 * (unsigned char) casts; the block registers are accessed through a macro of volatile 32-bit words. The last
 * call is a tail call.
 */
extern int dbg_printf(const char *, ...);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdcp_hash_feed_byte(unsigned char, unsigned char);

/* Registers of the hash block at 0xCF018E00, 32 bits each. The bytes of the list are written to the data
   register R04; R0C counts down from 0x3f as bytes are written (hdcp_hash_feed_byte starts the block
   through bit 0 of R14 when it reads 0 and reloads it); R14 holds the start bits (bit 0, 1, 2, 7) that clear
   themselves; R24 / R28 take the length in bytes. */
#define R(a) (*(volatile unsigned int *)(a))
#define R00 R(0xcf018e00)
#define R04 R(0xcf018e04)
#define R08 R(0xcf018e08)
#define R0C R(0xcf018e0c)
#define R10 R(0xcf018e10)
#define R14 R(0xcf018e14)
#define R18 R(0xcf018e18)
#define R24 R(0xcf018e24)
#define R28 R(0xcf018e28)

/* Registers of the DP receiver, read and written with dp_reg_*. */
#define RX_REG_CONTROL    0x30      /* bit 7 is set for the whole run and cleared at the end */
#define RX_REG_E8         0xe8      /* its bytes are read n * 5 times and printed under 'KSV' */
#define RX_REG_E9         0xe9      /* written 0xf; the routine waits for its low nibble to read 0 */
#define RX_REG_BINFO_LOW  0x2aa     /* printed with 0x2ab under 'Binfo'; its value is n */
#define RX_REG_BINFO_HIGH 0x2ab
#define RX_REG_VH_BASE    0x297     /* the 20 result bytes go to 0x294..0x297, 0x29b..0x298, ... */
#define BINFO_BYTES       2         /* these two bytes, */
#define M0_BYTES          8         /* the bytes 0..7 and */
#define M0_END_BYTE       0x80      /* ... 0x80 are fed after the list */
#define STEP_ARG_BIT0     0xaa      /* first argument of hdcp_hash_feed_byte: 0xaa starts through bit 0 of R14 */
#define RESULT_BYTES      20

/*
 * Feed the DP receiver's list of 5-byte entries, two Binfo bytes and a fixed tail through the hash block and
 * write the 20-byte result into receiver registers. It prints every step ('Calculate V', 'KSV', 'Binfo', 'M0',
 * 'VH<j>').
 *
 *   receiver  DP receiver 0 or 1 (called with port - 4 by hdcp_rx_dp_poll_v_calculation)
 *
 * Order:
 *  1. Bit 7 of receiver register 0x30 is set. The block is set up: R10 = 0x1f with a bit-7 start of R14, bit 0
 *     of R18 cleared, R00 = 0x11, receiver register 0xe9 = 0xf (waits for the low nibble to read 0), R08 = 0x10,
 *     R0C = 0x3f. n is read from register 0x2aa; one byte of register 0xe8 is read and dropped; R14 = 2 is written and
 *     waited for until bit 1 clears.
 *  2. n * 5 bytes are read from register 0xe8, printed and passed to hdcp_hash_feed_byte.
 *  3. Registers 0x2aa and 0x2ab are passed on and printed as 'Binfo'; then the bytes 0..7 (printed as 'M0') and
 *     0x80.
 *  4. length = n * 5 + 10 (list, Binfo, 8 bytes; the 0x80 is not counted) goes to R28 (low byte) and R24 (high
 *     byte). If R0C is 6 or less, bit 0 of R14 is started and R10 = 0x1f with a bit-7 start is repeated. Then
 *     length * 8 goes to R04, low byte with R0C = 0 and high byte with R0C = 1, followed by a bit-0 start,
 *     R00 = 0x22, R08 = 0 and a start through bit 4 of R10 that is waited for.
 *  5. 20 bytes are read from R04 and written to receiver registers (j / 4) * 8 - j + 0x297, that is four bytes to
 *     0x297 down to 0x294, the next four to 0x29b down to 0x298, and so on; each is printed as 'VH<j>'.
 *  6. Bit 7 of receiver register 0x30 is cleared again (tail call).
 * Every wait is a loop on the bit with no time-out.
 */
void hdcp_rx_dp_calculate_v(unsigned char receiver)
{
    unsigned short n;
    unsigned short length;
    unsigned short j;
    unsigned char value;
    unsigned int binfo_low;

    dbg_printf("\nCalculate V");
    dp_reg_update_bits(receiver, RX_REG_CONTROL, 0x80, 1);
    R10 = 0x1f;
    R14 = 0x80;
    while (R14 & 0x80)
        ;
    R18 &= ~1;
    R00 = 0x11;
    dp_reg_write8(receiver, RX_REG_E9, 0xf);
    while (dp_reg_read8(receiver, RX_REG_E9) & 0xf)
        ;
    R08 = 0x10;
    R0C = 0x3f;
    n = dp_reg_read8(receiver, RX_REG_BINFO_LOW);
    dp_reg_read8(receiver, RX_REG_E8);
    R14 = 2;
    while (R14 & 2)
        ;
    dbg_printf("\nKSV : ");
    for (length = 0; length < n * 5; length++) {
        value = dp_reg_read8(receiver, RX_REG_E8);
        dbg_printf("%02X", value);
        hdcp_hash_feed_byte(STEP_ARG_BIT0, value);
    }
    length = (n & 0xff) * 5;
    hdcp_hash_feed_byte(STEP_ARG_BIT0, dp_reg_read8(receiver, RX_REG_BINFO_LOW));
    hdcp_hash_feed_byte(STEP_ARG_BIT0, dp_reg_read8(receiver, RX_REG_BINFO_HIGH));
    binfo_low = dp_reg_read8(receiver, RX_REG_BINFO_LOW);
    dbg_printf("\nBinfo : %02X%02X ", binfo_low, dp_reg_read8(receiver, RX_REG_BINFO_HIGH));
    dbg_printf("\nM0 : ");
    for (j = 0; j < M0_BYTES; j++) {
        value = j;
        dbg_printf("%02X", value);
        hdcp_hash_feed_byte(STEP_ARG_BIT0, value);
    }
    hdcp_hash_feed_byte(STEP_ARG_BIT0, M0_END_BYTE);
    length += BINFO_BYTES + M0_BYTES;
    R28 = (unsigned char)length;
    R24 = (unsigned char)(length >> 8);
    if (R0C <= 6) {
        R14 |= 1;
        while (R14 & 1)
            ;
        R10 = 0x1f;
        R14 |= 0x80;
        while (R14 & 0x80)
            ;
    }
    R0C = 0;
    R04 = (length << 3) & 0xff;
    R0C = 1;
    R04 = ((length << 3) >> 8) & 0xff;
    R14 |= 1;
    while (R14 & 1)
        ;
    R00 = 0x22;
    R08 = 0;
    R10 |= 0x10;
    while (R10 & 0x10)
        ;
    for (j = 0; j < RESULT_BYTES; j++) {
        value = R04;
        dp_reg_write8(receiver, (j / 4) * 8 - j + RX_REG_VH_BASE, value);
        dbg_printf("\nVH%d, 0x%02X", j, value);
    }
    dp_reg_update_bits(receiver, RX_REG_CONTROL, 0x80, 0);
}
