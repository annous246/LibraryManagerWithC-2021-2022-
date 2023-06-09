#include<stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<windows.h>
/*do while has struct error then the use of while is much better*/
 int nb=1;
struct livre {
	int code;
	int nb_exemp;
};
struct emprunt{
	int num;
	int cd;
	char id[10];
	int etat;
};





int rech(struct livre tab[],int *p,int code){
	for(int i=0;i<*p;i++){
		if(tab[i].code==code){
			if(tab[i].nb_exemp!=0){
			
			 return i;}
			 else{
			 	return  -1;
			 }}
}

		return -5;
	
 }



int verif(livre tab[],int *p,int cd){
	int ok=-1;
	for(int i=0;i<*p;i++){
		if(tab[i].code==cd){
			return i;
		}
	}
	return ok;
}






int verifp(emprunt tabp[],int *l,int num){
	int ok=-1,i=0;
	for(i=0;i<*l;i++){
		if(tabp[i].num==num){
			return ok;
		}
	}
	return i;
}
int verifret(emprunt tabp[],int *l,int num){
	int ok=-1,i=0;
	for(i=0;i<*l;i++){
		if(tabp[i].num==num){
			return i;
		}
	}
	return ok;}









void ajout(struct livre tab[],int *p){
	int cd,nm;
	do{
	
	printf("\ndonner le code du livre et nombre des livres a ajouter    (le code se compose de 4 chiffres)");
	scanf("%d%d",&cd,&nm);}while(cd>9999||(cd<1000||nm<0));
	if(verif(tab,p,cd)==-1){
		tab[*p].code=cd;
		tab[*p].nb_exemp=nm;
			(*p)=(*p)+1;
	}
	else{
		tab[verif(tab,p,cd)].nb_exemp+=nm;
	}
}







void ajoutemp(struct emprunt tab[],int *l,struct livre tabl[],int *p){
	int code,num,etat,z=1;
	
	char id[10];do{
	
	printf("\ndonner le code du livre et votre id (exp: 15D) ");
	scanf("%d%s",&code,&id);/*FILE *m;
	m=fopen("files//employee .txt","w");
	fprintf(m,id);
	fclose(m);*/
	if(verifp(tab,l,num)==-1){
		printf("vous avez deja l'emprunt num %d aujourd'hui\n",num);
		z=0;
	}
	else if(rech(tabl,p,code)>-1) {
		z=1;
		tab[verifp(tab,l,nb)].num=nb;
		tab[verifp(tab,l,nb)].cd=code;
		tab[verifp(tab,l,nb)].etat=0;
			int i=0;nb++;
		do{
		tab[verifp(tab,l,nb)].id[i]=id[i];	
		i++;
		}while(id[i]!='\0');
		tab[verifp(tab,l,nb)].id[i]='\0';
		
	
		(tabl[rech(tabl,p,code)].nb_exemp)--;
		(*l)=(*l)+1;
	}
	else if(rech(tabl,p,code)==-1){
		printf("ce livre est out of stock\n");
		z=0;
	}
	else{
		printf("ce livre n'existe pas encore dans notre bibliotheque\n");
		z=0;}
	
	if(z==0){
	 	int d=5;
	 do{
	 	printf("voulez vous annuler cet empreint ?   (1=oui)   (2=non)");
	 	scanf("%d",&d);
	 	if(d==1){
	 		z=1;
		 }
	 }while(d!=2&&d!=1);}
	}while(z==0);
}








void rendreemp(struct emprunt tab[],int *l,struct livre tabl[],int *p){
	int num,z=0,d;
	char id[10];do{
	
	printf("\ndonner le numero de lemprunt a rendre");
	scanf("%d",&num);
	if(verifret(tab,l,num)>-1){
		if(tab[verifret(tab,l,num)].etat==0){
		
		tab[verifret(tab,l,num)].etat=1;
		(tabl[rech(tabl,p,tab[verifret(tab,l,num)].cd)].nb_exemp)+=1;
		z=1;}
		else{
			printf("vous allez deja retourne ce livre\n");
			goto ee;
		}
	}
	else if(verifret(tab,l,num)==-1) {
		z=0;
		
		printf("lempreint a rendre n'existe pas\n");
	
	}
	if(z==0){
	
	 d=0;
	 do{ee:
	 	printf("voulez vous annuler le retour de cet empreint?   (1=oui)   (2=non)");
	 	scanf("%d",&d);
	 	if(d==1){
	 		z=1;
		 }
	 }while(d!=2&&d!=1);}
	}while(z==0);
}









