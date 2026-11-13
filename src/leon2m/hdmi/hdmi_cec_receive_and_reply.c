/* hdmi_cec_receive_and_reply  (FUN_a00fc334)
 *
 * Receive a CEC message, answer it and return the command it carried.
 * Returns: command code
 * Name basis: derived - receive and reply dispatch with two switches
 *
 * Matching notes
 * --------------
 * FUN_a00fc334 (leon2m 0xa00fc334-0xa00fca34, 448 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - cec_receive_message() and cec_send_reply() are static helpers that the compiler inlines (cec_send_reply four
 *    times; the firmware shares one copy of the wait-loop tail at 0xa00fc4d8);
 *  - cec_receive_message() returns unsigned char (the firmware keeps 'mov 5' and 'cmp 1' at 0xa00fc358);
 *  - in every arm the message bytes are stored first, in index order, and the receive flag bit is set last
 *    (store order at 0xa00fc6d8..0xa00fc700 and 0xa00fc7dc..0xa00fc80c);
 *  - case order: 0x36, 0x82/0x84, 0x87 in the first switch; 0x9d, 0x83, 0x36, 0x91, 0x8f, 0x0f, 0x93/0xff,
 *    0x44, 0x47 in the second (other case orders give other registers inside the arms);
 *  - the data registers are read with the address expression of CEC_RX_DATA(i) as written.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/* Registers of the CEC block at 0xCF012000 that this routine uses (one byte value per 32-bit word). */
#define CEC_STATUS          0xcf012034  /* bits below; bits that have been seen are written back to it */
#define CEC_TX_LENGTH       0xcf012040  /* number of message bytes in CEC_TX_DATA0.. to send */
#define CEC_RX_REG_3C       0xcf01203c  /* when it reads 0, a received message is dropped unread */
#define CEC_TX_DEST         0xcf012080  /* destination address of the message to send */
#define CEC_TX_DATA0        0xcf012084  /* first byte of the message to send (the message code) */
#define CEC_TX_DATA1        0xcf012088
#define CEC_TX_DATA2        0xcf01208c
#define CEC_TX_DATA3        0xcf012090
#define CEC_RX_ADDRESS      0xcf0120c4  /* address byte of the received message (see below) */
#define CEC_RX_DATA(i)      (0xcf000000 | ((0x4832 + i) << 2))  /* byte i of the received message, 0xCF0120C8 + 4*i */
#define CEC_RX_DATA_COUNT   16          /* data registers read for every message */

/* CEC_STATUS bits. */
#define CEC_STATUS_RX_READY 0x01        /* a message has been received; written back once it has been read */
#define CEC_STATUS_BITS_38  0x38        /* when one is set, they are written back and no message is read */
#define CEC_STATUS_SEND     0x2e        /* written before and after a send; the send waits for one of them */

#define CEC_SEND_TIMEOUT_TICKS 1000     /* longest wait for the end of a send, in timer_get_ticks16 ticks */

/* Results of cec_receive_message(); the caller only acts on CEC_RX_TAKEN. */
#define CEC_RX_TAKEN        1           /* a message was read and handled */
#define CEC_RX_STATUS_38    5           /* one of CEC_STATUS_BITS_38 was set */
#define CEC_RX_NOTHING      6           /* no message, or CEC_RX_REG_3C read 0 */

/* Bits of hdmi_cec_rx_flags, one per kind of message kept for the caller. The lowest set bit decides the
   command this routine returns (bit n gives command n + 1). */
#define CEC_RX_FLAG0           0x01     /* not set by this routine */
#define CEC_RX_MSG_36          0x02     /* message 0x36 */
#define CEC_RX_ACTIVATE_SOURCE 0x04     /* message 0x82 or 0x84 with a byte other than 0 after the code */
#define CEC_RX_MSG_9D          0x08     /* message 0x9d */
#define CEC_RX_MSG_44          0x10     /* message 0x44 */
#define CEC_RX_VENDOR_ID       0x20     /* message 0x87 */
#define CEC_RX_MSG_47          0x40     /* message 0x47 */

/* Commands returned to hdmi_cec_api_get_command (the same values as its CEC_CMD_ names in
   sys_run_app_timer_task). */
enum {
    CEC_CMD_NONE            = 0,
    CEC_CMD_FLAG0           = 1,
    CEC_CMD_MSG_36          = 2,
    CEC_CMD_ACTIVATE_SOURCE = 3,    /* "_SYS_CECRequest_ActivateSC" in the caller */
    CEC_CMD_MSG_9D          = 4,    /* sys_run_app_timer_task has no case for it */
    CEC_CMD_MSG_44_OP40     = 5,    /* hdmi_cec_api_get_command passes it on only with operand 0x40 */
    CEC_CMD_VENDOR_ID       = 6,    /* "_SYS_CECRequest_VendorID" in the caller */
    CEC_CMD_MSG_47          = 7
};

