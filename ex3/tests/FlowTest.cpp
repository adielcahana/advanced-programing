#include <fstream>
#include "gtest/gtest.h"
#include "../src/Flow.h"
#include "../src/Driver.h"

TEST(FlowTest, initializeAndRunTest){
    const int NUM_OF_LINES_IN_CORRECT_OUTPUT = 9;
    string buffer;
    ifstream in("testsFiles/flow.txt");
    ofstream out("testsFiles/output.txt");
    cin.rdbuf(in.rdbuf()); //redirect std::cin
    cout.clear();
    cout.rdbuf(out.rdbuf()); //redirect std::cout
    Flow flow;
    while (!flow.shouldStop) {
        EXPECT_NO_THROW(flow.initialize());
        if (!flow.shouldStop) {
            EXPECT_NO_THROW(flow.run());
        }
    }
    in.close();
    out.close();
    cin.clear();
    cout.clear();
    ifstream correct("testsFiles/correct.txt");
    ifstream test("testsFiles/output.txt");
    string fromCorrect;
    string fromTest;
    int numOfLines = 0;
    while(!correct.eof() && !test.eof()){
        getline(correct, fromCorrect);
        getline(test,fromTest);
        EXPECT_EQ(strcmp(fromCorrect.c_str(), fromTest.c_str()) , 0);
        numOfLines++;
    }
    EXPECT_EQ(numOfLines , NUM_OF_LINES_IN_CORRECT_OUTPUT);
    correct.close();
    test.close();
}
