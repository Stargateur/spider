//
// DynamicLinkLibrary.hpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Thu Nov  5 18:09:48 2015 Antoine Plaskowski
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
  template<typename ptr_fct, typename ref_fct>
  ref_fct	get_symbole(std::string const &name) const
  {
    (void)dlerror();
    void	*symbole = dlsym(m_handle, name.c_str());
    char const *str = dlerror();
    if (str != NULL)
      {
	std::cerr << str << std::endl;
	throw std::exception();
      }
    return (*reinterpret_cast<ptr_fct>(symbole));
  }
private:
  void	*m_handle;
};

#endif		/* !DYNAMICLINKLIBRARY_HPP_ */
