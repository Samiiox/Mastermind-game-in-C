#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/* Les Developpeurs : 
BENZINANE Haitam
KHAIRY Sami
ELKAAMOUSE Issam 
GI 1 | 2021-2021
*/

//  ======================================   DECLARATION DES VARIABLES :  ===========================================================
int essai,bien=0,mal=0;
int i,k,r,q,f,y=0,j,animation;
int L;
char t;
FILE *dossier;
// TABLEAUX :
int j1[5],j2[5],tf[5]={0,0,0,0,0};
char nom1[20],nom2[20];

// =======================================    Declaration  [ PROTOTYPAGE]:============================================================
// POUR LA COLORATION ET LES CARACTERS :
void diff_printf(char Chaine[]);
// FONCTIONS POUR LE NIVEAU 1 :
void Niveau1(void);
void Joueur1_n1(void);
void Joueur2_n1(void);
// FONCTIONS POUR LE NIVEAU 2 :
void Niveau2(void);
void Joueur1_n2(void);
void Joueur2_n2(void);
// MENU 
void Welcome(int r);
void Choix(void);
void Niveaux(void);
void Regles(void);
void Revenir_au_menu_principal(void);
// Fonctions ont une relation avec les differnts pages du programme :
void File(int a);
void Joker(void);
void Perdu(void);
void Loading(void);


// POUR l'affichage l'acceuil :
void Welcome(int r){
     diff_printf("#S D@veloppeurs : #CHAITAM BENZINANE /  SAMI KHAIRY  / ELKAAMOUSE Issam    :  #W \n");
    diff_printf("#V La date d'aujourd'hui est :  #W");
    diff_printf("#P");
    // Pour afficher la date et l'heure avec une commande CMD
    system(" Date /t  && Time /t ") ;
    diff_printf("#W");
    // Message d'acceuil Avec animation :
    if(r==1) {
        diff_printf("#V");
        printf("\t\t\t\t");
        for ( animation = 0; animation < 50; animation++) {
            printf("%c", 178);
            Sleep(40);

        }
        printf("\n");
        for ( animation = 0; animation < 6; animation++) {
            if(animation!=3) {
                printf("\t\t\t\t%c\t\t\t\t\t\t %c \n", 178,178);
            }
            else {
                diff_printf("\t\t\t\t~           #R|||#W WELCOME TO THE GAME #R|||#V\t\t ~\n");
                diff_printf("\t\t\t\t~\t            #WMASTER MIND #V\t\t ~\n");
                Sleep(70);
            }
        }
        printf("\t\t\t\t");
        for ( animation = 0; animation < 50; animation++) {
            printf("%c", 178);
            Sleep(40);
        }
        printf("\n");
    }
    // Message d'acceuil Sans animation :
    if(r==0) {
        diff_printf("#V");
        printf("\t\t\t\t");
        for ( animation = 0; animation < 50; animation++) {
            printf("%c", 178);

        }
        printf("\n");
        for ( animation = 0; animation < 6; animation++) {
            if(animation!=3) {
                printf("\t\t\t\t%c\t\t\t\t\t\t %c \n", 178,178);
            }
            else {
                diff_printf("\t\t\t\t~           #R|||#W WELCOME TO THE GAME #R|||#V\t\t ~\n");
                diff_printf("\t\t\t\t~\t            #WMASTER MIND #V\t\t ~\n");
            }
        }
        printf("\t\t\t\t");
        for ( animation = 0; animation < 50; animation++) {
            printf("%c", 178);
        }
        printf("\n");
    }
}


