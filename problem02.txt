#include <iostream>
#include <cstring>   // for memset, memcpy
#include <iomanip>   // for setw (to print 2 digits)

using namespace std;

// Function prototype
void print_seat(int **seat, int row, int col);

int main() {
    const int ROWS = 10;
    const int COLS = 10;

    // ============================================
    // PART 1: Dynamically allocate 10x10 integer array
    // ============================================
    
    // Step 1: Allocate array of pointers (rows)
    int **seat = new int*[ROWS];
    
    // Step 2: Allocate each row (columns)
    for (int i = 0; i < ROWS; i++) {
        seat[i] = new int[COLS];
    }
    
    // Step 3: Initialize entire array to 0 using memset
    // Note: memset works on each row because each row is contiguous
    for (int i = 0; i < ROWS; i++) {
        memset(seat[i], 0, COLS * sizeof(int));
    }
    
    // Step 4: Assign the given seat values
    seat[0][0] = 11;
    seat[0][3] = 24;
    seat[1][1] = 35;
    seat[2][5] = 47;
    seat[3][3] = 58;
    seat[4][9] = 69;
    seat[5][0] = 70;
    seat[5][5] = 81;
    seat[5][9] = 92;
    seat[6][4] = 13;
    seat[7][7] = 26;
    seat[8][2] = 39;
    seat[9][9] = 44;
    
    cout << "=== PART 1: Initial Seat Map ===" << endl;
    print_seat(seat, ROWS, COLS);
    cout << endl;
    
    // ============================================
    // PART 2: Create backup using memcpy
    // ============================================
    
    // Allocate backup array
    int **backup = new int*[ROWS];
    for (int i = 0; i < ROWS; i++) {
        backup[i] = new int[COLS];
    }
    
    // Copy row by row using memcpy
    for (int i = 0; i < ROWS; i++) {
        memcpy(backup[i], seat[i], COLS * sizeof(int));
    }
    
    cout << "=== PART 2: Backup Seat Map (copied) ===" << endl;
    print_seat(backup, ROWS, COLS);
    cout << endl;
    
    // ============================================
    // PART 3: Clear row 5 in original seat map
    // ============================================
    
    // Clear entire row 5 (index 5) by setting all values to 0
    memset(seat[5], 0, COLS * sizeof(int));
    
    cout << "=== PART 3: Original After Clearing Row 5 ===" << endl;
    print_seat(seat, ROWS, COLS);
    cout << endl;
    
    cout << "=== PART 3: Backup (should be unchanged) ===" << endl;
    print_seat(backup, ROWS, COLS);
    cout << endl;
    
    // ============================================
    // PART 4: Find row with largest number of assigned seats
    // ============================================
    
    int maxAssigned = -1;
    int bestRow = -1;
    
    for (int i = 0; i < ROWS; i++) {
        int count = 0;
        for (int j = 0; j < COLS; j++) {
            if (backup[i][j] != 0) {
                count++;
            }
        }
        
        if (count > maxAssigned) {
            maxAssigned = count;
            bestRow = i;
        }
        // If tie, we keep the smallest row index (already iterating from 0 upward)
    }
    
    cout << "=== PART 4: Row with most assigned seats ===" << endl;
    cout << "Row " << bestRow << " has " << maxAssigned << " assigned seat(s)." << endl;
    cout << endl;
    
    // ============================================
    // PART 5: Release all dynamically allocated memory
    // ============================================
    
    // Delete original seat map
    for (int i = 0; i < ROWS; i++) {
        delete[] seat[i];
    }
    delete[] seat;
    
    // Delete backup seat map
    for (int i = 0; i < ROWS; i++) {
        delete[] backup[i];
    }
    delete[] backup;
    
    cout << "=== Memory successfully freed! ===" << endl;
    
    return 0;
}

// ============================================
// print_seat function
// Prints the full seat map in matrix form
// Each value printed in two digits, separated by one space
// ============================================

void print_seat(int **seat, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << setw(2) << seat[i][j];  // Print with 2-digit width
            if (j < col - 1) {
                cout << " ";  // Space between numbers (not after last)
            }
        }
        cout << endl;  // End of row
    }
}