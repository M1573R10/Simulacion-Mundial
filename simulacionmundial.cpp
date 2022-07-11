#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<conio.h>


using namespace std;

struct Equipo{
	char nombre[30];
	int grupo;
	int pg;
	int pp;
	int pe;
	int puntaje;
};

/** Para el juego de los encuentros **/
void jugarGrupo(Equipo e[], Equipo &e1, Equipo &e2)
{
	int i,j,g1,g2;

	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
	    {
		  do{
		   g1=rand()%5+1;
		   g2=rand()%5+1;
		  }while(g1==g2);
		   cout<<"Partido Equipo: "<<e[i].nombre<<" vs "<<e[j].nombre<<endl;
		   cout<<"Resultado:      "<<g1<<         " a "  <<g2<<endl;
		   if(g1>g2)
		   {
			   e[i].pg=e[i].pg+1;
			   e[j].pp=e[j].pp+1;
			   e[i].puntaje=e[i].puntaje+3;
		   }
		   else
			   if(g1<g2)
		       {
			     e[i].pp=e[i].pp+1;
			     e[j].pg=e[j].pg+1;
				 e[j].puntaje=e[j].puntaje+3;
		       }
			   else
				  {
				   e[i].pe=e[i].pe+1;
				   e[j].pe=e[j].pe+1;
				   e[i].puntaje=e[i].puntaje+1;
				   e[j].puntaje=e[j].puntaje+1;
			      }
	    }
	}
		
		Equipo temp;
		
		for(i=0;i<3;i++)
		   for(j=i+1;j<4;j++)
		     if(e[i].puntaje<e[j].puntaje)
		       {
		         temp=e[i];
				 e[i]=e[j];
				 e[j]=temp;
		        }
		cout<<"Los clasificados son los siguientes: "<<endl;
		e1=e[0];
		e2=e[1];
		for(i=0;i<2;i++)
			cout<<"Clasificado a Octavos de Final "<<e[i].nombre<<endl;
}

void LecturaArchivo(Equipo equipo[32])
{
	fstream leer_fich ("INPUT GRUPOS.txt",ios::in);
	char datos[256];
	int c=0;
	int g=1;
	
	srand((unsigned)time(NULL));
	system("cls");
	
	cout<<"Grupo "<<char(64+g)<<endl;
	
	/** EOF significa que si no hay nada mas que leer **/
	while (! leer_fich.eof() )
	{
		leer_fich.getline(datos, 256);// lee una linea del archivo
		strcpy(equipo[c].nombre,datos);
		equipo[c].grupo=g;
		equipo[c].pg=0;
		equipo[c].pp=0;
		equipo[c].pe=0;
		equipo[c].puntaje=0;
		c++;
		cout<<c<<" : "<<datos<<endl;
		if(c%4==0)
		{
			g++;
			cout<<"==========================="<<endl;
			getch();
			system("cls");
			cout<<"Grupo "<<char(64+g)<<endl;
		}
	}
	leer_fich.close();
}

