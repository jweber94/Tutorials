# ```boost::algorithm``` for string processing
+ String processing is just one part of the ```boost::algorithm``` library. Boost has a _master_ header file for all string algorithms, since there are more then 20 available within the library. 
    - The _master-header_ is ```#include <boost/algorithm/string.hpp>```

## Capitalize and lowercase strings
+ You can use ```boost::algorithm::to_upper_copy``` to create a resulting capitalized string or you use ```boost::algorithm::to_upper``` to hand over the string that should be capitalized by reference (see ```example_1.cpp```)
