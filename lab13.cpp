/*
1. Is there a fault in the program? If so, locate it and explain.
    Yes there is a fault in the program, specifically in the loop that counts absences. 
    The loop starts from index 1, which means it ignores the first attendance record (index 0). 
    This can lead to incorrect counting of absences if the first record is an absence (0).
2. Define a test case that does not execute the fault. Start from this ques-
tion, if it is possible, you should give the test case (the attendance record
with 10 values), the expected output and the actual output. If impossible,
explains the reason. Besides, you should implement the complete program,
including the functions under test, and verify your inputs along with their
corresponding outputs.
   It is impossible to define a valid test case (with 10 attendance values) that does not execute the fault. 
   Because the faulty code is in the loop header that always runs for any non-empty vector of size 10.
3. Define a test case that executes the fault but does not result in an error
state.
    Test Case: {1, 1, 1, 0, 1, 1, 0, 1, 1, 1}
    Expected Output: false (since there are only 2 absences)
    Actual Output: false (the fault does not affect this case)
4. Define a test case that results in an error state but not a failure.
    Test Case: {0, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    Expected Output: false (since there is only 1 absence)
    Actual Output: false (the fault does not affect this case)
5. Define a test case that results in failure.
    Test Case: {0, 0, 0, 1, 1, 1, 1, 1, 1, 1}
    Expected Output: true (since there are 3 absences)
    Actual Output: false (the fault causes the first absence to be ignored)
*/
#include <iostream>
#include <vector>
using namespace std;
bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (size_t i = 1; i < attendance_records.size(); ++i) {
        if (attendance_records[i] == 0) {
            absent_count++;
        }
    }
    return absent_count >= 3;
}
bool fail_lecture_correct(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (size_t i = 0; i < attendance_records.size(); ++i) {
        if (attendance_records[i] == 0) {
            absent_count++;
        }
    }
    return absent_count >= 3;
}
int main() {
    vector<int> q3 = {1, 1, 1, 0, 1, 1, 0, 1, 1, 1};
    cout << "Q3 Test Case: ";
    for (int x : q3) { cout << x << " "; }
    cout << "\n";
    cout << "Expected: " << (fail_lecture_correct(q3) ? "true" : "false") << "\n";
    cout << "Actual:   " << (fail_lecture(q3) ? "true" : "false") << "\n\n";

    vector<int> q4 = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Q4 Test Case: ";
    for (int x : q4) { cout << x << " "; }
    cout << "\n";
    cout << "Expected: " << (fail_lecture_correct(q4) ? "true" : "false") << "\n";
    cout << "Actual:   " << (fail_lecture(q4) ? "true" : "false") << "\n\n";

    vector<int> q5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    cout << "Q5 Test Case: ";
    for (int x : q5) { cout << x << " "; }
    cout << "\n";
    cout << "Expected: " << (fail_lecture_correct(q5) ? "true" : "false") << "\n";
    cout << "Actual:   " << (fail_lecture(q5) ? "true" : "false") << "\n\n";

    return 0;
}