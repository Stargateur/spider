//
// DynamicLinkLibraryexception.cpp for DynamicLinkLibraryexeption in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Apr  1 15:49:45 2015 Kevin Costa
// Last update Thu Oct 22 01:21:43 2015 Antoine Plaskowski
//

#include <string>
#include "DynamicLinkLibraryException.hpp"

DynamicLinkLibraryException::DynamicLinkLibraryException(std::string const &str) throw() :
  NibblerException(str)
{
}

DynamicLinkLibraryException::~DynamicLinkLibraryException(void) throw()
{
}
