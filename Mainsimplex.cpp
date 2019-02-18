/* Connexion / déconnexion */
#include <winsock.h>
#include <MYSQL/mysql.h>


/*mysql_options :

Le premier argument est un pointeur de structure, que nous avons vu juste avant.

Le deuxième argument est l'option que nous voulons configurer, nous utiliserons toujours MYSQL_READ_DEFAULT_GROUP, qui lie les options spécifiées dans le fichier my.cnf.

Enfin, le troisième argument est la valeur de cette option ; vous pouvez mettre le nom que vous souhaitez.

mysql_real_connect :

Le premier argument est toujours un pointeur vers votre structure.

Le deuxième argument est le nom de domaine ou l'adresse de votre hébergeur (dans mon cas, c'est www.goldzoneweb.info). S'il est marqué « localhost », je vous conseille de faire comme moi, et de mettre l'adresse de votre hébergeur car l'utilisation de « localhost » peut engendrer des erreurs.

Le troisième argument est votre identifiant de connexion.

Le quatrième argument est votre mot de passe.

Le cinquième argument est le nom de votre base de données.

Le sixième argument est le port, je vous conseille de mettre 0 pour éviter les erreurs.

Le septième argument est le socket à utiliser, je vous conseille de mettre NULL ici.

Et le huitième argument est le flag, je vous conseille de mettre 0.*/
MYSQL mysql;
/*initialisons MySQL, grâce à la fonction*/
mysql_init(MYSQL *mysql);

/* initialisation réalisée, il faut se connecte */
mysql_options(MYSQL *mysql, enum mysql_option option, const char *arg);
mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);


