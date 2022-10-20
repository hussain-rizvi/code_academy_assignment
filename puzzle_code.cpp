#include <bits/stdc++.h> 
using namespace std; 
#define ROW_SIZE        15
#define COLUMN_SIZE     15
#define WORDS_SIZE      16


const char *words[WORDS_SIZE] = {
    "balance",
    "bank",
    "cash",
    "check",
    "coin",
    "credit",
    "debit",
    "deposit",
    "dollar",
    "loan",
    "money",
    "paws",
    "pounce",
    "sunwest",
    "transfer",
    "withdraw"
};




char puzzle[ROW_SIZE][COLUMN_SIZE] = {
    {'a', 'x', 'd', 'u', 'r', 'y', 'h', 'p', 's', 'p', 't', 't', 'i', 'd', 't'},
    {'v', 'n', 'x', 's', 'e', 'c', 'a', 'q', 'c', 'u', 'i', 'u', 'o', 'z', 'p'},
    {'m', 'e', 'r', 'g', 'f', 'w', 'o', 'z', 'i', 's', 'n', 'l', 'k', 'a', 'c'},
    {'v', 's', 'c', 'x', 's', 'e', 's', 'x', 'o', 'f', 'l', 'w', 'z', 'j', 'z'},
    {'v', 't', 'r', 'p', 'n', 'd', 'l', 'p', 'b', 'a', 'c', 'h', 'e', 'b', 'y'},
    {'p', 'r', 'e', 'k', 'a', 'w', 'e', 'c', 'r', 'c', 't', 'x', 'n', 's', 'b'},
    {'f', 'p', 'd', 'm', 'r', 'd', 'l', 'o', 's', 'p', 'e', 'j', 'a', 'q', 't'},
    {'w', 'h', 'i', 'n', 't', 'l', 'y', 'i', 'b', 't', 'c', 'a', 's', 'h', 'n'},
    {'l', 'a', 't', 'c', 'i', 'q', 'n', 'n', 'r', 'i', 'l', 'h', 't', 'y', 'j'},
    {'k', 'r', 'r', 'x', 'o', 'i', 'f', 'k', 'y', 'b', 'w', 'o', 'e', 'w', 'a'},
    {'v', 'c', 'p', 'd', 'u', 'y', 'z', 'k', 'l', 'e', 't', 'n', 'a', 'k', 'w'},
    {'i', 'u', 'e', 'o', 'h', 'k', 'n', 'a', 'b', 'd', 'o', 't', 'a', 'n', 'a'},
    {'f', 'a', 'q', 'h', 'y', 't', 'j', 'b', 'i', 'm', 'y', 'm', 'u', 'd', 's'},
    {'v', 'q', 'z', 'f', 'c', 'j', 'i', 'e', 'e', 'm', 'n', 'k', 'u', 'x', 'l'},
    {'b', 'a', 'l', 'a', 'n', 'c', 'e', 'w', 'e', 'c', 'n', 'u', 'o', 'p', 'b'}
};




// For searching in all 8 direction 
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 


// This function searches in 
// all 8-direction from point 
// (row, col) in grid[][] 
bool search2D(char grid[ROW_SIZE][COLUMN_SIZE], int row, 
            int col, string word) 
{ 
    // If first character of word doesn't 
    // match with given starting point in grid. 
    if (grid[row][col] != word[0]) 
        return false; 


    int len = word.length(); 


    // Search word in all 8 directions 
    // starting from (row, col) 
    for (int dir = 0; dir < 8; dir++) { 
        // Initialize starting point 
        // for current direction 
        int k, rd = row + x[dir], cd = col + y[dir]; 


        // First character is already checked, 
        // match remaining characters 
        for (k = 1; k < len; k++) { 
            // If out of bound break 
            if (rd >= ROW_SIZE || rd < 0 || cd >= COLUMN_SIZE || cd < 0) 
                break; 


            // If not matched, break 
            if (grid[rd][cd] != word[k]) 
                break; 


            // Moving in particular direction 
            rd += x[dir], cd += y[dir]; 
        } 


        // If all character matched, then value of must 
        // be equal to length of word 
        if (k == len) 
            return true; 
    } 
    return false; 
} 


// Searches given word in a given 
// matrix in all 8 directions 
void patternSearch(char grid[ROW_SIZE][COLUMN_SIZE], 
                string word) 
{ 
    // Consider every point as starting 
    // point and search given word 
    for (int row = 0; row < ROW_SIZE; row++) 
        for (int col = 0; col < COLUMN_SIZE; col++) 
            if (search2D(grid, row, col, word)) 
                cout <<"\""<<word<<"\""<< " found at row "
                    << row+1 << ", col "
                    << col+1 << endl; 
} 




int main() 
{ 
 
    for(int i=0;i<WORDS_SIZE+1;i++){
    patternSearch(puzzle, words[i]); 
    cout << endl;
    }
    return 0; 
} 

