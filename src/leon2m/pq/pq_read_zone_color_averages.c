/* pq_read_zone_color_averages  (FUN_a0150df8)
 *
 * Read 16 rows of 16 colour averages through the memory port into the three zone average tables.
 * Note: Nothing is uploaded: each row is read from region 0x18 + 0x30 + 0x78 * row by
 *   sys_mem_port_read_rgb_sums.
 * Name basis: derived - sys_mem_port_read_rgb_sums fills 16 entries of each table per row;
 *   pq_average_zone_color reads the tables as a 16 x 16 grid for the crosshair colour; called from
 *   sys_main_loop_periodic_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0150df8 @ 0xa0150df8-0xa0150e80 (136 bytes incl. the trailing nop), flags -mcpu=v8 -O3 -g.
 * Source form: the byte offset is its own unsigned short loop variable, initialised and stepped before the row
 * counter ('for (offset = 0, row = 0; row < 16; offset += 16, row++)').
 */
extern unsigned char pq_zone_averages_blue[], pq_zone_averages_green[], pq_zone_averages_red[];
extern void sys_mem_port_enable(unsigned char);
extern void sys_latch_status_state(unsigned char);
extern void sys_mem_port_read_rgb_sums(unsigned int, unsigned char *, unsigned char *, unsigned char *);
extern unsigned int sys_get_region_address(unsigned int);

#define REGION_REGISTER_SET_0x18 0x18   /* sys_get_region_address: address read from the registers at 0xCF011910 */
#define ROWS_START_OFFSET        0x30   /* first row, above the region address */
#define ROW_STRIDE               0x78   /* memory port address step from one row to the next */
#define ROWS                     16
#define ROW_ENTRIES              16

/*
 * Fill the three 256-byte tables from memory, 16 rows of 16 entries, through the memory port.
 *
 * The memory port is switched on and sys_latch_status_state(3) is called first. Each row is read by
 * sys_mem_port_read_rgb_sums from its own address (region 0x18 + 0x30, then + 0x78 per row): it reads the
 * values as triples and stores the average of eight triples per entry, the first value of each triple in
 * pq_zone_averages_blue, the second in pq_zone_averages_green and the third in pq_zone_averages_red. Then
 * sys_latch_status_state(0x10) is called. pq_api_get_zone_average_table hands the tables to
 * pq_average_zone_color, which takes them as red, green and blue.
 *
 * Called by sys_main_loop_periodic_task while sys_config bit 21 is set and channels 0 and 3 both wait in
 * MODE_WAITMODECHANGE, on every 20th such pass.
 */
void pq_read_zone_color_averages(void)
{
    unsigned int address;
    unsigned short row, offset;

    sys_mem_port_enable(1);
    sys_latch_status_state(3);
    address = sys_get_region_address(REGION_REGISTER_SET_0x18) + ROWS_START_OFFSET;
    for (offset = 0, row = 0; row < ROWS; offset += ROW_ENTRIES, row++) {
        sys_mem_port_read_rgb_sums(address, &pq_zone_averages_red[offset], &pq_zone_averages_green[offset], &pq_zone_averages_blue[offset]);
        address += ROW_STRIDE;
    }
    sys_latch_status_state(0x10);
}
