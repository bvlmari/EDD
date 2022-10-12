#include<stdio.h>
#include<stdlib.h>

struct Pila{
    int top;
    int capacidad;
    int* arreglo;
};

struct Pila* crear(int capacidad){
    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));//Reeserva del bloque de memoria
    pila->capacidad = capacidad;//asignameos el tamaño de la pila
    pila->top = -1; //inicializamos el valor en el tope de la pila
    pila -> arreglo = (int*)malloc(pila->capacidad*sizeof(int)); // creamos un arreglo que almacena los datos
    return pila;
}

int llena(struct Pila* pila){
    return pila->top == pila->capacidad-1;
}

int vacia(struct Pila* pila){
    return pila->top == -1;
}

void push(struct Pila* pila, int elemento){
    if(llena(pila))
        return;
    pila->arreglo[++pila->top]=elemento;
}

int pop(struct Pila* pila){
    if(vacia(pila))
        return 0;
    return pila->arreglo[pila->top--];
}

int peek(struct Pila* pila){
    int val = pop(pila);
    push(pila,val);
    return val;
}

void imprimir(struct Pila* pila){
    for(int i=0; i<=pila->top; i++)
        printf("%i\n", pila->arreglo[i]);
}

int buscar(struct Pila* pila, int valor){
    for(int i=0; i <= pila->top; i++)
        if(pila->arreglo[i]==valor)
            return i;
    
    return -1;
}

int numelementos(struct Pila* pila){
    return pila->top+1;
}

int main(){
    int num, tam, op;

    printf("\nIngrese el tamaño deseado de la pila");
    scanf("%d",&tam);
    struct Pila* pila = crear(tam); //se crea con el tamaño deseado

    printf("\nInsertar elemento a la pila\nRemover top de la pila\nSeleccione una opcion:")
    scanf("%d",&op);

    while(tam>0){
        printf("\nIngresa el numero que se quiere ingresar a la pila");
        scanf("%d",&num);
        push(pila, num);
        //pop(pila);
        tam--;
    }

    pop(pila);

    imprimir(pila);
    printf("La pila tiene %i elementos\n", numelementos(pila));

    if(llena(pila))
        printf("\nLa pila esta llena");
}
