#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include "graphics.h"
#include "kernelfunc.h"

void kmain(void) {

    init_graphics();

    //test
    SPrint("hello from MARLIX \n");

}
