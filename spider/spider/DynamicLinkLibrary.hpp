//
// DynamicLinkLibrary.hpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <plasko_a@epitech.eu>
// 
// Started on  Thu Nov  5 13:47:23 2015 Antoine Plaskowski
// Last update Thu Nov  5 13:47:24 2015 Antoine Plaskowski
//

#ifndef		DYNAMICLINKLIBRARY_HPP_
# define	DYNAMICLINKLIBRARY_HPP_

# include	<iostream>
# include	<string>
# include	<windows.h>
# include	<exception>

class		DynamicLinkLibrary
{
public:
  DynamicLinkLibrary(std::string const &name);
  ~DynamicLinkLibrary(void);
  template<typename T>
  T	get_symbole(std::string const &name) const
  {
    T	symbole = reinterpret_cast<T>(GetProcAddress(m_handle, name.c_str()));
    if (symbole == NULL)
      {
	std::cerr << "GetProcAddress :" << GetLastError() << std::endl;
	throw std::exception();
      }
    return (symbole);
  }
private:
  HMODULE	m_handle;
};

#endif		/* !DYNAMICLINKLIBRARY_HPP_ */
