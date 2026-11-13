/* pq_gamma_load_first_curve_preset0  (FUN_a010b030)
 *
 * Load preset 0 (or a given table) into the first preset-curve stage.
 * Name basis: derived - 64-byte table of 32 rising 16-bit points from ROM 0x19AD1C, table command 0x76; preset
 *   number as used by pq_api_load_preset_curves
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b030 @ 0xa010b030, flags -mcpu=v8 -O2 -g (section default).
 * Source form: the preset is copied to the stack before the null test, so the copy is made in both cases.
 */

#define FIRST_CURVE_STAGE_DEVICE 0x76   /* table port device number of the first preset-curve stage */
#define FIRST_CURVE_BYTES        0x40   /* size of one first-stage table */

extern unsigned char pq_gamma_first_curve_preset0[];
extern int memcpy(void *, const void *, unsigned int);
extern int reg_table_port_write(unsigned int, unsigned int, unsigned int, const unsigned char *);

/*
 * Write a 64-byte table into the first preset-curve stage through the table port (device 0x76, offset 0).
 *
 *   table   the bytes to write; null writes preset 0 from ROM (pq_gamma_first_curve_preset0)
 *   unused  not used
 *
 * The only caller is pq_api_load_preset_curves (selection 0, with a null table), which nothing in the firmware
 * calls.
 */
void pq_gamma_load_first_curve_preset0(unsigned char *table, unsigned int unused)
{
  unsigned char *data;
  unsigned char preset[FIRST_CURVE_BYTES];

  memcpy(preset, pq_gamma_first_curve_preset0, FIRST_CURVE_BYTES);
  data = table;
  if (table == 0) {
    data = preset;
  }
  reg_table_port_write(FIRST_CURVE_STAGE_DEVICE, 0, FIRST_CURVE_BYTES, data);
}
