#include <bits/stdc++.h>
using namespace std;

struct et{
int value;
et* left;
et* right;
et* parent;
};

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
        return true;
    return false;
}


int prec(char c){
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/' || c == '%')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

int Map(char c)
{
    switch(c)
    {
        case '+': return -1;
        case '-': return -2;
        case '*': return -3;
        case '/': return -4;
        case '^': return -5;
	default : return 3;
    }
}


et* newNode(int v)
{
    et *temp = new et;
    temp->left = temp->right = NULL;
    temp->value = v;
    return temp;
};





et* construct_tree(stack<int> s){

    et *t,*t1,*t2;
    stack<et *> st;
    while(!s.empty())
    {
        if(s.top()>=0)
        {
            t=newNode(s.top());
            s.pop();
            st.push(t);
        }
        else
        {
            t=newNode(s.top());
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();

            t->right=t1;
            t->left=t2;

            st.push(t);
            s.pop();
        }
    }
    return t;
}





stack<int> infix_to_postfix(char *s)
{
    stack<int> st,x;
    int p=0,a;
    x.push('N');
    for(int i=0;i<strlen(s);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            if(p)
            {
                a=st.top();
                st.pop();
                st.push(a*10+s[i]-'0');
            }
            else
            {
                st.push(s[i]-'0');
                p=1;
            }
        }

        else
        {
            p=0;
            if(s[i]=='(')
                x.push('(');
            else if(s[i]==')')
            {
                while(x.top()!='N'&&x.top()!='(')
                {
                    char c=x.top();
                    x.pop();
                    st.push(Map(c));
                }
                if(x.top()=='(')
                    x.pop();
            }
            else if(isOperator(s[i]))
            {
                while(x.top()!='N'&&x.top()!='('&&prec(s[i])<=prec(x.top()))
                {
                    char c=x.top();
                    x.pop();
                    st.push(Map(c));
                }
                x.push(s[i]);
            }
        }
    }
    while(x.top()!='N')
        {
            char c=x.top();
            x.pop();
            st.push(Map(c));
        }
    return st;
}


int eval(et* root)
{

   if (!root)
        return 0;


    if (!root->left && !root->right)
        return root->value;


    int l_val = eval(root->left);


    int r_val = eval(root->right);


    if (root->value==-1)
        return l_val+r_val;

    if (root->value==-2)
        return l_val-r_val;

    if (root->value==-3)
        return l_val*r_val;

    if(root->value==-4)
        return l_val/r_val;
    return pow(l_val,r_val);
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        while(n--)
        {
            char s[100000];
            cin>>s;

            stack <int> st,s1;
            st = infix_to_postfix(s);
            while(!st.empty())
            {
                s1.push(st.top());
                st.pop();
            }

            et *p=construct_tree(s1);

            cout<<eval(p)<<endl;

        }
    }
}
