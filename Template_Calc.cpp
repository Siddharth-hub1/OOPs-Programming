#include <iostream>
#include <string>
using namespace std;

// Class template for Calculator
template <typename T>
class Calculator {
private:
    T value1;
    T value2;

public:
    // Constructor
    Calculator(T v1, T v2) {
        value1 = v1;
        value2 = v2;
    }

   // Arithmetic operations
      T add() {
        return value1 + value2;
      }

  T subtract() {
            return value1 - value2;
        }

        T multiply() {
            return value1 * value2;
        }

        T divide() {
            if (value2 == 0) {
                throw "Division by zero!";
            }
            return value1 / value2;
        }
        
       // Find larger value
    T findLarger() {
        return (value1 > value2) ? value1 : value2;
    }

    // Find smaller value
    T findSmaller() {
        return (value1 < value2) ? value1 : value2;
    }

    // Display results
    void displayResults() {
        cout << "Value 1: " << value1 << endl;
        cout << "Value 2: " << value2 << endl;
        cout << "Addition: " << add() << endl;
        cout << "Subtraction: " << subtract() << endl;
        cout << "Multiplication: " << multiply() << endl;
        try {
            cout << "Division: " << divide() << endl;
        } catch (const char* msg) {
            cout << "Division Error: " << msg << endl;
        }
        cout << "Larger Value: " << findLarger() << endl;
        cout << "Smaller Value: " << findSmaller() << endl;
    }
  };

// Specialization of class template for string
    template <>
    class Calculator<string> {
    private:
        string value1;
        string value2;

    public:
        Calculator(string v1, string v2) {
            value1 = v1;
            value2 = v2;
        }

        void setvalues(string v1, string v2) {
            value1 = v1;
            value2 = v2;
            }
           
           string add() {
             return value1 + value2;
             }
             
             string findLarger() {
              return (value1 > value2) ? value1 : value2;
           }

   string findSmaller() {
        return (value1 < value2) ? value1 : value2;
    }

    void displayResults() {
        cout << "Value 1: " << value1 << endl;
        cout << "Value 2: " << value2 << endl;
        cout << "Concatenation: " << add() << endl;
        cout << "Larger (lexicographically): " << findLarger() << endl;
        cout << "Smaller (lexicographically): " << findSmaller() << endl;
    }
};

int main() {
    cout << "***** Class Template - Calculator *****" << endl;

     // Integer Calculator
        cout << "--- Integer Calculator ---" << endl;
        Calculator<int> intCalc(10, 5);
        intCalc.displayResults();

        // Float Calculator
        cout << "--- Float Calculator ---" << endl;
        Calculator<float> floatCalc(3.14, 2.71);
        floatCalc.displayResults();

        // Double Calculator
        cout << "--- Double Calculator ---" << endl;
        Calculator<double> doubleCalc(100.5, 50.25);
        doubleCalc.displayResults();

     // String Calculator (Template Specialization)
    cout << "--- String Calculator (Specialization) ---" << endl;
    Calculator<string> stringCalc("Hello ", "World");
    stringCalc.displayResults();

    // User input for integer calculator
    cout << "--- User Input Calculator ---" << endl;
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    Calculator<int> userCalc(num1, num2);
    userCalc.displayResults();

    return 0;
}
