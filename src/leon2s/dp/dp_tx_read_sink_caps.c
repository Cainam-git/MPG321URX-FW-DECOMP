/* dp_tx_read_sink_caps  (FUN_a008686c)
 *
 * Read the sink's DPCD capabilities and store rate, lanes and options.
 *   port: output
 * Name basis: proven - 16 bytes from DPCD 0x000 (and 0x2200 extended caps); rate codes 6/0x0A/0x14/0x1E
 *   checked
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008686c @ 0xa008686c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the first copies go through a row pointer (rec); later accesses index the record array again;
 *  - byte 5 (CAPS_AUX_WAIT) is read through the inlined static helper caps_aux_wait;
 *  - the valid bit is a 1-bit field of a union view of the record, stored from
 *    'unsigned char valid = mask & caps_ok' with the unsigned int mask = -(status == 0) computed first;
 *  - the rate and lane tests keep their compare forms ((unsigned char)(x - 31) <= 9, nested ifs,
 *    (unsigned char)(x - 1) > 1 && x != 4).
 */

/* Sink capability record of a DP output (dp_tx_sink_caps_records, 6 bytes each; filled with defaults by
   dp_tx_init_sink_caps). Byte offsets: */
#define CAPS_FLAGS      0       /* flag bits, see below */
#define CAPS_REV        1       /* revision byte (address 0 of the sink) */
#define CAPS_MAX_RATE   2       /* link rate code */
#define CAPS_MAX_LANES  3       /* lane count */
#define CAPS_BYTE4      4       /* address 3 of the sink */
#define CAPS_AUX_WAIT   5       /* training wait value (dp_tx_train_clock_recovery) */

/* Bits of CAPS_FLAGS set here. */
#define CAPS_BIT1       0x02    /* bit 1 of the byte at address 0x21 */
#define CAPS_BIT2       0x04    /* bit 0 of the byte at address 0x21 */
#define CAPS_BIT3       0x08    /* bit 6 of the byte at address 7 */
#define CAPS_BIT4       0x10    /* bit 7 of the lane byte; dp_tx_write_link_config and dp_tx_set_lane_count test it */
#define CAPS_BIT5       0x20    /* bit 7 of CAPS_BYTE4 */
#define CAPS_BIT6       0x40    /* bit 6 of the lane byte */
#define CAPS_VALID      0x80    /* every read and check passed */

/* Link rate codes (as dp_tx_limits_others). */
#define LINK_RATE_RBR   0x06
#define LINK_RATE_HBR   0x0a
#define LINK_RATE_HBR2  0x14
#define LINK_RATE_HBR3  0x1e

#define AUX_CMD_READ    0x90    /* AUX command of the reads here (dp_tx_write_link_config writes with 0x80) */
#define CAPS_ADDRESS    0x0000  /* first capability block of the sink */
#define CAPS_ADDRESS_2  0x2200  /* second block, read when bit 7 of the byte at address 0xE is set */
#define CAPS_READ_COUNT 0xf     /* count argument: 16 bytes */
#define SINK_ADDR_7     7       /* index in the read block = sink address */
#define SINK_ADDR_E     14
#define SINK_ADDR_21    0x21

union dp_tx_caps_record {
    unsigned char bytes[6];
    struct { unsigned char valid : 1, bit6 : 1, bit5 : 1, bit4 : 1, bit3 : 1, bit2 : 1, bit1 : 1, bit0 : 1; } flags;
};

extern union dp_tx_caps_record dp_tx_sink_caps_records[];
extern unsigned char dp_tx_aux_request_copy(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);
extern unsigned char dp_tx_aux_read_byte(unsigned int, unsigned int, unsigned int, unsigned char *);

static inline unsigned char caps_aux_wait(unsigned char p)
{
  return dp_tx_sink_caps_records[p].bytes[CAPS_AUX_WAIT];
}

/*
 * Read the capabilities of the sink on a DP output over AUX and store them, checked, in the output's caps record.
 *
 *   port  link output
 *
 * Called by dp_tx_run_hpd_actions when its steps include TODO_READ_CAPS (set after a plug on output 0 and when
 * the link was found lost). The valid bit (CAPS_VALID) ends up set only when every read succeeded and the rate code and
 * lane count needed no correction.
 *
 * Phases:
 *   1. Read 16 bytes from address 0: revision, rate code, lane byte and byte 3 go to bytes 1..4, the low 7 bits
 *      of the byte at address 0xE to the wait value.
 *   2. When bit 7 of that byte is set, read 16 bytes from address 0x2200 and keep the larger of each of the
 *      first three values; the wait value takes the new byte (all 8 bits) when its low 7 bits are larger.
 *   3. Rate code: 31..40 becomes HBR3; anything other than RBR, HBR, HBR2, HBR3 becomes RBR (a failure).
 *   4. Flags from the lane byte and byte 4; the lane count is the low 5 bits and must be 1, 2 or 4, otherwise it
 *      becomes 1 (a failure).
 *   5. Wait value: 1..4 becomes 4 times that, anything else 1. Flag bit 3 from bit 6 of the byte at address 7.
 *   6. Read the byte at address 0x21: flag bits 2 and 1 from its bits 0 and 1; set the valid bit.
 */
