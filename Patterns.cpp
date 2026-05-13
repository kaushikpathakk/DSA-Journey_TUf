#include <iostream>
using namespace std;
void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}
void pattern4(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}
void pattern5(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " * ";
        }
        cout << endl;
    }
}
void pattern6(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1;
        }
        cout << endl;
    }
}
void pattern7(int n)
{

    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern8(int n)
{

    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern9(int n)
{

    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * i + 1; j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        // star
        for (int j = 0; j < 2 * (n - i); j++)
        {
            cout << "*";
        }

        // space
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern10(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void pattern11(int n)
{
    int j;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            for (j = 1; j <= i + 1; j++)
            {
                if (j % 2 != 0)
                {
                    cout << " 0 ";
                }
                else
                {
                    cout << " 1 ";
                }
            }
        }
        else
        {
            for (j = 1; j <= i + 1; j++)
            {
                if (j % 2 == 0)
                {
                    cout << " 0 ";
                }
                else
                {
                    cout << " 1 ";
                }
            }
        }
        cout << endl;
    }
}
void pattern12(int n)
{
    int space = 2 * (n - 1);
    for (int i = 1; i <= n; i++)
    {
        // numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        // space
        for (int j = 0; j <= space; j++)
        {
            cout << " ";
        }
        // numbers
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << endl;
        space -= 2;
    }
}
void pattern13(int n)
{
    int temp = 1;
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= i; j++)
        {
            cout << temp << " ";
            temp += 1;
        }
        cout << endl;
    }
}
void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + i; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern15(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (char ch = 'A'; ch <= 'A' + i - 1; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}
void pattern17(int n)
{

    for (int i = 0; i < n; i++)
    { // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        // character
        char ch = 'A';
        int breakpopint = (2 * i + 1) / 2;
        for (int j = 1; j <= 2 * i + 1; j++)
        {
            cout << ch;
            if (j <= breakpopint)
                ch++;
            else
                ch--;
        }

        // space
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void pattern18(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + n - i;
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}
void pattern19(int n)
{
    int space = 0;

    // 🔼 upper part
    for (int i = 0; i < n; i++)
    {
        // left stars
        for (int j = 0; j < n - i; j++)
            cout << "* ";

        // space
        for (int j = 0; j < space; j++)
            cout << "  ";

        // right stars
        for (int j = 0; j < n - i; j++)
            cout << "* ";

        space += 2;
        cout << endl;
    }

    // 🔽 lower part
    space = 2 * (n - 1);

    for (int i = 1; i <= n; i++)
    {
        // left stars
        for (int j = 0; j < i; j++)
            cout << "* ";

        // space
        for (int j = 0; j < space; j++)
            cout << "  ";

        // right stars
        for (int j = 0; j < i; j++)
            cout << "* ";

        space -= 2;
        cout << endl;
    }
}
void pattern20(int n){
   for( int i = 0;  i < n ; i++){
    for ( int j =0 ; j< n ; j++){
        if( i==0 || j==0 || i==n-1|| j==n-1 ){
            cout<<"*";
        }
        else cout<<" ";
    }
    cout<<endl;
   }        
}
void pattern21( int n ){
    for (int i = 0; i < 2*n-1; i++)
    {
       for(int j = 0; j < 2*n-1; j++){
        int top = i;
        int left =j;
        int right = (2*n-2)-j;
        int down = (2*n-2)-i;
        cout<<(n - min(min( top , left), min( right , down)));
       }
       cout<<endl;
    }
    
}
int main()
{
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    int t;
    cout << " done " << endl;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        pattern2(n);
    }

    return 0;
}
//      https://www.skills.google/public_profiles/11c7cb70-d769-43ad-a9c7-f65e6376c2cc