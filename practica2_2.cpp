#include<iostream>
#include<fstream>
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
    persona p;
    int dato;
    cout<<"Introduzca el ID de registro de la persona"<<endl;
    cin>>dato;
    fstream FILE("./archivo.bin",ios::in| ios::binary);

    FILE.seekg(sizeof(persona) * dato  , ios::beg );

    cout<<FILE.tellg()<<endl;

    FILE.read(reinterpret_cast<char *>(&p), sizeof(persona));

    cout<<"Id de registro: "<<p.id_registro<<"\n"<<"Nombre: "<<p.nombre<<"\n"<<"Cedula: "<<p.ced<<"\n"<<"Edad: "<<p.edad<<"\n"<<"Peso: "<<p.peso<<"\n"<<"Altura: "<<p.altura<<"\n"<<"Genero: "<<p.genero<<endl;
    
    FILE.close();
    return 0;
}