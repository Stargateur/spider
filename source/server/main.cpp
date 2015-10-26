//
// main.cpp for main in /home/plasko_a/projet/epitech/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 18 06:53:16 2015 Antoine Plaskowski
// Last update Mon Oct 26 04:29:32 2015 Antoine Plaskowski
//

#include	"Server.hpp"
#include	"Option.hpp"

int		main(int argc, char **argv)
{
  Option	option;
  option.getopt(argc, argv);
  Server	server(option);

  while (server.run() == false)
    ;
  /*  int           sfd;
  int		client;
  SSL_CTX	*ctx;
  SSL		*ssl;
  const SSL_METHOD *method = SSLv3_server_method();
  char		buf[4096];
  
  SSL_library_init();
  SSL_load_error_strings();

  OPENSSL_no_config();
  if ((sfd = create_binded_socket("4242")) == -1)
    return (-1);
  if (listen(sfd, 42))
    return (-1);
  client = accept_client(sfd, 0);
  ctx = SSL_CTX_new(method);
  if (SSL_CTX_use_certificate_file(ctx, "localhost.cert", SSL_FILETYPE_PEM) != 1) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }
  if (SSL_CTX_use_PrivateKey_file(ctx, "localhost.key", SSL_FILETYPE_PEM) != 1 ) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }
  ssl = SSL_new(ctx);
  ret = SSL_set_fd(ssl, client);
  std::cout << SSL_ERROR_NONE << " : SSL_ERROR_NONE" << std::endl;
  std::cout << SSL_ERROR_ZERO_RETURN << " : SSL_ERROR_ZERO_RETURN" << std::endl;
  std::cout << SSL_ERROR_WANT_READ << " : SSL_ERROR_WANT_READ" << std::endl;
  std::cout << SSL_ERROR_WANT_WRITE << " : SSL_ERROR_WANT_WRITE" << std::endl;
  std::cout << SSL_ERROR_WANT_CONNECT << " : SSL_ERROR_WANT_CONNECT" << std::endl;
  std::cout << SSL_ERROR_WANT_ACCEPT << " : SSL_ERROR_WANT_ACCEPT" << std::endl;
  std::cout << SSL_ERROR_WANT_X509_LOOKUP << " : SSL_ERROR_WANT_X509_LOOKUP" << std::endl;
  std::cout << SSL_ERROR_SYSCALL << " : SSL_ERROR_SYSCALL" << std::endl;
  std::cout << SSL_ERROR_SSL << " : SSL_ERROR_SSL" << std::endl;
  if (ret != 1)
    {
      std::cout << "SSL_sed_fd : " << SSL_get_error(ssl, ret) << std::endl;
      ERR_print_errors_fp(stderr);
    }
  ret = SSL_accept(ssl);
  if (ret != 1)
    {
      ERR_print_errors_fp(stderr);
      std::cout << "SSL_accept : " << SSL_get_error(ssl, ret) << std::endl;
    }
  SSL_write(ssl, "coucou", 6);
  ret = SSL_read(ssl, buf, 2);
  write(1, buf, ret);
  ret = SSL_read(ssl, buf, 4096);
  write(1, buf, ret);*/
}
