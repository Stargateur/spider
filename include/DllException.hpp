//
// DllException.hpp for DllException in /home/plasko_a/projet/cplusplus/cpp_nibbler/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Apr  1 15:58:11 2015 Antoine Plaskowski
// Last update Wed Apr  1 16:04:28 2015 Antoine Plaskowski
//

#ifndef		DLLEXCEPTION_HPP_
# define	DLLEXCEPTION_HPP_

# include	"NibblerException.hpp"

class DllException : public NibblerException
{
public:
  DllException(std::string const &str) throw();
  virtual ~DllException(void) throw();
};

#endif		/* !DLLEXCEPTION_HPP_ */
