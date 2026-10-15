#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include "graphics.h"
#include "kernelfunc.h"

void kmain(void) {

    init_graphics();

    //test
    SPrint("hello from MARLIX\n");
    SPrint("-- Reporting marlix kernel v. 1.0 -- \n");

      SPrint((char*)strlen("hello"));

}
