#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#define TAM 600
#define PASS 239935
#define REN 10
#define LIMITE 4000

int opprincipal();
int valiadmin();
int menuadmin(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);

int opadministrador();
int opcliente();
int menucliente(int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);
int iniciocliente(char users[REN][30], char password[REN][10]);
int cambiarpass(int num, char users[REN][30],char password[REN][10]);
int numeros(char passaux[10]);
int reportedeclientes(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);
int retiro (int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);
int depositar(int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);
int arreglos(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]);
int cambiodebilletespararetiro(int cantidad, int bannohay500,int bannohay200,int bannohay100,int bannohay50);
int cambiodebilletesparadeposito(int cantidad);
void crearpass(int level,char users[REN][30], char password[REN][10]);
void inicializarloscontadores();
void cantidaddebilletes();
void saldodelcajero();

void gotoxy(int x,int y);  
void textcolor(int n);
void estrellas();
void lateral();
void superior();
void portada();
void repon();
void repoff();
void replinea();

void modoadministrador();	  //mensajes
void modocliente(); //menseje
void salir(); //mensaje
void admin1();	//mensaje
void admin2();	//mensaje	
void admin3();	//mensaje 
void admin4();	//mensaje
void admin5();	//mensaje
void adminsalir();
void cliente1();
void cliente2();
void cliente3();
void clientesalir();
void end(); //end mensajes
void tablaon(); //tablitas
void opstart(); //tablas o lineas como le quieran decir
void optwice();
void tablaoff();   
void cuend();	   
void linea(); //end tablas
//Variables globales.
//Denominacion de billetes.
int bi50=50;
int bi100=100;
int bi200=200;
int bi500=500;
//cantidad de billetes;
int cbi50= 0;
int cbi100= 500;
int cbi200= 250;
int cbi500= 0;
//El valor de la cantidad de billetes por denominacion
int vbi50 = 50000; 
int vbi100 = 50000;
int vbi200 = 50000; 
int vbi500 = 50000;

//Saldo del cajero
int saldototaldecajero = 200000;
 
//Este numero define la cantidad de billetes expedido.
int exbi500;
int exbi200;
int exbi100;
int exbi50;


int main()
{
	char users[REN][30]={" ", " ", " ", " ", " ", "MikoGrenore", "Mikaros", "Mik", "MiklosGrenore", "Mikakiu"};
	char password[REN][10]={" ", " ", " ", " ", " ", "123456", "Shana1", "Shana_", "Sh_ana", "Shana*"};
	char cuenta[REN][20]={" ", " ", " ", " ", " ", "5515 0015 0906", "5515 0006 1604", "5515 0012 1506", "5515 0001 4255", "5515 0096 1604"};
	int saldo[REN][1]={{0}, {0}, {0}, {0}, {0}, {5000}, {2500}, {8550}, {1500}, {18500}};
	int op, accesoadmin, accesouser, num;
	
	portada();
	Sleep(100); 
	Beep(600,200); 
	
	do
	{
		estrellas();
		textcolor(10);
		op=opprincipal();
		fflush(stdin);
		
		switch(op)
		{
			case 1: 
					do
					{
					
						modoadministrador();
						accesoadmin=valiadmin();
						
						if (accesoadmin==PASS)
						{
							system("cls");
							printf("\n\n\n\n \t\t\t\t BIENVENIDO . . .  ");
							getch();
							system("cls");
							menuadmin(users, password, cuenta, saldo);
						}
						else{
							printf("\n\n\t\t\t\t\t\t La contarase%ca es erronea",164);
							puts("\n\t\t\t\t\t EL SISTEMA SALDRA DEL MODO ADMINISTRADOR. . .");
							getch();
							break;
						}
					}while (accesoadmin!=PASS);
					break;
					
			case 2:	lateral();
						modocliente();
						accesouser = iniciocliente(users, password);
						if (accesouser>=0 || accesouser<=10)
						{
							if (accesouser != 333)
							{
								num=accesouser;
								menucliente(num, users, password, cuenta, saldo);
							}
							system("cls");
						}
						else
						{
							puts("Lo Sentimos Has Superado El Numero Maximo De Intentos");
							puts("El Sistema Saldra Del Modo Cliente. . .");
							getch();
							system("cls");
						}
											
					break;
			case 3: 
					salir();
					gotoxy(40,16);tablaon();
					gotoxy(40,17);printf(" %c             %c Saliendo %c              %c",186,175,174,186);
					gotoxy(40,18);cuend();
					getch();
					break;
		}		
	}while(op!=3);	
	
printf("\n\n\n");

	end();

printf("\n\n\n");
system("pause");
return 0;
}

int opprincipal()
{
	int op;
	

	
	do
	{
	
		gotoxy(40, 8);
			tablaon();
		gotoxy(40, 9); printf(" %c               %c Menu  %c               %c", 186,175,174, 186);
		gotoxy(40, 10); opstart();
		gotoxy(40, 11);printf(" %c  1  %c  Modo Admin                     %c",186, 186, 186);
		gotoxy(40, 12);optwice();
		gotoxy(40, 13);printf(" %c  2  %c  Mod cliente                    %c",186, 186, 186);
		gotoxy(40, 14);optwice();
		gotoxy(40, 15);printf(" %c  3  %c  Salir                          %c",186, 186, 186);
		gotoxy(40, 16);tablaoff();
			
		gotoxy(40, 18);printf(" Cual Opcion Deseas Utilizar?: ");
		fflush(stdin);
		scanf("%d", &op);
	Sleep(100); 
	Beep(600,200); 
	}while(op<0 || op>3);
	
	return op;
	
}

int valiadmin()
{
	
	int i; 
	char contra[6];
	char caracter;
	int pass;
	char resp;
	
	printf("\n\t\t\t\tPara entrar al modo administrador dijite la contrase%ca",164);
	printf("\n\n\t\t\t\tDeseas Ver Tu Contrase%ca Al Introducirla [s/n]:  ", 164);
	fflush(stdin);	
	scanf("%c", &resp);	
		
	for(i=0; i<=6; i++)
		{
			contra[i]='\0';
		}
			
	if(resp == 'S' || resp == 's')
	{
		i=0;
		printf("\n\n\t\t\t Porfavor Introduce Tu Contrase%ca [6 Caracteres en Total]: ",164);
		while ((caracter = getch()) != 13)
		{
			if(caracter!=8)  // no es retroceso
     		   {		
				contra[i]=caracter;
				i++;
				printf("%c", caracter);
       		}
    		else 
     		{
       			if(i>0)    // es retroceso y hay caracteres
       			{
           			printf("%c%c%c",8,32,8);
           				
				 	i--;  //el caracter a borrar e el backspace
        		}
				}
	Sleep(100); 
	Beep(600,200); 	   
	}
	}
	else
	{
		i=0;
		printf("\n\n\t\t\t Porfavor Introduce Tu Contrase%ca [6 Caracteres en Total]: ", 164);
		while ((caracter = getch()) != 13)
		{
			if(caracter!=8)  // no es retroceso
     		   {		
				contra[i]=caracter;
				i++;
				putchar('*');
        	}
       		else 
       		{
       			if(i>0)    // es retroceso y hay caracteres
       			{
           			printf("%c%c%c",8,32,8);
           			contra[i]='\0';
				 	i--;  //el caracter a borrar e el backspace
        		}
		}
	Sleep(100); 
	Beep(600,200); 
		}
	}
	contra[i] ='\0';
	//convertir la cadena en un numero entero 
	pass=atoi(contra);
	if (pass == PASS);
	{	
		return pass;
	}
	return 0;
}

