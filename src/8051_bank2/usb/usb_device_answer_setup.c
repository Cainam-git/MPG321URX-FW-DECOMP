/* usb_device_answer_setup  (FUN_CODE_573b)
 *
 * Answer a USB setup request from the PC while in device mode.
 * Name basis: proven - setup packet from reg 0x1D0; bRequest 0 GET_STATUS, 5 SET_ADDRESS, 6 GET_DESCRIPTOR, 9
 *   SET_CONFIGURATION
 *
 * Matching notes
 * --------------
 * 8051_bank2 module FUN_CODE_573b, one Keil C51 module compiled with OPTIMIZE(8,SPEED) LARGE: usb_device_answer_setup
 * @ 0x573b..0x5c20 and usb_device_dma_transfer @ 0x7a60..0x7ddb, with the Keil common-entry block usb_device_dma_transfer_entry @
 * 0x7a46..0x7a60 in front of usb_device_dma_transfer. The block is the shared argument set-up of the seven
 * usb_device_dma_transfer calls in usb_device_answer_setup (reply_length into R6:R7, byte request + 3 into R5 through
 * ?C?CLDOPTR); Keil emits it once because all seven calls pass the same arguments. The locals of the two routines
 * have names unique in the module so the block's operands resolve to usb_device_answer_setup.
 * Source forms the bytes depend on:
 *   - usb_device_answer_setup: desc_type and desc_index are two char locals (0x08F8 / 0x08F9) filled from one int
 *     load of wValue; the type tests are int compares ('(unsigned int)desc_type == 1' gives XRL A,#k / JNZ and
 *     reloads 0x08F8 each test); the index tests are char compares (CJNE); the case order is as written. Index 8 and
 *     the other index values are two arms with the same body; the firmware holds both copies (index 8 at
 *     0x5A62..0x5A8D, other index at 0x5A8F..0x5AB8).
 *   - usb_device_dma_transfer: LARGE parameters piece (0x090B) and request_type (0x090D); locals failed (0x090E),
 *     value (0x090F), tries (0x0913), remaining (0x0917), offset (0x0919), declared in that XDATA order.
 *     'value = x & 0x7f000000; value >>= 24;' are two statements (the firmware stores value between the mask and
 *     ?C?ULSHR); 'if (value > piece)' (SETB C / JC); the shared tail from the value store at 0x7C3D is Keil's
 *     cross-jump of the two direction arms.
 */

/* Device-mode control requests of the FOTG210 controller (the controller name is the one in the firmware's own
 * "fotg210: ..." texts). Its registers are 32 bits wide and are reached through the register window
 * (reg_window_read32 / reg_window_write32). Register meanings below are what these two routines and
 * usb_otg_service_irq do with them; the bit names come from the texts printed next to them. */
#define REG_DEVICE_ADDRESS   0x0104      /* bits 0..6 = address given by request SET_ADDRESS; 0 after a host reset */
#define REG_CX               0x0120      /* control endpoint register ("cx_..." texts) */
#define CX_FINISH            0x00000001  /* set before "fotg210: cx_finish!" */
#define CX_STALL             0x00000004  /* set before "fotg210: cx_stall!" */
#define CX_BIT5              0x00000020  /* waited for before every piece sent with request_type bit 7 set */
#define CX_COUNT_MASK        0x7f000000  /* bits 24..30: count compared with the piece size (bit 7 clear) */
#define REG_GROUP2_STATUS    0x014c      /* status group 2 of usb_otg_service_irq; a bit found is written back */
#define GRP2_HOST_EVENTS     0x00000007  /* bits 0..2: "reset by host", "suspend/removed", "resume" */
#define GRP2_DMA_DONE        0x00000080  /* the only bit that ends a piece without "dma fail" */
#define GRP2_DMA_ERROR       0x00000100  /* "fotg210: dma error" */
#define REG_1C0              0x01c0      /* 0x10 while the setup packet is read or a piece moves, 0 after */
#define REG_1C0_ON           0x10
#define REG_DMA_CONTROL      0x01c8
#define DMA_BUSY             0x00000001  /* "fotg210: dma busy"; also set to start a piece */
#define DMA_BIT1             0x00000002  /* set when request_type bit 7 is set, cleared otherwise */
#define DMA_LENGTH_SHIFT     8           /* piece size in bits 8 and up */
#define DMA_FAIL_VALUE       0x18        /* written after "fotg210: dma fail" */
#define REG_DMA_ADDRESS      0x01cc      /* port memory address of the piece */
#define REG_SETUP_PACKET     0x01d0      /* the 8-byte setup packet, read as two 32-bit words */
#define DMA_TRIES            1000

