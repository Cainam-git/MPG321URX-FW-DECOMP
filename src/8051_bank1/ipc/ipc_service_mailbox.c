/* ipc_service_mailbox  (FUN_CODE_9243)
 *
 * Run one command and exchange pending messages with the main processor.
 * Note: Both message loops stop after 100 rounds, so a dead main processor cannot hang the 8051.
 * Name basis: proven - header of the source; docs/MAP.md update path; ipc_run_command, ipc_run_message,
 *   ipc_build_report_message
 *
 * Matching notes
 * --------------
 * One Keil module in this order: ipc_find_free_tx_slot (0x8512), ipc_find_rx_message (0x960F),
 *   ipc_service_mailbox (0x9243..0x9339, 246 bytes), ipc_portal_read (0xA4E9), ipc_portal_write (0xB228).
 *   Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * Reason for the module: ipc_portal_read has a Keil OPTIMIZE(8) common-entry block 0xA4D2..0xA4E9 with entry points
 *   used only by 0x8512 (0xA4D2, 0xA4D6), 0x960F (0xA4E0, 0xA4E3) and 0x9243 (0xA4E5 'MOV A,#5'), and
 *   ipc_portal_write has the block 0xB222 used by the two calls of 0x9243. Keil builds such a block only from calls
 *   inside the same module; without 0x8512 in the unit the bytes of 0x9243 differ. ipc_portal_read and
 *   ipc_portal_write are also the bodies of src/8051_bank1/ipc/ipc_portal_read.c and ipc/ipc_portal_write.c.
 * Source forms (both slot searches): each slot test is 'if (found) break; else { advance the index }', which gives
 *   the firmware's 'JZ / JNZ +2; SJMP exit' pair after ?C?ULCMP. ipc_service_mailbox's first loop is a for loop
 *   over the round counter, the second a do-while.
 * Source form (ipc_find_free_tx_slot): the mask is '1 << ((header >> 8) & 0xff)'.
 * Source form (ipc_service_mailbox): the ipc_clear_portal_word argument is '(unsigned int)(slot * PORTAL_SLOT_BYTES
 *   + PORTAL_RX_SLOTS)' (the firmware zero-extends R4/R5 with CLR A).
 * volatile only on 0xF00A; everything else is RAM or goes through the AHB bridge routines.
 */
#include <reg51.h>

/* The mailbox portal to the main processor, reached over the AHB bridge (docs/MAILBOX.md). */
#define PORTAL_AHB_BASE        0x9F0A0100UL /* portal word +0x00; the low address byte is the word offset */
#define PORTAL_COMMAND_WORD    0            /* portal word +0x00: the command word */
#define PORTAL_RX_SLOTS        0x10         /* slots main processor -> 8051: +0x10 + 20 * slot */
#define PORTAL_TX_SLOTS        0x60         /* slots 8051 -> main processor: header word +0x60 + 20 * slot */
#define PORTAL_TX_PAYLOAD      0x64         /* ... and its four data words from +0x64 + 20 * slot */
#define PORTAL_SLOT_BYTES      20           /* one slot = header word + four data words */
#define PORTAL_SLOT_COUNT      4
#define IPC_MSG_WORDS          5
#define IPC_MSG_PAYLOAD_WORDS  4
#define IPC_MSG_TYPE_MASK      0x0f         /* header bits 3..0: message type, 0 = slot empty */
#define IPC_8051_MSG_NONE      0
#define IPC_8051_MSG_UART      3            /* 8051 -> main: received serial bytes; header bits 15..8 = port */
#define IPC_NO_RX_MESSAGE      0xfe         /* ipc_find_rx_message: no filled slot */
#define IPC_NO_FREE_TX_SLOT    0xff         /* ipc_find_free_tx_slot: no empty slot */
#define IPC_SERVICE_ROUNDS     100          /* most messages taken or sent per call, each way */
#define RUN_STATE_RUNNING      2            /* sys_run_state: 0 power saving, 1 power off, 2 running */
#define F00A_MARK              0x55         /* written to 0xF00A each round (0xAA while a flash handshake is held) */

/* One 32-bit AHB word, also as its four bytes (Keil stores the most significant byte first). */
typedef union { unsigned long value; unsigned char bytes[4]; } ahb_word;
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata sys_run_state;
extern ahb_word xdata reg_ahb_read_addr;
extern ahb_word xdata reg_ahb_write_addr;
extern ahb_word xdata reg_ahb_write_value;
extern ahb_word reg_ahb_read32(void);
extern void reg_ahb_write32(void);
extern void MailBox_UpdateDDCFlag(void);
extern void ipc_run_command(unsigned long cmd);
extern unsigned char xdata ipc_rx_slot_index;
extern unsigned char xdata ipc_tx_slot_index, uart_rx_reported_mask;
void ipc_portal_read(unsigned char off, unsigned long *dst, unsigned char n);
void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n);
unsigned char ipc_find_rx_message(void);
extern void ipc_run_message(unsigned long *msg);
extern void ipc_build_report_message(unsigned long *msg);
extern void ipc_clear_portal_word(unsigned long off);
extern void ipc_step_poll_slot(void);