int iniciocliente(char users[REN][30], char password[REN][10])
{
	char passaux[10];
	char useraux[30];
	int i=0, r, us=0, ps=0, intento=0, cuenta=0, n;
	char caracter;
	char resp;
	
	printf("\n\t\t\t\t\t\t Bienvenido Al Modo Cliente");
	printf("\n  \t                                                Intento No. %d", intento+1);
do
{	
	if(cuenta>=4)
	{
		system("cls");
		modocliente();	
		printf("\n\t\t\t\t\t\t Bienvenido Al Modo Cliente");
		printf("\n  \t                                                Intento No. %d", intento+1);
	}

	
		for(i=0; i<=30; i++)
		{
			useraux[i]='\0';
		}
		
		printf("\n\n\t\t\t\t Porfavor Introduse tu Nombre De Usuario: ");
		fflush(stdin);
		gets(useraux);
	Sleep(100); 
	Beep(600,200); 
		
	do
	{	
		
		printf("\n\t\t\t\t Deseas Ver Tu Contrase%ca Al Introducirla [S/n]:  ", 164);
		fflush(stdin);	
		scanf("%c", &resp);	
	Sleep(100); 
	Beep(600,200); 

			
		for(i=0; i<=10; i++)
			{
				passaux[i]='\0';
			}
			
		if(resp == 'S' || resp == 's')
		{
			i=0;
			printf("\n\n \t\t\t Porfavor Introduce Tu Contrase%ca [6 Caracteres en Total]: ",164);
			while ((caracter = getch()) != 13)
			{
				if(caracter!=8)  // no es retroceso
     		    {		
					passaux[i]=caracter;
					i++;
					printf("%c", caracter);
        		}
       			else 
       			{
       				if(i>0)    // es retroceso y hay caracteres
       				{
           				printf("%c%c%c",8,32,8);
           				passaux[i]='\0';
				 		i--;  //el caracter a borrar e el backspace
        			}
				}
		Sleep(100); 
	Beep(600,200); 	   
			} 
		}
		else
		{
			i=0;
			printf("\n\n \t\t\t Porfavor Introduce Tu Contrase%ca [6 Caracteres en Total]: ", 164);
			while ((caracter = getch()) != 13)
			{
				if(caracter!=8)  // no es retroceso
     		    {		
					passaux[i]=caracter;
					i++;
					putchar('*');
        		}
       			else 
       			{
       				if(i>0)    // es retroceso y hay caracteres
       				{
           				printf("%c%c%c",8,32,8);
           				passaux[i]='\0';
				 		i--;  //el caracter a borrar e el backspace
        			}
				}	   
	Sleep(100); 
	Beep(600,200); 
			}
		}
		
		for(r=0; r<REN; r++)
		{
			if(strcmp(users[r], useraux) == 0)
			{
				us=1;
					
				if(strcmp(password[r], passaux) == 0)
				{
					ps=1;
					n=r;
				}
				else
				{
					ps=0;
				}
			}
		}
		
		if (us==1)
		{
			if(ps==1)
			{
				return n;
			}
			else
			{
				printf("\n\t\t\t\t La cuenta existe, pero el password incorrecto \n");
				intento++;
				cuenta=5;
				getch();
				break;
			}
		}
		else
		{
			printf("\n\t\t\t\t\t La Cuenta No Existe. . . \n ");
			intento++;
			cuenta=4;
			getch();
			break;
		}

	}while (intento<3);
}while (cuenta>=4 && intento<3);

	if (intento==3)
	{
		return 333;
	}



}



int opadministrador()
{
		int op;
	
	do
	{
		lateral();
		
		gotoxy(40,3);tablaon();
		gotoxy(40,4); printf(" %c        %c MENU ADMINISTRADOR %c         %c", 186,175,174, 186);
		gotoxy(40,5);	opstart(); 
		gotoxy(40,6); printf(" %c     %c   INICIALIZAR ARREGLOS          %c  ",186, 186, 186);
		gotoxy(40,7); printf(" %c  1  %c (cuentas, password, saldo       %c  ",186, 186, 186);
		gotoxy(40,8); printf(" %c     %c  y nombre para 10 clientes)     %c  ",186, 186, 186);
		gotoxy(40,9);	optwice();
		gotoxy(40,10);printf(" %c  2  %c  REPORTE DE CLIENTES            %c  ",186, 186, 186);
		gotoxy(40,11);	optwice();	
		gotoxy(40,12);printf(" %c  3  %c  INICIALIZAR CONTADORES DE      %c  ",186, 186, 186);
		gotoxy(40,13);printf(" %c     %c  BILLETES DE CADA DENOMINACION  %c  ",186, 186, 186);
		gotoxy(40,14);	optwice();
		gotoxy(40,15);printf(" %c  4  %c  REPORTE DE CUANTOS BILLETES    %c  ",186, 186, 186);
		gotoxy(40,16);printf(" %c     %c  HAY POR DENOMINACION           %c  ",186, 186, 186);
		gotoxy(40,17);	optwice();
		gotoxy(40,18);printf(" %c  5  %c  MOSTRAR SALDO DE CAJERO        %c  ",186, 186, 186);
		gotoxy(40,19);	optwice();
		gotoxy(40,20);printf(" %c  6  %c  REGRESAR AL MENU PRINCIPAL     %c  ",186, 186, 186);
		gotoxy(40,21);	tablaoff();
			
		printf("\n\t\t\t\t\t Cual Opcion Deseas Utilizar: ");
		fflush(stdin);
		scanf("%d", &op);
			Sleep(100); 
	Beep(600,200); 
	}while(op<0 || op>6);
	
	return op;
}

int menuadmin(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1])
{
	
	int op;

	do
	{
		op=opadministrador();
		fflush(stdin);
		
		switch(op)
		{
			case 1: admin1();
					arreglos(users, password,cuenta,saldo);
					break;
			case 2: admin2();
					reportedeclientes(users, password,cuenta,saldo);
					break;
			case 3: admin3();
					inicializarloscontadores();
					break;
			case 4: admin4();
					cantidaddebilletes();
					break;
			case 5: admin5();
					saldodelcajero();
					break;												
			case 6: adminsalir();
					lateral();
					superior();
					gotoxy(40, 16);	tablaon();
					gotoxy(40,17);printf(" %c             %c SALIENDO %c              %c",186,175,174,186);
					gotoxy(40,18);cuend();
					fflush(stdin);
					getch;
					system("cls");
					break;
		}		
	}while(op!=6);	
	
}

