#include <iostream>
using namespace std;
int main()
{
    // Integer Types
    int mainInt;            // Standard integer type (can hold positive and negative numbers)
    short mainShort;        // Typically 16 bits (shorter integer type)
    long mainLong;          // Typically 32 bits (longer integer type)
    long long mainLongLong; // At least 64 bits (Introduced in C++11, very large integer type)
    unsigned int mainUInt;  // Unsigned integer (can only hold non-negative numbers)

    // Floating-Point Types
    float mainFloat;            // Single-precision floating point (approximate real numbers)
    double mainDouble;          // Double-precision floating point (more precision than float)
    long double mainLongDouble; // Higher precision floating point (even more precision than double)

    // Character Types
    char mainChar;           // Typically holds a single ASCII character (like 'a', 'B', '$', etc.)
    unsigned char mainUChar; // Only holds positive values (values from 0 to 255)
    signed char mainSChar;   // Holds both positive and negative values (values from -128 to 127)
    wchar_t mainWChar;       // Wide character type (used for representing wide characters, like Unicode)

    // Boolean Type
    bool mainBool; // Holds true or false (used for conditions and logic)

    // Void Type
    void mainVoid; // Denotes absence of type (used when a function doesn't return a value)

    // Derived Data Types

    // Array of integers (a collection of similar data items)
    int mainArray[5];

    // Pointer to an integer (stores the memory address of another variable)
    int *mainPointer;

    // Reference to an integer (similar to a pointer, but must be initialized when declared and cannot be NULL)
    int &mainReference = mainInt;

    // Function returning an integer (a block of code that performs a specific task)
    int mainFunction(int x)
    {
        return x * x;
    }

    // Structure with two integers (a user-defined data type that groups related data together)
    struct Point
    {
        int x, y;
    } mainPoint;

    // Union with integer, float, and character (shares memory for all its members)
    union Data
    {
        int i;
        float f;
        char c;
    } mainData;

    // Enumeration for days of the week (a user-defined data type consisting of integral constants)
    enum Days
    {
        Sun,
        Mon,
        Tue,
        Wed,
        Thu,
        Fri,
        Sat
    } mainDay;

    // User-Defined Types

    // User-defined class (a complex data type that can have data members and member functions)
    class MyClass
    {
        int classMember;
    };

    // User-defined struct (similar to a class but with default public members)
    struct MyStruct
    {
        int structMember;
    };
}