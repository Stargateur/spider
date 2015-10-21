//
// DynamicLinkLibrary.hpp for DynamicLinkLibrary in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Thu Oct 22 01:20:16 2015 Antoine Plaskowski
//

#ifndef		DYNAMICLINKLIBRARY_HPP_
# define	DYNAMICLINKLIBRARY_HPP_

# include	<string>
# include	<dlfcn.h>
# include	"DynamicLinkLibraryException.hpp"

class		DynamicLinkLibrary
{
public:
  DynamicLinkLibrary(std::string const &path_lib);
  ~DynamicLinkLibrary(void);
  template<typename T>
  T const	getSymbole(std::string const &str_symbole) const
  {
    if (m_handle == NULL)
      {
	if (m_dlopen_dlerror != NULL)
	  throw (DynamicLinkLibraryException(m_dlopen_dlerror));
	throw (DynamicLinkLibraryException("Error unknown"));
      }
    
    (void)dlerror();
    T	const symbole = reinterpret_cast<T>(dlsym(m_handle, str_symbole.c_str()));
    char const * const	str = dlerror();
    if (str != NULL)
      throw (DynamicLinkLibraryException(str));
    return (symbole);
  }
private:
  void * const	m_handle;
  char const *	m_dlopen_dlerror;
};

#endif		/* !DYNAMICLINKLIBRARY_HPP_ */