/* Request fields. */
#define REQ_TYPE_BITS        0x60        /* bits 5..6 of bmRequestType: only requests with both clear are answered */
#define REQ_DIR_BIT          0x80        /* bit 7 of bmRequestType, passed on to usb_device_dma_transfer */
#define REQ_GET_STATUS       0
#define REQ_SET_ADDRESS      5
#define REQ_GET_DESCRIPTOR   6
#define REQ_SET_CONFIGURATION 9
#define ADDRESS_MASK         0x7f

/* Descriptor types asked for (high byte of wValue). Each answer is a table in CODE memory whose byte 1 holds the
 * same type number; the names say what the table is where the firmware shows it. */
#define DESC_TYPE_DEVICE     1           /* 0x7F86, 18 bytes */
#define DESC_TYPE_CONFIG     2           /* 0x80E6, 32 bytes */
#define DESC_TYPE_STRING     3           /* text tables, picked by the low byte of wValue */
#define DESC_TYPE_6          6           /* 0x8106, 10 bytes */
#define DESC_TYPE_7          7           /* 0x8110, 32 bytes */
#define DESC_TYPE_0F         0x0f        /* 0x7F98, 80 bytes */

/* Printed texts (CODE addresses). */
#define FMT_DESC_TYPE        0x7edd      /* "DescType = %02BX\r\n" */
#define FMT_DESC_INDEX       0x7ef0      /* "DescIdx = %02BX\r\n" */
#define FMT_CX_FINISH        0x7f02      /* "fotg210: cx_finish!\r\n" */
#define FMT_CX_STALL         0x7f18      /* "fotg210: cx_stall!\r\n" */
#define FMT_CX_IDLE          0x7f2d      /* "fotg210: cx_idle?\r\n" */
#define FMT_DMA_BUSY         0x7f41      /* "fotg210: dma busy\r\n" */
#define FMT_DMA_ERROR        0x7ea9      /* "fotg210: dma error\r\n" */
#define FMT_DMA_RESET        0x7f55      /* "fotg210: dma reset by host\r\n" */
#define FMT_DMA_FAIL         0x7f72      /* "fotg210: dma fail\r\n" */

/* Result of the request, chosen after the "cx_..." text it prints. */
#define CX_RESULT_IDLE       0
#define CX_RESULT_FINISH     1
#define CX_RESULT_STALL      2

/* The setup packet as the two 32-bit register words land in memory (Keil stores a long with its high byte first,
 * so the fields lie in this order). */
struct setup_request {
    unsigned int wValue;         /* +0 */
    unsigned char bRequest;      /* +2 */
    unsigned char bmRequestType; /* +3 */
    unsigned int wLength;        /* +4: bytes the PC asks for */
    unsigned int wIndex;         /* +6 */
};
unsigned long reg_window_read32(unsigned int reg);
void reg_window_write32(unsigned int reg, unsigned long v);
void reg_window_set_bits32(unsigned int reg, unsigned long v);
void usb_port_write_bytes(unsigned char *buf, unsigned char n);
void usb_device_dma_transfer(unsigned int size, unsigned char dir);
extern void lib_printf517(void *fmt, ...) large;