extern void (*hdmi_cec_send_hook)(int, int);
extern unsigned short timer_get_ticks16(void);
extern void ipc_signal_alive(void);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned char hdmi_cec_rx_flags, hdmi_cec_peer_address, hdmi_cec_sender, hdmi_cec_operand;
extern unsigned char hdmi_cec_rx_message[5], hdmi_cec_rx_word[4];

/* Send the message already written to CEC_TX_DATA0.. : `length` bytes to address `dest`. When a send hook is set
   (hdmi_cec_set_send_hook) it is called with dest and length instead of writing the two registers. Waits up to CEC_SEND_TIMEOUT_TICKS
   for one of the CEC_STATUS_SEND bits, calling ipc_signal_alive meanwhile, then writes them back. The same
   steps are written out in hdmi_cec_send_message_first and its twins. */
static void cec_send_reply(unsigned char dest, unsigned char length)
{
    unsigned short start;

    REG(CEC_STATUS) = CEC_STATUS_SEND;
    if (hdmi_cec_send_hook != 0)
        hdmi_cec_send_hook(dest, length);
    else {
        REG(CEC_TX_DEST) = dest;
        REG(CEC_TX_LENGTH) = length;
    }
    start = timer_get_ticks16();
    while (!(REG(CEC_STATUS) & CEC_STATUS_SEND)) {
        ipc_signal_alive();
        if (timer_ticks_since(start) > CEC_SEND_TIMEOUT_TICKS)
            break;      /* give up; the status is read and written back all the same */
    }
    REG(CEC_STATUS);
    REG(CEC_STATUS) = CEC_STATUS_SEND;
}

/* Take one received message from the CEC block, if there is one.
 *
 * Phases:
 *  1. Status check: CEC_STATUS_BITS_38 set -> clear them, CEC_RX_STATUS_38. No CEC_STATUS_RX_READY -> nothing
 *     to do, CEC_RX_NOTHING. CEC_RX_REG_3C reads 0 -> acknowledge the message unread, CEC_RX_NOTHING.
 *  2. Read: the address byte and all 16 data registers into `message`. The high nibble of the address byte
 *     goes to hdmi_cec_peer_address, the destination of the replies below.
 *  3. Dispatch on the message code (message[0]): one switch when the low nibble of the address byte is 0xF,
 *     another for every other value. An arm either keeps message bytes for the caller and sets its
 *     hdmi_cec_rx_flags bit, or writes a reply and sends it at once.
 *  4. Acknowledge the message (CEC_STATUS_RX_READY written back), CEC_RX_TAKEN.
 * Codes without an arm are acknowledged and dropped. */
