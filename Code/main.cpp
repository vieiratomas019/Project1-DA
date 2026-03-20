#include <iostream>

#include "data_structures/Graph.h"
#include "algorithms/edmonds_karp.h"
#include "algorithms/ford_fulkerson.h"

void usage(int argc, char* argv[]) {
    std::cerr << "Usage CLI: myProg\nUsage Batch: myProg -b [input_file] [output_filename]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 4) {
        usage(argc, argv);
    }

    return 0;
}