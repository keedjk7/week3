#include <iostream>
#include<string.h>
#include <ctype.h>

using namespace std;

const int MAX_CHAR = 50;

struct leaf {
    int index;
    leaf* child[MAX_CHAR];
    
    leaf()
    {
        for (int i = 0; i < MAX_CHAR; i++) {
            child[i] = NULL;
        }
        index = -1;
    }
};

void sort(leaf* root, string str, int index){
    leaf* node = root;
    for (int i = 0; i < str.size(); i++) {

        char C = tolower(str[i]) - 'a';

        if (!node->child[C]) {
            node->child[C] = new leaf();
        }
        node = node->child[C];
    }
    node->index = index;
}

bool print(leaf* node, string Keep[])
{
    if (node == NULL) {
        return false;
    }

    for (int i = 0; i < MAX_CHAR; i++) {
        if (node->child[i] != NULL) {
            if (node->child[i]->index != -1) {
                cout << Keep[node->child[i]->index] << endl;
            }
            print(node->child[i], Keep);
        }
    }
}

void sort_print(string Keep[], int input)
{
    leaf* root = new leaf();

    for (int i = 0; i < input; i++) {
        sort(root, Keep[i], i);
    }
    printf("\nSort by dictionary\n");
    print(root, Keep);
}
int main()
{
    string Keep[1000];
    int input;
    printf("Number Of Input String : ");
    cin >> input;
    for (int i = 0; i < input; i++) {
        cin >> Keep[i];
    }
    sort_print(Keep, input);
    return 0;
}