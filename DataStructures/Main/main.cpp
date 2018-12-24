#include <iostream>
#include <thread>

#include "../Allocator/Allocator.h"

/*! This is the main function of the DataStructures solution
 *	That's where the implemented data structures can be tested
 */
int main(int argc, char** argv)
{
    std::cout << "***** C++ Data Structures Test Class *****" << std::endl;

    //std::cout << "************** Allocator *****************" << std::endl;
    //std::cout << "Sofar this compiles only in GCC, not in VS" << std::endl;

    //allocatorTest<std::vector>();
    //allocatorTest<std::list>();
    //allocatorTest<SetWithDefaultComparator>();

    std::cout << "************** CoreCount *****************" << std::endl;

    unsigned int c = std::thread::hardware_concurrency();
    std::cout << " number of cores: " << c << std::endl;

    return 0;
}