void affemp(struct emprunt tab[],int *l){
	if(!*(l))puts("Pas d'empreint aujourd'hui");
	for(int i=0;i<*l;i++){
		printf("numero=%d\n",tab[i].num);
		printf("code du livre=%d\n",tab[i].cd);
		printf("id=%s\n",tab[i].id);
		printf("etat de retour=%d\n\n",tab[i].etat);
		
	}
}
	
	
	
	
	void aff(livre tab[],int *p){
		for(int i=0;i<*p;i++){
			printf("\ncode=%d           ",tab[i].code);
			printf("\n nombre de livres=%d\n",tab[i].nb_exemp);
		}
	}
	
	
	
	
	
	
	void recherche(struct livre tab[],int *p){
		int c,ok=0;
		printf("donner le code du livre a trouver ");
		scanf("%d",&c);
		
		
		for(int i=0;i<*p;i++){
		if(tab[i].code==c){
			 ok=1;
		  if(tab[i].nb_exemp!=0){
		  	printf("ce livre se trouve dans le rayon numero %d\n",i+1);
		  	printf("il reste %d de ce livre",tab[i].nb_exemp);
		  	
		  }}}
		  
		
		if(ok!=1){
			printf("ce livre n'existe pas");
			
		}
	
	}





int main(){
	int n,i=0,j=0,k,c=0,ok=7;
	 int *p=&i,*l=&j;
	
	system("Color E0");
   do{
   	printf("donner la taille de bibliotheque");
   	scanf("%d",&n);
   }while(n<-1);
   
   livre tab[n];
   emprunt tabp[k];
   for(int j=0;j<n;j++){printf("Livre numero %d\n",j+1);ajout(tab,p);}
   aff(tab,p);
    while(ok!=1){
   do{
   	printf("\n\n      \t \t      _______________________________________                ______________________________________\n");
   printf(" \t\t      | (1) afficher la bibliotheque(|///|) | ") ;
   printf("\t \t     | (2)  empreinter un livre (|///|-->)|  ");
   	printf("     \n\t \t      ---------------------------------------                --------------------------------------");
   	printf("\n\n\n\n _____________________________________________   _____________________________________     ___________________________________\n");
   printf(" | (3) afficher les empreints du jour ( o-o )|") ; 
   printf("   | (4) rendre un empreint (|///|<--) | ");   printf("    | (5) rechercher un livre (|/?/|) | ");
   	printf("     \n ---------------------------------------------   -------------------------------------     -----------------------------------");
   	printf(" \n\n\n\n\t\t\t\t\t              ___________________________\n");
   printf("\t\t\t\t\t              | (6) ajouter un livre (+)|\n");
   printf("\t\t\t\t\t              ---------------------------\n");
   	printf(" \n\n\n\n\t\t\t\t\t              ___________________________\n");
   printf("\t\t\t\t\t              | (0) Exit (X)|\n");
   printf("\t\t\t\t\t              ---------------------------\n");
   scanf("%d",&c);}while(c!=1&&c!=2&&c!=3&&c!=4&&c!=5&&c!=6&&c!=0);
switch(c){
	
	case(0):ok=-1;
	while(ok!=0&&ok!=1){
		printf("exit? (1=oui) (0=non)  (vous risquez de tous perdre!)");
		scanf("%d",&ok);
		system("\\cls");
	
	}
;break;	
	case(2):do{
   	printf("donner le nbre des emprunts");
   	scanf("%d",&k);
   }while(k<1);
   for(int i=0;i<k;i++){
   	ajoutemp(tabp,l,tab,p);
   }
  printf("\n\n\n");break;
	case(1):
		system("\cls");
	aff(tab,p);
  printf("\n\n\n");goto v;
	case(3):
		system("\cls");affemp(tabp,l);
  printf("\n\n\n");goto v;
	case(4):rendreemp(tabp,l,tab,p);
		system("\cls");
  printf("\n\n\n");break;
	case(5):system("\cls");recherche(tab,p);
  printf("\n\n\n");goto v;
    case(6):ajout(tab,p);
		system("\cls");
	}
   puts("Done");
   Sleep(1000);	system("\cls");v:;
}

  
   
	
	
	
	return 0;
}
