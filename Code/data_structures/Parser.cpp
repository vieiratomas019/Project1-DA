#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>

#include "Parser.h"

using namespace std;

Parser::Parser(): paramos(), ctrl(){}

void Parser::parse(const string& filename){
  ifstream read(filename);

  if (!read.is_open()) {
    std::cerr << "File could not be opened" << std::endl;
    return;
  }

  Part part = NOT_INITIALIZED;
  for(string line; getline(read, line); ){
    if (line == "#Submissions") part = SUBMISSIONS;
    else if (line == "#Reviewers") part = REVIEWERS;
    else if (line == "#Parameters") part = PARAMETERS;
    else if (line == "#Control") part = CONTROL;
    else if (!line.empty() && line.at(0) != '#') parseline(part, line); // only parse lines with info
  }
}

void Parser::parseline(Part part, const string& line){
  stringstream ss(line);

  // create delimiters
  char comma = ',', quote = '"';

  switch (part){
    case NOT_INITIALIZED: break;
    case SUBMISSIONS: {
      Submission s;
      string token, bin;

      // ID
      getline(ss, token, comma);
      s.id = stoi(token);

      // Title
      getline(ss, bin, quote);
      getline(ss, s.title, quote);
      getline(ss, bin, comma);

      // Authors
      getline(ss, token, comma);
      s.authors.push_back(token);

      // Email
      getline(ss, s.email, comma);

      // Primary Domain
      getline(ss, token, comma);
      s.primary = stoi(token);

      // Secondary Domain
      if (getline(ss, token)) {
        try {
          s.secondary = stoi(token);
        } catch (const invalid_argument& e) {
          s.secondary = 0;
        }
      }
      else {
        s.secondary = 0;
      }

      submissions.push_back(s);

      break;
    }
    case REVIEWERS: {
      Reviewer r;
      string token;

      // ID
      getline(ss, token, comma);
      r.id = stoi(token);

      // Name
      getline(ss, r.name, comma);

      // Email
      getline(ss, r.email, comma);

      // Primary Expertise
      getline(ss, token, comma);
      r.primary = stoi(token);

      // Secondary Expertise
      if (getline(ss, token)) {
        try {
          r.secondary = stoi(token);
        } catch (const invalid_argument& e) {
          r.secondary = 0;
        }
      }
      else {
        r.secondary = 0;
      }

      reviewers.push_back(r);

      break;
    }
    case PARAMETERS: {
      string param, value;

      // get both
      getline(ss, param, comma);
      getline(ss, value);

      if (param.find("MinReviewsPerSubmission") != string::npos) {
        paramos.MinReviewsPerSubmission = stoi(value);
      }
      else if (param.find("MaxReviewsPerReviewer") != string::npos) {
        paramos.MaxReviewsPerReviewer = stoi(value);
      }
      else if (param.find("PrimaryReviewerExpertise") != string::npos) {
        paramos.PrimaryReviewerExpertise = stoi(value);
      }
      else if (param.find("SecondaryReviewerExpertise") != string::npos) {
        paramos.SecondaryReviewerExpertise = stoi(value);
      }
      else if (param.find("PrimarySubmissionDomain") != string::npos) {
        paramos.PrimarySubmissionDomain = stoi(value);
      }
      else if (param.find("SecondarySubmissionDomain") != string::npos) {
        paramos.SecondarySubmissionDomain = stoi(value);
      }

      break;
    }
    case CONTROL: {
      string token;

      getline(ss, token, comma);

      if (token.find("GenerateAssignments") != string::npos) {
        getline(ss, token);
        ctrl.GenerateAssignments = stoi(token);
      }
      else if (token.find("RiskAnalysis") != string::npos) {
        getline(ss, token);
        ctrl.RiskAnalysis = stoi(token);
      }
      else if (token.find("OutputFileName") != string::npos) {
        string bin;

        getline(ss, bin, quote); // discard quotes
        getline(ss, ctrl.OutputFileName, quote);
      }
      break;
    }
    default: break;
  }
}