! trap_type_2b_entry  (FUN_a00602b0)
!
! Trap table slot 0x2b (type 2b): reads %psr and %tbr and jumps to the handler at 0xa0060504.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a00602b0 @ 0xa00602b0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00602b0
	.type FUN_a00602b0, #function
FUN_a00602b0:
! Slot of trap type 0x2B, data_store_error. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! trap_write_buffer_error (0xA0060504): counts down the word at 0xA8076000 and
! retries the trapped instruction while it stays 0 or more, else stops (start value 0).
! (the trap-name table calls it 'Write buffer error'.)
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0060400), %l4       ! upper bits of the handler address 0xA0060504
	jmp  %l4 + 0x104                  ! jump to 0xA0060504: count the error, retry or stop
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a00602b0, .-FUN_a00602b0
