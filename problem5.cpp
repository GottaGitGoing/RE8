#include "problem5.hpp"
#include <stdexcept>
#include <iostream>
#include <string>


namespace
{

    const unsigned int initialCapacity = 10;


    void arrayCopy(std::string* target, std::string* source, unsigned int size)
    {
        for (unsigned int i = 0; i < size; i++)
        {
            target[i] = source[i];
        }
    }
}



ArrayList::ArrayList()
    : items{new std::string[initialCapacity]}, sz{0}, cap{initialCapacity}
{
//    std::cout << "ArrayList::ArrayList()" << std::endl;
}



ArrayList::ArrayList(const ArrayList& a)
    : items{new std::string[a.cap]}, sz{a.sz}, cap{a.cap}
{
//    std::cout << "ArrayList::ArrayList(const ArrayList&)" << std::endl;
    arrayCopy(items, a.items, sz);
}



ArrayList::~ArrayList()
{
//    std::cout << "ArrayList::~ArrayList()" << std::endl;
    delete[] items;
}




ArrayList& ArrayList::operator=(const ArrayList& a)
{
//    std::cout << "ArrayList& ArrayList::operator=(const ArrayList&)" << std::endl;

    if (this != &a)
    {
        std::string* newItems = new std::string[a.cap];
        try
        {
            arrayCopy(newItems, a.items, a.sz);
        }
        catch(const std::bad_array_new_length& e)
        {
            std::cout << "Copy Failed in Overloading operator, sz is corrupted " 
                      << e.what() << '\n';
            delete[] newItems;
        }
        
        

        sz = a.sz;
        cap = a.cap;

        delete[] items;
        items = newItems;
    }

    return *this;
}



std::string& ArrayList::at(unsigned int index)
{
    std::string potential_error = "Invalid Index: " + std::to_string(index) + 
                                   " Cannot go beyond Index Size: " +
                                    std::to_string(this->size()-1);

    if (index >=sz || index<0)
    {
        throw std::out_of_range(potential_error);
    }
    
    return items[index];
}


const std::string& ArrayList::at(unsigned int index) const
{
    std::string potential_error = "Invalid Index: " + std::to_string(index) + 
                                   " Cannot go beyond Index Size: " +
                                    std::to_string(this->size()-1);
    if (index >=sz || index<0)
    {
        throw std::out_of_range(potential_error);
    }
    return items[index];
}



void ArrayList::add(const std::string& s)
{
    if (sz == cap)
    {
        int newCap = cap * 2 + 1;

        std::string* newItems = new std::string[newCap];
        try
        {
            arrayCopy(newItems, items, sz);
        }
        catch(const std::bad_alloc& e)
        {
            std::cout << " Copy failed.. Invalid Resizing" << e.what() << std::endl;
            delete[] newItems;
        }
        
        

        cap = newCap;

        delete[] items;
        items = newItems;
    }

    items[sz] = s;
    sz++;
}




unsigned int ArrayList::size() const
{
    return sz;
}


unsigned int ArrayList::capacity() const
{
    return cap;
}