/* usb_device_answer_setup: read the setup packet the PC sent to the control endpoint and answer it.
 *
 * Caller: usb_otg_service_irq (its only caller), when bit 0 of the group 0 status (register 0x144) is set;
 * usb_otg_service_irq is called from sys_main for both controllers while the requested USB mode is 1 (device mode).
 *
 * Phases:
 *   1. Read the packet: REG_1C0 = 0x10, two 32-bit words from REG_SETUP_PACKET, REG_1C0 = 0.
 *   2. Answer it, only when bits 5..6 of bmRequestType are clear; by bRequest:
 *        SET_ADDRESS (5):    bits 0..6 of wValue go into bits 0..6 of REG_DEVICE_ADDRESS;
 *        GET_DESCRIPTOR (6): prints the type (high byte of wValue); the table of that type is copied into the port
 *                            memory (usb_port_write_bytes) and sent (usb_device_dma_transfer), at most wLength
 *                            bytes. Type 3 also prints the index (low byte of wValue) and picks one of seven text
 *                            tables by it; an index without a table of its own gets the table of index 8. A type
 *                            without a table is not answered but still counts as handled;
 *        GET_STATUS (0):     two zero bytes are sent;
 *        SET_CONFIGURATION (9): nothing is done.
 *      These four requests give CX_RESULT_FINISH; anything else leaves CX_RESULT_IDLE.
 *   3. Close the request: FINISH sets CX_FINISH in REG_CX and prints "fotg210: cx_finish!"; IDLE prints
 *      "fotg210: cx_idle?". The STALL arm (CX_STALL and "fotg210: cx_stall!") is never reached: nothing sets
 *      CX_RESULT_STALL.
 *
 * The text tables of type 3 (UTF-16 texts after a 2-byte head):
 *   index 0: 0x7FE8, 4 bytes 04 03 09 04;      index 1: 0x7FEC, "NOVATEK";
 *   index 2: 0x7FFC, "Novatek NT68400 Billboard DEV";  index 3: 0x8038, "Billboard Configuration";
 *   index 4: 0x8068, "Billboard Interface";     index 7: 0x8090, "USB Storage";
 *   index 8 and others: 0x80A8, "ALT Mode Configured Successful". */