// FONCTION DES COULEURS :
// #R: ROUGE / #B: BLEU /   #V: VERT /    #C: BLEU CIEL /    #W: BLANC/    #J: JAUNE/    #S: ROSE/   #G: GRIS/  #P: remplissage blue
void diff_printf(char Chaine[]) {
    int t,i,k;
    t = strlen(Chaine);
    i = 0;
    while (i < t) {
        if (Chaine[i] == '#' && Chaine[i + 1] == 'R') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'B') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'V') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'C') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'W') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'G') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'J') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'S') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
        else if (Chaine[i] == '#' && Chaine[i + 1] == 'P') SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16);

        if (Chaine[i] == '#') i += 2;
        k = i;
        while (Chaine[k] != '#' && k < t) {
            if (Chaine[k] == '@') printf("%c", 130); // Codes ascii pour les caracteres speaciaux
            else if (Chaine[k] == '%') printf("%c", 136);
            else if (Chaine[k] == '�') printf("%c", 138);
            else if (Chaine[k] == '&') printf("%c", 220);
            else if (Chaine[k] == '~') printf("%c", 178);
            else if (Chaine[k] == '|') printf("%c", 3);
            else printf("%c", Chaine[k]);
            k++;
        }
        i = k;
    }
}

// Pour revenir au menu principale :
void Revenir_au_menu_principal() {
	int M;
    M = getch();
    switch(M) {
    case '0' : {
        system("cls");
        Welcome(0);
        Choix();
    }
    default:
        Revenir_au_menu_principal();
    }
}



main() {
	// Pour donner au fenetre un titre
    SetConsoleTitle("Master Mind");
    // Chargement du jeu : 
    Loading();
    // affichage du message d'acceuil avec animation : 
    Welcome(1);
    // affichage du menu : 
    Choix();
}
// Pour Afficher les regles :
void Regles() {
    diff_printf("\n\t\t\t #R===== R@gles de jeu =====#W\t\t\t\t");
    diff_printf("== #Jd@veloppeurs :#W HAITAM/ISSAM/SAMI ==\n");
    printf("\n\n");
    diff_printf("Le jeu se d@roule suivant ces @tapes :\n");
    diff_printf("#C1. #GLe joueur 1#W propose un code (entre au clavier de 5 chiffres)\n");
    diff_printf("#C2. #GLe joueur 2#W saisie un code de 5 chiffres.\n");
    diff_printf("#C3. #WLe programme indique le nombre des chiffres bien plac@s et mal plac@s.\n");
    diff_printf("#C4. #WSi le code est trouv@ le jeu se termine , le joueur 2 gagne .\n");
    diff_printf("#C5. #WSi le nombre max d'essais est atteint (20 tentatives), le jeu se termine avec affichage du code.\n\n\n");
    diff_printf("En outre, le jeu propose deux niveaux de difficult@s :\n");
    diff_printf("#SNiveau 1#W (d@butant) : tous les chiffres du codes sont distincts.\n");
    diff_printf("#SNiveau 2#W (expert)   : les chiffres peuvent se r@p@t@ plusieurs fois.\n\n" );
    diff_printf("Il exsite une option joker ou le joueur 2 peut afficher un chiffre  entre [ 1 et� 5 ] de son choix.\n");
    diff_printf("Cette option n'est disponible qu'a partir de la 10 @me tentative.\n");
    diff_printf("Elle peut %tre utilis@ qu'une seule fois \n");
    diff_printf("#RDans ce cas pr@cis, le joueur 2 perd 3 essais et continue le jeu #W.\n\n");
    diff_printf("#S 0 --> Revenir au menu principal#W ");
    Revenir_au_menu_principal();
}
// Fonction du menu
void Niveau1() {
    system("cls");
    Welcome(0);
    diff_printf("\n\n#RNOTE 1 #W : vous ne pouves pas r@p@ter un nombre  plus que 2 fois.\n");
    diff_printf("#RNOTE 2 #W : vous ne pouvez entrer que des nombres entre [ 0  et  9 ].\n");
    diff_printf("#RNOTE 3 #W : vous ne pouvez  pas entrer des caract@res. \n");
// Appel du niveau 1  joueur 1 :
    Joueur1_n1();
    system("cls");
    Welcome(0);
// Appel du niveau 1  joueur 2 :
    Joueur2_n1();
}

