! trap_write_buffer_error_part1  (FUN_a0060500)
!
! Load the write-buffer error budget counter.
! Note: Entered at 0xA0060504 (first word is trap_return_skip's delay slot); part 2 decrements the counter and
!   raises 'ta 0' once it goes negative, else retries.
! Name basis: proven - trap-table slot 0x2B jumps to 0x504; trap-name table: 'Write buffer error'
!
! Matching notes
! --------------
! leon2s FUN_a0060500 @ 0xa0060500  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060500
	.type FUN_a0060500, #function
FUN_a0060500:
	rett  %l2 + 4                     ! delay slot of the 'jmp %l2' before it: return from the trap
! Handler of trap type 0x2B, data_store_error (the trap-name table calls it 'Write buffer error'),
! entered here at 0xA0060504 from slot trap_type_2b_entry. It counts the error down in the word at
! 0xA8076000: while the count stays 0 or more it runs the trapped instruction again, else it stops the
! processor. The start value of the word is 0, so the first such error stops the processor.
	sethi  %hi(0xa8076000), %l4       ! upper bits of the error count word
	or  %l4, 0, %l4                   ! %l4 = 0xA8076000
	ld  [ %l4 ], %l5                  ! %l5 = the error count
	.size FUN_a0060500, .-FUN_a0060500
