#include <iostream>

#include "data_structures/Graph.h"
#include "data_structures/Menu.h"
#include "algorithms/edmonds_karp.h"
#include "algorithms/ford_fulkerson.h"
#include "data_structures/Parser.h"

void usage() {
    std::cerr << "Usage CLI: myProg\nUsage Batch: myProg -b [input_file] [output_filename]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 4) {
        usage();
    }

    if (argc == 1) {
        // while loop perguntar o input file
            // se quer sair do programa : sair
            // se input file valido
                // Parser parser;
                // parser.parse()
                // break;
        // === THEN ===
        // mostrar menu full para que o user edite alguma coisa do input file
            // ==== USER CAN: ====
            // request information: provided the current config from the parsed input file (list reviewers, submissions, parameters, etc)
            // change some information ??????????
        // create the graph with the stored info
        // run the algorithm
        // still some missing steps
    }

    return 0;
}