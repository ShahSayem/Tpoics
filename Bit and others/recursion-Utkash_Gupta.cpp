#include <bits/stdc++.h>
#define   ll   long long
using namespace std;


void say_hello_n_1(int n)
{
    if (n == 0) //Base case
        return;

    cout<<"Hello "<<n<<"\n";
    say_hello_n_1(n-1);
}

void say_hello1_n(int n)
{
    if (n == 0) //Base case
        return;

    say_hello1_n(n-1);
    cout<<"Hello "<<n<<"\n";
}

int sum1_n(int n)
{
    if (n == 0)
        return 0;

    int left_part = sum1_n(n-1);
    return left_part + n;
}

int sum_digits(int n)
{
    if (n == 0)
        return 0;
    
    int last_digit = n%10;
    int remaining = n/10;
    return sum_digits(remaining) + last_digit;
}

int fact(int n)
{
    if (n == 1)
        return 1;

    ll x = n*fact(n-1);
    return x;
}

void pattern_print1(int n)
{
    if (n == 0)
        return;
    
    pattern_print1(n-1);
    for (int i = 1; i <= n; i++){
        cout<<i<<" ";
    }
    cout<<"\n";   
}

void pattern_print2(int n)
{
    if (n == 0)
        return;

    for (int i = 1; i <= n; i++){
        cout<<i<<" ";
    }
    cout<<"\n";
    pattern_print2(n-1);   
}

void pattern_print3(int n)
{
    if (n == 1){
        cout<<1<<"\n";
        return;
    }

    for (int i = 1; i <= n; i++){
        cout<<i<<" ";
    }
    cout<<"\n";

    pattern_print3(n-1);

    for (int i = 1; i <= n; i++){
        cout<<i<<" ";
    }
    cout<<"\n";    
}

int fibo(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    
    return fibo(n-1) + fibo(n-2);
}

bool palindrome(string s, int i)
{
    if (i > s.size()/2)
        return true;

    return s[i] == s[s.size()-i-1] && palindrome(s, i+1);
}

int main()
{
    say_hello1_n(7);
    cout<<"\n";

    say_hello_n_1(5);
    cout<<"\n";

    cout<<"Sum till n: ";
    cout<<sum1_n(5);
    cout<<"\n\n";

    cout<<"Sum of digits: ";
    cout<<sum_digits(786);
    cout<<"\n\n";

    cout<<"Factorial: ";
    cout<<fact(4);
    cout<<"\n\n";

    pattern_print1(8);
    cout<<"\n";

    pattern_print2(5);
    cout<<"\n";

    pattern_print3(4);
    cout<<"\n";

    cout<<5<<"th Fibonacci number: ";
    cout<<fibo(5);
    cout<<"\n";

    string s = "lool";
    if (palindrome(s, 0))
        cout<<"Palindrome\n";
    else
        cout<<"Not Palindrome\n";

    return 0;
}
    