// Menu principale :
void Choix() {
    int c;
    diff_printf("#V\t\t[1] --> Jouer \n");
    diff_printf("#V\t\t[2] --> Les r@gles \n");
    diff_printf("#R\t\t[3] --> Quitter #W \n\n");
    diff_printf("#J ==> QUE VOULEZ VOUS CHOISIR ?  :#W   \n\n ");
    c = getch();
    switch (c) {
    case '1': {
        system("cls");
        Welcome(0);
        Niveaux();
        break;
    }
    case '2': {
        system("cls");
        Welcome(0);
        Regles();
        break;
    }
    case '3':
    	// Message de sortie ;
        diff_printf("#V ++++  Revenez plus tard ++++ #R<3#W ");
        exit(1);
        break;
    default :
    	// Commande CMD pour effacher le contenu de la fenetre : 
        system("cls");
        Welcome(0);
        Choix();
    }
}

// la lecture du tableau pour le joueur 1 niveau 1 :
void Joueur1_n1() {
	diff_printf("#W");
    puts("\nJoueur 1 Quelle est votre nom ? : \t\t");
    scanf("%s",&nom1);
    printf("\n\nBonjour ");
    diff_printf("#V");
    printf(" [ %s ] ",nom1);
    diff_printf("#W");
    diff_printf("vous %tes dans ");
    diff_printf("#V");
    printf("le niveau 1\n\n");
    diff_printf("#W");

    for (i = 0; i < 5; i++) {
wrong5:
        diff_printf("#B");
        printf(" %c Le nombre |%d| :",3, i + 1);
        diff_printf("#W");
        
        while(scanf("%d", &j1[i]) != 1) {
            diff_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a ");
            while(getchar() != '\n');
            goto wrong5;
        }
        if (j1[i] < 0 || j1[i] > 9 ) {
            diff_printf("#R S'il vous plait entrez un nombre entre 0 et 9#W \n \a");
            goto wrong5;
        }
        for (q = 1; q <= i; q = q + 1) {
            if (j1[i] == j1[i - q]) {
                diff_printf("#RVous avez r@p@ter un nombre#W \n \a");
                goto wrong5;
            }
        }
    }
}

// la lecture du tableau pour le joueur 2 niveau 1 et analyse des nombres bien  places et des nombres mal places :
void Joueur2_n1() {
	diff_printf("#W");
     puts("Joueur 2 Quelle est votre nom ? : \t\t");
    scanf("%s",&nom2);
    printf("\n\nBonjour ");
    diff_printf("#V");
    printf(" [ %s ] ",nom2);
    diff_printf("#W");
    diff_printf("vous %tes dans ");
    diff_printf("#V");
    printf("le niveau 1\n\n");
    diff_printf("#W");
    diff_printf("#V=====================================#W\n\n");
    printf("              %s VS  %s \n\n",nom1,nom2);
    diff_printf("#V=====================================#W\n\n\n\n");
    essai= 20;
    while (bien != 5 ||  essai<= 0) {
        printf(" %d essai(s) qui vous restent: \n", essai);
        for (i = 0; i < 5; i++) {
wrong7:
            diff_printf("#B");
            printf(" %c Le nombre |%d| :",3, i + 1);
            diff_printf("#W");
            while(scanf("%d", &j2[i]) != 1) {
                diff_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a");
                while(getchar() != '\n');
                goto wrong7;
            }
            if (j2[i] < 0 || j2[i] > 9) {
                diff_printf("#R S'il vous plait entrez un nombre entre 0 et 9#W \n \a");
                goto wrong7;
            }
            for (q = 1; q <= i; q = q + 1) {
                if (j2[i] == j2[i - q]) {
                    diff_printf("#RVous avez r@p@ter un nombre#W \n \a");
                    goto wrong7;
                }
            }
        }
        // comptage des bien et des mals
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 5; k++) {
                if (j1[i] == j2[k] && i != k) {
                    mal = mal + 1;
                }
            }
        }
        for (i = 0; i < 5; i++) {
            if (j1[i] == j2[i]) {
                bien = bien + 1;
            }
        }
        // Analyse des resultats
        if (bien == 5) {
            diff_printf("#V=====================================#W\n\n");
            diff_printf(" #VBravo!vous avez gagnez#W \n");
            printf("Votre score est:\t %d \n\n\n",essai);
            diff_printf("#V=====================================#W\n\n");
            // Pour enregister le score dans le fichier :
            File(1);
azerty:
            diff_printf("#S  [0] --> Revenir au menu principal#W\n ");
            diff_printf("#S [1]--> Quitter#W\n\n");
            L=getch();
            switch(L) {
            case '0' :
                system("cls");
                Welcome(0);
                Choix();
                break;
            case'1'  :
                diff_printf("#V ++++  Revenez plus tard ++++ #R<3#W ");
                exit(1);
                break;
            default :
                system("cls");
                diff_printf("#RERREUR :#W VOUS AVEZ TAPEZ UN AUTRE PARAMETRE\n\n");
                goto azerty ;
            }
        }if(bien!=5){
        diff_printf("#R");
        printf(" [  %d  ] sont mal plac%cs  \n", mal,130);
        diff_printf("#W");
        diff_printf("#V");
        printf(" [  %d  ] sont bien plac%cs \n\n\n", bien, 130);
        diff_printf("#W");}
        // Le devrouillage du Joker :
        if (essai < 12) {
            if (essai > 4) {
                if(y==0) {
                    printf("Le joker est devrouill%c maintenant \n", 130);
                    Joker();
                }
            }
        }
