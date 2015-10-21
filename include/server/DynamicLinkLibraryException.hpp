//
// DynamicLinkLibraryException.hpp for DynamicLinkLibraryException in /home/plasko_a/projet/cplusplus/cpp_nibbler/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Apr  1 15:58:11 2015 Antoine Plaskowski
// Last update Thu Oct 22 01:22:30 2015 Antoine Plaskowski
//

#ifndef		DYNAMICLINKLIBRARYEXCEPTION_HPP_
# define	DYNAMICLINKLIBRARYEXCEPTION_HPP_

# include	"NibblerException.hpp"

class DynamicLinkLibraryException : public NibblerException
{
public:
  DynamicLinkLibraryException(std::string const &str) throw();
  virtual ~DynamicLinkLibraryException(void) throw();
};

#endif		/* !DYNAMICLINKLIBRARYEXCEPTION_HPP_ */
