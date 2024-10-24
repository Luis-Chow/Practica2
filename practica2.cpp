#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct persona{
    int id_registro;
    char nombre[50];
    int ced;
    int edad;
    float peso;
    float altura;
    char genero[10];
};

int main(){
    int dato;
    char genero;
    cout<<"Cuantas personas desea ingresar?"<<endl;
    cin>>dato;
    persona p;

    fstream FILE("./archivo.bin",ios::out| ios::binary);
    for(int i =0; i<dato; i++){
        p.id_registro = i;
        cout<<"Introduzca el nombre de la persona"<<endl;
        cin>>p.nombre;
        cout<<"Introduzca la cedula de la persona"<<endl;
        cin>>p.ced;
        cout<<"Introduzca la edad de la persona"<<endl;
        cin>>p.edad;
        cout<<"Introduzca el peso de la persona en KG"<<endl;
        cin>>p.peso;
        cout<<"Introduzca la altura de la persona en metros"<<endl;
        cin>>p.altura;
        cout<<"Introduzca el genero de la persona (M/F)"<<endl;
        cin>>genero;
        if (genero == 'M' || genero == 'm') {
            strcpy(p.genero, "Masculino"); 
        } else if (genero == 'F' || genero == 'f') {
            strcpy(p.genero, "Femenino"); 
        } else {
            cout << "Opcion no valida. Ingrese M o F" << endl;
        }
        FILE.write(reinterpret_cast<char *>(&p), sizeof(persona));
    }
    FILE.close();
    return 0;
}