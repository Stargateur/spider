//
// Dll.hpp for Dll in /home/plasko_a/projet/cplusplus/cpp_nibbler
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 22:26:06 2015 Antoine Plaskowski
// Last update Wed Apr  1 16:53:17 2015 Antoine Plaskowski
//

#ifndef		DLL_HPP_
# define	DLL_HPP_

# include	<string>
# include	<dlfcn.h>
# include	"DllException.hpp"

class		Dll
{
public:
  Dll(std::string const &path_lib);
  ~Dll(void);
  template<typename T>
  T const	getSymbole(std::string const &str_symbole) const
  {
    if (m_handle == NULL)
      {
	if (m_dlopen_dlerror != NULL)
	  throw (DllException(m_dlopen_dlerror));
	throw (DllException("Error unknown"));
      }
    
    (void)dlerror();
    T	const symbole = reinterpret_cast<T>(dlsym(m_handle, str_symbole.c_str()));
    char const * const	str = dlerror();
    if (str != NULL)
      throw (DllException(str));
    return (symbole);
  }
private:
  void * const	m_handle;
  char const *	m_dlopen_dlerror;
};

#endif		/* !DLL_HPP_ */
