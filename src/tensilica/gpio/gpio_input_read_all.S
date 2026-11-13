# gpio_input_read_all  (fn_40008c58): 0x40008c58-0x40008c5f (firmware file offset 0x38c58-0x38c5f), 3 instructions
# Name basis: descriptive - read_impwire; no caller
# No call instruction targets it and no 4-byte aligned word in the program holds its address.
# Returns the whole 32-bit IMPWIRE input (read_impwire).
# Arguments: none. Locals: none.
# Returns: IMPWIRE.

	.balign	4, 0                    # functions start on a 4-byte boundary; any gap is zero bytes
	.type	gpio_input_read_all, @function
gpio_input_read_all:                    # fn_40008c58
	entry	a1, 32                  # 40008c58
	# return IMPWIRE;
	read_impwire	a2              # 40008c5b
	retw.n                          # 40008c5e
	.size	gpio_input_read_all, . - gpio_input_read_all
