#include <iostream>
#include <stack>
#include <string>

using namespace std ;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    string text ;
    getline( cin, text ) ;
    int faulty_position = -1;

    std::stack <Bracket> opening_brackets_stack ;
    for ( int position = 0; position < text.length(); ++position ) {
        char next = text[position] ;
        Bracket *b = new Bracket(next, position + 1) ;

        if (next == '(' || next == '[' || next == '{') {
           opening_brackets_stack.push(*b);
        }

        if (next == ')' || next == ']' || next == '}') {
            if (opening_brackets_stack.size() == 0) {
                faulty_position = position + 1;
                break;
            } else if (opening_brackets_stack.top().Matchc(next)) {
                opening_brackets_stack.pop();
            } else {
                faulty_position = position + 1;
                break;
            }
        }
    }

    if( opening_brackets_stack.size() == 0 && faulty_position == -1 ) {
        cout << "Success" << endl;
    } else {
        if ( faulty_position == -1 ) {
            faulty_position = opening_brackets_stack.top().position;
        }
        cout << faulty_position << endl;
    }

    return 0;
}
