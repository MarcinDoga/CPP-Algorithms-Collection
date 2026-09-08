#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

enum TokenType
{
    NUMBER,
    OPERATOR,
    LPAREN,
    RPAREN
};

struct Token
{
    TokenType type;
    double value;
    char op;
};

vector<Token> tokenize(const string& input)
{
    vector<Token> tokens;
    for (size_t i = 0; i < input.size();)
    {
        char c = input[i];

        if (c == ' ')
        {
            i++;
            continue;
        }

        if ((c >= '0' && c <= '9') || c == '.')
        {
            double num = 0.0;
            double frac = 0.1;
            bool afterDot = false;

            while (i < input.size() &&
                ((input[i] >= '0' && input[i] <= '9') || input[i] == '.'))
            {
                if (input[i] == '.')
                {
                    afterDot = true;
                }
                else if (!afterDot)
                {
                    num = num * 10 + (input[i] - '0');
                }
                else
                {
                    num += (input[i] - '0') * frac;
                    frac *= 0.1;
                }
                i++;
            }

            tokens.push_back({ NUMBER, num, 0 });
            continue;
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            tokens.push_back({ OPERATOR, 0, c });
            i++;
            continue;
        }

        if (c == '(')
        {
            tokens.push_back({ LPAREN, 0, 0 });
            i++;
            continue;
        }

        if (c == ')')
        {
            tokens.push_back({ RPAREN, 0, 0 });
            i++;
            continue;
        }

        i++;
    }
    return tokens;
}

int precedence(char op)
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

vector<Token> toPostfix(const vector<Token>& tokens)
{
    vector<Token> output;
    vector<Token> stack;

    for (const Token& t : tokens)
    {
        if (t.type == NUMBER)
        {
            output.push_back(t);
        }
        else if (t.type == OPERATOR)
        {
            while (!stack.empty() &&
                stack.back().type == OPERATOR &&
                (
                    precedence(stack.back().op) > precedence(t.op) ||
                    (precedence(stack.back().op) == precedence(t.op) && t.op != '^')
                    ))
            {
                output.push_back(stack.back());
                stack.pop_back();
            }
            stack.push_back(t);
        }
        else if (t.type == LPAREN)
        {
            stack.push_back(t);
        }
        else if (t.type == RPAREN)
        {
            while (!stack.empty() && stack.back().type != LPAREN)
            {
                output.push_back(stack.back());
                stack.pop_back();
            }
            stack.pop_back();
        }
    }

    while (!stack.empty())
    {
        output.push_back(stack.back());
        stack.pop_back();
    }

    return output;
}

double evaluate(const vector<Token>& postfix)
{
    vector<double> stack;

    for (const Token& t : postfix)
    {
        if (t.type == NUMBER)
        {
            stack.push_back(t.value);
        }
        else
        {
            double b = stack.back(); stack.pop_back();
            double a = stack.back(); stack.pop_back();

            if (t.op == '+') stack.push_back(a + b);
            if (t.op == '-') stack.push_back(a - b);
            if (t.op == '*') stack.push_back(a * b);
            if (t.op == '/') stack.push_back(a / b);
            if (t.op == '^') stack.push_back(pow(a, b));
        }
    }
    return stack.back();
}

int main()
{
    string input;
    cout << "\tLimes Interpretation\n\n";
    cout << "Give your function (+ - * / ^ () ): ";
    getline(cin, input);

    auto tokens = tokenize(input);
    auto postfix = toPostfix(tokens);
    double result = evaluate(postfix);

    cout << "\nResult: " << result << endl;
}