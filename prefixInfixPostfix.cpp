#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <limits>

using namespace std;

string s;

// --------------------------------------------------
// Operator Priority
// --------------------------------------------------
int priorityOfOprator(char ch) {
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

// --------------------------------------------------
// Check Operand
// --------------------------------------------------
bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9');
}

// --------------------------------------------------
// Input Expression
// --------------------------------------------------
string inputExpression() {

    cout << "\nPlease enter the expression for ";
    getline(cin, s);

    cout << "\nThanks for your input. Your expression has been received.\n";

    return s;
}

// --------------------------------------------------
// Infix -> Postfix
// --------------------------------------------------
string infixToPostfix() {

    stack<char> stk;
    string ans;

    int i = 0;

    while (i < s.length()) {

        // Operand
        if (isOperand(s[i])) {
            ans += s[i];
        }

        // Opening parenthesis
        else if (s[i] == '(') {
            stk.push(s[i]);
        }

        // Closing parenthesis
        else if (s[i] == ')') {

            while (!stk.empty() && stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }

            if (!stk.empty() && stk.top() == '(') {
                stk.pop();
            }
        }

        // Operator
        else {

            while (!stk.empty() &&
                   stk.top() != '(' &&
                   priorityOfOprator(s[i]) <=
                   priorityOfOprator(stk.top())) {

                ans += stk.top();
                stk.pop();
            }

            stk.push(s[i]);
        }

        i++;
    }

    // Empty remaining stack
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

// --------------------------------------------------
// Infix -> Prefix
// --------------------------------------------------
string infixToPrefix() {

    stack<char> stk;
    string ans;

    int i = s.length() - 1;

    while (i >= 0) {

        // Operand
        if (isOperand(s[i])) {
            ans += s[i];
        }

        // Closing parenthesis
        else if (s[i] == ')') {
            stk.push(s[i]);
        }

        // Opening parenthesis
        else if (s[i] == '(') {

            while (!stk.empty() && stk.top() != ')') {
                ans += stk.top();
                stk.pop();
            }

            if (!stk.empty() && stk.top() == ')') {
                stk.pop();
            }
        }

        // Operator
        else {

            while (!stk.empty() &&
                   stk.top() != ')' &&
                   priorityOfOprator(s[i]) <
                   priorityOfOprator(stk.top())) {

                ans += stk.top();
                stk.pop();
            }

            stk.push(s[i]);
        }

        i--;
    }

    // Empty remaining stack
    while (!stk.empty()) {
        ans += stk.top();
        stk.pop();
    }

    // Reverse answer
    reverse(ans.begin(), ans.end());

    return ans;
}

// --------------------------------------------------
// Postfix -> Infix
// --------------------------------------------------
string postfixToInfix() {

    stack<string> stk;

    int i = 0;

    while (i < s.length()) {

        // Operand
        if (isOperand(s[i])) {
            stk.push(string(1, s[i]));
        }

        // Operator
        else {

            string t1 = stk.top();
            stk.pop();

            string t2 = stk.top();
            stk.pop();

            string concat =
                "(" + t2 + s[i] + t1 + ")";

            stk.push(concat);
        }

        i++;
    }

    return stk.top();
}

// --------------------------------------------------
// Prefix -> Infix
// --------------------------------------------------
string prefixToInfix() {

    stack<string> stk;

    int i = s.length() - 1;

    while (i >= 0) {

        // Operand
        if (isOperand(s[i])) {
            stk.push(string(1, s[i]));
        }

        // Operator
        else {

            string t1 = stk.top();
            stk.pop();

            string t2 = stk.top();
            stk.pop();

            string concat =
                "(" + t1 + s[i] + t2 + ")";

            stk.push(concat);
        }

        i--;
    }

    return stk.top();
}

// --------------------------------------------------
// Postfix -> Prefix
// --------------------------------------------------
string postfixToPrefix() {

    stack<string> stk;

    int i = 0;

    while (i < s.length()) {

        // Operand
        if (isOperand(s[i])) {
            stk.push(string(1, s[i]));
        }

        // Operator
        else {

            string t1 = stk.top();
            stk.pop();

            string t2 = stk.top();
            stk.pop();

            string concat =
                s[i] + t2 + t1;

            stk.push(concat);
        }

        i++;
    }

    return stk.top();
}

// --------------------------------------------------
// Prefix -> Postfix
// --------------------------------------------------
string prefixToPostfix() {

    stack<string> stk;

    int i = s.length() - 1;

    while (i >= 0) {

        // Operand
        if (isOperand(s[i])) {
            stk.push(string(1, s[i]));
        }

        // Operator
        else {

            string t1 = stk.top();
            stk.pop();

            string t2 = stk.top();
            stk.pop();

            string concat =
                t1 + t2 + s[i];

            stk.push(concat);
        }

        i--;
    }

    return stk.top();
}

// --------------------------------------------------
// Main
// --------------------------------------------------
int main() {

    int choice;

    while (true) {

        cout << "\n\n";
        cout << "-----------------------------------------------\n";
        cout << " All Conversion Related to Infix Prefix & Postfix\n";
        cout << "-----------------------------------------------\n";

        cout << "1. Infix to Prefix Conversion\n";
        cout << "2. Infix to Postfix Conversion\n";
        cout << "3. Prefix to Infix Conversion\n";
        cout << "4. Prefix to Postfix Conversion\n";
        cout << "5. Postfix to Infix Conversion\n";
        cout << "6. Postfix to Prefix Conversion\n";
        cout << "7. Exit the Application\n";

        cout << "\nEnter your choice(1-7): ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "\nInfix Expression: " << inputExpression();
            cout << "\nPrefix Expression: " << infixToPrefix();
            break;

        case 2:
            cout << "\nInfix Expression: " << inputExpression();
            cout << "\nPostfix Expression: " << infixToPostfix();
            break;

        case 3:
            cout << "\nPrefix Expression: " << inputExpression();
            cout << "\nInfix Expression: " << prefixToInfix();
            break;

        case 4:
            cout << "\nPrefix Expression: " << inputExpression();
            cout << "\nPostfix Expression: " << prefixToPostfix();
            break;

        case 5:
            cout << "\nPostfix Expression: " << inputExpression();
            cout << "\nInfix Expression: " << postfixToInfix();
            break;

        case 6:
            cout << "\nPostfix Expression: " << inputExpression();
            cout << "\nPrefix Expression: " << postfixToPrefix();
            break;

        case 7:
            cout << "\nExiting application...\n";
            return 0;

        default:
            cout << "\nInvalid choice. Please try again.\n";
        }
    }

    return 0;
}