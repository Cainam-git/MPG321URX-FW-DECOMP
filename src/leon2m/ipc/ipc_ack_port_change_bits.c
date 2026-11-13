/* ipc_ack_port_change_bits  (FUN_a01387a4)
 *
 * Ask the input processor to acknowledge the port change bits.
 * Note: Called by startup_main as the first task of every main-loop pass.
 * Name basis: derived - command 0x81 through the mailbox portal 1 sender; reads seven port records from the
 *   mailbox first; mailbox command 0x81, whose handler in the input program shows the meaning
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01387a4 @ 0xa01387a4-0xa0138ae8 (209 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - the debug test is a small static function dbg_on() ("if (dbg_is_print_enabled(level)) return 1; return 0;"),
 *    inlined. Its inlined return paths leave labels that stop GCC's first CSE pass from skipping around the
 *    debug-print block (-fcse-skip-blocks), so ack_byte keeps its own register (firmware 'mov %i4,%l1' +
 *    'stb %l1'). With a plain 'if (dbg_is_print_enabled(0x20))' the pass replaces ack_byte by the AND result.
 *    dbg_on() is used for all three prints (using it only for the last one gives the same code);
 *  - the end value is computed twice: unsigned int ack_bits = (unsigned char)(slot_count & changed_byte) for the
 *    test and the print, unsigned char ack_byte = slot_count & changed_byte for the command byte; slot_count
 *    takes ack_mask first, which gives the firmware's operand order of the AND;
 *  - the unused four-word array unused_words is cleared together with descriptor.
 */
extern void *memset(void *, int, unsigned int);

/* What the main program keeps of one input port of the input processor (16 bytes). The fields from colour_space
   on carry the input program's port record fields of the same name (ipc_build_port_descriptor there). */
struct port_template
{
  unsigned char type;               /* +0: link state of the input program's port record */
  unsigned char colour_space;       /* +1 */
  unsigned short htotal;            /* +2 */
  unsigned short vtotal;            /* +4 */
  unsigned short hactive;           /* +6 */
  unsigned short vactive;           /* +8 */
  unsigned short pixel_clock;       /* +0xA */
  unsigned char flags;              /* +0xC: the input program's published_flags */
  unsigned char byte_0xd;           /* +0xD: its byte +0xE */
  unsigned char byte_0xe;           /* +0xE: bits 0..4 of its byte +0x12 */
  unsigned char byte_0xf;
};

/* Mailbox portal 1 (the input processor): slot 0 holds the status words, slots 1..7 one port descriptor each. */
#define IPC_PORTAL_INPUT_CPU        1
#define SLOT0_STATUS_WORDS          0       /* word 0 bits 4..31: link state of port records 0..6, one nibble each */
#define SLOT0_CHANGE_WORD           0xc     /* word 3: bits 16..23 = changed bit of slot 1..7's port */
#define PORT_SLOT_COUNT             7
#define PORT_ID_LAST                9       /* port ids run 1..9 (port record = id - 1) */

#define LINK_STATE_POWER_ON         2       /* the input program's link states ('PHY_POWERON') */
#define LINK_STATE_READY            5

#define IPC_CMD_ACK_PORT_CHANGE     0x81    /* input program: clear these bits of slot 0 word 3, byte 2 */
#define IPC_CMD_DATA_BYTES          0xc

#define DBG_MAILBOX                 0x20    /* debug class of the mailbox prints */

extern struct port_template input_port_templates[];
extern unsigned char ipc_input_cpu_port_nibbles[];
extern unsigned char ipc_port_descriptor_dumped_flag;
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern unsigned char dbg_is_print_enabled(unsigned int level);
extern int dbg_printf();
extern void ipc_send_command();
extern void ipc_8051_tx_queue_flush(void);
extern void ipc_8051_poll_messages(void);

static int dbg_on(unsigned int level)
{
  if (dbg_is_print_enabled(level))
    return 1;
  return 0;
}

/*
 * The first task of each pass of the main loop (startup_main). It services the mailboxes and takes the input port
 * state the input processor publishes (ipc_publish_port_status in the input program), then acknowledges the port
 * changes it has taken.
 *
 * Phases:
 *   1. 8051 mailbox: move queued messages into free slots (ipc_8051_tx_queue_flush) and decode an arrived message
 *      (ipc_8051_poll_messages).
 *   2. Read the link state nibbles of slot 0 word 0 into the type of templates 0..6.
 *   3. Read the changed bits (slot 0 word 3, bits 16..23).
 *   4. For slot 1..7: read its descriptor. It is taken only when its port id (byte 0) equals the id the main program
 *      assigned to that slot (ipc_input_cpu_port_nibbles) and lies in 1..9. Flags and byte_0xd are copied to the
 *      template of that port (id - 1). When the template's type is LINK_STATE_READY all fields are copied; if the
 *      slot's changed bit is set, the type becomes LINK_STATE_POWER_ON and the slot is counted for the
 *      acknowledge. A port in any other state is counted for the acknowledge at once. The first descriptor of a
 *      READY port ever taken is also printed word by word (when the debug class is on; the once-flag is set
 *      either way).
 *   5. When changed bits are set and counted slots meet them, print the common bits and send them with command
 *      0x81, which clears them in the input program's status word.
 */
