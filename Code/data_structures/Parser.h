#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <set>
#include <string>
using namespace std;

struct Submission{
  int id;
  string title;
  vector<string> authors;
  string email;
  int primary;
  int secondary;
};

struct Reviewer{
  int id;
  string name;
  string email;
  int primary;
  int secondary;
};

struct Parameters{
  int MinReviewsPerSubmission;
  int MaxReviewsPerReviewer;
  int PrimaryReviewerExpertise = 1;
  int SecondaryReviewerExpertise = 0;
  int PrimarySubmissionDomain;
  int SecondarySubmissionDomain;
};

struct Control{
  int GenerateAssignments;
  int RiskAnalysis = 0;
  string OutputFileName;
};

class Parser{
  public:
    Parser();
    void parse(string filename);

  private:
    set<Submission> submissions;
    set<Reviewer> reviewers;
    Parameters paramos;
    Control ctrl;
    void parseline(int mode, string line);
};
#endif //PARSER_H
