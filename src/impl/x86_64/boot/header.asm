section .multiboot_header
header_start:
;magic number
dd 0xe85250d6 ; multiboot 2

; arch
dd 0 ; protected mode

; header length
dd Header_end - header_start

;checksum
dd 0x100000000 - (0xe85250d6 + 0 + (Header_end - header_start))

; end tag
dw 0
dw 0
dd 8
Header_end: