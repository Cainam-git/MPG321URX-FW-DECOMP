/* HDMI21RX2PacketSwitch  (FUN_a00a8508)
 *
 * Write one packet-forwarding selection of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver
 *   sel: selection 0..2
 *   data: 4 bytes
 * Name basis: proven - original name printed ('HDMI21RX2PacketSwitch WRONG selection!!!'); selections 0..2 =
 *   words 0xA8/0xAC, 0xE8, 0xEC
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8508, flags -mcpu=v8 -Os -g.
 * Source form: the read-modify-write is an inlined helper that reads the register into a local, combines
 * '(v & ~mask) | val' into it and stores it back. The values are built in a zeroed local pair first. The
 * register block is reached through a volatile pointer in the receiver record.
 */
struct hdmi_rx21_reg_blocks { unsigned char pad[0x30]; volatile unsigned int *block12; };
struct switch_words { unsigned int first; unsigned int second; };
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern int dbg_printf(const char *, ...);

/* Replace the bits of *reg that are in `mask` by `bits` (bits outside the mask are ORed in unchanged). */
static inline void modify_bits(volatile unsigned int *reg, unsigned int mask, unsigned int bits)
{
    unsigned int value = *reg;

    value = (value & ~mask) | bits;
    *reg = value;
}

/*
 * Write one packet-forwarding selection of an HDMI 2.1 receiver. The four bytes in `data` go to these words
 * of the receiver's register block 12 (the pointer at +0x30 of its record in hdmi_rx21_reg_blocks):
 *   selection 0: word 0xA8 gets data[0] in bits 31..29 (mask 0xE0000000);
 *                word 0xAC gets data[1], data[2], data[3] as bytes 0..2 (mask 0x3FFFFF);
 *   selection 1: word 0xE8 gets the four bytes as one little-endian word (mask 0x3FFFFFE0);
 *   selection 2: word 0xEC, the same way.
 * Any other selection only prints the "WRONG selection" text.
 *   port: HDMI 2.1 receiver
 *   sel:  selection 0..2
 *   data: 4 bytes
 */
void HDMI21RX2PacketSwitch(unsigned char port, unsigned char sel, unsigned char *data)
{
    struct switch_words words = { 0, 0 };

    switch (sel) {
    case 0:
        words.first = data[0] << 24;
        words.second = data[1] | data[2] << 8 | data[3] << 16;
        modify_bits(&ARR_a807db00[port].block12[0xa8 / 4], 0xe0000000, words.first);
        modify_bits(&ARR_a807db00[port].block12[0xac / 4], 0x3fffff, words.second);
        break;
    case 1:
        words.first = data[0] | data[1] << 8 | data[2] << 16 | data[3] << 24;
        modify_bits(&ARR_a807db00[port].block12[0xe8 / 4], 0x3fffffe0, words.first);
        break;
    case 2:
        words.first = data[0] | data[1] << 8 | data[2] << 16 | data[3] << 24;
        modify_bits(&ARR_a807db00[port].block12[0xec / 4], 0x3fffffe0, words.first);
        break;
    default:
        dbg_printf("HDMI21RX2PacketSwitch WRONG selection!!!");
        break;
    }
}
