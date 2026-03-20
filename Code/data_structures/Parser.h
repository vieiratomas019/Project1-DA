#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

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
  void parse(const string& filename);

  // getters
  const vector<Submission>& getSubmissions() const { return submissions; }
  const vector<Reviewer>& getReviewers() const { return reviewers; }
  const Parameters& getParameters() const { return paramos; }
  const Control& getControl() const { return ctrl; }


private:
  enum Part {
    NOT_INITIALIZED,
    SUBMISSIONS,
    REVIEWERS,
    PARAMETERS,
    CONTROL
  };

  /* Fields */
  vector<Submission> submissions;
  vector<Reviewer> reviewers;
  Parameters paramos;
  Control ctrl;

  /* Methods */
  void parseline(Part part, const string& line);
};
#endif //PARSER_H
