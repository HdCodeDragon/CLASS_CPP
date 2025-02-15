#ifndef _CLASS_H_
#define _CLASS_H_

#include <iostream>
#include <string>
typedef unsigned int ID;
class Base
{
    friend void check_Name(const Base &base);

public:
    // 定一个类型成员 用户可以使用其
    typedef std::string::size_type name_len;
    // Base() = default;
    Base(ID temp_id = 777, std::string temp_name = "JoyBoy") : id(temp_id), len(0), name(temp_name) {}
    void set_NameId(ID temp_id, std::string temp_name);
    // 默认参数应该从右至左定义 在成员函数中设置默认参数不好，
    // void set_NameId(std::string temp_name, temp_id = 777);
    void set_NameId(std::string temp_name);
    inline void show_NameId();
    // Security check for Name
    std::string check_NameLength(std::string temp_name) const;

private:
    ID id;
    name_len len;
    std::string name;
};
void check_Name(const Base &base)
{
    std::cout << base.id << std::endl;
}
#endif