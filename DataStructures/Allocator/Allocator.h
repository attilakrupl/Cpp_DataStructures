#pragma once

#include <atomic>
#include <memory>

#include <iostream>
#include <vector>
#include <list>
#include <set>

namespace my 
{
    std::atomic_int g_memory_used(0);
    
    template <typename T>
    class Allocator : public std::allocator<T>
    {
        private:
            using Base = std::allocator<T>;
            using Pointer = typename std::allocator_traits<Base>::pointer;
            using SizeType = typename std::allocator_traits<Base>::size_type;
            
        public:
            Allocator() = default;

            template <typename U>
            Allocator( const Allocator<U>& other )
                :Base( other )
            {}

            template <typename U>
            struct rebind
            {
                using other = Allocator<U>;
            };
            
            Pointer allocate(SizeType n)
            {
                g_memory_used.fetch_add( n * sizeof(T));
                return Base::allocate(n);
            }
            
            void deallocate(Pointer p, SizeType n)
            {
                g_memory_used.fetch_sub(n * sizeof(T));
                Base::deallocate(p, n);
            }
    };

}

template <template <typename T, typename AllocT> typename ContainerT>
void allocatorTest()
{
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "Memory usage before: " << my::g_memory_used.load() << std::endl;
    ContainerT<int, my::Allocator<int> > container;
    for ( int i = 0; i < 1000; ++i)
    {
        container.insert(std::end(container), i);
    }
    std::cout << "Memory usage after: " << my::g_memory_used.load() << std::endl;
}

template <typename T, typename AllocT>
using SetWithDefaultComparator = std::set<T, std::less<>, AllocT>;