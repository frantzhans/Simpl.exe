#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <MYSQL/mysql.h>

using namespace std;


int main(int argc, char*argv[])
{
    MYSQL *sql;

//initialisation mysql 
    if((sql = mysql_init(NULL))== NULL)
    {
        printf("Erreur d'initialisation\n");
        return 0;
    }    
//connexion au serveur(localhost)    
    if(mysql_real_connect(sql,"localhost","USERNAME","PASSWORD","projeysimplexe",0,NULL,0))
    {
       printf("erreur de connexion\n");
       return 0;
    }

        //ON LANCE LA REQUETE 
    requete(&mysql);

       
    


const int tailleX = 2; // = Nombre de composants différents nécessaires.
const int tailleY = 2; // = Nombre de produits à prendre en compte.

double RetourneTableau()
{
    double tab;
    tab = new double[tailleX][tailleY];
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            tab[i][j] = 0; // = Qte de composant j pour le produit i.
        }   
    }
    return tab;
}


int TrouverColonnePivot(double tab,double Pivot)
{
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            if(tab[i][j] = Pivot)
            {
                return j;
            }
        }
    }
}

//const int colonnePivot = TrouverColonnePivot(tab,Pivot);

int TrouverLignePivot(double tab,double Pivot)
{
    for(int i = 0;i<tailleY;i++)
    {
        for(int j = 0;j<tailleX;j++)
        {
            if(tab[i][j] = Pivot)
            {
                return j;
            }
        }
    }

     //fermeture connexion serveur MySQL
    mysql_close(sql);    
    
}






//const int lignePivot = TrouverLignePivot(tab,Pivot);


/*BDD MySQL :
 *      -Utilisateur (Username, Password, Email, Grade)
 *      -Envoi (NbProduits, NbComposants, Resultat)
 *      -Produits(NomProduit, PrixProduit, QteChaqueComposant, QteProduitsCrées)
 *      -Composants (NomComposant, PrixComposant, QteComposantDispo, QteComposantRestants)
*/



















//frantz
/*


#include <cstdlib>

using namespace std;




int main(void)
{
    MYSQL mysql;
    //initialisation mysql 
    mysql_init(MYSQL *mysql);
    mysql_options(&mysql,MYSQL_READ_DEFAULT_GROUP,"option");

    /*localhost peut generer des erreurs*/
    if(mysql_real_connect(&mysql,"localhost","mon_pseudo","******","ma_base",0,NULL,0))
    {
        mysql_close(&mysql);
    }
    else
    {
        printf("Une erreur s'est produite lors de la connexion à la BDD!");
    }

    return 0;
}

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

// initialisation r�alis�e, il faut se connecte 
mysql_options(MYSQL *mysql, enum mysql_option option, const char *arg);
mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);

//la fonction permettant de faire des requêtes MySQL 
mysql_query(MYSQL *mysql, const char *query);

//spécifier pour cette fonction le pointeur de structures ainsi que la requête
mysql_query(&mysql, "INSERT INTO ma_table VALUES('valeur 1', 'valeur 2', 'etc')");

//savoir combien de lignes ont été affectées par votre requête, il suffit d'appeler la fonction :
mysql_affected_rows(MYSQL *mysql);

//pour récupérer le résultat il y a deux façons de faire:
mysql_use_result(MYSQL *mysql)  //récupère le jeu de résultat, mais ne l'enregistre pas dans le client stocker la valeur de retour de cette fonction dans un pointeur de structure de type MYSQL_RES

//Stocker un jeu de résultat ne suffit pas pour le lire ; appeler une autre fonction :
mysql_fetch_row(MYSQL_RES *result);

stocke les valeurs de la ligne suivante dans le jeu de résultats. Il est nécessaire, de libérer la mémoire allouée par cette fonction.
mysql_free_result(MYSQL_RES *result);


//requete selection table scores
 mysql_query(&mysql, "SELECT * FROM scores");
 //Déclaration des objets
        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
        int i = 1;
         //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(&mysql);
        //Tant qu'il y a encore un résultat ...
        while ((row = mysql_fetch_row(result)))
        {
           printf("Resultat %ld\n", i);
           i++;
        }
        //Libération du jeu de résultat
        mysql_free_result(result);

        //Fermeture de MySQL
        mysql_close(&mysql);



//cette fonction stocke le jeu de résultat dans une mémoire tampon
        mysql_store_result(MYSQL *mysql)