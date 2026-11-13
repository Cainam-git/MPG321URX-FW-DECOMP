/* sys_output_record_clear_flags  (FUN_a012baf0)
 *
 * Clear the 16-bit flags of an output record.
 * Name basis: descriptive - halfword +0x1C of the 0x24-byte records at 0xA802D8DC; unused
 *
 * Matching notes
 * --------------
 * FUN_a012baf0 (leon2m 0xa012baf0-0xa012bb14, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
/* Output record (0x24 bytes, table sys_output_records): only the flag halfword at +0x1c is named here. */
struct output_record
{
  unsigned char pad0[0x1c];
  unsigned short request_flags;                 /* +0x1c: the flag halfword sent in output messages */
  unsigned char pad1e[6];
};
extern struct output_record sys_output_records[];

/* Clear the flag halfword (+0x1c) of output record index. Not called by name anywhere in the source. */
void sys_output_record_clear_flags(unsigned char index)
{
    sys_output_records[index].request_flags = 0;
}
