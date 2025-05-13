#include <iostream>
using namespace std;

class stack
{
public:
    int size = 50;
    char a[50];
    int top = -1;

    bool isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void push(char x)
    {
        if (isFull())
        {
            cout << endl;
            cout << "Stack Overflow !!" << endl;
        }
        else
        {
            a[++top] = x;
        }
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << endl;
            cout << "Stack Underflow !!" << endl;
            return '0';
        }
        else
        {
            return a[top--];
        }
    }

    char top1()
    {
        if (isEmpty())
        {
            cout << endl;
            cout << "Stack Underflow !!" << endl;
            return '0';
        }
        else
        {
            return a[top];
        }
    }

    int top2()
    {
        if (isEmpty())
        {
            cout << endl;
            cout << "Stack Underflow !!" << endl;
            return 0;
        }
        else
        {
            return (a[top] - 48);
        }
    }
};

int precedence(char x)
{
    if (x == '/' || x == '*')
    {
        return 3;
    }

    else if (x == '+' || x == '-')
    {
        return 2;
    }

    else
    {
        return 1;
    }
}

class expression
{
public:
    string infix, postfix="";

    stack s1, s2;

    expression()
    {
        cout << endl;
        cout << "Enter a Infix Expression :" << endl;
        cin >> infix;
    }

    void InfixToPostfix()
    {
        for (int i = 0; i < infix.size(); i++)
        {
            if (precedence(infix[i]) == 1)
            {
                postfix += infix[i];
            }

            else
            {
                if (s1.isEmpty())
                {
                    s1.push(infix[i]);
                }
                else
                {
                    if (precedence(infix[i]) > precedence(s1.top1()))
                    {
                        s1.push(infix[i]);
                    }
                    else
                    {
                        while (!s1.isEmpty() && (precedence(infix[i]) <= precedence(s1.top1())))
                        {
                            char temp;
                            temp = s1.pop();
                            postfix += temp;
                        }
                        s1.push(infix[i]);
                    }
                }
            }
        }
        while (!s1.isEmpty())
        {
            char temp;
            temp = s1.pop();
            postfix += temp;
        }
        cout << endl;
        cout << "Resultant Postfix Expression : " << postfix << endl;
    }

    void evaluation()
    {
        for (int i = 0; i < postfix.size(); i++)
        {
            if (postfix[i] >= '0' && postfix[i] <= '9')
            {
                s2.push(postfix[i]);
            }

            else
            {
                int n = s2.top2();
                s2.pop();
                int m = s2.top2();
                s2.pop();

                if (postfix[i] == '/')
                {
                    int r = m / n;
                    s2.push((char)(r + 48));
                }
                else if (postfix[i] == '*')
                {
                    int r = m * n;
                    s2.push((char)(r + 48));
                }
                else if (postfix[i] == '+')
                {
                    int r = m + n;
                    s2.push((char)(r + 48));
                }
                else
                {
                    int r = m - n;
                    s2.push((char)(r + 48));
                }
            }
        }
        cout << endl;
        cout << "Evaluation of Postfix Expression " << postfix << " is " << s2.top1() << endl;
    }
};

int main()
{
    expression e;

    int ch = 0;
    // string s;
    // string pf = "";

    do
    {
        cout << endl;
        cout << "* * * * * Infix To Postfix Converter and Calculator * * * * *" << endl;
        cout << "1) Infix to Postfix Converter" << endl;
        cout << "2) Evalution of Postfix Expression" << endl;
        cout << "3) Exit" << endl;
        cout << "Enter your choice :" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            // stack s1;
            e.InfixToPostfix();
            break;
        }

        case 2:
        {
            // stack s2;
            e.evaluation();
            exit(0);
            break;
        }

        case 3:
        {
            exit(0);
        }

        default:
        {
            cout << endl;
            cout << "Invalid Choice!!" << endl;
            break;
        }
        }
    } while (ch != 3);
    return 0;
}
