#include <iostream>
#include <string>

#include <boost/tokenizer.hpp>

int main()
{
    std::cout << "Start program\n"; 
        // Define string for the tokenizing
    std::wstring s = L"Boost C++ Libraries";  
        // Reference wstring: https://stackoverflow.com/questions/402283/stdwstring-vs-stdstring and wchar_t: https://docs.microsoft.com/de-de/cpp/cpp/char-wchar-t-char16-t-char32-t?view=msvc-170
        // https://stackoverflow.com/questions/38649540/why-is-there-an-l-when-assigning-a-wstring --> L"" is the prefix for wchar_t to make the compiler know that you want to use a string made 
        // out of wchar_t instead of the char on the rvalue 
    boost::char_separator<wchar_t> sep{L" ", L"+"};

        // Create tokenizer instance
    boost::tokenizer<boost::char_separator<wchar_t>, std::wstring::const_iterator, std::wstring> tok{s, sep};  

    for (const auto & t : tok)
    {
        std::wcout << t << '\n';
    }
    std::cout << "Finished program\n"; 
    return 0; 
}