// UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)

#include <bits/stdc++.h>

using namespace std;

int main() {

    string input;
    list<char> linkedList;

    while (getline(cin, input)) {

        linkedList.clear();
        list<char>::iterator it = linkedList.begin();
        
        for (int i=0; i<input.size(); i++) {
            if (input[i] == '[') it = linkedList.begin();
            else if (input[i] == ']') it = linkedList.end();
            else linkedList.insert(it, input[i]);
        }


            for (const auto& element : linkedList) {
                std::cout << element;
            }
            std::cout << std::endl;


    }


    return 0;
}