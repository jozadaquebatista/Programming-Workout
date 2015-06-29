 /*// Function template example.
 #include <iostream>
 #include <cstdio>
 using namespace std;
 template <class X> void swapargs(X &a, X &b)// This is a function template.
    {
        X temp;
        temp = a;
        a = b;
        b = temp;
    }
 int main()
 {
    int i=10, j=20;
    double x=10.1, y=23.3;
    char a='x', b='z';
    cout << "Original i, j: " << i << ' ' << j << '\n';
    cout << "Original x, y: " << x << ' ' << y << '\n';
    cout << "Original a, b: " << a << ' ' << b << '\n';
    swapargs(i, j); // swap integers
    swapargs(x, y); // swap floats
    swapargs(a, b); // swap chars
    cout << "Swapped i, j: " << i << ' ' << j << '\n';
    cout << "Swapped x, y: " << x << ' ' << y << '\n';
    cout << "Swapped a, b: " << a << ' ' << b << '\n';
    getchar();
    return 0;
 }*/
 
#include <iostream>
 using namespace std;
 template <class type1, class type2>
    void myfunc(type1 x, type2 y)
            {
            cout << x << ' ' << y << '\n';
            }
 int main()
 {
    myfunc(10, "hi");
    myfunc(0.23, 10L);
    return 0;
 }
