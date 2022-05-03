#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
//FALTA 6 - 7
void ejercicio1();
void ejercicio2();
void ejercicio3();
void ejercicio4();
void ejercicio5();
void ejercicio6();
void ejercicio7();
int cargaArreglos(int legajos[20],char nombres[20][30],int anos[20]);                                   //(1)
void muestraArreglos(int legajos[20],char nombres[20][30],int anos[20],int cantidad);                   //(2)
int busquedaLegajos(int legajos[20],int cantidad,int *busqueda,int *posicion);                          //(3)
void muestraArregloEspecifico(int legajos[20],char nombres[20][30],int anos[20],int cantidad);          //(4)
void ordenSeleccion(int legajos[20],char nombres[20][30],int anos[20],int cantidad);                    //(5)
int posicionMenor(char nombres[20][30],int a,int cantidad);                                             //(6)
void muestraArregloIndividual(int legajos[20],char nombres[20][30],int anos[20],int cantidad);          //(7)
int main()
{
    int ejercicio;
    do
    {
        do
        {
            printf("EJERCICIOS                                                 INGRESAR");
            printf("\nEJERCICIO 1  ...................................................  1");
            printf("\nEJERCICIO 2  ...................................................  2");
            printf("\nEJERCICIO 3  ...................................................  3");
            printf("\nEJERCICIO 4  ...................................................  4");
            printf("\nEJERCICIO 5  ...................................................  5");
            printf("\nEJERCICIO 6  ...................................................  6");
            printf("\nEJERCICIO 7  ...................................................  7\n");
            printf("\nIngrese el ejercicio: ");
            scanf("%i",&ejercicio);
        }
        while(ejercicio!=1 && ejercicio!=2 && ejercicio!=3 && ejercicio!=4 && ejercicio!=5 && ejercicio!=6 && ejercicio!=7 && ejercicio!=0);
        if(ejercicio!=0)
        {
            printf("\nEJERCICIO %i\n\n",ejercicio);
        }
        switch(ejercicio)
        {
            case 1:
            {
                ejercicio1();
            }
            break;
            case 2:
            {
                ejercicio2();
            }
            break;
            case 3:
            {
                ejercicio3();
            }
            break;
            case 4:
            {
                ejercicio4();
            }
            break;
            case 5:
            {
                ejercicio5();
            }
            break;
            case 6:
            {
                ejercicio6();
            }
            break;
            case 7:
            {
                ejercicio7();
            }
            break;
        }
    }
    while(ejercicio!=0);
    printf("\nTP5 TERMINADO\n");
    printf("\nVersion 1.0\n");
    return 0;
}
int cargaArreglos(int legajos[20],char nombres[20][30],int anos[20])                                    //INICIO FUNCION CARGAARREGLOS              (1)
{
    int i;
    char continuar='s';
    srand(time(NULL));
    for(i=0;i<20 && continuar=='s';i++)
    {
        //EL NUMERO DE LEGAJO SE ASIGNA EN ORDEN EMPEZANDO POR EL 1
        legajos[i]=i+1;
        printf("Ingrese el nombre del alumno: ");
        fflush(stdin);
        gets(nombres[i]);
        //LA EDAD SE GENERA AL AZAR ENTRE 18 Y 30 ANOS
        anos[i]=rand()%13+18;
        printf("Desea ingresar otra palabra? s/n Respuesta: ");
        fflush(stdin);
        scanf("%c",&continuar);
    }
    printf("\n");
    return i;
}                                                                                                       //FIN FUNCION CARGAARREGLOS
void muestraArreglos(int legajos[20],char nombres[20][30],int anos[20],int cantidad)                    //INICIO FUNCION MUESTRAARREGLOS            (2)
{
    int i;
    printf("Alumnos:\n| Legajo | Nombre                         | Anos |\n");
    for(i=0;i<cantidad;i++)
    {
        printf("|   %2i   | %-30s |  %i  |\n",legajos[i],nombres[i],anos[i]);
    }
    printf("\n");
}                                                                                                       //FIN FUNCION MUESTRAARREGLOS
int busquedaLegajos(int legajos[20],int cantidad,int *busqueda,int *posicion)                           //INICIO FUNCION BUSQUEDALEGAJOS            (3)
{
    int i,flag=0;
    printf("Ingrese el legajo que desea buscar: ");
    scanf("%i",busqueda);
    for(i=0;i<cantidad && flag==0;i++)
    {
        if(legajos[i]==*busqueda)
        {
            *posicion=i;
            flag=1;
        }
    }
    return flag;
}                                                                                                       //FIN FUNCION BUSQUEDALEGAJOS
void muestraArregloEspecifico(int legajos[20],char nombres[20][30],int anos[20],int cantidad)           //INICIO FUNCION MUESTRAARREGLOESPECIFICO   (4)
{
    int i,busqueda=0,posicion=-1,flag=0;
    flag=busquedaLegajos(legajos,cantidad,&busqueda,&posicion);
    for(i=0;i<cantidad;i++)
    {
        if(legajos[i]==busqueda && flag==1)
        {
            printf("\nAlumno:\n| Legajo | Nombre                         | Anos |\n");
            printf("|   %2i   | %-30s |  %i  |\n",legajos[i],nombres[i],anos[i]);
        }
    }
    if(flag==0)
    {
        printf("\nNo existe el legajo %i.\n",busqueda);
    }
    printf("\n");
}                                                                                                       //FIN FUNCION MUESTRAARREGLOESPECIFICO
void ordenSeleccion(int legajos[20],char nombres[20][30],int anos[20],int cantidad)                     //INICIO FUNCION ORDENSELLECION             (5)
{
    int i=0,posicion,auxL[1],auxA[1];
    char auxN[1][30];
    while (i<cantidad-1)
    {
        posicion=posicionMenor(nombres,i,cantidad);                                                     //FUNCION POSICIONMENOR
        auxL[0]=legajos[posicion];
        strcpy(auxN[0],nombres[posicion]);
        auxA[0]=anos[posicion];
        legajos[posicion]=legajos[i];
        strcpy(nombres[posicion],nombres[i]);
        anos[posicion]=anos[i];
        legajos[i]=auxL[0];
        strcpy(nombres[i],auxN[0]);
        anos[i]=auxA[0];
        i++;
    }
}                                                                                                       //FIN FUNCION ORDENSELLECION
int posicionMenor(char nombres[20][30],int a,int cantidad)                                              //INICIO FUNCION POSICIONMENOR              (6)
{
    int posicion=a;
    int i=a+1;
    char menor[1][30];
    strcpy(menor[0],nombres[a]);
    while (i<cantidad)
    {
        if(strcmp(menor[0],nombres[i])==1)
        {
            strcpy(menor[0],nombres[i]);
            posicion=i;
        }
        i++;
    }
    return posicion;
}                                                                                                       //FIN FUNCION POSICIONMENOR
void muestraArregloIndividual(int legajos[20],char nombres[20][30],int anos[20],int cantidad)           //INICIO FUNCION MUESTRAARREGLOESPECIFICO   (7)
{
    int i;
    char continuar;
    printf("Enter para continuar y luego de cada alumno:");
    fflush(stdin);
    scanf("%c",&continuar);
    printf("\nAlumno:\n| Legajo | Nombre                         | Anos |");
    for(i=0;i<cantidad;i++)
    {
            fflush(stdin);
            scanf("%c",&continuar);
            printf("|   %2i   |",legajos[i]);
            printf(" %-30s |",nombres[i]);
            printf("  %i  |",anos[i]);
    }
    printf("\n");
}                                                                                                       //FIN FUNCION MUESTRAARREGLOESPECIFICO
void cargaArregloRandom(int arreglo[20])                                                                //INICIO FUNCION CARGAARREGLORANDOM         (8)
{
    int i;
    srand(time(NULL));                                                                                  //INICIALIZA EL GENERADOR DE NUMEROS RANDOM
    for(i=0;i<20;i++)
        {
            arreglo[i]=rand()%100+1;
        }
}                                                                                                       //FIN FUNCION CARGAARREGLORANDOM
void muestraArreglo(int arreglo[20])                                                                    //INICIO FUNCION MUESTRAMATRIZINT           (9)
{
    int i;
    for(i=0;i<20;i++)
    {
        printf("|%2i| ",arreglo[i]);
    }
    printf("\n");
}                                                                                                       //FIN FUNCION MUESTRAMATRIZINT
void buscarPar(int arreglo[20],int pares[20])                                                           //INICIO FUNCION BUSCARPAR                  (10)
{
    int i,j=0;
    for(i=0;i<20;i++)
    {
        if(arreglo[i]%2==0)
        {
            pares[j]=arreglo[i];
            j++;
        }
    }
}                                                                                                       //FIN FUNCION BUSCARPAR
void ejercicio1()
{
    //Crear una funcion que los cargue, hasta que el usuario lo decida.
    int cantidad,legajos[20]={},anos[20]={};
    char nombres[20][30]={};
    cantidad=cargaArreglos(legajos,nombres,anos);                                                       //FUNCION CARGARREGLOS
    muestraArreglos(legajos,nombres,anos,cantidad);                                                     //FUNCION MUESTRAARREGLOS
    printf("Se cargaron %i alumnos.\n\n",cantidad);
}
void ejercicio2()
{
    //Crear una funcion que busque dentro del arreglo de legajos y retorne la posicion de un determinado valor.
    int cantidad,busqueda=0,posicion=-1,flag,legajos[20]={},anos[20]={};
    char nombres[20][30]={};
    cantidad=cargaArreglos(legajos,nombres,anos);                                                       //FUNCION CARGARREGLOS
    muestraArreglos(legajos,nombres,anos,cantidad);                                                     //FUNCION MUESTRAARREGLOS
    flag=busquedaLegajos(legajos,cantidad,&busqueda,&posicion);                                         //FUNCION BUSQUEDALEGAJOS
    if(flag==1)
    {
        printf("\nEl legajo %i esta cargado en la posicion i=%i.\n\n",busqueda,posicion);
    }
    else
    {
        printf("\nNo existe el legajo %i.\n\n",busqueda);
    }
}
void ejercicio3()
{
    //Hacer una funcion que reciba como parametro todos los arreglos y encuentre el nombre correspondiente a un determinado legajo y lo imprima por pantalla.
    //Se debe invocar la función 2.
    int cantidad,legajos[20]={},anos[20]={};
    char nombres[20][30]={};
    cantidad=cargaArreglos(legajos,nombres,anos);                                                       //FUNCION CARGARREGLOS
    muestraArreglos(legajos,nombres,anos,cantidad);                                                     //FUNCION MUESTRAARREGLOS
    muestraArregloEspecifico(legajos,nombres,anos,cantidad);                                            //FUNCION MUESTRAARREGLOESPECIFICO
}
void ejercicio4()
{
    //Hacer una funcion que reciba como parametro todos los arreglos y los ordene por nombre.
    //(por el metodo de seleccion o insercion).
    int cantidad,legajos[20]={},anos[20]={};
    char nombres[20][30]={};
    cantidad=cargaArreglos(legajos,nombres,anos);                                                       //FUNCION CARGARREGLOS
    muestraArreglos(legajos,nombres,anos,cantidad);                                                     //FUNCION MUESTRAARREGLOS
    ordenSeleccion(legajos,nombres,anos,cantidad);
    printf("Alumnos ordenados por nombre\n");
    muestraArreglos(legajos,nombres,anos,cantidad);                                                     //FUNCION MUESTRAARREGLOS
}
void ejercicio5()
{
    //Mostrar por pantalla los 3 arreglos pero de a un "registro" por vez.
    int cantidad,legajos[20]={},anos[20]={};
    char nombres[20][30]={};
    cantidad=cargaArreglos(legajos,nombres,anos);                                                       //FUNCION CARGARREGLOS
    //MUESTRO CADA REGISTRO DE ALUMNO POR ALUMNO
    muestraArregloIndividual(legajos,nombres,anos,cantidad);
    printf("\n");
}
void ejercicio6()
{
    //Se cuenta con un arreglo de numeros enteros que ya fue cargado.
    //Se pide hacer una funcion que copie los datos de todos los valores del arreglo anterior que sean pares en otro arreglo del tamaño justo.
    //Usar malloc dentro de la función y retornar el arreglo o usar dos parámetros de tipo arreglo y crear el arreglo dinámico antes de la invocación.
    //Desarrolle las funciones que considere necesarias, por ejemplo, una función que cuente la cantidad de elementos pares y otra para el traspaso de los elementos.

    /*int arreglo[20]={},pares[20]={};
    cargaArregloRandom(arreglo);                                                               //FUNCION CARGARREGLOS
    muestraArreglo(arreglo);                                                                   //FUNCION MUESTRAARREGLOS

    buscarPar(arreglo,pares);

    pares = (pares) malloc(100 * strlen(pares));

    muestraArreglo(pares);                                                                     //FUNCION MUESTRAARREGLOS

    printf("\n");*/
}
void ejercicio7()
{
    //Hacer una funcion que reciba un arreglo dinamico por parametro, la cantidad de elementos validos del mismo, y un valor que indique el nuevo tamaño que se le quiere dar a dicho arreglo.
    //La funcion debe redimensionar el arreglo (usar la funcion realloc) y retornar el puntero a dicho espacio de memoria.
    //Investigar el uso de la funcion realloc.
}