void ipc_service_mailbox(void);

/* Find an empty slot for a message to the main processor.
 *   1. Rebuild uart_rx_reported_mask: one bit (number = header bits 15..8) for every outgoing slot that still holds
 *      a serial message (type 3).
 *   2. Look at up to four slots from ipc_tx_slot_index on, wrapping after slot 3, and stop at the first empty one
 *      (type 0). When that is not the first slot looked at, the search runs once more from the same start.
 * Returns the empty slot (ipc_tx_slot_index is left on it; ipc_step_poll_slot moves it on after the write), or
 * 0xFF when all four slots are taken.
 */
unsigned char ipc_find_free_tx_slot(void)
{
    unsigned long header;
    unsigned char slot;     /* slots looked at, then the result */
    unsigned char start_slot;

    slot = 0xff;
    /* 1. Serial ports whose received bytes still wait in a slot. */
    uart_rx_reported_mask = 0;
    for (slot = 0; slot < PORTAL_SLOT_COUNT; slot++) {
        ipc_portal_read(slot * PORTAL_SLOT_BYTES + PORTAL_TX_SLOTS, &header, 1);
        if ((header & IPC_MSG_TYPE_MASK) == IPC_8051_MSG_UART) uart_rx_reported_mask |= 1 << ((header >> 8) & 0xff);
    }
    /* 2. First empty slot, round robin from ipc_tx_slot_index. */
    start_slot = ipc_tx_slot_index;
    for (slot = 0; slot < PORTAL_SLOT_COUNT; slot++) {
        ipc_portal_read(ipc_tx_slot_index * PORTAL_SLOT_BYTES + PORTAL_TX_SLOTS, &header, 1);
        if ((header & IPC_MSG_TYPE_MASK) == IPC_8051_MSG_NONE)
            break;
        else {
            ipc_tx_slot_index++;
            if (ipc_tx_slot_index >= PORTAL_SLOT_COUNT) ipc_tx_slot_index = 0;
        }
    }
    if (slot != 0 && slot != PORTAL_SLOT_COUNT) {
        /* Found, but not at the start slot: search again from the start. */
        ipc_tx_slot_index = start_slot;
        for (slot = 0; slot < PORTAL_SLOT_COUNT; slot++) {
            ipc_portal_read(ipc_tx_slot_index * PORTAL_SLOT_BYTES + PORTAL_TX_SLOTS, &header, 1);
            if ((header & IPC_MSG_TYPE_MASK) == IPC_8051_MSG_NONE)
                break;
            else {
                ipc_tx_slot_index++;
                if (ipc_tx_slot_index >= PORTAL_SLOT_COUNT) ipc_tx_slot_index = 0;
            }
        }
    }
    if (slot == PORTAL_SLOT_COUNT) slot = IPC_NO_FREE_TX_SLOT;
    else slot = ipc_tx_slot_index;
    return slot;
}

/* Find the next filled slot of a message from the main processor (header type bits 3..0 not 0).
 * Looks at up to four slots from ipc_rx_slot_index on, wrapping after slot 3; when the filled slot is not the first
 * one looked at, the search runs once more from the same start.
 * Returns the slot and moves ipc_rx_slot_index past it, so the next call starts at the following slot; 0xFE when
 * no slot is filled.
 */
unsigned char ipc_find_rx_message(void)
{
    unsigned long header;
    unsigned char slot;     /* slots looked at, then the result */
    unsigned char start_slot;

    slot = 0xff;
    start_slot = ipc_rx_slot_index;
    for (slot = 0; slot < PORTAL_SLOT_COUNT; slot++) {
        ipc_portal_read(ipc_rx_slot_index * PORTAL_SLOT_BYTES + PORTAL_RX_SLOTS, &header, 1);
        if ((header & IPC_MSG_TYPE_MASK) != IPC_8051_MSG_NONE)
            break;
        else {
            ipc_rx_slot_index++;
            if (ipc_rx_slot_index >= PORTAL_SLOT_COUNT) ipc_rx_slot_index = 0;
        }
    }
    if (slot != 0 && slot != PORTAL_SLOT_COUNT) {
        /* Found, but not at the start slot: search again from the start. */
        ipc_rx_slot_index = start_slot;
        for (slot = 0; slot < PORTAL_SLOT_COUNT; slot++) {
            ipc_portal_read(ipc_rx_slot_index * PORTAL_SLOT_BYTES + PORTAL_RX_SLOTS, &header, 1);
            if ((header & IPC_MSG_TYPE_MASK) != IPC_8051_MSG_NONE)
                break;
            else {
                ipc_rx_slot_index++;
                if (ipc_rx_slot_index >= PORTAL_SLOT_COUNT) ipc_rx_slot_index = 0;
            }
        }
    }
    if (slot == PORTAL_SLOT_COUNT) {
        slot = IPC_NO_RX_MESSAGE;
    } else {
        slot = ipc_rx_slot_index;
        ipc_rx_slot_index++;
        if (ipc_rx_slot_index >= PORTAL_SLOT_COUNT) ipc_rx_slot_index = 0;
    }
    return slot;
}

