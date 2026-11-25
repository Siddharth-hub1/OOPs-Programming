#include <iostream>
using namespace std;

  // Function template for finding maximum
   template <typename T>
   T findMax(T a, T b) {
    return (a > b) ? a : b;
  }

  // Function template for finding minimum
   template <typename T>
   T findMin(T a, T b) {
    return(a < b) ? a : b;
  }

  //function template foe swapping 
   template <typename T>
   void swapValues(T &a, T &b) {
     T temp = a;
     a = b;
     b = temp;
   }
  
  // Function template for finding maximum of three values
  template <typename T>
  T findMax3(T a, T b, T c) {
    T max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
  }
 
  // Function template for finding minimum of three values
  template <typename T>
  T findMin3(T a, T b, T c) {
    T min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
  }
 
  // Function template with multipple types 
  template <typename T, typename U>
  void displayComparison(T a , U b) {
     cout << "Comparing " << a << " (type " << typeid(a).name() << ") "
          << b << "(type " << typeid(b).name() << ")" << endl;
     cout<< "Max: " << ((a > b) ? a : b) << endl;
     cout<< "Min: " << ((a < b) ? a : b) << endl;
 }
    
   int main() {
    cout << "===== Function Templates =====" << endl;

    // Integer operations
    int int1 = 10, int2 = 20;
    cout << "\n--- Integer Operations ---" << endl;
    cout << "Values: " << int1 << ", " << int2 << endl;
    cout << "Max: " << findMax(int1, int2) << endl;
    cout << "Min: " << findMin(int1, int2) << endl;

    cout << "Swapping..." << endl;
    swapValues(int1, int2);
    cout << "After swap: " << int1 << ", " << int2 << endl;
   
    // Floating point operations
    float f1 = 3.14, f2 = 2.71, f3 = 4.2;
    cout << "\n--- Floating Point Operations ---" << endl;
    cout << "Values: " << f1 << ", " << f2 << ", " << f3 << endl;
    cout << "Max (3 values): " << findMax3(f1, f2, f3) << endl;
    cout << "Min (3 values): " << findMin3(f1, f2, f3) << endl;

     // Double operations
    double d1 = 100.5, d2 = 200.7;
    cout << "\n--- Double Operations ---" << endl;
    cout << "Values: " << d1 << ", " << d2 << endl;
    cout << "Max: " << findMax(d1, d2) << endl;
    cout << "Min: " << findMin(d1, d2) << endl;
    
    
    // Character operations
    char c1 = 'M', c2 = 'A';
    cout << "\n--- Character Operations ---" << endl;
    cout << "Values: " << c1 << ", " << c2 << endl;
    cout << "Max: " << findMax(c1, c2) << endl;
    cout << "Min: " << findMin(c1, c2) << endl;

    // Mixed type operations
    cout << "\n--- Mixed Type Operations ---" << endl;
    displayComparison(10, 3.14);
    displayComparison(5.5, 3);
    displayComparison('B', 65);

     return 0;
  }