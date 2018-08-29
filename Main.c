#include <stdio.h>
#include <stdlib.h>

#include "Parser.h"
#include "Printer.h"
#include "Absyn.h"
#include "Compiler.h"

int main(int argc, char ** argv) {
    FILE *input;
    input = stdin;
    Exp parse_tree = pExp(input);
    if (parse_tree) {
        compile(parse_tree);
        printf("\n");
        return 0;
    }
    return 1;
}
