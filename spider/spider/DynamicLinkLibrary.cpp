//
// DynamicLinkLibrary.cpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:28:36 2015 Antoine Plaskowski
// Last update Thu Nov  5 13:46:59 2015 Antoine Plaskowski
//

#include	"DynamicLinkLibrary.hpp"

DynamicLinkLibrary::DynamicLinkLibrary(std::string const &name) :
  m_handle(LoadLibrary(name.c_str(), RTLD_LAZY))
{
  if (m_handle == NULL)
    {
      std::cerr << "LoadLibrary :" << GetLastError() << std::endl;
      throw std::exception();
    }
}

DynamicLinkLibrary::~DynamicLinkLibrary(void)
{
  if (FreeLibray(m_handle) != 0)
    {
      std::cerr << "FreeLibrary :" << GetLastError() << std::endl;
    }
}
