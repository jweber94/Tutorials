# ```boost::accumulators``` 
+ Is a combination of a container structure with dedication of number datatypes
+ Accumulators are commonly used for measurement data, since it allows to calculate statistical characteristics natively (which is not possable by default with the STL containers)
+ Another special property is that every time we insert new elements to the accumulator container, the statistical characteristics get evaluated again with the newly added data
+ The accumulator library hands over an interface, how you can implement your own accumulator class. 
    - If you want to do this, you need to work more deeply with the framework
    - If you just want to use the standart accumulators from the library, you will use ```boost::accumulators::accumulator_set which is within the header boost/accumulators/accumulators.hpp
+ The Header boost/accumulators/statistics.hpp contains all accumulator structures, that the library delivers by default    
    - But remember, if you lookup the interface, you can write your own!
+ Accumulators deliver operators to do calculations with for example complex numbers (```std::complex```), int or (mathmatical) vectors 
    - Therefore you need to include ```boost/accumulators/numeric/functional.hpp```
    - In order to use this operators, you need to define their macros 
        - e.g. ```BOOST_NUMERIC_FUNCTIONAL_STD_COMPLEX_SUPPORT``` 

## Usage
+ The basis of all accumulators is an instance of the class ```boost::accumulators::accumulator_set```. 
    - Is a template with ```<a, b>```: 
        - ```a```: Datastructure that we want to use in order to accumulate things
        - ```b```: Defines the accumulators tags/options that we want to use. To be a little more specific, with ```b``` you define _WHAT_ should be calculated and not _HOW_ the calculation should be done. The explicit calculation is then defined by the accumulator itself, which is called in the background by the tag that was handed over in the template definition. CAUTION: You can hand over multiple template parameters for ```b```, since the accumulator_set is implemented as a variadic template.
            - The parameter needs to use the ```boost::accumulators::features``` template as its input. 
    - After the creation of an instance of the ```accumulator_set``` template class, you can call it as a function with the ```()```-Operator to hand over values. If you insert new values, the handed over tags of the template argument ```b``` get immediatly calculated.
    - For every tag in the ```b``` argument, there is a corresponding ***extractor***. If you call the extractor with you accumulator_set, you will receive the corresponding values of the extractor. 