fin1:
        essai -= 1;
        if (essai == 0) {
            Perdu();
            File(0);
            diff_printf("#S [0] --> Revenir au menu principal#W ");
            Revenir_au_menu_principal();
            break;
        }
        mal = 0;
        bien = 0;
    }
}

// niveau 2
// la leccture du tableau pour le joueur 1 niveau 2 :
void Joueur1_n2() {
    puts("Joueur 1 Quelle est votre nom ? : \t\t");
    scanf("%s",&nom1);
    printf("\n\nBonjour ");
    diff_printf("#V");
    printf(" [ %s ] ",nom1);
    diff_printf("#W");
    diff_printf("vous %tes dans ");
    diff_printf("#V");
    printf("le niveau 2\n\n");
    diff_printf("#W");

    for (i = 0; i < 5; i++) {
wrong3:
        diff_printf("#B");
        printf(" %c Le nombre |%d| :",3, i + 1);
        diff_printf("#W");
        while(scanf("%d", &j1[i]) != 1) {
            diff_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a ");
            while(getchar() != '\n');
            goto wrong3;
        }

        if (j1[i] < 0 || j1[i] > 9 ) {
            diff_printf("#R S'il vous plait entrez un nombre entre 0 et 9#W \n \a");
            goto wrong3;
        }
        // pour copier le code entrer par le joueur 1:
        tf[i]=j1[i];
    }
}