void ipc_ack_port_change_bits(void)
{
  unsigned short slot_numbers[7];
  unsigned int unused_words[4];
  unsigned int descriptor[4];
  unsigned int slot0[4];
  unsigned char command_data[12];
  unsigned int change_word;
  unsigned short ack_mask = 0;      /* bit i: slot i + 1 may be acknowledged */
  unsigned short changed_bits;
  unsigned char changed_byte;
  unsigned char i;
  unsigned char j;
  unsigned int ack_bits;
  unsigned char template_index;
  unsigned char ack_byte;
  unsigned char slot_count = 7;     /* reused for the acknowledge mask at the end */
  struct port_template *template;

  /* Phase 1. */
  ipc_8051_tx_queue_flush();
  ipc_8051_poll_messages();

  slot_numbers[0] = 1;
  slot_numbers[1] = 2;
  slot_numbers[2] = 3;
  slot_numbers[3] = 4;
  slot_numbers[4] = 5;
  slot_numbers[5] = 6;
  slot_numbers[6] = 7;
  for (i = 0; i < 4; i++)
  {
    unused_words[i] = 0;
    descriptor[i] = 0;
  }

  /* Phase 2: link states, nibble i + 1 of slot 0 word 0 for port record i. */
  ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, SLOT0_STATUS_WORDS, slot0, 4);
  for (i = 0; i < slot_count; i++)
  {
    input_port_templates[i].type = ((slot0[0] >> 4) >> (i * 4)) & 0xf;
  }

  /* Phase 3. */
  ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, SLOT0_CHANGE_WORD, &change_word, 1);
  changed_bits = (unsigned char) (change_word >> 16);
  changed_byte = changed_bits;

  /* Phase 4: the port descriptors. */
  for (i = 0; i < PORT_SLOT_COUNT; i++)
  {
    ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, (unsigned char) (slot_numbers[i] << 4), descriptor, 4);
    if ((((unsigned char) descriptor[0]) != ipc_input_cpu_port_nibbles[i]) || ((ipc_input_cpu_port_nibbles[i] - 1U) > PORT_ID_LAST - 1))
    {
      continue;
    }
    template_index = descriptor[0] - 1;
    template = &input_port_templates[template_index];
    template->flags = descriptor[0] >> 8;
    template->byte_0xd = descriptor[0] >> 16;
    if (input_port_templates[template_index].type == LINK_STATE_READY)
    {
      template->colour_space = descriptor[1];
      template->byte_0xe = (descriptor[1] >> 8) & 0x1f;
      template->htotal = descriptor[1] >> 16;
      template->vtotal = descriptor[2];
      template->hactive = descriptor[2] >> 16;
      template->vactive = descriptor[3];
      template->pixel_clock = descriptor[3] >> 16;
      if ((changed_bits >> i) & 1)
      {
        input_port_templates[template_index].type = LINK_STATE_POWER_ON;
        ack_mask |= 1 << i;
      }
      /* Dump the descriptor words once, the first time. */
      if (ipc_port_descriptor_dumped_flag == 0)
      {
        ipc_port_descriptor_dumped_flag = 1;
        for (j = 0; j < 4; j++)
        {
          if (dbg_on(DBG_MAILBOX))
            {
              dbg_printf("\n ulMailBoxData[%d] ", j);
            }
          if (dbg_on(DBG_MAILBOX))
            {
              dbg_printf("   %08lX", descriptor[j]);
            }
        }

      }
    }
    else
    {
      ack_mask |= 1 << i;
    }
  }

  /* Phase 5: acknowledge the changed bits that were taken. */
  if (changed_bits != 0)
  {
    if (ack_mask != 0)
    {
      slot_count = ack_mask;
      ack_bits = (unsigned char) (slot_count & changed_byte);
      ack_byte = slot_count & changed_byte;
      if (ack_bits != 0)
      {
        if (dbg_on(DBG_MAILBOX))
          dbg_printf("updatedflag %d\r\n", ack_bits);
        memset(command_data, 0, IPC_CMD_DATA_BYTES);
        command_data[0] = ack_byte;
        ipc_send_command(IPC_CMD_ACK_PORT_CHANGE, IPC_CMD_DATA_BYTES, command_data, 0);
      }
    }
  }
}
