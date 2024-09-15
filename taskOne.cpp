#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
template <typename T>

class Abyaz_Lab03
{
private:
    int capacity;
    T *stack;
    int top;

public:
    Abyaz_Lab03()
    {
        top = -1;
        capacity = 50;
        stack = new T[capacity];
    }
    ~Abyaz_Lab03()
    {
        delete[] stack;
    }

    void push(T value)
    {
        if (top < capacity)
        {
            stack[++top] = value;
        }
        else
        {
            cout << "Error: Stack overflow!! You can try calling resize function to resize the stack" << endl;
        }
    }

    T pop()
    {
        if (top > -1)
        {
            T valueToReturn = stack[top];
            stack[top--] = 0;
            return valueToReturn;
        }
        else
        {
            cout << "Error: There is nothing in stack to pop!!" << endl;
            return -1;
        }
    }

    T peek()
    {
        if (top > -1)
        {
            return stack[top];
        }
        else
        {
            return -1;
        }
    }
    bool isEmpty()
    {
        return top == -1 ? true : false;
    }
    int size()
    {
        return top + 1;
    }
    void resize()
    {
        int newCapacity = capacity * 2;
        T *temp = new T[newCapacity];
        for (int i = 0; i <= top; ++i)
        {
            temp[i] = stack[i];
        }
        delete[] stack;
        stack = temp;
        capacity = newCapacity;
    }
    void display()
    {
        for (int i = top; i > -1; --i)
        {
            cout << stack[i];
        }
    }

    static std::string reverseString(string word)
    {
        Abyaz_Lab03<char> stack;
        for (int i = 0; i < word.length(); ++i)
        {
            stack.push(word[i]);
        }
        string reversedWord = "";
        while (!stack.isEmpty())
        {
            reversedWord += stack.pop();
        }
        return reversedWord;
    }

    static bool checkPalindrome(string word)
    {
        Abyaz_Lab03<char> stack;
        int counter = 0;
        for (int i = 0; i < word.length(); ++i)
        {
            stack.push(word[i]);
        }
        while (!stack.isEmpty())
        {
            if (stack.pop() != word[counter])
            {
                return false;
            }
            counter++;
        }
        return true;
    }
    static bool stringComparison(string s, string t)
    {
        Abyaz_Lab03<char> sStack;
        Abyaz_Lab03<char> tStack;

        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '#' && !sStack.isEmpty())
            {
                sStack.pop();
            }
            if (t[i] == '#' && !tStack.isEmpty())
            {
                tStack.pop();
            }
            else
            {

                sStack.push(s[i]);
                tStack.push(t[i]);
            }
        }

        if (sStack.size() != t.size())
        {
            return false;
        }
        while (!sStack.isEmpty() && !tStack.isEmpty())
        {
            if (sStack.pop() != tStack.pop())
                return false;
        }
        return true;
    }
    static void fibonacciGenerator(int n)
    {
        if (n <= 1)
        {
            cout << n << endl;
        }
        Abyaz_Lab03<int> fibonacciStack;
        int first = 0;
        int result = 0;
        int second = 1;
        fibonacciStack.push(0);
        fibonacciStack.push(1);
        for (int i = 2; i <= n; ++i)
        {
            result = first + second;
            fibonacciStack.push(result);
            first = second;
            second = result;
        }
        while (!fibonacciStack.isEmpty())
        {
            cout << fibonacciStack.pop() << endl;
        }
    };
};

int main()
{
    Abyaz_Lab03<int> stack;
    cout << stack.pop() << endl;
    cout << stack.isEmpty() << endl;
    stack.push(10);
    stack.push(20);
    cout << stack.peek() << endl;
    cout << stack.isEmpty() << endl;
    cout << stack.size() << endl;
    stack.display();
    return 0;
}
// // Second question
// string word = "hello";

// // Third question
// string word4 = "hello";
// cout << Abyaz_Lab03<char>::reverseString(word4) << endl;

// // Fourth question
// string word2 = "dad";
// cout << boolalpha << Abyaz_Lab03<char>::checkPalindrome(word2) << endl;
// string word3 = "hello";
// cout << boolalpha << Abyaz_Lab03<char>::checkPalindrome(word3) << endl;

// // Fifth question
// string s = "ab#c";
// string t = "ad#c";
// cout << boolalpha << Abyaz_Lab03<char>::stringComparison(s, t) << endl;

// // Sixth question
// Abyaz_Lab03<int>::fibonacciGenerator(5);
// return 0;
// }