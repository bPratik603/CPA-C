#include <iostream> 
#include <string> 
#include <vector> 

int main(void)
{
    std::vector<std::string> str_vec; 
    std::cout << "CPP VERSION" << std::endl; 
    str_vec.push_back(std::string("Hello")); 
    str_vec.push_back(std::string("World")); 
    str_vec.push_back(std::string("CoreCode")); 
    str_vec.push_back(std::string("Programming")); 
    str_vec.push_back(std::string("Academy")); 

    for(std::vector<std::string>::size_type i = 0; 
        i != str_vec.size(); 
        ++i)
            std::cout << "str_vec[" << i << "]:" << str_vec[i] << std::endl; 

    return (0); 
}