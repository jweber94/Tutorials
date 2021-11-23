# String processing with ```boost```

+ Boost gives you a lot of algorithms and functions to conveniently processing string and string streams
+ Main components of the string processing part of the boost library is: 
    - ```boost::string_algorithms```: Tailored algorithms for processing strings, like capitalization or lowercasing 
    - ```boost::lexical_cast```: Casting/converting strings to other datatypes like int, double, ...
    - ```boost::format```: Type safe conversion to ```std::string``` via ```std::printf```. You can use you own datastructures by overloading the ```<<``` and ```>>``` operators
    - ```boost::regex```: Search through string with regular expressions (```boost::xpressive``` can be used to work with plain C++ code instead of regular expressions)
    - ```boost::tokenizer```: Iterate over substrings by defining separator elements
    - ```boost::spirit```: Can be used to define your own parsers