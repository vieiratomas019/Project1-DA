//
// Created by baguetes on 20/03/2026.
//

#ifndef PROJECT1_MENU_H
#define PROJECT1_MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "Parser.h"

using namespace std;

void showMenu();
void showSubmissions(const Parser& parser);
void showReviewers(const Parser& parser);
void showParameters(const Parser& parser);
void showControl(const Parser& parser);
void showAll(const Parser& parser);
//still some missing steps

#endif //PROJECT1_MENU_H