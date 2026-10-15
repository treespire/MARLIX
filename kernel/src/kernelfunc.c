void serial(char text) {

    register long register1 __asm__("a0") = text;
    register long register2 __asm__("a7") = 1;
    asm volatile ("ecall" : "+r" (register1) : "r" (register2) : "memory");

}


// making it work

void SPrint(char *string) {
    while (*string) {
        serial(*string++);
    }
}

size_t strlen( volatile const char  *text) {
    volatile size_t len = 0;
    while (text[len] != 0) {
       len++;
    }
    return len;
}