#ifndef _CLASS_H_
#define _CLASS_H_

#include <iostream>
#include <string>
typedef unsigned int ID;
class Base
{
    friend void check_Name(const Base &base);

public:
    // ��һ�����ͳ�Ա �û�����ʹ����
    typedef std::string::size_type name_len;
    // Base() = default;
    Base(ID temp_id = 777, std::string temp_name = "JoyBoy") : id(temp_id), len(0), name(temp_name) {}
    void set_NameId(ID temp_id, std::string temp_name);
    // Ĭ�ϲ���Ӧ�ô��������� �ڳ�Ա����������Ĭ�ϲ������ã�
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