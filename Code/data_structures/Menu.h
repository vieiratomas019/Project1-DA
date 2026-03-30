//
// Created by baguetes on 20/03/2026.
//

#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"
#include "ReviewAssigner.h"

using namespace std;

/**
 * @brief Prints the Menu Options
 */
void showMenu();
/**
 * @brief Prints the Submissions Info
 * @param parser Parser Object that contains the desired info
 */
void showSubmissions(const Parser& parser);
/**
 * @brief Prints the Reviewers Info
* @param parser Parser Object that contains the desired info
 */
void showReviewers(const Parser& parser);
/**
 * @brief Prints the Parameters Info
* @param parser Parser Object that contains the desired info
 */
void showParameters(const Parser& parser);
/**
 * @brief Prints the Control Info
 * @param parser Parser Object that contains the desired info
 */
void showControl(const Parser& parser);
/**
 * @brief Prints the Info Submenu Options
 */
void showInfoOptions();
/**
 * @brief Handler/ Parser for the users input for options
 * @param parser reference to object parser that contains the desired info
 * @param opt_list string that contains the list of desired options
 */
void showWantedInfo(const Parser& parser, string opt_list);
/**
 * @brief Handler for Generate Assignments
 * @param parser reference to object parser that contains the desired info
 * @param review_assigner reference to object review assigner that will be used to generate the graph and run the algorithm
 */
void handleGenerateAssignments(const Parser& parser, const ReviewAssigner& review_assigner);
/**
 * @brief Changes the value of a Control Parameter
 * @param parser reference to object parser that contains the desired info
 */
void changeVariable(Parser& parser);

#endif //PROJECT1_MENU_H