int menucliente(int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1])
{
	
	int op;

	do
	{
		system("cls");
		op=opcliente();
		fflush(stdin);
		
		switch(op)
		{
			case 1: cliente1();
					retiro (num, users, password, cuenta, saldo); 
					
					break;
			case 2: cliente2();
					depositar (num, users, password, cuenta, saldo);
					break;
			case 3: 
					cliente3();
					cambiarpass(num, users, password); 
	
					break;												
			case 4: clientesalir();
					lateral();
					superior();
					gotoxy(40, 16);	tablaon();
					gotoxy(40,17);printf(" %c             %c SALIENDO %c              %c",186,175,174,186);
					gotoxy(40,18);cuend();
					getch;
					break;
		}		
	}while(op!=4);	
	
}
int cambiarpass (int num, char users[REN][30],char password[REN][10])
{
	char passaux[10];
	int i, validacion=0, espacio=0, letra=0, numero=0, especial=0;
	char caracter;
	lateral();
	gotoxy(40,8); printf("\n\t\t\t\t\t\t Bienvenido -%s-",users[num]);
			
		
		do{
			for(i=0; i<=10; i++)
			{
			passaux[i]='\0';
			}
			
			validacion=0;
			i=0;
			printf("\n\n\t\t\t Porfavor Introduce Tu Contrase%ca Actual [6 Caracteres en Total]: ",164);
			while ((caracter = getch()) != 13)
			{
				if(caracter!=8)  // no es retroceso
     		    {		
					passaux[i]=caracter;
					i++;
					printf("%c", caracter);
        		}
       			else 
       			{
       				if(i>0)    // es retroceso y hay caracteres
       				{
           				printf("%c%c%c",8,32,8);
           				passaux[i]='\0';
				 		i--;  //el caracter a borrar e el backspace
        			}
				}	
					Sleep(100); 
	Beep(600,200);    
			} 
			
			if(strcmp(passaux,password[num])!=0)
			{
				printf("\n\t\t\t\t La Contrase�a Introducida es Incorrecta. . .");
				validacion=5;
			}	
				
		}while (validacion!=0);
		
		
	do
	{
		do
		{
		validacion=0;
		
		printf("\n\n\t\t\t\t Recuerda La Contrase%ca Deve Contener Lo Siguiente:", 164);
		printf("\n\t\t\t\t  - Tener una longitud EXACTA de 6 caracteres.");
		printf("\n\t\t\t\t  - Iniciar con alguna letra mayuscula o minuscula.");
		printf("\n\t\t\t\t  - A partir del segundo caracter puede ser otra letra, \n\t\t\t\t     un caracter, un _ , o un digito.");
		printf("\n\t\t\t\t  - Debe tener al menos UN digito (0,1,2,3,4,5,6,7,8,9).");
		for(i=0; i<=10; i++)
		{
			passaux[i]='\0';
		}
	
			i=0;
			printf("\n\n\t\t\t Porfavor Introduce Tu Nueva Contrase%ca [6 Caracteres en Total]: ",164);
			gets(passaux);
			Sleep(100); 
	Beep(600,200); 
	if(strlen(passaux)<6 || strlen(passaux)>6)
	{
		printf("\n\t\t\t\t\t La Contrase%ca No Tiene La Longitud Correcta", 164);
		validacion++;
	}
	else
	{
		for(i=0; i<strlen(passaux); i++)
		{
			
			if(isblank(passaux[i]) != 0)
			{
				espacio++;
			}	
			else
			{
				if(isalpha (passaux[i]) != 0)
				{
					
					if(islower(passaux[i]) != 0)
					{
						letra++;
					}
					
					if(isupper(passaux[i]) != 0 )
					{
						letra++;
					}
				}
				else
				{
					if(isdigit(passaux[i]) != 0 )
					{
						numero++;
					}
					else
					{
						
						if(passaux[i] == '_')
						{
							especial++;
						}
						
						if(passaux[i] == '*')
						{
							especial++;
						}
					}
				}
			}
		}//fin for
	
	}
	
	}while(validacion != 0);
	
	if(espacio>0)
	{
		printf("\n\t\t\t\t\t La Contrase%ca No Puede Contener Espacion", 164);
		validacion++;
	}
	
	
	if(numero>0)
	{
		if(isdigit(passaux[0]) != 0 )
		{
			printf("\n La Contrase%ca No Puede Iniciar Con Un Numero", 164);
			validacion++;
		}
	}
	else
	{
		printf("\n La Contrase%c No Contiene Ningun Numero", 164);
		validacion++;
	}
	
	if(especial>0)
	{
			if(passaux[0] == '_')
			{
				validacion++;
				printf("\n La Contrase%ca No Puede Iniciar Con Un Caracter Especial", 164);
			}
			
			if(passaux[0] == '*')
			{
				validacion++;
				printf("\n La Contrase�a No Puede Iniciar Con Un Caracter Especial");
			}
	}

	}while (validacion!=0);
			
			strcpy(password[num],"");
			
			printf("\n \t\t\t\t La Contrase%ca Es Valida.", 164);
			strcpy(password[num],passaux);
			getch();
		
			printf("\n\n\t\t\t Tu Nueva Contrase%ca Es:  %s", 164, password[num]);
		
			getch();
			
}

void crearpass(int level,char users[REN][30], char password[REN][10])
{
	char passaux[10];
	int validacion=0, espacio=0, letra=0, numero=0, especial=0, i;
	
	do
	{
		do
		{
			gotoxy(35,3);
		printf("\n\n\t\t\t\t Recuerda La Contrase%ca Deve Contener Lo Siguiente:",164);
		printf("\n\t\t\t\t  - Tener una longitud EXACTA de 6 caracteres.");
		printf("\n\t\t\t\t  - Iniciar con alguna letra mayuscula o minuscula.");
		printf("\n\t\t\t\t  - A partir del segundo caracter puede ser otra letra, \n\t\t\t\t     un caracter, un _ , o un digito.");
		printf("\n\t\t\t\t  - Debe tener al menos UN digito (0,1,2,3,4,5,6,7,8,9).");
		for(i=0; i<=10; i++)
		{
			passaux[i]='\0';
		}
		validacion=0;
		lateral();
			i=0;
			gotoxy(35,10);printf("\n\n\t\t\t   Porfavor Introduce La Contrase%ca Para El Usuario[%s]: ",164, users[level]);
			fflush(stdin);
			gets(passaux);
		Sleep(100); 
	Beep(600,200); 
	if(strlen(passaux)<6 || strlen(passaux)>6)
	{
		printf("\n\t\t\t\t\t La Contrase%ca No Tiene La Longitud Correcta",164);
		validacion++;
	}
	else
	{
		for(i=0; i<strlen(passaux); i++)
		{
			if(isblank(passaux[i]) != 0)
			{
				espacio++;
			}	
			else
			{
				if(isalpha (passaux[i]) != 0)
				{
					
					if(islower(passaux[i]) != 0)
					{
						letra++;
					}
					
					if(isupper(passaux[i]) != 0 )
					{
						letra++;
					}
				}
				else
				{
					if(isdigit(passaux[i]) != 0 )
					{
						numero++;
					}
					else
					{
						
						if(passaux[i] == '_')
						{
							especial++;
						}
						
						if(passaux[i] == '*')
						{
							especial++;
						}
					}
				}
			}
		}//fin for
	
	}
	
	}while(validacion != 0);
	
	if(numero>0)
	{
		if(isdigit(passaux[0]) != 0 )
		{
			printf("\n\t\t\t\t La Contrase%ca No Puede Iniciar Con Un Numero",164);
			validacion++;
		}
	}
	else
	{
		printf("\n\t\t\t\t La Contrase%ca No Contiene Ningun Numero",164);
		validacion++;
	}
	
		if(espacio>0)
	{
		printf("\n\t\t\t\t La Contrase%ca No Puede Contener Espacion",164);
		validacion++;
	}
	
	if(especial>0)
	{
			if(passaux[0] == '_')
			{
				validacion++;
				printf("\n\t\t\t\t La Contrase%ca No Puede Iniciar Con Un Caracter Especial", 164);
			}
			
			if(passaux[0] == '*')
			{
				validacion++;
				printf("\n\t\t\t\t La Contrase%ca No Puede Iniciar Con Un Caracter Especial",164);
			}
		}
	}while (validacion!=0);
			
			for(i=0; i<=10; i++)
			{
				password[level-1][i]='\0';
			}
			
				strcpy(password[level],"");
			
			printf("\n\t\t\t\t La Contrase%ca Cumple Todas Las Caracteristicas.",164);
			strcpy(password[level],passaux);
			getch();
}