void dp_tx_read_sink_caps(unsigned char port)
{
  unsigned char reply[16] = {0};
  unsigned char read_ok;
  unsigned char caps_ok;
  unsigned char value;
  unsigned int addr_e_byte;
  unsigned char *rec;

  /* 1. First capability block. */
  read_ok = dp_tx_aux_request_copy(port, AUX_CMD_READ, CAPS_ADDRESS, CAPS_READ_COUNT, reply) != 0;
  addr_e_byte = reply[SINK_ADDR_E];
  rec = dp_tx_sink_caps_records[port].bytes;
  rec[CAPS_REV] = reply[0];
  rec[CAPS_MAX_RATE] = reply[1];
  rec[CAPS_MAX_LANES] = reply[2];
  rec[CAPS_BYTE4] = reply[3];
  rec[CAPS_AUX_WAIT] = addr_e_byte & 0x7f;
  caps_ok = read_ok;

  /* 2. Second block: take the larger values. */
  if (addr_e_byte & 0x80)
  {
    if (dp_tx_aux_request_copy(port, AUX_CMD_READ, CAPS_ADDRESS_2, CAPS_READ_COUNT, reply) == 0)
    {
      caps_ok = 0;
    }
    if (reply[0] > dp_tx_sink_caps_records[port].bytes[CAPS_REV])
    {
      dp_tx_sink_caps_records[port].bytes[CAPS_REV] = reply[0];
    }
    if (reply[1] > dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE])
    {
      dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE] = reply[1];
    }
    if (reply[2] > dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES])
    {
      dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES] = reply[2];
    }
    if ((reply[SINK_ADDR_E] & 0x7f) > caps_aux_wait(port))
    {
      dp_tx_sink_caps_records[port].bytes[CAPS_AUX_WAIT] = reply[SINK_ADDR_E];
    }
  }

  /* 3. Rate code. */
  if (((unsigned char) (dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE] - 31)) <= 9)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE] = LINK_RATE_HBR3;
  }
  value = dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE];
  if ((value != LINK_RATE_RBR) && (value != LINK_RATE_HBR))
  {
    if (value != LINK_RATE_HBR2)
    {
      if (value != LINK_RATE_HBR3)
      {
        dp_tx_sink_caps_records[port].bytes[CAPS_MAX_RATE] = LINK_RATE_RBR;
        caps_ok = 0;
      }
    }
  }

  /* 4. Flags from the lane byte and byte 4, then the lane count. */
  if (((signed char) dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES]) < 0)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] |= CAPS_BIT4;
  }
  else
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] &= ~CAPS_BIT4;
  }
  if (dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES] & 0x40)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] |= CAPS_BIT6;
  }
  else
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] &= ~CAPS_BIT6;
  }
  if (((signed char) dp_tx_sink_caps_records[port].bytes[CAPS_BYTE4]) < 0)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] |= CAPS_BIT5;
  }
  else
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] &= ~CAPS_BIT5;
  }
  value = dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES] & 0x1f;
  dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES] = value;
  if ((((unsigned char) (value - 1)) > 1) && (value != 4))
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_MAX_LANES] = 1;
    caps_ok = 0;
  }

  /* 5. Wait value and flag bit 3. */
  value = caps_aux_wait(port);
  if (((unsigned char) (value - 1)) <= 3)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_AUX_WAIT] = value << 2;
  }
  else
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_AUX_WAIT] = 1;
  }
  if (reply[SINK_ADDR_7] & 0x40)
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] |= CAPS_BIT3;
  }
  else
  {
    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] &= ~CAPS_BIT3;
  }

  /* 6. The byte at address 0x21 (dp_tx_aux_read_byte returns 0 on success), then the valid bit. */
  value = dp_tx_aux_read_byte(port, AUX_CMD_READ, SINK_ADDR_21, reply);
  {
    unsigned int mask = -(value == 0);
    unsigned char valid = mask & caps_ok;

    dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] = (dp_tx_sink_caps_records[port].bytes[CAPS_FLAGS] & (~(CAPS_BIT1 | CAPS_BIT2))) | ((reply[0] & 1) << 2) | (reply[0] & 2);
    dp_tx_sink_caps_records[port].flags.valid = valid;
  }
}
