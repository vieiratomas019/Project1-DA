#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Submission{
  int id;
  string title;
  string authors;
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
  string OutputFileName = "output.csv";
};

class Parser{
public:
  /**
 * @brief Constructor of a Parser Object
 */
  Parser();

  /**
 * @brief Function to parse the information from a file to parser structs
 * @param filename name of the file we want to parse
 * @note Time Complexity: O(R + S), R: number of Reviewers, S: number of Submissions
 */
  void parse(const string& filename);

  // getters
  /** @brief Returns the list of submissions from the parsed input file */
  const vector<Submission>& getSubmissions() const { return submissions; }
  /** @brief Returns the list of reviewers from the parsed input file */
  const vector<Reviewer>& getReviewers() const { return reviewers; }
  /** @brief Returns the parameters from the parsed input file */
  const Parameters& getParameters() const { return paramos; }
  /** @brief Returns the control values from the parsed input file */
  Control getControl() const { return ctrl; }

  // setters for control values (needed for changeVariable)
  /** @brief Sets the GenerateAssignments control value
 *  @param new_value New value for GenerateAssignments
 */
  void setGenerateAssignemnts(int new_value){ ctrl.GenerateAssignments = new_value;}
  /** @brief Sets the RiskAnalysis control value
   *  @param new_value New value for RiskAnalysis
   */
  void setRiskAnalysis(int new_value){ctrl.RiskAnalysis = new_value;}
  /** @brief Sets the OutputFileName control value
   *  @param new_value New value for OutputFileName
   */
  void setOutputFilename(string new_value){ctrl.OutputFileName = new_value;}


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