int arreglos(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1])
{
	char useraux[30];
	int i,  level, cont=0, repetir=0;
	char resp, us;
	
	lateral();
	gotoxy(35, 13);printf("\n\t\t\t\t\t Verificando Lugares Disponibles. . .");
	printf("\n\t\t\t\t\t\t     ");
	for(i=0;i<15;i++){
	
		Sleep(50); 
		Beep(500,200); 
		printf("%c",219);
	}
	
	for(i=0; i<REN; i++)
	{
		if(strcmp(users[i], " ")==0)
		{
			cont++;
		}
	}
	
	printf("\n\t\t\t\t Existen %d Lugares Disponibles Para Usuarios Nuevos.", cont);
	getch();
	
	level=(cont-1);
	
	if(cont>0)
	{
		printf("\n\n\t\t\t\t Deseas Crear Otro Usuario  s/n : ");
		fflush(stdin);
		scanf("%c", &resp);
			Sleep(100); 
	Beep(600,200); 
		if(resp == 's' || resp == 'S')
		{
			printf("\n\t\t\t\t\t Ahora Rellena Los Campos Nesesarios.\n");
			
			do
			{
				for(i=0; i<=30; i++)
				{
					useraux[i]='\0';
				}
				i=0;
				printf("\n\t\t\t    Introduce El Nombre Del Usuario [Maximo 30 Caracteres]: ");
				fflush(stdin);
				gets(useraux);
					Sleep(100); 
	Beep(600,200); 
				printf("\n\n\t\t\t\t\t El Nombre De Usuario Sera: %s", useraux);
				printf("\n\n\t\t\t\t Deseas Confimar Este Nombre De Usuario s/n: ");
				fflush(stdin);
					scanf("%c", &us);
						Sleep(100); 
	Beep(600,200); 
			}while(us=='n' || us == 'N');
			system("cls");
			strcpy(users[level], useraux);
			
			crearpass(level, users, password);
	
			printf("\n\n\t\t\t\t\t La Nueva Contrase%ca Es:  %s", 164, password[level]);
		
			getch();
			
		
		
			
		do
		{	
			printf("\n\n\t\t\t\t Generando Numero De Cuenta Porfavor Espere. . .");
			getch();
			
			repetir=0;
						printf("\n\t\t\t\t\t\t   ");
			for(i=0;i<15;i++){	
			Sleep(50); 
			Beep(500,200); 
			printf("%c",219);
			}
			
			cuenta[level][0]='5';
			cuenta[level][1]='5';
			cuenta[level][2]='1';
			cuenta[level][3]='5';
			cuenta[level][4]=' ';
			cuenta[level][5]='0';
			cuenta[level][6]='0';
		
				
			for(i=7; i<14; i++)
			{
				if(i==9)
				{
					cuenta[level][i]=' ';
				}
				else
				cuenta[level][i]=48+rand()%(57-48+1);
			}
			
			for(i=0; i<10; i++)
			{
				if((strcmp(cuenta[level], cuenta[i])) == 0 )
			 	{
			 		repetir++;
				}
				else
				{
					repetir=0;
				}
			}
		
		}while(repetir>0);	
		
			printf("\n\n\t\t\t\t\t El Numero De Cuenta Es: %s", cuenta[level]);
			getch();
			
			
			printf("\n\n\t\t\t\t\t El Saldo De La Cuenta Comenzara En: 0 ");
			printf("\n\n\t\t\t\t\t Gracias Por Crear La Cuenta.");
		}
		else
		{
			printf("\n\n\t\t\t\t\t Gracias Por Consultar Este Apartado.");
		}
				
		
		
	}
	else
	{
		printf("\n\t\t\t\t Lo Sentimos El Numero Maximo de Clentes Fue Alcanzado");
	}
	Sleep(100); 
	Beep(600,200); 
	getch();
	system("cls");
}
 int retiro (int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]){
	int retiro,i;
	char resp; 
	//Banderas de condicion
	int baninsuficiente,banexcedio,bansinfondos,banmultiplo50,banmultiplo100,banmultiplo200,banmultiplo500;
	//Banderas de los contadores de los billetes 
	int bannohay500,bannohay200,bannohay100,bannohay50;		
	banexcedio = 0;
	baninsuficiente = 0;
	bansinfondos=0;
	banmultiplo50 = 0;
	banmultiplo100 = 0;
	banmultiplo200 = 0;
	banmultiplo500 = 0;
	bannohay500 = 0;
	bannohay200 = 0;
	bannohay100 = 0;
	bannohay50 = 0;	
	
	do{
	system("cls");
	cliente1();
	lateral();
	gotoxy(50,10);printf("Saldo actual: %d\n", saldo[num-1][1]);
	fflush(stdin);
	gotoxy(45,12);printf("Cantidad que desea retirar: ");
	scanf("%d", &retiro);
	fflush(stdin);
		Sleep(100); 
	Beep(600,200); 
	if(cbi50>0){
		if((retiro%50)==0){
			banmultiplo50=1;
		}
	}
	 if(cbi100>0){
	 	if(retiro%100==0){
	 		banmultiplo100=1;
	 	}
	 }
	 if(cbi200>0){
	 	if(retiro%200==0){
	 		banmultiplo200=1;
	 	}
	 }
	 if(cbi500>0){
	 	if(retiro%500==0){
	 		banmultiplo500=1;
	 	}
	 }
	// Si el contador esta en 0;
	
	if(cbi50<=0){
		printf("\n\t\t\t\tNo hay suficionetes billetes de $50. \n\t\t\t Se tratara de hacer la transaccion con billetes de diferente denominacion.");
		bannohay50 = 1;
	}
	 if(cbi100<=0){
	 	printf("\n\n\t\t\t\tNo hay suficionetes billetes de $100. \n\t\t\t Se tratara de hacer la transaccion con billetes de diferente denominacion.");
		bannohay100 = 1;
	}
	 if(cbi200<=0){
	 	printf("\n\n\t\t\t\tNo hay suficionetes billetes de $200. \n \t\t\tSe tratara de hacer la transaccion con billetes de diferente denominacion.");
	 	bannohay200= 1;
	 }
	 if(cbi500<=0){
	 printf("\n\n\t\t\t\tNo hay suficionetes billetes de $500. \n\t\t\t Se tratara de hacer la transaccion con billetes de diferente denominacion. ");
		bannohay500 = 1;	
	 }
	fflush(stdin);
	//si el cajeor no tiene saldo
	if(retiro > saldototaldecajero){
		printf ("\n\t\t\t\tLo sentimos, no tenemos los suficientes fondos.\n\t\t\t\t\t Por favor, vuelva mas tarde... ");
		bansinfondos=1;
	}
	//Si la cantidad es invalid por no se multipo.
	fflush(stdin);
	if (banmultiplo50 == 0 && banmultiplo100 == 0 && banmultiplo200 == 0 && banmultiplo500 == 0){
	printf("\n\t\t\t\t\tLa cantidad es invalida");
	}
	if(retiro > LIMITE){
		printf("\n\t\t\t\t Su retiro excede el limite de retiro del cajero de $%d.",LIMITE);
		banexcedio = 1;
	}
	if(retiro > saldo [num-1][1]){
		printf("\n\t\t\t\t\t Su saldo es insuficiente para el retiro.");
		baninsuficiente = 1;
	}
	fflush(stdin);
	if(baninsuficiente == 0 && banexcedio == 0 && bansinfondos == 0 && (banmultiplo50 == 1 || banmultiplo100 == 1 || banmultiplo200 == 1 || banmultiplo500 == 1)){
	printf("\n\t\t\t\t\t\t     ");
	for(i=0;i<15;i++){
	
		Sleep(50); 
		Beep(500,200); 
		printf("%c",219);
	}
	
	printf("\n\n\t\t\t\t\tLa transaccion esta completa...");
	getch();
	Sleep(50); 
	Beep(600,900); 
	fflush(stdin);
	saldo[num-1][1] -= retiro;
	saldototaldecajero = saldototaldecajero - retiro;
	
	
	printf("\n\t\t\t\t\tSaldo despues del retiro: %d\n", saldo[num-1][1]);
	// Para los contadores de los billetes 
	int cantidad,i;
    int rebi500,rebi200,rebi100,rebi50;
     cantidad = retiro;
	 rebi500= 0;
	 rebi200= 0;
	 rebi100=0; 
	 rebi50 = 0;
	fflush(stdin); 
     //funcion para cambio de billetes
	 cambiodebilletespararetiro(cantidad, bannohay500,bannohay200,bannohay100,bannohay50);
     
	 printf("\n\n\t\t\t\t\t\tEl cajero expide:");
	if(exbi500 > 0){
	  printf("\n\t\t\t\t\t\t%d billetes de 500", exbi500);	
	 }
	if(exbi200 > 0){
	  printf("\n\t\t\t\t\t\t%d billetes de 200", exbi200);	
	 }
	if(exbi100 > 0){
	  printf("\n\t\t\t\t\t\t%d billetes de 100", exbi100);	
	 }
	if(exbi50 > 0){
	  printf("\n\t\t\t\t\t\t%d billetes de 50", exbi50);	
	 } 
	
     
	if(exbi500 > 0){
	 for(i = 0; i<exbi500; i++){
     	rebi500++;
	 }
	}
	if(exbi200 > 0){
	 for(i = 0; i<exbi200; i++){
     	rebi200++;
	 }
	}
	if(exbi100 > 0){
	 for(i = 0; i<exbi100; i++){
     	rebi100++;
	 }
	}
	if(exbi50 > 0){ 
	 for(i = 0; i<exbi50; i++){
     	rebi50++;
	 }
	}
	 cbi500 =cbi500 - rebi500;
	 cbi200 =cbi200 - rebi200;
	 cbi100 =cbi100 - rebi100;
	 cbi50 =cbi50 - rebi50;
}
	printf("\n\n\t\t\t\t\t\t Su saldo es de: $%d",saldo[num-1][1]);
	fflush(stdin);
	printf("\n\t\t\t\t\t Desea hacer algun otro retiro?(s/n):  ");
	scanf("%c",&resp);
	}while(resp == 'S' || resp == 's');
	system("cls");
}