void usb_device_answer_setup(void)
{
    unsigned char address;
    unsigned char result;
    unsigned char desc_type;
    unsigned char desc_index;
    unsigned int reply_length;
    unsigned long packet[2];
    unsigned long reg_value;
    struct setup_request *request;
    request = (struct setup_request *)packet;
    /* 1. Read the setup packet. */
    reg_window_write32(REG_1C0, REG_1C0_ON);
    packet[0] = reg_window_read32(REG_SETUP_PACKET);
    packet[1] = reg_window_read32(REG_SETUP_PACKET);
    reg_window_write32(REG_1C0, 0);
    /* 2. Answer it. */
    result = CX_RESULT_IDLE;
    if ((request->bmRequestType & REQ_TYPE_BITS) == 0) {
        switch (request->bRequest) {
        case REQ_SET_ADDRESS:
            address = request->wValue & ADDRESS_MASK;
            reg_value = reg_window_read32(REG_DEVICE_ADDRESS);
            reg_value &= ~ADDRESS_MASK;
            reg_value |= address;
            reg_window_write32(REG_DEVICE_ADDRESS, reg_value);
            result = CX_RESULT_FINISH;
            break;
        case REQ_GET_DESCRIPTOR:
            desc_type = request->wValue >> 8;
            desc_index = request->wValue;
            lib_printf517((void code *)FMT_DESC_TYPE, desc_type);
            /* Each arm: send the table, but never more than the PC asked for. */
            reply_length = request->wLength;
            if ((unsigned int)desc_type == DESC_TYPE_DEVICE) {
                if (request->wLength > 0x12) reply_length = 0x12;
                usb_port_write_bytes((void code *)0x7f86, 0x12);
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            } else if ((unsigned int)desc_type == DESC_TYPE_CONFIG) {
                if (request->wLength > 0x20) reply_length = 0x20;
                usb_port_write_bytes((void code *)0x80e6, 0x20);
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            } else if ((unsigned int)desc_type == DESC_TYPE_0F) {
                if (request->wLength > 0x50) reply_length = 0x50;
                usb_port_write_bytes((void code *)0x7f98, 0x50);
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            } else if ((unsigned int)desc_type == DESC_TYPE_STRING) {
                lib_printf517((void code *)FMT_DESC_INDEX, desc_index);
                if (desc_index == 0) {
                    if (request->wLength > 4) reply_length = 4;
                    usb_port_write_bytes((void code *)0x7fe8, 4);
                } else if (desc_index == 1) {
                    if (request->wLength > 0x10) reply_length = 0x10;
                    usb_port_write_bytes((void code *)0x7fec, 0x10);
                } else if (desc_index == 2) {
                    if (request->wLength > 0x3c) reply_length = 0x3c;
                    usb_port_write_bytes((void code *)0x7ffc, 0x3c);
                } else if (desc_index == 3) {
                    if (request->wLength > 0x30) reply_length = 0x30;
                    usb_port_write_bytes((void code *)0x8038, 0x30);
                } else if (desc_index == 4) {
                    if (request->wLength > 0x28) reply_length = 0x28;
                    usb_port_write_bytes((void code *)0x8068, 0x28);
                } else if (desc_index == 7) {
                    if (request->wLength > 0x18) reply_length = 0x18;
                    usb_port_write_bytes((void code *)0x8090, 0x18);
                } else if (desc_index == 8) {
                    if (request->wLength > 0x3e) reply_length = 0x3e;
                    usb_port_write_bytes((void code *)0x80a8, 0x3e);
                } else {
                    /* Any other index: the same table as index 8. */
                    if (request->wLength > 0x3e) reply_length = 0x3e;
                    usb_port_write_bytes((void code *)0x80a8, 0x3e);
                }
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            } else if ((unsigned int)desc_type == DESC_TYPE_6) {
                if (request->wLength > 0x0a) reply_length = 0x0a;
                usb_port_write_bytes((void code *)0x8106, 0x0a);
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            } else if ((unsigned int)desc_type == DESC_TYPE_7) {
                if (request->wLength > 0x20) reply_length = 0x20;
                usb_port_write_bytes((void code *)0x8110, 0x20);
                usb_device_dma_transfer(reply_length, request->bmRequestType);
            }
            result = CX_RESULT_FINISH;
            break;
        case REQ_GET_STATUS:
            /* Two zero bytes from 0x8130. */
            reply_length = request->wLength;
            if (request->wLength > 2) reply_length = 2;
            usb_port_write_bytes((void code *)0x8130, 2);
            usb_device_dma_transfer(reply_length, request->bmRequestType);
            result = CX_RESULT_FINISH;
            break;
        case REQ_SET_CONFIGURATION:
            result = CX_RESULT_FINISH;
            break;
        }
    }
    /* 3. Close the request on the control endpoint. */
    switch (result) {
    case CX_RESULT_FINISH:
        reg_value = reg_window_read32(REG_CX);
        reg_value |= CX_FINISH;
        reg_window_set_bits32(REG_CX, reg_value);
        lib_printf517((void code *)FMT_CX_FINISH);
        break;
    case CX_RESULT_STALL:
        reg_value = reg_window_read32(REG_CX);
        reg_value |= CX_STALL;
        reg_window_set_bits32(REG_CX, reg_value);
        lib_printf517((void code *)FMT_CX_STALL);
        break;
    case CX_RESULT_IDLE:
        lib_printf517((void code *)FMT_CX_IDLE);
        break;
    }
}

extern unsigned int xdata usb_device_max_packet;
extern unsigned long xdata usb_mem_base;
void timer_delay_units(unsigned char n);

