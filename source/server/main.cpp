//
// main.cpp for main in /home/plasko_a/projet/epitech/cpp_spider
// 
// Made by Antoine Plaskowski
// Login   <antoine.plaskowski@epitech.eu>
// 
// Started on  Sun Oct 18 06:53:16 2015 Antoine Plaskowski
// Last update Thu Oct 22 09:46:41 2015 Antoine Plaskowski
//

#include	"DynamicLinkLibrary.hpp"
#include	<unistd.h>
#include	<stdio.h>
#include	<iostream>
#include	<openssl/ssl.h>
#include	<openssl/err.h>
#include	<openssl/conf.h>
#include	<mysql.h>
#include	<string.h>
#include	<time.h>
#include	"create_binded_socket.h"
#include	"accept_client.h"
#include	"ITime.hpp"

int		main(int argc, char **argv)
{
  DynamicLinkLibrary	dll;
  int		ret;
  MYSQL *con = mysql_init(NULL);
  MYSQL_RES *result;

  dll.load_dll(argv[1]);
  fct_new_itime lol = dll.get_symbole<fct_new_itime>(NAME_FCT_NEW_ITIME);
  ITime *titi = lol();
  titi->now();
  time_t timexd = titi->get_second();
  std::cout << ctime(&timexd) << std::endl;
  std::cout << titi->get_second() << std::endl;
  std::cout << titi->get_nano() << std::endl;
  return (0);
  if (con == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
    }

  if (mysql_real_connect(con, "localhost", "root", "paprika",
			 NULL, 0, NULL, 0) == NULL)
    {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
    }

  if (mysql_query(con, "CREATE DATABASE epitech_tp"))
    {
      fprintf(stderr, "%s\n", mysql_error(con));
    }
  if (mysql_select_db(con, "epitech_tp"))
    {
      fprintf(stderr, "%s\n", mysql_error(con));
    }
  // if (mysql_query(con, "use epitech_tp"))
  //   {
  //     fprintf(stderr, "%s\n", mysql_error(con));
  //   }
  if (mysql_query(con, "select * from equipe_film"))
    {
      fprintf(stderr, "%s\n", mysql_error(con));
    }
  /* process each statement result */
  do {
    /* did current statement return data? */
    result = mysql_store_result(con);
    if (result)
      {
	/* yes; process rows and free the result set */
	mysql_free_result(result);
      }
    else          /* no result set or error */
      {
	if (mysql_field_count(con) == 0)
	  {
	    printf("%lld rows affected\n",
		   mysql_affected_rows(con));
	  }
	else  /* some error occurred */
	  {
	    printf("Could not retrieve result set\n");
	    break;
	  }
      }
    /* more results? -1 = no, >0 = error, 0 = yes (keep looping) */
    if ((ret = mysql_next_result(con)) > 0)
      printf("Could not execute statement\n");
  } while (ret == 0);
  mysql_close(con);
  exit(0);
  int           sfd;
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
  write(1, buf, ret);
}
