//
// Dllexception.cpp for Dllexeption in /home/costa_b/rendu/cpp_nibbler/source
// 
// Made by Kevin Costa
// Login   <costa_b@epitech.net>
// 
// Started on  Wed Apr  1 15:49:45 2015 Kevin Costa
// Last update Wed Apr  1 16:04:36 2015 Antoine Plaskowski
//

#include <string>
#include "DllException.hpp"

DllException::DllException(std::string const &str) throw() :
  NibblerException(str)
{
}

DllException::~DllException(void) throw()
{
}
