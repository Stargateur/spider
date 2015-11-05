//
// main.cpp for main in /home/plasko_a/projet/epitech/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 18 06:52:57 2015 Antoine Plaskowski
// Last update Thu Nov  5 17:05:33 2015 Antoine Plaskowski
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
  int		cfd;
  SSL_CTX	*ctx;
  SSL		*ssl;
  char		buf[4096];
  int		ret;

  SSL_library_init();
  SSL_load_error_strings();
  OPENSSL_no_config();
  //  cfd = create_connected_socket("localhost", "4242");
  cfd = create_connected_socket("::1", "4242");
  std::cout << cfd << std::endl;
  ctx = SSL_CTX_new(SSLv3_client_method());
  // if (SSL_CTX_use_certificate_file(ctx, "cert.pem", SSL_FILETYPE_PEM) != 1) {
  //   ERR_print_errors_fp(stderr);
  //   exit(EXIT_FAILURE);
  // }
  // if (SSL_CTX_use_PrivateKey_file(ctx, "localhost.key", SSL_FILETYPE_PEM) != 1 ) {
  //   ERR_print_errors_fp(stderr);
  //   exit(EXIT_FAILURE);
  // }
  ssl = SSL_new(ctx);
  if (ssl == NULL)
    exit(1);
  ret = SSL_set_fd(ssl, cfd);
  if (ret != 1)
    {
      ERR_print_errors_fp(stderr);
      std::cout << "SSL_sed_fd : " << SSL_get_error(ssl, ret) << std::endl;
    }
  ret = SSL_connect(ssl);
  if (ret != 1)
    {
      ERR_print_errors_fp(stderr);
      std::cout << "SSL_connect : " << SSL_get_error(ssl, ret) << std::endl;
    }
  SSL_write(ssl, "coucou", 6);
  ret = SSL_read(ssl, buf, 4096);
  write(1, buf, ret);
}
