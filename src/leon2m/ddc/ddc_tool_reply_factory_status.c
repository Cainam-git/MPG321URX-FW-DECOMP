/* ddc_tool_reply_factory_status  (FUN_a00d1184)
 *
 * Fill the factory tool reply with the factory mode or burn-in state.
 *   req: request
 *   p: reply
 * Note: Uncalled copy of the 0xAA arm; request byte 7 picks bit 14 of settings word +0, Burn In byte
 *   0xA802D465 or 0xA802D466.
 * Name basis: derived - glossary: 0xA802D465 = Burn In
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1184 (0xa00d1184-0xa00d1220, 156 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain on req[7]; the checksum is a static helper inlined here.
 */
extern unsigned int user_settings;              /* settings word +0 (docs/RECORDS.md) */
extern unsigned char user_settings_burn_in_flag, user_settings_fast_uph;

#define DDC_CHECKSUM_SEED               0x50    /* first value of the reply XOR checksum */
#define DDC_LENGTH_MASK                 0x7f
#define TOOL_RESULT_BAD_VALUE           0xe4    /* a request value without an answer */
#define SETTINGS_WORD0_FACTORY_MODE_BIT 14

/* XOR of the seed and reply bytes 0 .. (byte 1 & 0x7F) + 1 (same as ddc_tool_calc_checksum). */
static unsigned char tool_checksum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & DDC_LENGTH_MASK) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

/*
 * Answer in byte 7 with the value that request byte 7 asks for, and store the checksum in byte 8:
 *   0  the factory mode bit (bit 14 of settings word +0), 0 or 1
 *   1  the Burn In flag (user_settings_burn_in_flag)
 *   2  the settings byte at user_settings_fast_uph (+0x1D6)
 *   other  TOOL_RESULT_BAD_VALUE
 *
 *   req  the tool request
 *   p    the reply
 *
 * Nothing calls this copy; ddc_tool_build_reply has the same body for its answer kind 0xAA.
 */
void ddc_tool_reply_factory_status(const unsigned char *req, unsigned char *p)
{
    if (req[7] == 0)
        p[7] = (user_settings >> SETTINGS_WORD0_FACTORY_MODE_BIT) & 1;
    else if (req[7] == 1)
        p[7] = user_settings_burn_in_flag;
    else if (req[7] == 2)
        p[7] = user_settings_fast_uph;
    else
        p[7] = TOOL_RESULT_BAD_VALUE;
    p[8] = tool_checksum(p, DDC_CHECKSUM_SEED);
}