// La leccture du tableau pour le joueur 2 niveau 2 et analyse des nombres bien  places et des nombres mal places :
void Joueur2_n2() {
    diff_printf("#W");
    puts("Le joueur 2 entrez votre Nom: \t\t");
    scanf("%s",&nom2);
    printf("\n\nBonjour ");
    diff_printf("#V");
    printf(" [ %s ] ",nom2);
    diff_printf("#W");
    diff_printf("vous %tes dans ");
    diff_printf("#V");
    printf("le niveau 2\n\n");
    diff_printf("#W");
    diff_printf("#V=====================================#W\n\n");
    printf("              %s VS  %s \n\n",nom1,nom2);
    diff_printf("#V=====================================#W\n\n\n\n");
    essai = 20;
    while (bien != 5 || essai <= 0) {
        diff_printf("#J");
        printf(" %d essai(s) qui vous restent: \n", essai);
        diff_printf("#W");
        for (i = 0; i < 5; i++) {
wrong4:
            diff_printf("#B");
            printf("  %c Le nombre |%d| :",3, i + 1);
            diff_printf("#W");
            while(scanf("%d", &j2[i]) != 1) {
                diff_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a ");
                while(getchar() != '\n');
                goto wrong4;
            }
            if (j2[i] < 0 || j2[i] > 9) {
                diff_printf("#R S'il vous plait entrez un nombre entre 0 et 9#W \n \a");
                goto wrong4;
            }
        }
        // Comptage des bien et des mals
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 5; k++) {
                if (tf[i] == j2[k] && i==k) {
                    bien = bien + 1;
                    // Pour eliminer chaque nombre qui est bien place afin de ne les pas compter une autre fois:
                    j2[k]=-1;
                    tf[i]=-2;
                    break;
                }
            }
        }
        for (i = 0; i < 5; i++) {
            for (k = 0; k < 5; k++) {
                if (tf[i] == j2[k] && i != k) {
                    mal = mal + 1;
                    // Pour eliminer chaque nombre qui est mal place afin de ne les pas compter une autre fois:
                    j2[k]=-4;
                    tf[i]=-3;
                    break;
                }
            }
            tf[i]=j1[i];
        }
        // Analyse des resultats
        if (bien == 5) {
            diff_printf("#V=====================================#W\n\n");
            diff_printf(" #VBRAVO!");
            diff_printf("vous avez gagnez#W \n");
            printf("Votre score est:\t %d \n\n\n",essai);
            diff_printf("#V=====================================#W\n\n");
            File(1);
azerty:
            diff_printf("#S  [0]--> Revenir au menu principal#W\n ");
            diff_printf("#S [1]--> Quitter#W\n\n");
            L=getch();
            switch(L) {
            case '0' :
                system("cls");
                Welcome(0);
                Choix();
                break;
            case'1'  :
                diff_printf("#V ++++  Revenez plus tard ++++ #R<3#W ");
                exit(1);
                break;
            default :
                system("cls");
                Welcome(0);
                diff_printf("#RERREUR :#W VOUS AVEZ TAPEZ UN AUTRE PARAMETRE\n\n");
                goto azerty ;
            }
        } if(bien!=5){
		
        diff_printf("#R");
        printf(" [  %d  ] sont mal plac%cs  \n", mal,130);
        diff_printf("#W");
        diff_printf("#V");
        printf(" [  %d  ] sont bien plac%cs \n\n\n", bien, 130);
        diff_printf("#W");
        }
        // Le devrouillage du Joker :
        if (essai < 12) {
            if (essai > 4) {
                if(y==0) {
                    printf("Le joker est devrouill%c maintenant \n", 130);
                    Joker();
                }
            }
        }
        essai -= 1;
        if (essai == 0) {
            Perdu();
            File(0);
            diff_printf("#S [0] --> Revenir au menu principal #W ");
            Revenir_au_menu_principal();
            break;
        }
        mal = 0;
        bien = 0;
    }
}

// choix des niveaux :
void Niveaux() {
    int c;
    diff_printf("#S\t\t[0]--> Revenir au menu #W\n ");
    diff_printf("\t\t[1]--> #GNiveau#W 1\n");
    diff_printf("\t\t[2]--> #RNiveau#W 2\n\n");
    diff_printf(" #J==> QUE VOULEZ VOUS CHOISIR ? :#W\n");
    c = getch();
    switch (c) {
    case '0':
        Revenir_au_menu_principal();
        system("cls");
        break;
    case '1':
        Niveau1();
        break;
    case '2':
        Niveau2();
        break;
    default:
        system("cls");
        Welcome(0);
        Niveaux();
    }
}

// FONCTION DU JOKER :
void Joker() {
    int o, v;
rep:
    diff_printf("#CTapez #S1#C si vous voulez prendre un joker sinon tapez #S0#W \n\n ");
    o = getch();
    switch(o) {
    case '0':
        printf("  ");
        break;
    case '1':
        y=1;
        if (essai > 3) {
rep4:
            printf("Entrez le numero du chiffre que vous voulez voir\n\n");


            while(scanf("%d", & v) !=1) {
                diff_printf(" #R [ S'il vous plait donnez un nombre : ] #W \n \a ");
                while(getchar() != '\n');
                goto rep4;
            }
            if (v < 6 && v > 0) {
                printf(" La valeur du numero %d  est : %d \n\n", v, j1[v - 1]);
                essai -= 3;
            }
            else {
                diff_printf(" #R[ Veuillez vous entrer un nombre entre 1 et 5 ]#W \n\n");
                goto rep4;
            }
            break;
        default:
            Joker();
        }

    }
}