int cambiodebilletespararetiro(int cantidad,int bannohay500, int bannohay200, int bannohay100, int bannohay50){
	if (bannohay500 != 1){
	exbi500=cantidad/500;
     cantidad=cantidad%500;
 	}	
	 if (bannohay200 != 1){
	 exbi200=cantidad/200;
     cantidad=cantidad%200;
	}
	 if (bannohay100 != 1){
	 exbi100=cantidad/100;
     cantidad=cantidad%100; 
 	}
	 if (bannohay50 != 1){
	 exbi50=cantidad/50;
     cantidad=cantidad%50;
 	}
}
int depositar(int num, char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1]){
	int deposito,i;
	char resp; 
	//Banderas de condicion
	int banexcedio,ban0,banmultiplo50,banmultiplo100,banmultiplo200,banmultiplo500;
	ban0 = 0;
	banexcedio = 0;
	banmultiplo50 = 0;
	banmultiplo100 = 0;
	banmultiplo200 = 0;
	banmultiplo500 = 0;
	
	
	do{
	system("cls");
	cliente2();
	lateral();
	gotoxy(48,10);printf("Saldo actual: %d\n", saldo[num-1][1]);
	fflush(stdin);
	gotoxy(42,12);	printf("Cantidad que desea depositar: ");
	scanf("%d", &deposito);
	fflush(stdin);
	
	if((deposito%50)==0){
		banmultiplo50=1;
	}
	
	
	if(deposito%100==0){
	 	banmultiplo100=1;
	}
	 
	if(deposito%200==0){
	 	banmultiplo200=1;
	}
	
	if(deposito%500==0){
	 	banmultiplo500=1;
	}
	// Si el deposito es 0 ;
	fflush(stdin);
	if( deposito == 0){
		printf("\n\t\t\t\t ERROR. El deposito no puede ser 0.\n");
		ban0=1;
	}
	//Si la cantidad es invalid por no se multipo.
	fflush(stdin);
	if (banmultiplo50 == 0 && banmultiplo100 == 0 && banmultiplo200 == 0 && banmultiplo500 == 0){
	printf("\n\t\t\t\t\tLa cantidad es invalida");
	}
	if(deposito > LIMITE){
		printf("\n\t\t\t Su deposito excede el limite de deposito del cajero de $%d.",LIMITE);
		banexcedio = 1;
	}

	fflush(stdin);
	if(banexcedio == 0 && ban0 == 0 && (banmultiplo50 == 1 || banmultiplo100 == 1 || banmultiplo200 == 1 || banmultiplo500 == 1)){
	printf("\n\t\t\t\t\t\t     ");
	for(i=0;i<15;i++){
	
		Sleep(50); 
		Beep(500,200); 
		printf("%c",219);
	}
	
	printf("\n\n\t\t\t\t\tLa transaccion esta completa...");
	getch();
	Sleep(50); 
	Beep(600,900);
	fflush(stdin);
	saldo[num-1][1]=saldo[num-1][1]+deposito;
	saldototaldecajero = saldototaldecajero + deposito;
	
	printf("\n\n\t\t\t\t\tSaldo despues del deposito: %d\n", saldo[num-1][1]);
	// Para los contadores de los billetes 
	int cantidad,i;
    int rebi500,rebi200,rebi100,rebi50;
     cantidad = deposito;
	 rebi500= 0;
	 rebi200= 0;
	 rebi100=0; 
	 rebi50 = 0;
	fflush(stdin); 
     cambiodebilletesparadeposito(cantidad);
     printf("\n\n\t\t\t\t\tEl cajero recibe:");
	if(exbi500 > 0){
	  printf("\n\t\t\t\t\t%d billetes de 500", exbi500);	
	 }
	if(exbi200 > 0){
	  printf("\n\t\t\t\t\t%d billetes de 200", exbi200);	
	 }
	if(exbi100 > 0){
	  printf("\n\t\t\t\t\t%d billetes de 100", exbi100);	
	 }
	if(exbi50 > 0){
	  printf("\n\t\t\t\t\t	%d billetes de 50", exbi50);	
	 } 
	
     
	if(exbi500 > 0){
	 for(i = 0; i<exbi500; i++){
     	rebi500++;
	 }
	}
	if(exbi200 > 0){
	 for(i = 0; i<exbi200; i++){
     	rebi200++;
	 }
	}
	if(exbi100 > 0){
	 for(i = 0; i<exbi100; i++){
     	rebi100++;
	 }
	}
	if(exbi50 > 0){ 
	 for(i = 0; i<exbi50; i++){
     	rebi50++;
	 }
	}
	 cbi500 =cbi500 + rebi500;
	 cbi200 =cbi200 + rebi200;
	 cbi100 =cbi100 + rebi100;
	 cbi50 =cbi50 + rebi50;
}
	printf("\n\n\t\t\t\t\t\t Su saldo es de: $ %d",saldo[num-1][1]);
	fflush(stdin);
	printf("\n\t\t\t\t\t Desea hacer algun otro deposito ?(s/n):  ");
	scanf("%c",&resp);
		Sleep(100); 
	Beep(600,200); 
	}while(resp == 'S' || resp == 's');
	system("cls");
}
int cambiodebilletesparadeposito(int cantidad){

	exbi500=cantidad/500;
     cantidad=cantidad%500;
	 exbi200=cantidad/200;
     cantidad=cantidad%200;
     exbi100=cantidad/100;
     cantidad=cantidad%100; 
     exbi50=cantidad/50;
     cantidad=cantidad%50;
}

