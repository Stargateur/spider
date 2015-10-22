//
// DynamicLinkLibrary.hpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Thu Oct 22 02:39:34 2015 Antoine Plaskowski
//

#ifndef		DYNAMICLINKLIBRARY_HPP_
# define	DYNAMICLINKLIBRARY_HPP_

# include	<iostream>
# include	<string>
# include	<dlfcn.h>

class		DynamicLinkLibrary
{
public:
  DynamicLinkLibrary(void);
  ~DynamicLinkLibrary(void);
  bool	load_dll(std::string const &name);
  template<typename T>
  T const	get_symbole(std::string const &name) const
  {
    if (m_handle == NULL)
      return (NULL);

    (void)dlerror();
    T	const symbole = reinterpret_cast<T>(dlsym(m_handle, name.c_str()));
    char const *str = dlerror();
    if (str != NULL)
      std::cerr << str << std::endl;
    return (symbole);
  }

private:
  void	*m_handle;
};

#endif		/* !DYNAMICLINKLIBRARY_HPP_ */
