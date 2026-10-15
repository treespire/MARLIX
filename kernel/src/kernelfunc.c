static void serial(char text) {

    register long register1 __asm__("a0") = text;
    register long register2 __asm__("a7") = 1;
    asm volatile ("ecall" : "+r" (register1) : "r" (register2) : "memory");

}