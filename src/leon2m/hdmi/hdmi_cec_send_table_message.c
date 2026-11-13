/* hdmi_cec_send_table_message  (FUN_a00fccbc)
 *
 * Send CEC message 0x32 with the three bytes of a table entry.
 * Name basis: derived - opcode 0x32 (set menu language) with a 3-byte entry of a 16-entry table; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fccbc @ 0xa00fccbc, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the table is an initialised const local array (the firmware holds its initialiser at 0x19a466); GCC copies it
 *    to the stack with a memcpy call, and memcpy is declared with the link name memcpy (an __asm__ name, no
 *    code);
 *  - the send steps are a static helper that the compiler inlines;
 *  - the final status read is a plain volatile read whose value is dropped.
 */
#define R(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 (the same names as in hdmi_cec_receive_and_reply). */
#define CEC_STATUS          0xcf012034
#define CEC_TX_LENGTH       0xcf012040  /* number of message bytes to send */
#define CEC_TX_DEST         0xcf012080  /* destination address of the message to send */
#define CEC_TX_DATA0        0xcf012084  /* first byte of the message to send (the message code) */
#define CEC_TX_DATA1        0xcf012088
#define CEC_TX_DATA2        0xcf01208c
#define CEC_TX_DATA3        0xcf012090
#define CEC_STATUS_SEND     0x2e        /* the send waits for one of these bits */
#define CEC_SEND_TIMEOUT_TICKS 1000     /* longest wait for the end of a send, in timer_get_ticks16 ticks */
#define CEC_DEST_0F         0xf

extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern void (*hdmi_cec_send_hook)(int, int);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void ipc_signal_alive(void);

/* Send the message already written to CEC_TX_DATA0.. : `length` bytes to address `dest`. The same steps as in
   hdmi_cec_send_message_first: the send hook gets dest and length when it is set; the wait is bounded by
   CEC_SEND_TIMEOUT_TICKS. */
static void cec_send_and_wait(unsigned char dest, unsigned char length)
{
    unsigned short start;

    R(CEC_STATUS) = CEC_STATUS_SEND;
    if (hdmi_cec_send_hook != 0)
        hdmi_cec_send_hook(dest, length);
    else {
        R(CEC_TX_DEST) = dest;
        R(CEC_TX_LENGTH) = length;
    }
    start = timer_get_ticks16();
    while (!(R(CEC_STATUS) & CEC_STATUS_SEND)) {
        ipc_signal_alive();
        if (timer_ticks_since(start) > CEC_SEND_TIMEOUT_TICKS)
            break;
    }
    (void)R(CEC_STATUS);
    R(CEC_STATUS) = CEC_STATUS_SEND;
}

/*
 * Send message code 0x32 with the three letters of entry `index` of a table of 16 language codes, to address 0xF
 * (4 bytes in all). The table reads "eng", "spa", "fra", "ger", "ita", "por", "rus", "zho", "swe", "pol", "cze",
 * "kor", "zho", "jpn", "dut", "fin". The index is not range-checked. Nothing calls this routine;
 * hdmi_cec_receive_and_reply sends the same code with the first entry ("eng") as its answer to message 0x91.
 */
void hdmi_cec_send_table_message(unsigned int index)
{
    const unsigned char languages[16][3] = {
        { 'e', 'n', 'g' }, { 's', 'p', 'a' }, { 'f', 'r', 'a' }, { 'g', 'e', 'r' },
        { 'i', 't', 'a' }, { 'p', 'o', 'r' }, { 'r', 'u', 's' }, { 'z', 'h', 'o' },
        { 's', 'w', 'e' }, { 'p', 'o', 'l' }, { 'c', 'z', 'e' }, { 'k', 'o', 'r' },
        { 'z', 'h', 'o' }, { 'j', 'p', 'n' }, { 'd', 'u', 't' }, { 'f', 'i', 'n' }
    };

    R(CEC_TX_DATA0) = 0x32;
    R(CEC_TX_DATA1) = languages[index][0];
    R(CEC_TX_DATA2) = languages[index][1];
    R(CEC_TX_DATA3) = languages[index][2];
    cec_send_and_wait(CEC_DEST_0F, 4);
}
