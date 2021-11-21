# ```boost::tokenizer```
+ ```boost::tokernizer``` and its associated functions and classes are used to process ```std::string``` elements by iterating over them with a self defined tokenizer logic. 
+ The tokenizer class is template based and you can work with the tokenized parts of the handed over string by accessing the parts with iterator elements, which result from the ```boost::tokenizer```
    - You can iterate over the string elements in the tokenized base string by iterating from the ```boost::tokenizer::begin()``` to the ```boost::tokenizer::end()``` iterator. 

## Usage
+ You have to hand over the ```boost::tokenizer<T>``` a separator class (*not* an instance of the class, just the class type), that describes how the tokenizer should separate the ```std::string``` that it has received during initialization
    - e.g.: ```boost::char_separator``` is from the ```#include <boost/tokenizer.hpp>``` and separates spaces as well as punctuation marks (, ; : ? ! - < > [] {} usw.) but also prints the punctuaion marks 
    - You ***can*** define punctuation marks that get showed by the tokenizer and punctuation marks that get surpressed by the tokenizer
         - By default, only spaces get surpressed by the ```boost::char_separator``` and all other punctuation marks get printed
    - If you want to specify the punctuation marks that are printed or surpressed as well as which punctuation marks are used for separation of the base string of the ```boost::tokenizer```, you have to define a ```boost::char_separator``` instance and hand it over to the ```boost::tokenizer<T>``` with the base string to construct the tokenizer instance. 
        - The constructor of ```boost::char_separator<char>``` can receive three arguments but only the first one is mandatory for initialization
            - 1. argument: Describes the separators that the be surpessed within the output (see ```example_2.cpp```)
            - 2. argument: Describes the separators that should not be surpressed (i.e. printed or added to the tokenized part strings). If you don't hand over a second argument to the char_separator, no separators are defined that should separate the base string *and* printed out to the scree/inserted in the tokenized strings (see ```example_3```)
            - 3. argument: Says if empty partial expressions should be surpessed or not. (An empty partial expression is defined by two sepatators next to each other) (see ```example_4.cpp```)
## Additional functionallities
+ The tokenizer library gives you the possabiliy to work with wstrings (see ```example_5.cpp```) 
+ If you want to tokenize a string that describes the read out from a ```.csv``` file, you can use a ```boost::tokenizer<boost::escaped_list_separator<char> >``` to tokenize the strings
    - CAUTION: This also treads the ```\n``` as a comma! 
+ If you want to define on which indices the given string should be tokenized, you can use a ```boost::offset_separator``` instance (see ```example_7.cpp```)