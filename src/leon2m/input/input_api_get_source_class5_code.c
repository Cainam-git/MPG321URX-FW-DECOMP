/* input_api_get_source_class5_code  (FUN_a0143bc4)
 *
 * Return 2 when the port entry of a source has class 5, else 0.
 * Returns: 2 or 0
 * Name basis: descriptive - class field of the port entry; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0143bc4 @ 0xa0143bc4-0xa0143c14, flags -mcpu=v8 -O3 -g (cflags in symbols/leon2m.json).
 * Source form the exact build depends on: the two callees are declared without prototypes and their results are
 * masked to a byte; the answer is a byte local that is 0 or 2.
 */

extern unsigned char port_entries;      /* first port entry; 0x12 bytes per entry */
extern int input_port_table_find_code();
extern int input_find_port_entry_by_bus_id();

#define PORT_ENTRY_SIZE  0x12
#define PORT_CLASS_SHIFT 12             /* class: bits 12-15 of the entry's first halfword */

/*
 * Return 2 when the port entry of a source has class 5, else 0.
 *
 *   source  the source (the port code of a port table row, as input_port_table_find_code takes it)
 *
 * The source is turned into an input index (input_port_table_find_code), that into an entry
 * (input_find_port_entry_by_bus_id).
 */
unsigned int input_api_get_source_class5_code(unsigned int source)
{
  unsigned int entry;
  unsigned char result;

  entry = input_port_table_find_code(source & 0xff);
  entry = input_find_port_entry_by_bus_id(entry & 0xff) & 0xff;
  result = 0;
  if (*(unsigned short *)(&port_entries + (entry & 0xff) * PORT_ENTRY_SIZE) >> PORT_CLASS_SHIFT == 5) {
    result = 2;
  }
  return result;
}
