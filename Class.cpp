#include "Class.h"
#include <iostream>
#include <string>

void Base::set_NameId(ID temp_id, std::string temp_name)
{
    // trycatch ���Բ����쳣
    this->id = temp_id;
    this->name = check_NameLength(temp_name);
}
void Base::set_NameId(std::string temp_name)
{
    // Create a temproray object to pass private member , would that be better?
    this->name = check_NameLength(temp_name);
}
void Base::show_NameId()
{
    std::cout << this->id << " " << this->name << std::endl;
}
// ���Name�Ϸ��� Using "trycatch" to catch Exception , but now Using "if else" to simplify method.
// check_NameLength������ֱ�Ӵ�std::cin��ȡ���룬������ķ�����ͨ������һ���õ�ʵ����
// ��Ϊ��ʹ�ø÷����������ⲿ���룬�������临���ԺͿɲ����ԡ�
std::string Base::check_NameLength(std::string temp_name) const
{
    std::string new_name = temp_name;

    while ((new_name).size() > 10)
    {
        // Security Check for name.
        std::cout << "Your name is too long more than 10 characters. " << std::endl;
        std::cout << "Please enter again. " << std::endl;
        std::cin >> new_name;
    }
    // Modifying a member function to const in a class indicates that an objecct's data menmbers cannot be modified
    //  and non-const funciton cannot be called within that funciton
    // In const function , Only const function can be called.
    // this->len = new_name.size();
    std::cout << "Your name can be used. " << std::endl;
    return new_name;
}
int main()
{
    Base base_1;
    Base base_2;
    base_2.set_NameId("edward*newgate");

    base_1.show_NameId();
    base_2.show_NameId();
    // check_Name(base_1);
    // check_Name(base_2);
    return 0;
}