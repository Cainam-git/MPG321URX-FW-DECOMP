# ldc_units_setup_driver_type2  (fn_40008010): 0x40008010-0x4000802b (firmware file offset 0x38010-0x3802b), 12 instructions
# Name basis: descriptive - called by ldc_select_led_driver for driver type 2
# Called from: ldc_select_led_driver
# Sets unit 0 up for LED driver type 2: mode bits 2, length 12 with flag 1, register +0x38 bit 13 = 1 (the
# same calls end ldc_units_init with 0, 0 and 0). Called by ldc_select_led_driver for driver type 2.
# Arguments: none. Locals: none. Returns: nothing.
# Calls: ldc_unit_set_mode_bits, ldc_unit_set_length_and_flag, ldc_unit_set_reg38_bit13

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	ldc_units_setup_driver_type2, @function
ldc_units_setup_driver_type2:           # fn_40008010
	entry	a1, 32                  # 40008010
	# ldc_unit_set_mode_bits(1, 2);
	movi.n	a10, 1                  # 40008013
	movi.n	a11, 2                  # 40008015
	call8	ldc_unit_set_mode_bits  # 40008017
	# ldc_unit_set_length_and_flag(1, 1, 12);
	movi.n	a10, 1                  # 4000801a
	movi.n	a11, 1                  # 4000801c
	movi.n	a12, 12                 # 4000801e
	call8	ldc_unit_set_length_and_flag # 40008020
	# ldc_unit_set_reg38_bit13(1, 1);
	movi.n	a10, 1                  # 40008023
	movi.n	a11, 1                  # 40008025
	call8	ldc_unit_set_reg38_bit13 # 40008027
	retw.n                          # 4000802a
	.size	ldc_units_setup_driver_type2, . - ldc_units_setup_driver_type2
