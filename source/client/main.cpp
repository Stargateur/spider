//
// main.cpp for main in /home/plasko_a/projet/epitech/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 18 06:52:57 2015 Antoine Plaskowski
// Last update Mon Oct 26 12:20:34 2015 Antoine Plaskowski
//

#include	<sstream>
#include	<unistd.h>
#include	<openssl/ssl.h>
#include	<openssl/err.h>
#include	<openssl/conf.h>
#include	<iostream>
#include	<unistd.h>
#include	"Option.hpp"
#include	"DynamicLinkLibrary.hpp"
#include	"ISocket.hpp"
#include	"IProtocol.hpp"
#include	"IDatabase.hpp"

int		main(int argc, char **argv)
{
  Option	option;

  option.getopt(argc, argv);
  DynamicLinkLibrary	dll_isocket(option.get_path_lib_isocket());
  fct_new_iclient	new_iclient = dll_isocket.get_symbole<fct_new_iclient>(NAME_FCT_NEW_ICLIENT);
  fct_new_istandard	new_istandard = dll_isocket.get_symbole<fct_new_istandard>(NAME_FCT_NEW_ISTANDARD);
  ISocket	&client = new_iclient(option.get_host(), option.get_port());
  ISocket	&in = new_istandard(ISocket::IN);
  DynamicLinkLibrary	dll_itime(option.get_path_lib_itime());
  fct_new_itime	new_itime = dll_itime.get_symbole<fct_new_itime>(NAME_FCT_NEW_ITIME);
  ITime	&time = new_itime();
  DynamicLinkLibrary	dll_iprotocol(option.get_path_lib_iprotocol());
  fct_new_iprotocol	new_iprotocol = dll_iprotocol.get_symbole<fct_new_iprotocol>(NAME_FCT_NEW_IPROTOCOL);
  IProtocol	&protocol = new_iprotocol(client, time);
  DynamicLinkLibrary	dll_idatabase(option.get_path_lib_idatabase());
  fct_new_idatabase	new_idatabase = dll_idatabase.get_symbole<fct_new_idatabase>(NAME_FCT_NEW_IDATABASE);
  IDatabase	&database = new_idatabase();
  fct_iselect	iselect = dll_isocket.get_symbole<fct_iselect>(NAME_FCT_ISELECT);
  IProtocol::Keyboard	keyboard = {time, "press", "ff", "rio.exe"};
  std::list<IProtocol::Keyboard *>	lol;

  lol.push_back(&keyboard);
  protocol.keyboard(lol);
  while (true)
    {
      in.want_read();
      protocol.select();
      iselect(nullptr);
      if (in.can_read())
	{
	  uint8_t	buf[4096 + 1];
	  uintmax_t ret = in.read(*buf, 4096);
	  buf[ret] = '\0';
	  if (ret == 0)
	    break;
	  IProtocol::Log	log = {(char *)buf};
	  std::list<IProtocol::Log *> xd;
	  xd.push_back(&log);
	  protocol.log(xd);
	}
      if (protocol.run() == true)
	return (0);
    }
  // int		cfd;
  // SSL_CTX	*ctx;
  // SSL		*ssl;
  // char		buf[4096];
  // int		ret;

  // SSL_library_init();
  // SSL_load_error_strings();
  // OPENSSL_no_config();
  // //  cfd = create_connected_socket("localhost", "4242");
  // cfd = create_connected_socket("::1", "4242");
  // std::cout << cfd << std::endl;
  // ctx = SSL_CTX_new(SSLv3_client_method());
  // // if (SSL_CTX_use_certificate_file(ctx, "cert.pem", SSL_FILETYPE_PEM) != 1) {
  // //   ERR_print_errors_fp(stderr);
  // //   exit(EXIT_FAILURE);
  // // }
  // // if (SSL_CTX_use_PrivateKey_file(ctx, "localhost.key", SSL_FILETYPE_PEM) != 1 ) {
  // //   ERR_print_errors_fp(stderr);
  // //   exit(EXIT_FAILURE);
  // // }
  // ssl = SSL_new(ctx);
  // if (ssl == NULL)
  //   exit(1);
  // ret = SSL_set_fd(ssl, cfd);
  // if (ret != 1)
  //   {
  //     ERR_print_errors_fp(stderr);
  //     std::cout << "SSL_sed_fd : " << SSL_get_error(ssl, ret) << std::endl;
  //   }
  // ret = SSL_connect(ssl);
  // if (ret != 1)
  //   {
  //     ERR_print_errors_fp(stderr);
  //     std::cout << "SSL_connect : " << SSL_get_error(ssl, ret) << std::endl;
  //   }
  // SSL_write(ssl, "coucou", 6);
  // ret = SSL_read(ssl, buf, 4096);
  // write(1, buf, ret);
}