int reportedeclientes(char users[REN][30],char password[REN][10],char cuenta[REN][20],int saldo[REN][1])
{
	int i, j;
	int numero;
	numero = 1;
	getch();
	system("cls");
	printf("\n\t\t\t\t\t Reporte de clientes.");
	gotoxy(6,3);repon();
	gotoxy(6,4); printf(" %c   No.  %c      Cuenta      %c Nombre de la cuenta %c Password de cuenta %c Saldo de cuenta %c", 186, 186, 186, 186, 186, 186  );
	gotoxy(6,5);replinea();
	gotoxy(6,6); printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,7);replinea();
	gotoxy(6,8); printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,9);replinea();
	gotoxy(6,10);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,11);replinea();
	gotoxy(6,12);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,13);replinea();
	gotoxy(6,14);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,15);replinea();
	gotoxy(6,16);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,17);replinea();
	gotoxy(6,18);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,19);replinea();
	gotoxy(6,20);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,21);replinea();
	gotoxy(6,22);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,23);replinea();
	gotoxy(6,24);printf(" %c        %c                  %c                     %c                    %c                 %c", 186, 186, 186, 186, 186, 186 );
	gotoxy(6,25);repoff();
	
	j=0;
	for (i=0;i<REN;i++)
	{	
		gotoxy(11,6+j);printf("%d",numero);
		gotoxy(18,6+j);printf("%s",cuenta[i]);
		gotoxy(37,6+j);printf("%s",users[i]);
		gotoxy(61,6+j);printf("%s",password[i]);
		gotoxy(80,6+j);printf("%d",saldo[i][0]);
		j=j+2;numero ++;
	}

	getch();
	system("cls");
}
void repon()
{
	int i;
		

		printf(" %c",201);//Inicio de la barra para finalizar
			for(i=0; i<=87; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==8 || i== 27)
				{
					printf("%c", 203);
				}
				else
				{
					if(i==49 || i== 70)
					{
						printf("%c", 203);
					}
					else
					{
							printf("%c", 205);					
					}				
				}
			}
		printf("%c",187);//final de la barra separadora
}

void replinea()
{
	int i;
		
		
		printf(" %c",204);//Inicio de la barra para finaliza
		for(i=0; i<=87; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==8 || i== 27)
				{
					printf("%c", 206);
				}
				else
				{
					if(i==49 || i== 70)
					{
						printf("%c", 206);
					}
					else
					{
							printf("%c", 205);					
					}				
				}
			}
		printf("%c",185);//final de la barra separadora
}
void repoff()
{
	int i;
		
		
		printf(" %c",200);//Inicio de la barra para finaliza
		for(i=0; i<=87; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==8 || i== 27)
				{
					printf("%c", 202);
				}
				else
				{
					if(i==49 || i== 70)
					{
						printf("%c", 202);
					}
					else
					{
							printf("%c", 205);					
					}				
				}
			}
		printf("%c",188);//final de la barra separadora
}
			
void inicializarloscontadores(){
	int i;
	char resp;
	lateral();
	gotoxy(20,8);
	printf("\n\t\t\t Desea inicializar los contadores de billetes de cada denominacion? (s/n): ");
	scanf("%c",&resp);
		Sleep(100); 
	Beep(600,200); 
	if(resp == 's' || resp == 'S'){
		//Variables globales que se inicializaran.
		//Denominacion de billetes.
		bi50=50;
		bi100=100;
		bi200=200;
		bi500=500;
		//cantidad de billetes;
		cbi50= 1000;
		cbi100= 500;
		cbi200= 250;
		cbi500= 100;
		//El valor de la cantidad de billetes por denominacion
		vbi50 = 50000; 
		vbi100 = 50000;
		vbi200 = 50000; 
		vbi500 = 50000;

		//Saldo del cajero
		saldototaldecajero = 200000;					
	printf("\n\t\t\t\t\t\tInicializando...");	
		printf("\n\t\t\t\t\t\t");
	for(i=0;i<15;i++){
	
		Sleep(50); 
		Beep(500,200); 
		printf("%c",219);
	}
	printf("\n\n\t\t\tLos contadores de los billetes de cada denominacion han sido inicializados.");
	getch();	
	Sleep(100); 
	Beep(600,200); 
	
	
	system("cls");	
	}
	else{
		printf("\n\n\t\t\t\t\tLos contadores no se inicializaran");
		getch();
		system("cls");
	}	
	system("cls");
}

void cantidaddebilletes(){
	lateral();
	gotoxy(35,8);
	printf("\n\t\t\tReporte de los billetes que hay en el cajero por denominacion.");
	printf("\n\n\t\t\t\t\t Cantidad de billetes de 50: %d",cbi50);
	printf("\n\n\t\t\t\t\t Cantidad de billetes de 100: %d",cbi100);
	printf("\n\n\t\t\t\t\t Cantidad de billetes de 200: %d",cbi200);
	printf("\n\n\t\t\t\t\t Cantidad de billetes de 500: %d",cbi500);
	getch();
	system("cls");	
}
void saldodelcajero(){
		lateral();
		gotoxy(40,15);printf("\n\t\t\t\t\tEl saldo del cajero es de: $%d",saldototaldecajero);
		getch();
		system("cls");
			Sleep(100); 
	Beep(600,200); 
}

int opcliente()
{
		int op;
	
	do
	{
		lateral();
		gotoxy(40,8);tablaon();
		gotoxy(40,9); printf(" %c            %c MENU CLIENTE %c           %c", 186,175,174, 186);
		gotoxy(40,10);	opstart();
		gotoxy(40,11);printf(" %c  1  %c   Retirar                       %c  ",186, 186, 186);	
		gotoxy(40,12);	optwice();
		gotoxy(40,13);printf(" %c  2  %c   Depositar                     %c  ",186, 186, 186);
		gotoxy(40,14);	optwice();	
		gotoxy(40,15);printf(" %c  3  %c   Cambiar password              %c  ",186, 186, 186);
		gotoxy(40,16);	optwice();
		gotoxy(40,17);printf(" %c  4  %c   salir                         %c  ",186, 186, 186);
		gotoxy(40,18);	tablaoff();
			
		gotoxy(40,20);printf("Cual Opcion Deseas Utilizar (?): ");
		fflush(stdin);
		scanf("%d", &op);
			Sleep(100); 
	Beep(600,200); 
	}while(op<0 || op>4);
	
	return op;
}


