//
// DynamicLinkLibrary.cpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Thu Oct 22 01:19:18 2015 Antoine Plaskowski
//

#include	<dlfcn.h>
#include	<iostream>
#include	<string>
#include	"DynamicLinkLibrary.hpp"
#include	"DynamicLinkLibraryException.hpp"

DynamicLinkLibrary::DynamicLinkLibrary(std::string const &path_lib) :
  m_handle(dlopen(path_lib.c_str(), RTLD_LAZY)),
  m_dlopen_dlerror(NULL)
{
  if (m_handle == NULL)
    m_dlopen_dlerror = dlerror();
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
