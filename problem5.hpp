// problem5.hpp

#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <string>



class ArrayList
{
public:
    ArrayList();

    ArrayList(const ArrayList& array);

    ~ArrayList();
    
    ArrayList& operator=(const ArrayList& array);

    std::string& at(unsigned int index);

    const std::string& at(unsigned int index) const;

    void add(const std::string& s);

    unsigned int size() const;

    unsigned int capacity() const;

private:
    std::string* items;
    unsigned int sz;
    unsigned int cap;
};




#endif