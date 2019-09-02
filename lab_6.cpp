#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main()
{
    pair<ll, ll> p;
    p = {-1, -1};
    ll no_of_queries;
    ll no_of_users;
    cin >> no_of_users >> no_of_queries;
    vector<pair<ll, ll>> v;
    int x = 0;
    while (no_of_queries--)
    {
        cin >> x;
        if (x == 1)
        {
            ll userid, amount, i;
            cin >> userid >> amount;
            if (v.empty())
            {
                v.push_back({userid, amount});
            }
            else
            {
                for (i = 0; i < v.size(); i++)
                {
                    if (userid == v[i].first)
                    {
                        v[i].second += amount;
                        amount=v[i].second;
                        break;
                    }
                }
                if (i == v.size())
                {
                    v.push_back({userid,amount});
                }
            }
            if (amount > p.second)
            {
                p = {userid,amount};
            }
        }
        else if (x == 2)
        {
            if (p.first == -1)
            {
                cout << "No data available\n";
            }
            else
            {
                cout << p.first << "\n";
            }
        }
        else cout<<"Invalid input\n";
    }
}
