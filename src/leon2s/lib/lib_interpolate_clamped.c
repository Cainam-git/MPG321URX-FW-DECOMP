/* lib_interpolate_clamped  (FUN_a0062718)
 *
 * Interpolate linearly between two values and clamp outside the given range.
 *   start_value: result at the range start and below it
 *   end_value: result at the range end and above it
 *   range_start
 *   range_end
 *   position: point to interpolate at
 * Returns: interpolated value
 * Name basis: derived - unsigned linear interpolation with limits; used by the guided curve builder
 *
 * Matching notes
 * --------------
 * FUN_a0062718 (leon2s 0xa0062718, 144 bytes), flags -mcpu=v8 -Os -g.
 * The range_start >= range_end case is tested first and the result is kept in the parameter start_value
 * ('start_value = end_value', '+=', '-=') with one return.
 */
/*
 * Clamped linear interpolation between two values.
 *
 *   start_value  result at the start of the range and below it
 *   end_value    result at the end of the range and above it
 *   range_start  start of the range
 *   range_end    end of the range
 *   position     the point to interpolate at
 *
 * range_start <  range_end: start_value when position <= range_start; end_value when position >= range_end; in
 *           between the value start_value + (end_value - start_value) * (position - range_start) /
 *           (range_end - range_start), computed with unsigned arithmetic (the difference is taken the other way
 *           round when end_value is the smaller).
 * range_start >= range_end (no range): end_value when position >= range_start, else start_value.
 *
 * Called by hdr_build_guided_curve, which passes two constants for the range and a computed position.
 */
unsigned int lib_interpolate_clamped(unsigned int start_value, unsigned int end_value, unsigned int range_start,
                                     unsigned int range_end, unsigned int position)
{
    if (range_start >= range_end) {
        if (position >= range_start)
            start_value = end_value;
    } else if (position > range_start) {
        if (position >= range_end)
            start_value = end_value;
        else if (end_value >= start_value)
            start_value += (end_value - start_value) * (position - range_start) / (range_end - range_start);
        else
            start_value -= (start_value - end_value) * (position - range_start) / (range_end - range_start);
    }
    return start_value;
}
