/* pq_gamma_load_second_curve_preset1  (FUN_a010b24c)
 *
 * Load preset 1 (or a given table) into the second preset-curve stage.
 * Name basis: derived - 32-byte table from ROM 0x19AE5C written with table command 0xB6; preset number as used
 *   by pq_api_load_preset_curves
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010b24c @ 0xa010b24c, flags -mcpu=v8 -O2 -g.
 * Source form: the preset is copied to the stack before the null test, so the copy is made in both cases.
 */

#define SECOND_CURVE_STAGE_DEVICE 0xb6  /* table port device number of the second preset-curve stage */
#define SECOND_CURVE_BYTES        0x20  /* size of one second-stage table */

extern unsigned char pq_gamma_second_curve_preset1[];
extern int memcpy(void *, const void *, unsigned int);
extern int reg_table_port_write(unsigned int, unsigned int, unsigned int, const unsigned char *);

/*
 * Write a 32-byte table into the second preset-curve stage through the table port (device 0xB6, offset 0).
 *
 *   table   the bytes to write; null writes preset 1 from ROM (pq_gamma_second_curve_preset1)
 *   unused  not used
 *
 * The only caller is pq_api_load_preset_curves (with a null table), which nothing in the firmware calls.
 */
void pq_gamma_load_second_curve_preset1(unsigned char *table, unsigned int unused)
{
  unsigned char *data;
  unsigned char preset[SECOND_CURVE_BYTES];

  memcpy(preset, pq_gamma_second_curve_preset1, SECOND_CURVE_BYTES);
  data = table;
  if (table == 0) {
    data = preset;
  }
  reg_table_port_write(SECOND_CURVE_STAGE_DEVICE, 0, SECOND_CURVE_BYTES, data);
}
