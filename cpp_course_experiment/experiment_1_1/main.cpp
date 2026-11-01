#include <iostream>
#include <cstring>
#include <assert.h>
#include <chrono>

struct MyString
{
private:
    char *_data = nullptr;
    size_t size = 0;
    //int capacity = 10;
public:
    ~MyString()
    {
        std::cout << "~MyString()\n";
        delete [] _data;
    }
    MyString()
    {

    }
    MyString(const MyString& other_string)
        :size (other_string.size)
    {
        if (other_string._data == nullptr || size == 0)
        {
            _data = nullptr;
            return;
        }
        std::cout << "MyString(const MyString& )\n";
        _data = new char[other_string.size+1];
        for (int i = 0;i<other_string.size;i++)
        {
            _data[i] = other_string._data[i];
        }
        _data[size] =0;
    }
    MyString(MyString&& other)
        :size(other.size),_data(other._data)
    {
        std::cout << "MyString(MyString&&)\n";
        other._data=nullptr;
    }
    MyString(const char* s)
    {
        std::cout << "MyString(const char *)\n";
        if (s==nullptr)
        {
            return;
        }

        size=strlen(s);
        if (size == 0)
        {
            _data = nullptr;
            return;
        }
        _data=new char[strlen(s)+1];
        strcpy(_data,s);
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
        if (size == 0 || other_string._data == nullptr)
        {
            _data = nullptr;
            return *this;
        }
        _data = new char[other_string.size+1];
        strcpy(_data,other_string._data);
        return *this;
    }
    MyString& operator+=(const MyString& other)
    {
        if (_data==nullptr)
        {
            *this = other;
            return *this;
        }
        if (other._data==nullptr)
        {
            return *this;
        }
        char *temp = new char[this->size+other.size+1];
        strcpy(temp,_data);
        strcpy(temp+size,other._data);
        delete [] _data;
        size = this->size+other.size;
        _data = temp;
        return *this;
    }
    char& operator[](int i)
    {
        assert(i>=0&&i<size);
        return _data[i];
    }
    bool empty() const
    {
        if (size==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    char* c_str() const
    {
        return _data;
    }
    MyString& operator<<(const char* s)
    {
        *this+=MyString(s);
        return *this;
    }
    MyString operator+(const MyString& b)
    {
        MyString temp=(*this);
        temp+=b;
        return temp;
    }
    size_t length() const{
        return size;
    }
};

std::ostream& operator<<(std::ostream& o, const MyString& str)
{
    if(str.empty())
        return o;
    printf("%s", str.c_str());
    return o;
}
MyString foo(MyString a)
{
    return a;
}

int main()
{
    std::cout << " 1. 基础构造 \n";
    MyString s1 = "abc";
    std::cout << "s1 = " << s1 << "，长度：" << s1.length() << "\n";
    std::cout << "\n2. 拷贝构造\n";
    MyString s2(s1);
    std::cout << "s2 拷贝自 s1：" << s2 << "\n";
    s2[1] = 'o';
    std::cout<<"执行s2[1] = 'o'"<<std::endl;
    std::cout<<"s1:"<<s1<<" s2:"<<s2<<std::endl;
    std::cout << "\n3. 拷贝赋值\n";
    MyString s3;
    s3 = s1;
    std::cout << "s3 赋值为 s1：" << s3 << "\n";
    std::cout << "\n=== 4. 字符串拼接 ===\n";
    MyString s4 = "Hello ";
    s4 += "world";
    std::cout << "s4 += \"world\" 结果：" << s4 << "\n";
    return 0;
}
// int main()
// {
//     const int test_count = 1;
//     auto start = std::chrono::steady_clock::now();
//     for (int i = 0; i < test_count; ++i)
//     {
//         MyString s("abc");
//         MyString ST = foo(s);
//     }
//     auto end = std::chrono::steady_clock::now();
//     auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
//     std::cout << "10万次总耗时：" << total_us.count() << " 微秒" << std::endl;
//     std::cout << "平均单次耗时：" << 1.0 * total_us.count() / test_count << " 微秒" << std::endl;
//
//     return 0;
// }

