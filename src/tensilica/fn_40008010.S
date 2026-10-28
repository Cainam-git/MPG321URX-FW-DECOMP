# fn_40008010: 0x40008010-0x4000802b (firmware file offset 0x38010-0x3802b), 12 instructions
# Called from: fn_40000de8
# Calls: fn_40006c9c, fn_40006de8, fn_40006e94

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008010, @function
fn_40008010:
	entry	a1, 32                  # 40008010
	movi.n	a10, 1                  # 40008013
	movi.n	a11, 2                  # 40008015
	call8	fn_40006c9c             # 40008017
	movi.n	a10, 1                  # 4000801a
	movi.n	a11, 1                  # 4000801c
	movi.n	a12, 12                 # 4000801e
	call8	fn_40006de8             # 40008020
	movi.n	a10, 1                  # 40008023
	movi.n	a11, 1                  # 40008025
	call8	fn_40006e94             # 40008027
	retw.n                          # 4000802a
	.size	fn_40008010, . - fn_40008010
