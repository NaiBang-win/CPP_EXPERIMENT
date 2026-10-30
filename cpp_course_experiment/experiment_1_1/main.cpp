#include <iostream>
#include <string.h>
struct MyString
{
private:
    char *_data = nullptr;
    size_t size = 0;
    //int capacity = 10;
public:
    ~MyString()
    {
        delete [] _data;
    }
    MyString()
    {

    }
    MyString(const MyString& other_string)
        :size (other_string.size)
    {
        _data = new char[capacity];
        for (int i = 0;i<other_string.size;i++)
        {
            _data[i] = other_string._data[i];
        }
    }
    MyString& operator=(const MyString& other_string)
    {
        if (this==&other_string)
        {
            return *this;
        }
        delete [] _data;
        size = other_string.size;
        _data = nullptr;
        if (other_string.size==0)
        {
            return *this;
        }
        _data = new char[other_string.size+1];
        strcpy(_data,other_string._data);
        return *this;
    }
};
int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
