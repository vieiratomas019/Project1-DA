#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include "Parser.h"
using namespace std;

Parser::Parser():submissions(), reviewers(), paramos(), ctrl(){}

void Parser::parse(string filename){
  ifstream read(filename);

  int mode;
  for(string line; getline(read, line); ){
    if (line == "#Submissions"){
      mode = 0;
    }

    else if (line == "#Reviewers"){
      mode = 1;
    }

    else if (line == "#Parameters"){
      mode = 2;
    }

    else if (line == "#Control"){
      mode = 3;
    }

    // skip "#Id, Title, Authors,E-mail,Primary,Secondary" lines
    else if (line.at(0) != '#'){
      parseline(mode, line);
    }
  }
}

void Parser::parseline(int mode, string line){
  switch (mode){
    case 0:
    case 1:
    case 2:
    case 3:
  }
}