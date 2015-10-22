//
// DynamicLinkLibrary.cpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Thu Oct 22 02:36:04 2015 Antoine Plaskowski
//

#include	<dlfcn.h>
#include	<iostream>
#include	<string>
#include	"DynamicLinkLibrary.hpp"

DynamicLinkLibrary::DynamicLinkLibrary(void) :
  m_handle(NULL)
{
}

DynamicLinkLibrary::~DynamicLinkLibrary(void)
{
  if (m_handle != NULL)
    {
      if (dlclose(m_handle) != 0)
	{
	  char *str = dlerror();

	  if (str != NULL)
	    std::cerr << str << std::endl;
	}
    }
}

bool	DynamicLinkLibrary::load_dll(std::string const &name)
{
  if ((m_handle = dlopen(name.c_str(), RTLD_LAZY)) == NULL)
    {
      char *str = dlerror();

      if (str != NULL)
	std::cerr << str << std::endl;
      return (true);
    }
  return (false);
}
