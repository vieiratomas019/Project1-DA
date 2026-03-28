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

void showMenu();
void showSubmissions(const Parser& parser);
void showReviewers(const Parser& parser);
void showParameters(const Parser& parser);
void showControl(const Parser& parser);
void showAll(const Parser& parser);
void showInfoOptions();
void showWantedInfo(const Parser& parser, string opt_list);
void handleGenerateAssignments(const Parser& parser, const ReviewAssigner& review_assigner);
void handleGenerateAssignmentsBatch(const Parser& parser, const ReviewAssigner& review_assigner, const string& output_filename);
void changeVariable(Parser& parser);

#endif //PROJECT1_MENU_H