//
// DynamicLinkLibrary.cpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Sun Oct 25 03:38:04 2015 Antoine Plaskowski
//

#include	<dlfcn.h>
#include	<iostream>
#include	<string>
#include	<exception>
#include	"DynamicLinkLibrary.hpp"

DynamicLinkLibrary::DynamicLinkLibrary(std::string const &name) :
  m_handle(dlopen(name.c_str(), RTLD_LAZY))
{
  if (m_handle == NULL)
    {
      char *str = dlerror();

      if (str != NULL)
	std::cerr << str << std::endl;
      throw std::exception();
    }
}

DynamicLinkLibrary::~DynamicLinkLibrary(void)
{
  if (dlclose(m_handle) != 0)
    {
      char *str = dlerror();

      if (str != NULL)
	std::cerr << str << std::endl;
    }
}
