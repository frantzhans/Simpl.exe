/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kerze
 *
 * Created on 14 février 2019, 14:19
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    return 0;
}







/* Connexion / d�connexion */
#include <winsock.h>
#include <MYSQL/mysql.h>

/*mysql_options :
Le premier argument est un pointeur de structure, que nous avons vu juste avant.
Le deuxi�me argument est l'option que nous voulons configurer, nous utiliserons toujours MYSQL_READ_DEFAULT_GROUP, qui lie les options sp�cifi�es dans le fichier my.cnf.
Enfin, le troisi�me argument est la valeur de cette option ; vous pouvez mettre le nom que vous souhaitez.
mysql_real_connect :
Le premier argument est toujours un pointeur vers votre structure.
Le deuxi�me argument est le nom de domaine ou l'adresse de votre h�bergeur (dans mon cas, c'est www.goldzoneweb.info). S'il est marqu� � localhost �, je vous conseille de faire comme moi, et de mettre l'adresse de votre h�bergeur car l'utilisation de � localhost � peut engendrer des erreurs.
Le troisi�me argument est votre identifiant de connexion.
Le quatri�me argument est votre mot de passe.
Le cinqui�me argument est le nom de votre base de donn�es.
Le sixi�me argument est le port, je vous conseille de mettre 0 pour �viter les erreurs.
Le septi�me argument est le socket � utiliser, je vous conseille de mettre NULL ici.
Et le huiti�me argument est le flag, je vous conseille de mettre 0.*/
MYSQL mysql;
/*initialisons MySQL, gr�ce � la fonction*/
mysql_init(MYSQL *mysql);

/* initialisation r�alis�e, il faut se connecte */
mysql_options(MYSQL *mysql, enum mysql_option option, const char *arg);
mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);


