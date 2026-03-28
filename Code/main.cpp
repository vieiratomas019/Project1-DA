#include <iostream>

#include "data_structures/Graph.h"
#include "data_structures/Menu.h"
#include "algorithms/edmonds_karp.h"
#include "algorithms/ford_fulkerson.h"
#include "data_structures/Parser.h"
#include "data_structures/ReviewAssigner.h"
using namespace std;

void usage() {
    std::cerr << "Usage CLI: myProg\nUsage Batch: myProg -b [input_file] [output_filename]" << std::endl;
}

enum Options
{
    INFO,
    GRAPH,
    ALGORITHM,
    EXIT
};

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
            string quit = "quit";

            cout << "Type your Input File Name (type " + quit + " to exit): ";
            cin >> filename;

            // early exit
            if (filename == quit) exit(EXIT_SUCCESS);

            try
            {
                parser.parse("Input/" + filename);
                break;

            } catch (const exception& e)
            {
                cout << "=========== Error ===========" << endl << e.what() << endl << "=============================" << endl;
            }
        }

        //show options
        //show action based on the option
        ReviewAssigner review_assigner(parser);
        while (true)
        {
            showMenu();
            int option_num;
            string opt_list;
            cin >> option_num;

            switch (option_num)
            {
            case 1:
                showInfoOptions();
                cin >> opt_list;
                showWantedInfo(parser, opt_list);
                break;
            case 2:
                //function to create graph
                review_assigner.generate();
                cout << "Your Graph was created." << endl;
                break;
            case 3:
                handleGenerateAssignments(parser, review_assigner);
                break;
            case 4:
                changeVariable(parser);
                break;
            case 5:
                //quit
                exit(EXIT_SUCCESS);
            }

        }
    }

    // batch mode: -b dataset1.csv output_dataset1.csv
    if (string(argv[1]) != "-b")
    {
        usage();
        return 1;
    }

    Parser parser;
    parser.parse("Input/" + string(argv[2]));
    ReviewAssigner review_assigner(parser);
    review_assigner.generate();
    handleGenerateAssignmentsBatch(parser, review_assigner, string(argv[3]));

    return 0;
}