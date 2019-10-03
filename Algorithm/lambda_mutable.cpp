#include <vector>
#include <string>
#include <list>
#include <iterator>

#include "all_function.h"

int LambdaMutable() {

    {
        size_t v1 = 42;
        // auto f = [v1]() { return ++v1; }; //error
        v1 = 0;
        //auto j = f();
    }
    {
        size_t v1 = 42;
        auto f = [v1]() mutable { return ++v1; };
        v1 = 0;
        auto j = f(); // j = 43
    }
    {
        size_t v1 = 42;
        auto f = [&v1]() mutable { return ++v1; };
        v1 = 0;
        auto j = f(); // j = 1
    }
    return 0;
}

int LambdaTransform() {

    std::vector<int> vi{ 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) {return i < 0 ? -i : i; });

    vi = { 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) 
        {
            if (i < 0) return -i; else return i;
        });
    vi = { 1, -1, -2,2 };
    transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int
        {
            if (i < 0) return -i; else return i;
        });

    {
        typedef std::list<int> L;
        L l(5);
        typedef L::const_iterator CI;
        CI cb = l.begin(), ce = l.end();
        typedef L::iterator I;
        I b = l.begin();
        std::transform(cb, --ce, ++b, [](CI::value_type n) {return ++n; });
        /*template <class InputIterator, class OutputIterator, class UnaryOperator>
      OutputIterator transform (InputIterator first1, InputIterator last1,
                                OutputIterator result, UnaryOperator op)
    {
      while (first1 != last1) {
        *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
        ++result; ++first1;
      }
      return result;
    }*/
        std::copy(l.begin(), l.end(), std::ostream_iterator < CI::value_type >(std::cout));
        std::cout << std::endl;
    }
    {
        typedef std::list<int> L;
        L l(5);
        typedef L::const_iterator CI;
        CI cb = l.begin(), ce = l.end();
        typedef L::iterator I;
        I b = l.begin();
        std::transform(cb, --ce, b, [](CI::value_type n) {return ++n; });
        /*template <class InputIterator, class OutputIterator, class UnaryOperator>
      OutputIterator transform (InputIterator first1, InputIterator last1,
                                OutputIterator result, UnaryOperator op)
    {
      while (first1 != last1) {
        *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
        ++result; ++first1;
      }
      return result;
    }*/
        std::copy(l.begin(), l.end(), std::ostream_iterator < CI::value_type >(std::cout));
        std::cout << std::endl;
    }
    {
        typedef std::list<int> L;
        L l(5);
        typedef L::const_iterator CI;
        CI cb = l.begin(), ce = l.end();
        typedef L::iterator I;
        I b = l.begin();
        std::transform(cb, ce, b, [](CI::value_type n) {return ++n; });
        /*template <class InputIterator, class OutputIterator, class UnaryOperator>
      OutputIterator transform (InputIterator first1, InputIterator last1,
                                OutputIterator result, UnaryOperator op)
    {
      while (first1 != last1) {
        *result = op(*first1);  // or: *result=binary_op(*first1,*first2++);
        ++result; ++first1;
      }
      return result;
    }*/
        std::copy(l.begin(), l.end(), std::ostream_iterator < CI::value_type >(std::cout));
        std::cout << std::endl;
    }

    return 0;
}