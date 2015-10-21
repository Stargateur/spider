//
// start_lib.hpp for start_lib in /home/plasko_a/projet/cplusplus/cpp_nibbler/library/ncurses/include
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Mon Mar 30 18:07:37 2015 Antoine Plaskowski
// Last update Wed Apr  1 19:17:34 2015 Antoine Plaskowski
//

#ifndef		START_LIB_HPP_
# define	START_LIB_HPP_

extern "C"
{
  extern const char	lib_interp[] __attribute__((section(".interp")));
  
  void	start_lib(void) __attribute__((noreturn));
}

#endif		/* !START_LIB_HPP_ */
