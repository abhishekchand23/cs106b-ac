#include "HumanPyramids.h"
#include "error.h"
#include "grid.h"

using namespace std;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */
double weightOnBackOfRec(int row, int col, Grid<double>& gridWeightOnBackOf) {

    if (col > row) error("Not in range of the pyramid");

    if (row == 0 && col == 0) return 0;

    else if (gridWeightOnBackOf[row][col] > -1){
        return gridWeightOnBackOf[row][col];
    }
    else if (row == col) {
        gridWeightOnBackOf[row][col] = 0.5 * weightOnBackOfRec(row -1, col - 1, gridWeightOnBackOf) + 80.0;
        return gridWeightOnBackOf[row][col];
    }
    else if (col == 0) {
        gridWeightOnBackOf[row][col] =  0.5 * weightOnBackOfRec(row -1, col, gridWeightOnBackOf) + 80.0;
        return gridWeightOnBackOf[row][col];
    }
    else {
        gridWeightOnBackOf[row][col] = 0.5 * (weightOnBackOfRec(row - 1, col -1, gridWeightOnBackOf) +
                                              weightOnBackOfRec(row - 1, col, gridWeightOnBackOf)) + 160.0;
        return gridWeightOnBackOf[row][col];
    }
}

double weightOnBackOf(int row, int col) {
    Grid<double> sendGrid(row + 1, row + 1, -1.0);
    return weightOnBackOfRec(row, col, sendGrid);
}





/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */

PROVIDED_TEST("Milestone 1: Check Person A from the handout.") {
    /* Person E is located at row 0, column 0. */
    EXPECT_EQUAL(weightOnBackOf(0, 0), 0);
}

PROVIDED_TEST("Milestone 1: Check Person M from the handout.") {
    /* Person E is located at row 4, column 2. */
    EXPECT_EQUAL(weightOnBackOf(4, 2), 500);
}



/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Milestone 1: Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1), 240);
}

PROVIDED_TEST("Milestone 1: Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0));
    EXPECT_ERROR(weightOnBackOf(10, 11));
    EXPECT_ERROR(weightOnBackOf(-1, 10));
}

PROVIDED_TEST("Milestone 2: Memoization is implemented (should take under a second)") {
    /* TODO: Yes, we are asking you to make a change to this test case! Delete the
     * line immediately after this one - the one that starts with SHOW_ERROR - once
     * you have implemented memoization to test whether it works correctly.
     */

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50) >= 10000);
}
