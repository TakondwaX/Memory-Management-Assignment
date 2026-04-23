
#include <iostream>
#include <cstring>   // for strcpy, strcmp, strlen

using namespace std;

// Function to print the dictionary
void printDictionary(char **dict, int size) {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "] " << dict[i] << endl;
    }
}

// Function to search for a word and return its index (-1 if not found)
int searchWord(char **dict, int size, const char *target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(dict[i], target) == 0) {
            return i;
        }
    }
    return -1;
}

// Function to delete a word at a specific index and shift remaining words
void deleteWord(char **dict, int &size, int index) {
    if (index < 0 || index >= size) {
        cout << "Invalid index for deletion!" << endl;
        return;
    }
    
    // Free the memory of the word being deleted
    delete[] dict[index];
    
    // Shift all remaining words to the left
    for (int i = index; i < size - 1; i++) {
        dict[i] = dict[i + 1];
    }
    
    // Decrease size
    size--;
}

int main() {
    // ============================================
    // PART 1: Create string list with 5 words
    // ============================================
    
    // Dynamically allocate array of pointers (holds up to 5 words)
    char **dictionary = new char*[5];
    int capacity = 5;
    int currentSize = 5;
    
    // Initial words
    const char *initialWords[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    
    // Allocate memory for each word and copy it
    for (int i = 0; i < currentSize; i++) {
        dictionary[i] = new char[strlen(initialWords[i]) + 1];  // +1 for null terminator
        strcpy(dictionary[i], initialWords[i]);
    }
    
    cout << "[Initial Dictionary]" << endl;
    printDictionary(dictionary, currentSize);
    cout << endl;
    
    // ============================================
    // PART 2: Search for word "delta"
    // ============================================
    
    const char *searchTarget = "delta";
    int foundIndex = searchWord(dictionary, currentSize, searchTarget);
    
    cout << "[Search Result]" << endl;
    if (foundIndex != -1) {
        cout << searchTarget << " found at index " << foundIndex << endl;
    } else {
        cout << searchTarget << " not found" << endl;
    }
    cout << endl;
    
    // ============================================
    // PART 3: Modify word at index 1 from 'bravo' to 'blueberry'
    // ============================================
    
    const char *newWord = "blueberry";
    
    // Free the old memory at index 1
    delete[] dictionary[1];
    
    // Allocate new memory for "blueberry" and copy it
    dictionary[1] = new char[strlen(newWord) + 1];
    strcpy(dictionary[1], newWord);
    
    cout << "[After Update]" << endl;
    printDictionary(dictionary, currentSize);
    cout << endl;
    
    // ============================================
    // PART 4: Delete the word 'charlie'
    // ============================================
    
    // Find index of "charlie"
    int charlieIndex = searchWord(dictionary, currentSize, "charlie");
    
    if (charlieIndex != -1) {
        deleteWord(dictionary, currentSize, charlieIndex);
    }
    
    cout << "[After Delete]" << endl;
    printDictionary(dictionary, currentSize);
    cout << endl;
    
    // ============================================
    // PART 5: Clean up all dynamically allocated memory
    // ============================================
    
    for (int i = 0; i < currentSize; i++) {
        delete[] dictionary[i];
    }
    delete[] dictionary;
    
    cout << "=== Memory successfully freed! ===" << endl;
    
    return 0;
}