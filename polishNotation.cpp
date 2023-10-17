#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct STACK
{
    char val;
    struct STACK *next;

}STACK;

void OUTPUT_EXP(string);
void PREFIX(string);
string POSTFIX(string);
void EVALUATION(string);

int PRECEDENCE(char);
void PUSH(char);
char POP();

STACK *TOS = NULL;

main()
{
    int choice;
    string exp, NEW;
    char ch;

    cout << "Enter the Expression:";
    cin >> exp;
    cout << endl
         << endl;
    while (1)
    {

        cout << "             POLISH NOTATIONS        \n\n";
        cout << "*********************************************\n\n";
        cout << "         1)Output An Expression" << endl;
        cout << "         2)Prefix Of An Expression" << endl;
        cout << "         3)Postfix Of An Expression" << endl;
        cout << "         4)Calculation of An Expression" << endl;
        cout << "         5)Exit" << endl
             << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {

        case 1:
            OUTPUT_EXP(exp);
            break;
        case 2:
            PREFIX(exp);

            break;
        case 3:
            NEW = POSTFIX(exp);
            cout << "POSTFIX:" << NEW << endl;
            break;
        case 4:
            EVALUATION(exp);
            break;
        case 5:
            exit(0);
        }
    }
}

void OUTPUT_EXP(string str)
{
    cout << "THE ENTERED EXPRESSION IS:" << str << endl
         << endl;
    return;
}

void PREFIX(string str)
{

    int n = str.length();

    reverse(str.begin(), str.end()); // this function helps to reverse the string

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            str[i] = ')';

        else if (str[i] == ')')
            str[i] = '(';
    }

    string new_result;

    new_result = POSTFIX(str); // we get the postfix of the reversed string

    reverse(new_result.begin(), new_result.end());

    cout << "PREFIX:" << new_result << endl;
}

string POSTFIX(string str)
{
    string result = "";

    int n;
    n = str.length();

    for (int i = 0; i < n; i++)
    {
        if (isalpha(str[i]) || isdigit(str[i]))
        {
            result += str[i];
        }
        else if (str[i] == '(')
        {
            PUSH(str[i]);
        }

        else if (str[i] == ')')
        {
            while (TOS->next != NULL && TOS->val != '(')
            {
                result += TOS->val;
                POP();
            }
            POP();
        }

        else
        {
            if (TOS == NULL)
            {
                PUSH(str[i]);
            }

            else
            {
                if (PRECEDENCE(str[i]) > PRECEDENCE(TOS->val))
                {
                    PUSH(str[i]);
                }
                else
                {
                    while (TOS != NULL && PRECEDENCE(str[i]) <= PRECEDENCE(TOS->val))
                    {
                        result += TOS->val;
                        POP();
                    }
                    PUSH(str[i]);
                }
            }
        }
    }

    while (TOS != NULL)
    {
        result += TOS->val;
        POP();
    }

    cout << endl;

    return result;
}

void EVALUATION(string str)
{
    TOS = NULL;

    string result;

    result = POSTFIX(str);

    int n, a, b;

    n = result.length();

    for (int i = 0; i < n; i++)
    {
        if (isalpha(result[i]))
        {
            cout << result[i] << ":";
            cin >> a;
            PUSH(a + 48);
        }

        else
        {
            a = POP();
            b = POP();

            switch (result[i])
            {
            case '+':
            {
                PUSH(a + b - 48);
                break;
            }
            case '-':
            {
                PUSH(b - a + 48);
                break;
            }
            case '*':
            {
                PUSH(((a - 48) * (b - 48) + 48));
                break;
            }
            case '/':
            {
                PUSH(((b - 48) / (a - 48) + 48));
                break;
            }
            case '^':
            {
                PUSH(pow(b - 48, a - 48) + 48);
                break;
            }
            }
        }
    }

    cout << "RESULT:" << POP() << endl;
}

void PUSH(char exp)
{
    STACK *ptr = new STACK();

    if (TOS == NULL) // first element
    {
        ptr->val = exp;
        ptr->next = NULL;
        TOS = ptr;
    }

    else // addition of nodes on top
    {
        ptr->val = exp;
        ptr->next = TOS;
        TOS = ptr;
    }
}

char POP()
{
    int item;

    item = TOS->val;

    if (TOS == NULL)
        return 0;

    else if (TOS->next == NULL)
        TOS = NULL;

    else
        TOS = TOS->next;

    return item;
}

int PRECEDENCE(char pr)
{
    if (pr == '^')
        return 3;

    else if (pr == '*' || pr == '/')
        return 2;

    else if (pr == '+' || pr == '-')
        return 1;

    else
        return 0;
        
}