void end() //mensaje de despedida
{
	textcolor(10);
	system("cls");
	textcolor(10);
estrellas();
textcolor(10);
	gotoxy(40,10);  printf("  *****************************************  ");
	gotoxy(40,11);  printf("  *   Gracias Por Usar Este Codigo uwu    *  ");
	gotoxy(40,12);  printf("  *****************************************  ");
	gotoxy(40,14);	printf("          **Inserte Lenny Face Aqui**        ");
	gotoxy(40,15);linea();
	gotoxy(40,16);  printf("            Integrantes                      ");
   	gotoxy(40, 17); printf("        Marco Antonio Aguayo Garza           "); 	
	gotoxy(40, 18); printf("                                             ",160, 162,164);
	gotoxy(40, 19); printf("        Oscar Gonz%clez Esparza              ", 160);
	gotoxy(40, 20); printf("                                             ");
	gotoxy(40,21);linea();
	Sleep(100); 
	Beep(600,200); 
}

void modoadministrador()
{

	system("cls");
	lateral();
	superior();			
	textcolor(775);
		gotoxy(35,8);	tablaon();
		gotoxy(35,9); printf(" %c            %c Entrando A  %c            %c", 186,175,174, 186);
		gotoxy(35,10);printf(" %c               %c Modo %c                %c", 186,205,205, 186);
		gotoxy(35,11);printf(" %c          %c ADMINISTRADOR %c            %c",186,175,174,186);
		gotoxy(35,12);	cuend();
}


void modocliente()
{
	system("cls");
	lateral();
	gotoxy(40,8);		tablaon();
	gotoxy(40,9);     printf(" %c            %c Entrando A  %c            %c", 186,175,174, 186);
	gotoxy(40,10);    printf(" %c               %c Modo %c                %c", 186,205,205, 186);
	gotoxy(40,11);	  printf(" %c              %c Cliente %c              %c",186,175,174,186);
	gotoxy(40,12);		cuend();
}

void salir()
{
	system("cls");
	gotoxy(40,10);		tablaon();
	gotoxy(40,11);	printf(" %c        %c Has Seleccionado %c           %c", 186,175,174, 186);
	gotoxy(40,12);	printf(" %c              %c Salir %c                %c", 186,205,205, 186);
	gotoxy(40,13);	printf(" %c           %c Del cajero %c              %c",186,175,174,186);
	gotoxy(40,14);		cuend();
		printf("\n");
}

void admin1()
{
		system("cls");
		gotoxy(40,5);	tablaon();
		gotoxy(40,6);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
		gotoxy(40,7);	printf(" %c            %c Inicializar %c            %c", 186,205,205, 186);
		gotoxy(40,8);	printf(" %c              %c Arreglos %c             %c",186,175,174,186);
		gotoxy(40,9);	cuend();
		printf("\n");
}
void admin2()
{
		system("cls");
		gotoxy(40,10);	tablaon();
		gotoxy(40,11);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
		gotoxy(40,12);  printf(" %c  %c                                 %c  %c", 186,205,205, 186);
		gotoxy(40,13);	printf(" %c        %c Reporte De Clientes %c        %c",186,175,174,186);
		gotoxy(40,14);	cuend();
		printf("\n");	
}
void admin3()
{
		system("cls");
		gotoxy(40,3);	tablaon();
		gotoxy(40,4);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
		gotoxy(40,5);	printf(" %c            %c Inicialisar %c            %c", 186,205,205, 186);
		gotoxy(40,6);	printf(" %c        %c Contador De Billetes %c       %c",186,175,174,186);
		gotoxy(40,7);	cuend();
		printf("\n");	
}
void admin4()
{
		system("cls");
		gotoxy(40,3);	tablaon();
	  	gotoxy(40,4);printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
		gotoxy(40,5);printf(" %c            %c Reporte De %c             %c", 186,205,205, 186);
		gotoxy(40,6);printf(" %c        %c Cantidad De Billetes %c       %c",186,175,174,186);
		gotoxy(40,7);	cuend();
		printf("\n");	
}
void admin5()
{
		system("cls");
	gotoxy(40,8);		tablaon();
	gotoxy(40,9);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
	gotoxy(40,10);	printf(" %c             %c Mostrar %c               %c", 186,205,205, 186);
	gotoxy(40,11);	printf(" %c        %c Saldo Del Cajero %c           %c",186,175,174,186);
	gotoxy(40,12);		cuend();
		printf("\n");	
}
void adminsalir()
{
	system("cls");
	gotoxy(40,10);		tablaon();
	gotoxy(40,11);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
	gotoxy(40,12);	printf(" %c               %c Salir %c               %c", 186,205,205, 186);
	gotoxy(40,13);	printf(" %c      %c Del modo Administrador %c       %c",186,175,174,186);
	gotoxy(40,14);		cuend();
		printf("\n");
}
void cliente1()
{
	gotoxy(40,3);	system("cls");
	gotoxy(40,4);		tablaon();
	gotoxy(40,5);	printf(" %c          %c Has Seleccionado %c         %c", 186,175,174, 186);
	gotoxy(40,6);	printf(" %c             %c La Opcion %c             %c", 186,205,205, 186);
	gotoxy(40,7);	printf(" %c              %c Retirar %c              %c",186,175,174,186);
	gotoxy(40,8);		cuend();
		printf("\n");	
}
void cliente2()
{
	gotoxy(40,3);	system("cls");
	gotoxy(40,4);		tablaon();
	gotoxy(40,5);	printf(" %c          %c Has Seleccionado %c         %c", 186,175,174, 186);
	gotoxy(40,6);	printf(" %c             %c La Opcion %c             %c", 186,205,205, 186);
	gotoxy(40,7);	printf(" %c             %c Depositar %c             %c",186,175,174,186);
	gotoxy(40,8);		cuend();
		printf("\n");	
}
void cliente3()
{
		system("cls");
	gotoxy(40,3);		tablaon();
	gotoxy(40,4);	printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
	gotoxy(40,5);	printf(" %c             %c La Opcion %c             %c", 186,205,205, 186);
	gotoxy(40,6);	printf(" %c          %c Cambiar Pasword %c          %c",186,175,174,186);
	gotoxy(40,7);		cuend();
		printf("\n");	
}
void clientesalir()
{
		system("cls");
		gotoxy(40,10);	tablaon();
		gotoxy(40,11);printf(" %c         %c Has Seleccionado %c          %c", 186,175,174, 186);
		gotoxy(40,12);printf(" %c               %c Salir %c               %c", 186,205,205, 186);
		gotoxy(40,13);printf(" %c         %c Del Modo Cliente %c          %c",186,175,174,186);
		gotoxy(40,14);	cuend();
		printf("\n");	
}

//inician tablas 
void tablaon()
{
	int i;
	
	printf(" %c",201);
		for(i=0; i<=38; i++) //ciclo para facilitar creado de la tabla
		{
			printf("%c", 205);
		}
	printf("%c",187);
}

