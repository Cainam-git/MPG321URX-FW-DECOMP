# fn_40008c58: 0x40008c58-0x40008c5f (firmware file offset 0x38c58-0x38c5f), 3 instructions
# No call instruction targets it and no 4-byte aligned word in the program holds its address.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	fn_40008c58, @function
fn_40008c58:
	entry	a1, 32                  # 40008c58
	read_impwire	a2              # 40008c5b
	retw.n                          # 40008c5e
	.size	fn_40008c58, . - fn_40008c58
