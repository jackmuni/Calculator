# include <iostream>
# include <string>
# include <math.h>
using namespace std;

struct Node
{
int data;
Node *next;

};

class Stack
{
public:
Node *head;
Stack()
{
   head = NULL;
}
int top()
{
 if (head != NULL)
 return head ->data;
}

void push (int s)
{
Node *tmp =new Node;
tmp -> data =s;
tmp -> next = head;
head = tmp;
}

void pop ()
{
if (head != NULL)
{
Node *tmp = head;
head = head ->next;
delete tmp;
}
}

~Stack()
{
while (head!= NULL)
pop();
}

bool is_empty()
{
return head = NULL;
}
};

bool IsNumericDigit(char C)   // check if entered character is a number (0-9)
{
if(C >= '0' && C<= '9') return true;

return false;
}

bool IsOperator (char C) // check if entered character is an operator (+,-,*,/,potence, square root)
{
if(C== '+' || C== '-' || C == '*' || C== '/'  || C== 'e' || C== 's' ) return true;
return false;
}

int PerformOperation(char operation, int operand1, int operand2)
{
if(operation == '+') return operand1 + operand2;
else if(operation == '-') return operand1 - operand2;
else if(operation == '*') return operand1 * operand2;
else if(operation == '/') return operand1 /operand2;
else if(operation == 'e') return pow(operand1, operand2);
else if(operation == 's') return sqrt(operand1);
}

int Evaluate (string expression)
{
Stack S;

for(int i =0; i< expression.length(); i++){
if( expression [i] == ' ' || expression [i] == ',') continue;

else if (IsOperator(expression[i])){
int operand2 = S.top(); S.pop();
int operand1 = S.top(); S.pop();
int result = PerformOperation (expression [i], operand1, operand2);

S.push(result);
}

else if (expression[i] == 's'){
    int operand1 = S.top(); S.pop();
    int result = PerformOperation (expression [i], operand1, -1);

    S.push(result);

}

else if (IsNumericDigit(expression[i]))
{
int operand = 0;
while (i <expression.length() && IsNumericDigit(expression[i])){
operand = (operand*10) + (expression[i]-'0');
i++;
}
i--;

S.push(operand);
}

}
 return S.top();
}

int main()
{
cout <<Evaluate(" 5 5 +")<<endl;
cout <<Evaluate(" 8 2 /")<<endl;
cout <<Evaluate(" 5 4 *")<<endl;
cout <<Evaluate(" 5 2 3 + *")<<endl;
cout <<Evaluate(" 5 2 + 3 * ")<<endl;
cout <<Evaluate(" 1 2 3 4 + + +")<<endl;
cout<< Evaluate(" 1 2 + 3 + 4 +")<<endl;
cout << Evaluate("8 2 e") << endl;
cout << Evaluate("8 2 * s") <<endl;
cout << Evaluate("7 8 + s") <<endl;
}

