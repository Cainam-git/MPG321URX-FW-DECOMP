/* sys_output_record_set_word14  (FUN_a012bb14)
 *
 * Store a word in an output record.
 * Name basis: descriptive - word +0x14 of the 0x24-byte records; unused
 *
 * Matching notes
 * --------------
 * FUN_a012bb14 (leon2m 0xa012bb14-0xa012bb38, 36 bytes, leaf), flags -mcpu=v8 -O3 -g.
 */
/* Output record (0x24 bytes, table sys_output_records): only the word at +0x14 is named here. */
struct output_record
{
  unsigned char pad0[0x14];
  unsigned int word_0x14;
  unsigned char pad18[4];
  unsigned short request_flags;                 /* +0x1c */
  unsigned char pad1e[6];
};
extern struct output_record sys_output_records[];

/* Store value in the word at +0x14 of output record index. Not called by name anywhere in the source. */
void sys_output_record_set_word14(unsigned char index, unsigned int value)
{
    sys_output_records[index].word_0x14 = value;
}
