//
// ISelect.hpp for ISelect in /home/plasko_a/projet/cplusplus/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Wed Oct 21 22:02:47 2015 Antoine Plaskowski
// Last update Wed Oct 21 22:29:16 2015 Antoine Plaskowski
//

#ifndef		ISELECT_HPP_
# define	ISELECT_HPP_

#include	"Client.hpp"
#include	"ITime.hpp"

class ISelect
{
public:
  enum	flux
    {
      IN,
      OUT,
      ERR,
    };
public:
  bool	select(std::list<Client *> &clients);
  bool	set_timeout(ITime *timeout = nullptr);
  ITime const 	&get_timeout(void);
  bool	add_flux(flux flux);
  bool	can_read(flux flux);
  bool	can_write(flux flux);
};

#endif		/* !ISELECT_HPP_ */