void opstart()
{
	int i;
	
	printf(" %c",204);//Inicio de la barra separadora inicio de las opciones
			for(i=0; i<=38; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==5)
				{
					printf("%c", 203);
				}
				else
				{
					printf("%c", 205);
				}
			}
		printf("%c",185);//final de la barra separadora
}

void optwice()
{
	int i;
	
	printf(" %c",204);//Inicio de la barra separadora entre opciones
			for(i=0; i<=38; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==5)
				{
					printf("%c", 206);
				}
				else
				{
					printf("%c", 205);
				}
			}
		printf("%c",185);//final de la barra separadora
}

void tablaoff()
{
	int i;
		
		
		printf(" %c",200);//Inicio de la barra para finalizar
			for(i=0; i<=38; i++) //ciclo para facilitar creado de la tabla
			{
				if(i==5)
				{
					printf("%c", 202);
				}
				else
				{
					printf("%c", 205);
				}
			}
		printf("%c",188);//final de la barra separadora
}

void cuend()
{
	
		int i;
		
		
		printf(" %c",200);//Inicio de la barra para finalizar
			for(i=0; i<=38; i++) //ciclo para facilitar creado de la tabla
			{
				printf("%c", 205);
			}
		printf("%c",188);//final de la barra separadora
}
void linea()
{
		int i;
	
	printf(" %c",205);
		for(i=0; i<=40; i++) //ciclo para facilitar creado de la tabla
		{
			printf("%c", 205);
		}
	printf("%c",205);
}
void portada()
{

        gotoxy(35, 2); printf(".........................................");
        gotoxy(35, 3); printf("."); system("color 71"); printf("     ||||"); system("color 77"); printf("."); system("color 79"); printf("|        |||||||||"); system("color 77"); printf("."); system("color 71"); printf("|         "); system("color 70"); printf(".");
        gotoxy(35, 4); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("||         |||||||"); system("color 77"); printf("."); system("color 71"); printf("||        "); system("color 70"); printf(".");
        gotoxy(35, 5); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("|||            ||||"); system("color 77"); printf("."); system("color 71"); printf("||       "); system("color 70"); printf(".");
        gotoxy(35, 6); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("||||       "); system("color 76"); printf("-"); system("color 79"); printf("   ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 7); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("||||     "); system("color 76"); printf("--"); system("color 77"); printf("."); system("color 74"); printf("~"); system("color 79"); printf("  ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 8); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("||||   "); system("color 76"); printf("----"); system("color 77"); printf("."); system("color 74"); printf("~~"); system("color 79"); printf(" ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 9); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("|||| "); system("color 76"); printf("----"); system("color 77"); printf("."); system("color 74"); printf("~~~~"); system("color 79"); printf(" ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 10); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("|||| "); system("color 76"); printf("--"); system("color 77"); printf("."); system("color 74"); printf("~~~~"); system("color 79"); printf("   ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 11); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("|||| "); system("color 76"); printf("-"); system("color 77"); printf("."); system("color 74"); printf("~~"); system("color 79"); printf("      ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 12); printf("."); system("color 71"); printf("      |||"); system("color 77"); printf("."); system("color 79"); printf("|||| "); system("color 74"); printf(" ~"); system("color 79"); printf("        ||||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 13); printf("."); system("color 71"); printf("       ||"); system("color 77"); printf("."); system("color 79"); printf("||||            |||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 14); printf("."); system("color 71"); printf("        ||"); system("color 77"); printf("."); system("color 79"); printf("|||||||         ||"); system("color 77"); printf("."); system("color 71"); printf("|||      "); system("color 70"); printf(".");
        gotoxy(35, 15); printf("."); system("color 71");; printf("         |"); system("color 77"); printf("."); system("color 79"); printf("|||||||||        |"); system("color 77"); printf("."); system("color 71"); printf("||||     "); system("color 70"); printf(".");
        gotoxy(35, 16); printf(".........................................");
        
        
        
   		system("color 57");
   		gotoxy(35, 18); printf("-----------------------------------------");
   		gotoxy(35, 19); printf("CCBAS                         ISC 1%c%cA%c",167, 34,34);
   		gotoxy(35, 20); printf("        Proyecto: Cajero Automatico       ");
   		gotoxy(35, 21); printf("         ");
   		gotoxy(35, 22); printf("        Marco Antonio Aguayo Garza        "); 	
		gotoxy(35, 23); printf("                                          ",160, 162,164);
		gotoxy(35, 24); printf("        Oscar Gonz%clez Esparza           ", 160);
		gotoxy(35, 25); printf("                                          ");	
   		gotoxy(35, 26); printf("-----------------------------------------");
   		gotoxy(60, 27); printf("Vercion 1.0");
   		 
   		 
   		 getch();
			system("color 07");
   	
   		
}

void gotoxy(int x,int y){ //-----------------------------------------------------------------------------------------------------------------
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}  
/**********************************************/
void textcolor(int n){ //--------------------------------------------------------------------------------------------------------------------
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n); 
}

void estrellas(){       
     int num=800;
       int cont=0;
       int columna, renglon, i,color, tiempo=50;
       srand(time(0));
       system("cls"); //borra pantalla completa
       for (i=1; i<=num; i++){
       	if(i%2==0)
       	{
       		cont++;
		}
		
       	    textcolor(15);
       		columna = 0+rand()%(120-0+1); //aleatorio para la columna entre 1 y 80
      		renglon = 2+rand()%(30-2 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    gotoxy(columna, renglon); printf("%c",207);
       }
			
       fflush(stdin) ;   

}
void lateral(){       
     int num=800;
       int cont=0;
       int columna, renglon, i,color, tiempo=50;
       srand(time(0));
     //borra pantalla completa
       for (i=1; i<=num; i++){
       	if(i%2==0)
       	{
       		cont++;
		}
		
       	    textcolor(15);
       		columna = 0+rand()%(20-0+1); //aleatorio para la columna entre 1 y 80
      		renglon = 2+rand()%(30-2 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    gotoxy(columna, renglon); printf("%c",176);
       }
         for (i=1; i<=num; i++){
       	if(i%2==0)
       	{
       		cont++;
		}
		
       	    textcolor(15);
       		columna = 100+rand()%(120-10+1); //aleatorio para la columna entre 1 y 80
      		renglon = 2+rand()%(30-2 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    gotoxy(columna, renglon); printf("%c",176);
       }
			
       fflush(stdin) ;   

}
void superior(){       
     int num=800;
       int cont=0;
       int columna, renglon, i,color, tiempo=50;
       srand(time(0));
     //borra pantalla completa
       for (i=1; i<=num; i++){
       	if(i%2==0)
       	{
       		cont++;
		}
		
       	    textcolor(15);
       		columna = 0+rand()%(120-0+1); //aleatorio para la columna entre 1 y 80
      		renglon = 0+rand()%(5-0 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    gotoxy(columna, renglon); printf("%c",176);
       }
         for (i=1; i<=num; i++){
       	if(i%2==0)
       	{
       		cont++;
		}
		
       	    textcolor(15);
       		columna = 0+rand()%(120-0+1); //aleatorio para la columna entre 1 y 80
      		renglon = 25+rand()%(30-25 +1); //aleatorio para el renglon entre 1 y 24
      		color = 1 + rand()%(15-1+1); //aleatorio para el color entre 1 y 15
       		textcolor(color); //Cambia el color a la letra
       	    gotoxy(columna, renglon); printf("%c",176);
       }
			
       fflush(stdin) ;   

}
