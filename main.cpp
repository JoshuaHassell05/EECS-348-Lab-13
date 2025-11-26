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
    
3. Define a test case that executes the fault but does not result in an error
state.

4. Define a test case that results in an error state but not a failure.
    
5. Define a test case that results in failure.
  
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