int main()
{
	int opcion;
	
	Equipo equipo[32],equipo1,equipo2;
	
	Equipo equiposGrupo[4];
	
	/** Creamos la lista para los clasificados **/
	Equipo octavos1[8], octavos2[8];
	Equipo cuartos1[4],cuartos2[4];
	Equipo semi1[2],semi2[2];
	Equipo final1,final2;
	int g,i;
	do{
		system("cls");
	cout<<"COPA DEL MUNDO RUSIA 2018";
	cout<<"\n1) Detalles de los equipos";
	cout<<"\n2) Simulación";
	cout<<"\n5) Salir";
	cout<<"\n Ingrese opcion: ";
	cin>>opcion;
	switch(opcion){
	case 1: 
		
		cout<<"DETALLE DE LOS EQUIPOS PARTICIPANTES"<<endl;
			/** Equipo[32] son los paises del mundial
			Equipo[4] son la cantidad de equipos que se almacenaran en un grupo **/
		LecturaArchivo(equipo);
		break;
	case 2:
			int k=0,r=0;
			g=0;
			for(i=0;i<32;i++)
			{
				equiposGrupo[k]=equipo[i];
				k++;
				if(k%4==0)
				{
					g++;
					system("cls");
					cout<<"Grupo "<<char(64+g)<<endl;
					jugarGrupo(equiposGrupo,equipo1,equipo2);
					octavos1[r]=equipo1;
					octavos2[r]=equipo2;

					getch();
					r++;
					k=0;
				}
			}
			
			
			
			
			Equipo temp;
			for(i=0;i<8;i=i+2)
			{
				temp=octavos2[i];
				octavos2[i]=octavos2[i+1];
				octavos2[i+1]=temp;
			}
			    int g1,g2;
				cout<<" OCTAVOS DE FINAL "<<endl;
				cout<<octavos1[0].nombre<<" VS "<<octavos2[0].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos1[0]=octavos1[0];
				else
					cuartos1[0]=octavos2[0];
	
				cout<<octavos1[2].nombre<<" VS "<<octavos2[2].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
			 	cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos2[0]=octavos1[2];
				else
				cuartos2[0]=octavos2[2];
	
				cout<<octavos1[4].nombre<<" VS "<<octavos2[4].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos1[1]=octavos1[4];
				else
				cuartos1[1]=octavos2[4];
	
				cout<<octavos1[6].nombre<<" VS "<<octavos2[6].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos2[1]=octavos1[6];
				else
				cuartos2[1]=octavos2[6];
			
				cout<<octavos1[1].nombre<<" VS "<<octavos2[1].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos1[2]=octavos1[1];
				else
					cuartos1[2]=octavos2[1];
				
				cout<<octavos1[3].nombre<<" VS "<<octavos2[3].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos2[2]=octavos1[3];
				else
					cuartos2[2]=octavos2[3];
				
				cout<<octavos1[5].nombre<<" VS "<<octavos2[5].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
					cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos1[3]=octavos1[5];
				else
					cuartos1[3]=octavos2[5];
				
				cout<<octavos1[7].nombre<<" VS "<<octavos2[7].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cuartos2[3]=octavos1[7];
				else
					cuartos2[3]=octavos2[7];
				
				cout<<" CUARTOS DE FINAL "<<endl;
				cout<<cuartos1[0].nombre<<"vs "<<cuartos2[0].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					semi1[0]=cuartos1[0];
				else
					semi1[0]=cuartos2[0];
					
				cout<<cuartos1[1].nombre<<"vs "<<cuartos2[1].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					semi2[0]=cuartos1[1];
				else
					semi2[0]=cuartos2[1];
					
				cout<<cuartos1[2].nombre<<"vs "<<cuartos2[2].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					semi1[1]=cuartos1[2];
				else
					semi1[1]=cuartos2[2];
				
				cout<<cuartos1[3].nombre<<"vs "<<cuartos2[3].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					semi2[1]=cuartos1[3];
				else
					semi2[1]=cuartos2[3];
	
				cout<<" SEMI FINALES "<<endl;
				
				cout<<semi1[0].nombre<<"vs "<<semi2[0].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					final1=semi1[0];
				else
					final1=semi2[0];
				
				cout<<semi1[1].nombre<<"vs "<<semi2[1].nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					final2=semi1[1];
				else
					final2=semi2[1];
				
				cout<<" FINAL "<<endl;
				
				cout<<final1.nombre<<"vs "<<final2.nombre<<endl;
				do{
					g1=rand()%5+1;
					g2=rand()%5+1;
				}while(g1==g2);
				cout<<g1<<" a "<<g2<<endl;
				if(g1>g2)
					cout<<" CAMPEON "<<final1.nombre<<endl;
				else
				cout<<" CAMPEON "<<final2.nombre<<endl;
				system("PAUSE");
		}
	}while(opcion!=5);
	return 0;
}

