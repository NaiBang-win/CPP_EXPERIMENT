////
////  main.cpp
////  hello_world
////
////  Created by Ding Meng on 2025/2/24.
////
////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>


#include <chrono>
#define PRINT_INFO

class MyString{
private:
    char* _data = nullptr;
    size_t _length = 0;
    //size_t capacity = 0;
public:
    ~MyString(){
#ifdef PRINT_INFO
        std::cout << "~MyString()\n";
#endif
        delete [] _data;
    }
    /*expilcit*/
    MyString() {
#ifdef PRINT_INFO
        std::cout << "MyString()\n";
#endif
    }
    MyString(const MyString& other) : _length{other._length} {
#ifdef PRINT_INFO
        std::cout << "MyString(const MyString& )\n";
#endif
        if(nullptr == other._data)
            return;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
    }
    //移动构造
    MyString(MyString&& other) : _length{other._length}, _data{other._data} {
#ifdef PRINT_INFO
        std::cout << "MyString(MyString&&)\n";
#endif
        other._data = nullptr;
    }
    MyString(const char *s) {
#ifdef PRINT_INFO
        std::cout << "MyString(const char *)\n";
#endif
        if(nullptr == s)
            return;
        _length = strlen(s);
        _data = new char[_length + 1];
        strcpy(_data, s);
    }
    //=的重载
    MyString& operator=(const MyString& other){
#ifdef PRINT_INFO
        std::cout << "MyString& operator=(const MyString&)\n";
#endif
        if(this == &other)
            return *this;
        delete [] _data;
        _data = nullptr;
        _length = other._length;
        if(0 == other._length )
            return *this;
        _data = new char[_length + 1];
        strcpy(_data, other._data);
        return *this;
    }
    const char* c_str() const {
        return _data;
    }
    char* c_str() {
        return _data;
    }
    size_t length() const{
        return _length;
    }
    bool empty() const{
        return 0 == _length;
    }
    MyString& operator+= (const MyString& other) {
        if(other.empty()){
            return *this;
        }
        if(nullptr == _data){
            *this = other;
            return *this;
        }
        char *temp = new char[_length + other._length + 1];
        strcpy(temp, _data);
        strcpy(temp + _length, other._data);

        delete [] _data;
        _data = temp;
        _length += other._length;
        return *this;
    }
    char& operator[](int idx) {
        assert(idx >= 0 && idx < _length);
        return _data[idx];
    }
    bool operator == (const MyString& other) const{
        if (strcmp(_data, other._data) == 0)
            return true;
        return false;
    }
};

std::ostream& operator<<(std::ostream& o, const MyString& str) {
    if(str.empty())
        return o;
    printf("%s", str.c_str());
    return o;
}


int main(){
    
    
    return 0;
}
