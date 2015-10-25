//
// DynamicLinkLibrary.hpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Sun Oct 25 03:37:25 2015 Antoine Plaskowski
//

#ifndef		DYNAMICLINKLIBRARY_HPP_
# define	DYNAMICLINKLIBRARY_HPP_

# include	<iostream>
# include	<string>
# include	<dlfcn.h>

class		DynamicLinkLibrary
{
public:
  DynamicLinkLibrary(std::string const &name);
  ~DynamicLinkLibrary(void);
  template<typename T>
  T	get_symbole(std::string const &name) const
  {
    (void)dlerror();
    T	symbole = reinterpret_cast<T>(dlsym(m_handle, name.c_str()));
    char const *str = dlerror();
    if (str != NULL)
      {
	std::cerr << str << std::endl;
	throw std::exception();
      }
    return (symbole);
  }
private:
  void	*m_handle;
};

#endif		/* !DYNAMICLINKLIBRARY_HPP_ */
