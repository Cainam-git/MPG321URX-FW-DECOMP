! trap_window_overflow_entry  (FUN_a0060050)
!
! Trap table slot 0x05 (window overflow): reads %psr and %tbr and jumps to the handler at 0xa0060538.
! Name basis: proven - trap table position and the slot's own instructions
!
! Matching notes
! --------------
! leon2s FUN_a0060050 @ 0xa0060050  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060050
	.type FUN_a0060050, #function
FUN_a0060050:
! Slot of trap type 0x05, window_overflow. The trap has already put the PC and nPC of the
! trapped instruction in %l1 and %l2; the slot adds PSR and TBR and jumps on to
! the window-overflow handler (0xA0060538), which writes the next register window
! to its stack so that the SAVE can be retried.
	rd  %psr, %l0                     ! processor state register (PSR) to %l0
	sethi  %hi(0xa0060400), %l4       ! upper bits of the handler address 0xA0060538
	jmp  %l4 + 0x138                  ! jump to 0xA0060538: window-overflow handler
	rd  %tbr, %l3                     ! delay slot, runs before the jump: TBR (holds the trap type) to %l3
	.size FUN_a0060050, .-FUN_a0060050
