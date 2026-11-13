/* sys_api_get_channel_port_flag6  (FUN_a01438dc)
 *
 * Return flag bit 6 of the port record that a channel is mapped to.
 * Returns: 0 or 1
 * Name basis: descriptive - prints 'SYS remapping channel OOR' for channels above 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01438dc @ 0xa01438dc-0xa014398c (44 words), flags -mcpu=v8 -O3 -g.
 * Same remap helper as src/leon2m/sys/sys_api_get_channel_flag28.c.
 * Source form: unsigned char index (the firmware masks with 0xff after the remap), struct records
 * (0x78-byte channel, 0x2a-byte port), unsigned char return. Aids: none.
 */
/* Channel record (0x78 bytes); only the status word at +0 is used here (port = bits 12..15). */
struct channel_record { unsigned int status_word; unsigned char pad[0x74]; };
/* Port record (0x2a bytes); only the status halfword at +0 is used here. */
struct port_record { unsigned short status; unsigned char rest[0x28]; };
extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern int dbg_printf();

/* Return ch for 0..3, else -1. */
static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

/* Return bit 6 of the status halfword of the port record that channel ch is on. A channel above 3
 * prints "SYS remapping channel OOR" and is treated as channel 0. */
unsigned char sys_api_get_channel_port_flag6(unsigned char ch)
{
    unsigned char i = remap(ch);
    if (i > 3) { dbg_printf("SYS remapping channel OOR\r\n"); i = 0; }
    return (port_records[(channel_records[i].status_word >> 12) & 0xf].status >> 6) & 1;
}
