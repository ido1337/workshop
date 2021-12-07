#pragma once
#include <ostream>

// This class is manage a basic string and provide simple functionality 
class StringBasic final {
public:
    StringBasic();
    StringBasic(const char* const string);

    ~StringBasic();

    /*
     * gets the lenght of the string
     * @return the lenght of the string
    */
    const unsigned long getLenght() const noexcept;

    const char operator[](std::size_t index) const;
    char& operator[](std::size_t index);

    StringBasic& operator+=(const StringBasic& rhs);
    StringBasic& operator+=(const char* const rhs);
    StringBasic& operator+=(const char& rhs);

    StringBasic operator+(const StringBasic& rhs);
    StringBasic operator+(const char* const rhs);
    StringBasic operator+(const char& rhs);

    StringBasic(const StringBasic& other);
    StringBasic& operator=(const StringBasic& other);

    StringBasic(StringBasic&& other) noexcept;
    StringBasic& operator=(StringBasic&& other) noexcept;

    
    /*
     * inserting string in a specifc offset
     * @str string to insert
     * @offset offset to insert there the string
    */
    void insert(const StringBasic& str, std::size_t offset);
    

    /*
     * replacing all of the substrings in the string with newsubstring
     * @param substring existing substring to replace
     * @param newsubstring new substring to change to
    */
    void replace(const StringBasic& substring, const StringBasic& newsubstring);

private:
    friend std::ostream& operator<<(std::ostream& strm, const StringBasic& str) noexcept;


    /*
     * adding char to the current string we got
     * @chr char to add
    */
    void add_char(const char chr);


    /*
     * adding string to the current string we got
     * @param str string to add 
     *
    */
    void add_string(const char* const str);


    /*
     * increasing the size of the char array (coping the content of the array to the new size array)
     * @param increasment in how much we want to increase
     * 
    */
    void increase_size(std::size_t increasment);

private:
    char* m_string;
    std::size_t m_lenght; // the lenght of the string not included null terminate char
    std::size_t m_size; // current size of the chars array

    const std::size_t SIZE_SCALE = 2; // in order not to waste time on allocating memory all
                                        // the time we always allocate more than we need
};