/* Serve the mailbox portal once; sys_main calls it on every pass of its main loop.
 *
 * Phases, in order:
 *   1. Report the DDC access flags (MailBox_UpdateDDCFlag, portal word +0x0C).
 *   2. Read the command word (portal +0x00) and carry it out (ipc_run_command; the command numbers and what each
 *      does are in docs/MAILBOX.md).
 *   3. Stop here unless the run state is "running" afterwards (commands 0x16 power saving and 0x17 power off set
 *      it to 0 and 1).
 *   4. Messages from the main processor, up to 100: take the next filled slot (ipc_find_rx_message), read its five
 *      words, carry the message out (ipc_run_message) and clear the slot's header word, which frees the slot.
 *      Stops at the first round without a filled slot.
 *   5. Messages to the main processor, up to 100: find an empty slot (ipc_find_free_tx_slot), let
 *      ipc_build_report_message fill a message, write its four data words and then its header word into the slot,
 *      and move the slot index on (ipc_step_poll_slot). Stops when no slot is empty or the built header is 0
 *      (nothing to send).
 * Each round of both loops writes 0x55 to 0xF00A first.
 */
void ipc_service_mailbox(void)
{
    unsigned char slot;
    unsigned char rx_rounds;
    unsigned char tx_rounds;
    unsigned long command_word;
    unsigned long message[IPC_MSG_WORDS];   /* header word + four data words */

    /* 1.-2. DDC access flags, then the command. */
    MailBox_UpdateDDCFlag();
    ipc_portal_read(PORTAL_COMMAND_WORD, &command_word, 1);
    ipc_run_command(command_word);
    /* 3. After power saving or power off the message slots are left alone. */
    if (sys_run_state != RUN_STATE_RUNNING) return;

    /* 4. Messages from the main processor. */
    for (rx_rounds = IPC_SERVICE_ROUNDS; rx_rounds > 0; rx_rounds--) {
        DAT_EXTMEM_f00a = F00A_MARK;
        slot = ipc_find_rx_message();
        if (slot != IPC_NO_RX_MESSAGE) {
            ipc_portal_read(slot * PORTAL_SLOT_BYTES + PORTAL_RX_SLOTS, message, IPC_MSG_WORDS);
            ipc_run_message(message);
            ipc_clear_portal_word((unsigned int)(slot * PORTAL_SLOT_BYTES + PORTAL_RX_SLOTS));
        } else
            break;
    }

    /* 5. Messages to the main processor: data words first, header word last. */
    tx_rounds = IPC_SERVICE_ROUNDS;
    do {
        DAT_EXTMEM_f00a = F00A_MARK;
        slot = ipc_find_free_tx_slot();
        if (slot == IPC_NO_FREE_TX_SLOT) break;
        ipc_build_report_message(message);
        if (message[0] == 0) break;
        ipc_portal_write(slot * PORTAL_SLOT_BYTES + PORTAL_TX_PAYLOAD, &message[1], IPC_MSG_PAYLOAD_WORDS);
        ipc_portal_write(slot * PORTAL_SLOT_BYTES + PORTAL_TX_SLOTS, &message[0], 1);
        ipc_step_poll_slot();
        tx_rounds--;
    } while (tx_rounds > 0);
}

/* Read n consecutive 32-bit words from the portal, starting at byte offset off. */
void ipc_portal_read(unsigned char off, unsigned long *dst, unsigned char n)
{
    unsigned char i;
    ahb_word addr;
    ahb_word val;
    addr.value = PORTAL_AHB_BASE;
    for (i = 0; i < n; i++) {
        addr.bytes[3] = off + i * 4;    /* address bits 7..0 */
        reg_ahb_read_addr = addr;
        val = reg_ahb_read32();
        dst[i] = val.value;
    }
}

/* Write n consecutive 32-bit words into the portal, starting at byte offset off. */
void ipc_portal_write(unsigned char off, unsigned long *src, unsigned char n)
{
    unsigned char i;
    ahb_word addr;
    ahb_word val;
    addr.value = PORTAL_AHB_BASE;
    for (i = 0; i < n; i++) {
        addr.bytes[3] = off + i * 4;    /* address bits 7..0 */
        val.value = src[i];
        reg_ahb_write_addr = addr;
        reg_ahb_write_value = val;
        reg_ahb_write32();
    }
}
