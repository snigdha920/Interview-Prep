#include <bits/stdc++.h>
using namespace std;

int createBitVector(string s);
bool checkOneBitSet(int bitVector);
int toggle(int bitVector, int index);
bool isPalindromePermutation(string s);

bool isPalindromePermutation(string s) {
    int bitVector = createBitVector(s);
    return (bitVector == 0) || (checkOneBitSet(bitVector));
}

int createBitVector(string s) {
    int bitVector = 0;
    for(int i=0; i<s.length(); i++) {
        if(s[i] < 'a' || s[i] > 'z') continue;
        int index = (int) s[i]-'a';
        bitVector = toggle(bitVector, index);
    }
    return bitVector;
}

bool checkOneBitSet(int bitVector) {
    return (bitVector & (bitVector-1)) == 0;
}

int toggle(int bitVector, int index) {
    if(index < 0) return bitVector;
    int mask = 1 << index;
    if((bitVector & mask) == 0) {
        bitVector = bitVector | mask;
    } else {
        bitVector &= ~mask;
    }
    return bitVector;
}

int main() {
    string s;
    getline(cin, s);
    cout << isPalindromePermutation(s);
}
