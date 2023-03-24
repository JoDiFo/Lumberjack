#ifndef STRINGHELPERS_HPP
#define STRINGHELPERS_HPP

#include <sstream>

// My own std::to_string version for compatability
template <typename T>
std::string toString(const T& value);

#include "StringHelpers.inl"
#endif // STRINGHELPERS_HPP