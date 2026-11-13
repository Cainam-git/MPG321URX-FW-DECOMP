/* input_load_port_template  (FUN_a0136d20)
 *
 * Copy the port template received from the input processor into a port entry.
 * Name basis: derived - template flag bit 2 becomes entry bit 4; called by input_refresh_port_entries from the
 *   main loop
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0136d20 @ 0xa0136d20, flags -mcpu=v8 -O3 -g.
 * Source form: the first halfword of the entry is a bitfield struct; the type and the flag bits are written
 * through port_entries[port] (the other field copies go through a pointer local, 'entry'); template flag 5 is
 * written with an explicit '& 1' ('(flags >> 5) & 1'), without it gcc drops the 'and' and the registers rotate.
 */
/* A port template: 16 bytes sent by the input processor, at input_port_templates + 16 * index. */
struct port_template {
    unsigned char type;         /* +0 */
    unsigned char byte_1;       /* +1 */
    unsigned short word_2, word_4, word_6, word_8, word_a;  /* +2..+0xb */
    unsigned char flags;        /* +0xc: eight flags, spread into the entry by input_load_port_template */
    unsigned char byte_0xd;
    unsigned char byte_0xe;
    unsigned char byte_0xf;
};

/* A port entry, 18 bytes at port_entries + 18 * port. Halfword 0 holds the class and the flag bits. */
struct port_entry {
    unsigned short type:4;          /* halfword 0 bits 15..12: the class of the entry */
    unsigned short bits_11_to_7:5;  /* bits 11..7, not touched here */
    unsigned short flag_from_bit0:1;    /* bit 6, template flags bit 0 */
    unsigned short flag_from_bit1:1;    /* bit 5 */
    unsigned short flag_from_bit2:1;    /* bit 4 */
    unsigned short flag_from_bit3:1;    /* bit 3 */
    unsigned short flag_from_bit4:1;    /* bit 2 */
    unsigned short flag_from_bit6:1;    /* bit 1 */
    unsigned short flag_from_bit7:1;    /* bit 0 */
    unsigned short template_flag_5:1;   /* halfword +2 bit 15, template flags bit 5 */
    unsigned short rest_of_halfword_2:7;
    unsigned char byte_0x3;
    unsigned char byte_0x4, byte_0x5;
    unsigned short word_6, word_8, word_a, word_c, word_e;
    unsigned short word_10;
};
extern struct port_template input_port_templates[];
extern struct port_entry port_entries[];

/*
 * Copy port template 'port + 2' (ports 0..3 use the templates 2..5; any other value would use template 0)
 * into port entry 'port'. The templates are the ones the input processor sent (ipc_ack_port_change_bits);
 * the entries are what the control logic reads.
 *
 * Entry from template:
 *   class (bits 15..12 of halfword 0) = template byte 0;
 *   entry byte +4 = template byte 1; entry words +6, +8, +0xa, +0xc, +0xe = template words +2, +4, +6, +8, +0xa;
 *   entry byte +5 = template byte 0xe; entry byte +3 = template byte 0xd;
 *   template flags byte (+0xc), one flag each: bits 0, 1, 2, 3, 4 go to entry halfword 0 bits 6, 5, 4, 3, 2,
 *   bit 5 to halfword +2 bit 15, bits 6 and 7 to halfword 0 bits 1 and 0. Bits 11..7 of halfword 0 stay as they were.
 * No result. Called only by input_refresh_port_entries, once for each of the ports 0..3.
 */
void input_load_port_template(unsigned char port)
{
    unsigned char template_index;
    struct port_template *tmpl;
    struct port_entry *entry;

    template_index = 0;
    switch (port) {
    case 0: template_index = 2; break;
    case 1: template_index = 3; break;
    case 2: template_index = 4; break;
    case 3: template_index = 5; break;
    }
    port_entries[port].type = input_port_templates[template_index].type;
    tmpl = &input_port_templates[template_index];
    entry = &port_entries[port];
    entry->byte_0x4 = tmpl->byte_1;
    entry->word_6 = tmpl->word_2;
    entry->word_8 = tmpl->word_4;
    entry->word_a = tmpl->word_6;
    entry->word_c = tmpl->word_8;
    entry->word_e = tmpl->word_a;
    entry->byte_0x5 = tmpl->byte_0xe;
    port_entries[port].flag_from_bit0 = tmpl->flags;
    port_entries[port].flag_from_bit1 = tmpl->flags >> 1;
    port_entries[port].flag_from_bit2 = tmpl->flags >> 2;
    port_entries[port].flag_from_bit3 = tmpl->flags >> 3;
    port_entries[port].flag_from_bit4 = tmpl->flags >> 4;
    port_entries[port].template_flag_5 = (tmpl->flags >> 5) & 1;
    port_entries[port].flag_from_bit6 = tmpl->flags >> 6;
    port_entries[port].flag_from_bit7 = tmpl->flags >> 7;
    entry->byte_0x3 = tmpl->byte_0xd;
}
