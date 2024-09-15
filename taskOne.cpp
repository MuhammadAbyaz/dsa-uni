#include <iostream>
#include <string>
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
        if (top == capacity){
            resize();
        }
        stack[++top] = value;
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
            cout << stack[i]<< " ";
        }
    }

    static string reverseString(string word)
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
            else if (s[i] != '#')
            {
            sStack.push(s[i]); 
            }
        }
        for (int i =0 ; i < t.length(); ++i){
            if (t[i] == '#' && !tStack.isEmpty())
            {
                tStack.pop();
            }
            else if (t[i] != '#')
            {
            tStack.push(t[i]); 
            }
        }

        if (sStack.size() != tStack.size())
        {
            return false;
        }
        while (!sStack.isEmpty() && !tStack.isEmpty())
        {
            char sValue = sStack.pop();
            char tValue = tStack.pop();
            if (sValue != tValue){return false;}
        }
        return true;
    }
    static int fibonacciGenerator(int n)
    {
        if (n <= 1){
            return n;
        }
        return fibonacciGenerator(n -1) + fibonacciGenerator(n -2);
    };
};

int main()
{
    return 0;
}
// First Question
    // Abyaz_Lab03<int> stack;
    // cout << stack.pop() << endl;
    // cout << "Is stack empty: " << boolalpha << stack.isEmpty() << endl;
    // stack.push(10);
    // stack.push(20);
    // cout << "Stack's top: " << stack.peek() << endl;
    // cout << "Is stack empty: " << boolalpha << stack.isEmpty() << endl;
    // cout << "Stack size: " << stack.size() << endl;
    // cout << "Displaying stack" << endl;
    // stack.display();

// Second question
    // string word;
    // cout << "Enter word you want to reverse: ";
    // cin >> word;
    // cout << "Reversed Word: " << Abyaz_Lab03<char>::reverseString(word);

// Third question
    // string word;
    // cout << "Enter word to check whether its a palindrome or not: " << endl;
    // cin >> word;
    // cout << boolalpha << Abyaz_Lab03<char>::checkPalindrome(word) << endl;

// Fourth question
    // string firstWord;
    // string secondWord;
    // cout << "Enter first word: ";
    // cin >> firstWord;
    // cout << "Enter second word: ";
    // cin >> secondWord;
    // cout << boolalpha << Abyaz_Lab03<char>::stringComparison(firstWord, secondWord) << endl;

// Fifth question
    // int n;
    // cout << "Enter number term you want in the series: ";
    // cin >> n;
    // Abyaz_Lab03<int> stack;
    // for(int i = 1; i <= n; ++i){
    //     stack.push(Abyaz_Lab03<int>::fibonacciGenerator(i));
    // }
    // while (!stack.isEmpty())
    // {
    //     cout << stack.pop() << " ";
    // }