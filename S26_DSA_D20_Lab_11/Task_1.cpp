#include <iostream>

using namespace std;

/* 1. what i understand about this code
The main idea here is to play around with sentences and words using recursion. 
We need to count how many words and letters are in a line, flip the letters from small to
capital (and the other way around), and then reverse the whole thing. 
The tricky part is that we can't use any simple loops like for or while. 
Every time we want to move to the next letter, the function has to call itself again.

2. task solution assumption and understanding 
I'll use the \0 (the hidden end-marker of a string) to know when to stop.
- For counting: I'll check each character. 
  If it's a letter and the one before it was a space, that's a new word.
- For case flipping: I'll check if a letter is in the a-z range or A-Z range and jump across the ASCII table by 32 to swap them.
- For reversing: I'll first find where the sentence ends, then swap the very first letter with the very last one.
  Then I'll move my "markers" inward and do it again.

3. functions used in this code and why
The word-reversal is actually just a two-step process using the character reversal.
First, I reverse the entire sentence so the last word is at the front. 
Then, I go through and reverse the letters of each individual word back so they make
sense again. 
I also wrote a tiny bit of logic to find the length of the string manually since we aren't using string libraries.

4.learning from task 
I learned that recursion is basically like a loop that remembers where it's
been. 

5. skills developed 
I'm much more comfortable with pointers now and how they point to memory
addresses. I also feel like I can break down big problems into tiny, repeating
steps which is really what recursion is all about.
*/

// 1. Count and display number of words
void countWords(const char* sentence) {
    static int totalWords = 0;
    static bool lookingForWord = true;

    if (*sentence == '\0') {
        cout << "Words: " << totalWords << endl;
        totalWords = 0; // reset for next time
        lookingForWord = true;
        return;
    }

    if (*sentence != ' ' && lookingForWord) {
        totalWords++;
        lookingForWord = false;
    }
    else if (*sentence == ' ') {
        lookingForWord = true;
    }

    countWords(sentence + 1);
}

// 2. Count and display number of characters
void countCharaters(const char* sentence) {
    static int totalChars = 0;

    if (*sentence == '\0') {
        cout << "Characters: " << totalChars << endl;
        totalChars = 0;
        return;
    }

    totalChars++;
    countCharaters(sentence + 1);
}

// 3. Reverses the sentence character-wise
void reverse(char*& sentence) {
    static int left = 0;
    static int right = -1;

    if (right == -1) {
        int len = 0;
        while (sentence[len] != '\0') len++;
        right = len - 1;
    }

    if (left >= right) {
        left = 0;
        right = -1;
        return;
    }

    char temp = sentence[left];
    sentence[left] = sentence[right];
    sentence[right] = temp;

    left++;
    right--;
    reverse(sentence);
}

// 4. Reverses the sentence words-wise
void reverseWords(char*& sentence) {
    // Flipping the whole thing
    reverse(sentence);

    // Flipping each word back to normal
    static int head = 0;
    static int tail = 0;

    if (sentence[tail] == ' ' || sentence[tail] == '\0') {
        int a = head, b = tail - 1;
        while (a < b) {
            char tmp = sentence[a];
            sentence[a] = sentence[b];
            sentence[b] = tmp;
            a++; b--;
        }

        if (sentence[tail] == '\0') {
            head = 0; tail = 0;
            return;
        }
        head = tail + 1;
    }

    tail++;
    reverseWords(sentence);
}

// 5. Converts lower to uppercase and uppercase to lowercase
void convert(char* sentence) {
    if (*sentence == '\0') return;

    if (*sentence >= 'a' && *sentence <= 'z') {
        *sentence -= 32;
    }
    else if (*sentence >= 'A' && *sentence <= 'Z') {
        *sentence += 32;
    }

    convert(sentence + 1);
}

int main() {
    char myText[] = "hi! how are you bro?";
    char* ptr = myText;

    cout << "Original Text: " << ptr << endl;

    countCharaters(ptr);
    countWords(ptr);

    convert(ptr);
    cout << "Swapped Case: " << ptr << endl;

    reverse(ptr);
    cout << "Character Reverse: " << ptr << endl;

    char myText2[] = "Data Structures Lab";
    char* ptr2 = myText2;
    reverseWords(ptr2);
    cout << "Word Reverse: " << ptr2 << endl;

    return 0;
}