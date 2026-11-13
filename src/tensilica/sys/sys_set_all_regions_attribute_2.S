# sys_set_all_regions_attribute_2  (fn_4000a10c): 0x4000a10c-0x4000a11d (firmware file offset 0x3a10c-0x3a11d), 8 instructions
# Name basis: descriptive - code only: calls sys_set_region_attributes(0, 0xFFFFFFFF, 2, 0); nothing calls
#   it
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Calls sys_set_region_attributes(0, 0xFFFFFFFF, 2, 0) and keeps the result in a stack slot without using it. Nothing calls it
# and no stored word holds its address.
# Arguments: none.
# Locals: a1+0 result.
# Returns: nothing.
# Calls: sys_set_region_attributes

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	sys_set_all_regions_attribute_2, @function
sys_set_all_regions_attribute_2:        # fn_4000a10c
	entry	a1, 48                  # 4000a10c
# result = sys_set_region_attributes(0, -1, 2, 0);
	movi.n	a10, 0                  # 4000a10f
	movi.n	a11, -1                 # 4000a111
	movi.n	a12, 2                  # 4000a113
	movi.n	a13, 0                  # 4000a115
	call8	sys_set_region_attributes # 4000a117
	s32i.n	a10, a1, 0              # 4000a11a
	retw.n                          # 4000a11c
	.size	sys_set_all_regions_attribute_2, . - sys_set_all_regions_attribute_2