/* usb_device_dma_transfer: move piece by piece between the port memory and the control endpoint.
 *   piece:        bytes in all (the first piece size, cut to usb_device_max_packet per round)
 *   request_type: bmRequestType of the request; only bit 7 is used
 *
 * Caller: usb_device_answer_setup (all seven calls), each time right after usb_port_write_bytes has copied the
 * table to send.
 *
 * Phases, repeated per piece of at most usb_device_max_packet bytes until no bytes remain:
 *   1. Wait until DMA_BUSY in REG_DMA_CONTROL is clear (printing "fotg210: dma busy" once when it was set).
 *   2. Point REG_DMA_ADDRESS at the piece: usb_mem_base * 0x20 + offset.
 *   3. Prepare by request_type bit 7: set, wait for CX_BIT5 in REG_CX, wait one delay unit, REG_1C0 = 0x10 and the
 *      control value has DMA_BIT1 set; clear, REG_1C0 = 0x10, then up to 1000 delay units until the count in bits
 *      24..30 of REG_CX reaches the piece size (a larger count becomes the piece size), DMA_BIT1 clear.
 *   4. Start: REG_DMA_CONTROL = piece size << 8 with DMA_BIT1 as above, then DMA_BUSY set.
 *   5. Wait: up to 1000 reads of REG_GROUP2_STATUS; GRP2_DMA_DONE ends the piece well, GRP2_DMA_ERROR and the host
 *      events end it with their texts. The bit found is written back to the register.
 *   6. Unless GRP2_DMA_DONE came: REG_DMA_CONTROL = 0x18 and "fotg210: dma fail". Then REG_1C0 = 0 and the next
 *      piece starts usb_device_max_packet bytes further on. A failed piece is not repeated. */
void usb_device_dma_transfer(unsigned int piece, unsigned char request_type)
{
    unsigned char failed;
    unsigned long value;
    unsigned long tries;
    unsigned int remaining;
    unsigned int offset;
    remaining = piece;
    offset = 0;
    do {
        if (piece > usb_device_max_packet) piece = usb_device_max_packet;
        remaining -= piece;
        /* 1. Wait for the previous transfer. */
        if (reg_window_read32(REG_DMA_CONTROL) & DMA_BUSY) {
            lib_printf517((void code *)FMT_DMA_BUSY);
            while (reg_window_read32(REG_DMA_CONTROL) & DMA_BUSY) ;
        }
        /* 2. Port memory address of this piece. */
        reg_window_write32(REG_DMA_ADDRESS, usb_mem_base * 0x20 + offset);
        /* 3. Prepare by direction bit. */
        if (request_type & REQ_DIR_BIT) {
            while ((reg_window_read32(REG_CX) & CX_BIT5) != CX_BIT5) ;
            timer_delay_units(1);
            reg_window_write32(REG_1C0, REG_1C0_ON);
            value = piece << DMA_LENGTH_SHIFT;
            value |= DMA_BIT1;
        } else {
            reg_window_write32(REG_1C0, REG_1C0_ON);
            tries = DMA_TRIES;
            do {
                timer_delay_units(1);
                value = reg_window_read32(REG_CX) & CX_COUNT_MASK;
                value >>= 24;
            } while (--tries != 0 && value < piece);
            if (value > piece) piece = value;
            value = piece << DMA_LENGTH_SHIFT;
            value &= ~DMA_BIT1;
        }
        /* 4. Start the piece. */
        reg_window_write32(REG_DMA_CONTROL, value);
        value = reg_window_read32(REG_DMA_CONTROL);
        value |= DMA_BUSY;
        reg_window_write32(REG_DMA_CONTROL, value);
        /* 5. Wait for its end. */
        failed = 0xff;
        for (tries = 0; tries < DMA_TRIES; tries++) {
            value = reg_window_read32(REG_GROUP2_STATUS);
            if (value & GRP2_DMA_DONE) {
                failed = 0;
                reg_window_write32(REG_GROUP2_STATUS, GRP2_DMA_DONE);
                break;
            }
            if (value & GRP2_DMA_ERROR) {
                reg_window_write32(REG_GROUP2_STATUS, GRP2_DMA_ERROR);
                lib_printf517((void code *)FMT_DMA_ERROR);
                break;
            }
            if (value & GRP2_HOST_EVENTS) {
                reg_window_write32(REG_GROUP2_STATUS, GRP2_HOST_EVENTS);
                lib_printf517((void code *)FMT_DMA_RESET);
                break;
            }
        }
        /* 6. Report a failure, move on. */
        if (failed) {
            reg_window_write32(REG_DMA_CONTROL, DMA_FAIL_VALUE);
            lib_printf517((void code *)FMT_DMA_FAIL);
        }
        reg_window_write32(REG_1C0, 0);
        piece = remaining;
        offset += usb_device_max_packet;
    } while (remaining);
}