void File(int a) {
    // pour la creation du dossier:
    system("mkdir MasterMind");
    diff_printf("#R Un dossier a @t@ cr@e a la place ou vous avez executes le programme contenant Votre score...#W \n");
    // La creation du fichier dans le dossier :
    dossier=fopen("MasterMind/Score.txt","w");
    // Verification si le fichier est bien ouvert  :
    if(dossier==NULL) {
        printf("Erreur d'ouverture du fichier '");
    }
    // Pour l'ajout de date et temps  dans le fichier:
    char cur_time[128];
    time_t      t;
    struct tm*  ptm;
    t = time(NULL);
    ptm = localtime(&t);
    strftime(cur_time, 128, "%Y-%m-%d \n %H:%M:%S", ptm);
    // Pour la presentation du du score dans le fichier :
    fprintf(dossier,"======================================================== \t\t\n ");
    fprintf(dossier,"==                                                    ==\n");
    fprintf(dossier,"==                                                    ==\n");
    fprintf(dossier,"==                   +++MASTER MIND+++                ==\n");
    fprintf(dossier,"==                                                    ==\n");
    fprintf(dossier,"==                                                    ==\n");
    fprintf(dossier,"========================================================\n\n");
    if(a==1) {
        fprintf(dossier,"=====================================\n\n");
        fprintf(dossier,"            %s Vous avez gagnez \n",nom2);
        fprintf(dossier,"           %s Votre score est : %d \n\n",nom2,essai);
        fprintf(dossier,"            %s Vous avez perdu \n\n",nom1);
        fprintf(dossier,"=====================================\n\n\n\n");
    }
    if (a==0) {
        fprintf(dossier,"=====================================\n\n");
        fprintf(dossier,"            %s Vous avez gagnez \n\n",nom1);
        fprintf(dossier,"            %s Vous avez perdu \n",nom2);
        fprintf(dossier,"           %s Votre score est : %d \n\n",nom2,essai);
        fprintf(dossier,"=====================================\n\n\n\n");
    }
    fprintf(dossier, "%s\n", cur_time);
    fprintf(dossier," == > Devloppeurs : HAITAM BENZINANE \n SAMI KHAIRY \n ISSAM EL KAAMOUSE\n");
    fprintf(dossier, " | @2021-2022 | ESTC |");
    fclose(dossier);

}
void Niveau2() {
    system("cls");
    Welcome(0);
    diff_printf("\n\n#RNOTE 1 #W : vous  pouvez r@p@ter un nombre plusieur fois. \n");
    diff_printf("#RNOTE 2 #W : vous ne pouvez entrer que des nombres entre [ 0  et  9 ] .\n");
    diff_printf("#RNOTE 3 #W : vous ne pouvez  pas entrer des caract@res. \n");
// Appel du niveau 2  joueur 1 :
    Joueur1_n2();
    system("cls");
    Welcome(0);
// Appel du niveau 2  joueur 2 :
    Joueur2_n2();
}
void Loading()
{   int u;
    system("color 0a");
    printf("\n\n\n\n\t\t\t\t\t Chargement du jeu ...\n\n");
    printf("\t\t\t\t\t");
    for ( u = 0; u < 26; u++)
        printf("%c", 177);
    printf("\r");
    printf("\t\t\t\t\t");
    for ( u = 0; u < 26; u++) {
        printf("%c", 219);
        Sleep(60);
    }
    system("cls");
}
void Perdu() {
    diff_printf("#R [  vous avez depasse le nombre de tentatives ]#W \n\n");
    diff_printf("#R===================================#W\n");
    printf("\n%s vous avez perdu     \n",nom2);
    diff_printf("le code @tait :");
    for(i=0; i<5; i++) {
        printf("%d - ",j1[i]);
    }
    diff_printf("#B \nVotre score est :#R 0#W\n");
    printf("\n");
    diff_printf("#R===================================#W\n\n\n");
}
