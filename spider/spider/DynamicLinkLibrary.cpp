//
// DynamicLinkLibrary.cpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Mon Nov  9 14:15:39 2015 Antoine Plaskowski
//

#include	"DynamicLinkLibrary.hpp"

DynamicLinkLibrary::DynamicLinkLibrary(std::string const &name) :
  m_handle(LoadLibrary(name.c_str()))
{
  if (m_handle == NULL)
    {
      std::cerr << "LoadLibrary :" << GetLastError() << " for " << name << std::endl;
      throw std::exception();
    }
}

DynamicLinkLibrary::~DynamicLinkLibrary(void)
{
  if (FreeLibrary(m_handle) != 0)
    {
      std::cerr << "FreeLibrary :" << GetLastError() << std::endl;
    }
}
