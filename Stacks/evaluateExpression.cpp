/* Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*/

int Solution::evalRPN(vector<string> &A) {
stack<string> s;
int n1, n2;
string q;
for(int i=0; i<A.size(); i++)
{
    if(A[i]!= "+" && A[i]!= "-" && A[i]!= "*" && A[i]!= "/")
        s.push(A[i]);
    else
    {
        q=s.top();
        n1=stoi(q);
        s.pop();
        
        q=s.top();
        n2=stoi(q);
        s.pop();
        
        if(A[i]=="+")
            n2=n2+n1;
        if(A[i]=="-")
            n2=n2-n1;
        if(A[i]=="*")
            n2=n2*n1;
        if(A[i]=="/")
            n2=n2/n1;
            
        s.push(to_string(n2));
    }
}
q=s.top();
n2=stoi(q);
return n2;
}