static unsigned char cec_receive_message(void)
{
    unsigned char message[16];
    unsigned char rx_address, i;

    /* 1. Status check. */
    if (REG(CEC_STATUS) & CEC_STATUS_BITS_38) {
        REG(CEC_STATUS) = CEC_STATUS_BITS_38;
        return CEC_RX_STATUS_38;
    }
    if (!(REG(CEC_STATUS) & CEC_STATUS_RX_READY))
        return CEC_RX_NOTHING;
    if (REG(CEC_RX_REG_3C) == 0) {
        REG(CEC_STATUS) = CEC_STATUS_RX_READY;
        return CEC_RX_NOTHING;
    }

    /* 2. Read the message. */
    rx_address = REG(CEC_RX_ADDRESS);
    for (i = 0; i < CEC_RX_DATA_COUNT; i++)
        message[i] = REG(CEC_RX_DATA(i));
    hdmi_cec_peer_address = rx_address >> 4;

    /* 3. Dispatch on the message code. */
    if ((rx_address & 0xf) == 0xf) {
        /* Address low nibble 0xF: these codes are only kept, never answered. */
        switch (message[0]) {
        case 0x36:
            hdmi_cec_rx_flags |= CEC_RX_MSG_36;
            break;
        case 0x82:
        case 0x84:
            /* The byte after the code is the sender byte that sys_run_app_timer_task turns into an input
               source (0x10..0x40); 0 is kept but not reported. */
            hdmi_cec_sender = message[1];
            if (message[1] != 0)
                hdmi_cec_rx_flags |= CEC_RX_ACTIVATE_SOURCE;
            break;
        case 0x87:
            /* Code and three bytes, read back as one word by hdmi_cec_get_message_word (sys_run_app_timer_task
               stores them in hdmi_cec_vendor_id_bytes). hdmi_cec_request_vendor_id clears these bytes before its request. */
            hdmi_cec_rx_word[0] = message[0];
            hdmi_cec_rx_word[1] = message[1];
            hdmi_cec_rx_word[2] = message[2];
            hdmi_cec_rx_word[3] = message[3];
            hdmi_cec_rx_flags |= CEC_RX_VENDOR_ID;
            break;
        }
    } else {
        /* Any other low nibble: kept codes, and codes answered to hdmi_cec_peer_address (0x83 to address 0xF). */
        switch (message[0]) {
        case 0x9d:
            hdmi_cec_sender = message[1];
            hdmi_cec_rx_flags |= CEC_RX_MSG_9D;
            break;
        case 0x83:
            /* Answer: 0x84, 0, 0, 0 to address 0xF. */
            REG(CEC_TX_DATA0) = 0x84;
            REG(CEC_TX_DATA1) = 0;
            REG(CEC_TX_DATA2) = 0;
            REG(CEC_TX_DATA3) = 0;
            cec_send_reply(0xf, 4);
            break;
        case 0x36:
            hdmi_cec_rx_flags |= CEC_RX_MSG_36;
            break;
        case 0x91:
            /* Answer: 0x32 and the text "eng", the same code and first table entry that
               hdmi_cec_send_table_message sends. */
            REG(CEC_TX_DATA0) = 0x32;
            REG(CEC_TX_DATA1) = 0x65;
            REG(CEC_TX_DATA2) = 0x6e;
            REG(CEC_TX_DATA3) = 0x67;
            cec_send_reply(hdmi_cec_peer_address, 4);
            break;
        case 0x8f:
            /* Answer: 0x90, 0. */
            REG(CEC_TX_DATA0) = 0x90;
            REG(CEC_TX_DATA1) = 0;
            cec_send_reply(hdmi_cec_peer_address, 2);
            break;
        case 0x0f:
            /* Answer: 0, 2. */
            REG(CEC_TX_DATA0) = 0;
            REG(CEC_TX_DATA1) = 2;
            cec_send_reply(hdmi_cec_peer_address, 2);
            break;
        case 0x93:
        case 0xff:
            /* Answer: 0, 0, 0. */
            REG(CEC_TX_DATA0) = 0;
            REG(CEC_TX_DATA1) = 0;
            REG(CEC_TX_DATA2) = 0;
            cec_send_reply(hdmi_cec_peer_address, 3);
            break;
        case 0x44:
            /* The byte after the code is the operand (hdmi_cec_get_operand). */
            hdmi_cec_operand = message[1];
            hdmi_cec_rx_flags |= CEC_RX_MSG_44;
            break;
        case 0x47:
            /* Code and four bytes, copied out by hdmi_cec_copy_message (sys_run_app_timer_task copies
               them to hdmi_cec_source_name). */
            hdmi_cec_rx_message[0] = message[0];
            hdmi_cec_rx_message[1] = message[1];
            hdmi_cec_rx_message[2] = message[2];
            hdmi_cec_rx_message[3] = message[3];
            hdmi_cec_rx_message[4] = message[4];
            hdmi_cec_rx_flags |= CEC_RX_MSG_47;
            break;
        }
    }

    /* 4. Acknowledge. */
    REG(CEC_STATUS) = CEC_STATUS_RX_READY;
    return CEC_RX_TAKEN;
}

/* Receive step of the HDMI CEC link: take at most one message from the CEC block, answer the codes that get a
 * fixed answer, and report the kept ones as a command.
 *
 * Called only by hdmi_cec_api_get_command, which sys_run_app_timer_task runs in its CEC step. When the HDMI CEC
 * setting is off, PIP/PBP is on or the OLED power state or step is not 0, that step drops the command, but the
 * message is still taken and answered here.
 *
 * Phases:
 *  1. cec_receive_message(): read one message, answer it or keep its bytes and set a bit in hdmi_cec_rx_flags.
 *  2. Only when a message was taken: turn the lowest set bit of hdmi_cec_rx_flags into a command (bit n ->
 *     command n + 1) and clear all bits. Each taken message sets at most one bit.
 * Returns CEC_CMD_NONE when no message was taken or the message set no bit; the bytes of a kept message stay in
 * hdmi_cec_sender / hdmi_cec_operand / hdmi_cec_rx_word / hdmi_cec_rx_message for the caller to fetch. */
int hdmi_cec_receive_and_reply(void)
{
    int command = CEC_CMD_NONE;
    unsigned char flags;

    /* 1. Receive. */
    if (cec_receive_message() == CEC_RX_TAKEN) {
        /* 2. Lowest set bit -> command; then the flags start again from nothing. */
        flags = hdmi_cec_rx_flags;
        if (flags & CEC_RX_FLAG0)
            command = CEC_CMD_FLAG0;
        else if (flags & CEC_RX_MSG_36)
            command = CEC_CMD_MSG_36;
        else if (flags & CEC_RX_ACTIVATE_SOURCE)
            command = CEC_CMD_ACTIVATE_SOURCE;
        else if (flags & CEC_RX_MSG_9D)
            command = CEC_CMD_MSG_9D;
        else if (flags & CEC_RX_MSG_44)
            command = CEC_CMD_MSG_44_OP40;
        else if (flags & CEC_RX_VENDOR_ID)
            command = CEC_CMD_VENDOR_ID;
        else if (flags & CEC_RX_MSG_47)
            command = CEC_CMD_MSG_47;
        hdmi_cec_rx_flags = 0;
    }
    return command;
}
