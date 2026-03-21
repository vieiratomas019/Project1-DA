#include <iostream>

#include "data_structures/Graph.h"
#include "data_structures/Menu.h"
#include "algorithms/edmonds_karp.h"
#include "algorithms/ford_fulkerson.h"
#include "data_structures/Parser.h"
using namespace std;

void usage() {
    std::cerr << "Usage CLI: myProg\nUsage Batch: myProg -b [input_file] [output_filename]" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 4) {
        usage();
        return 1;
    }

    if (argc == 1) {
        // WITH THE INPUT FILE: KEEP IN MIND THAT THE PATH MUST INCLUDE THE Input/ FOLDER

        // while loop perguntar o input file
            // se quer sair do programa : sair
            // se input file valido
                // Parser parser;
                // parser.parse()
                // break;
        // === THEN ===
            // ==== USER CAN: ====
            // request information: provided the current config from the parsed input file (list reviewers, submissions, parameters, etc
        // create the graph with the stored info
        // run the algorithm
        // still some missing steps

        // choose input file
        Parser parser;

        while (true)
        {
            string filename;
            cout << "Type your Input File Name: ";
            cin >> filename;

            try
            {

                parser.parse("Input/" + filename);
                break;

            } catch (const exception& e)
            {
                cerr << "Error: " << e.what() << endl;
            }
        }

        //show options
        showMenu();
        //show action based on the option

    }

    return 0;
}