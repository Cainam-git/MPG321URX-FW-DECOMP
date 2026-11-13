/* panel_layer_stream_data  (FUN_a0110d64)
 *
 * Stream a block of data words into the stream register of both halves.
 * Name basis: descriptive - table byte, 0x14 and a mode word first; registers 0xD0030400 / 0xD0038400; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0110d64 @ 0xa0110d64-0xa0110f44 (480 bytes). Flags -mcpu=v8 -O3 -g.
 * Source form: each switch case writes both registers with its constant (the firmware's per-case address set-up
 * and shared store tail); the loop limit (word_count >> 2) is kept in a local; each data word is read twice.
 */
#define REG(address) (*(volatile unsigned int *)(address))

/* The two register sets (first 0xD0030000, second 0xD0038000) receive the same values. */
#define STREAM_COMMAND_REGISTER   0xd003b000    /* written with 0x40, then polled until it reads 0 */
#define STREAM_COMMAND            0x40
#define STREAM_WAIT_TICKS         100

/* The block to send. */
struct stream_block {
    unsigned short length;      /* +0: size of the data in bytes; length / 4 words are sent */
    unsigned char unit_byte;    /* +2: written to register 0x404 of both sets */
    unsigned char pad3;
    unsigned int *data;         /* +4: the data words */
};
extern unsigned char panel_layer_update_strobe_enabled;
extern unsigned short timer_get_ticks16(void);

/*
 * Send the words of a block to register 0x408 of both register sets, once to each set with the same word.
 *   1. Write the block's byte at +2 to register 0x404 and 0x14 to register 0x410 of both sets.
 *   2. For mode 0, 1, 2 or 3 write 0x03210000, 0x10320000, 0x21030000 or 0x32100000 to register 0x420 of both sets;
 *      any other mode writes nothing.
 *   3. If panel_layer_update_strobe_enabled is 1: write 0x40 to 0xD003B000 and wait until it reads 0 or 100 ticks have
 *      passed.
 *   4. Send length / 4 words.
 *   5. Write 0x32100000 to register 0x420 of both sets and, if panel_layer_update_strobe_enabled is 1, repeat step 3.
 * No routine in the image calls it.
 */
void panel_layer_stream_data(struct stream_block *block, unsigned char mode)
{
    unsigned int i, word_count;
    unsigned short start_ticks;

    REG(0xd0030404) = block->unit_byte;
    REG(0xd0038404) = block->unit_byte;
    REG(0xd0030410) = 0x14;
    REG(0xd0038410) = 0x14;
    switch (mode) {
    case 0: REG(0xd0030420) = 0x3210000; REG(0xd0038420) = 0x3210000; break;
    case 1: REG(0xd0030420) = 0x10320000; REG(0xd0038420) = 0x10320000; break;
    case 2: REG(0xd0030420) = 0x21030000; REG(0xd0038420) = 0x21030000; break;
    case 3: REG(0xd0030420) = 0x32100000; REG(0xd0038420) = 0x32100000; break;
    }
    if (panel_layer_update_strobe_enabled == 1) {
        REG(STREAM_COMMAND_REGISTER) = STREAM_COMMAND;
        start_ticks = timer_get_ticks16();
        while (REG(STREAM_COMMAND_REGISTER) != 0 && (unsigned short)(timer_get_ticks16() - start_ticks) < STREAM_WAIT_TICKS)
            ;
    }
    word_count = block->length >> 2;
    for (i = 0; i < word_count; i++) {
        REG(0xd0030408) = block->data[i];
        REG(0xd0038408) = block->data[i];
    }
    REG(0xd0030420) = 0x32100000;
    REG(0xd0038420) = 0x32100000;
    if (panel_layer_update_strobe_enabled == 1) {
        REG(STREAM_COMMAND_REGISTER) = STREAM_COMMAND;
        start_ticks = timer_get_ticks16();
        while (REG(STREAM_COMMAND_REGISTER) != 0 && (unsigned short)(timer_get_ticks16() - start_ticks) < STREAM_WAIT_TICKS)
            ;
    }
}
