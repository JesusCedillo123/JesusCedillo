#include <iostream>
#include<stdlib.h> 
#include<stdio.h>
using namespace std; 

class ADC{
	
	private:   
		
		int resolucion,numcan,frec, *canales;   
		float *volt,*resout;
	
	public: 
	
		ADC(int,int,int);  
		void setnumcan(int _numcan,int _res,int _frec);
		virtual void calculador(); 
		
		int getnumcan(); 
		int getfrec(); 
		int getres();
};  

class ADC2 : public ADC{
	private: 	
	static const int f_osc=8; 
	int ack; 
	
	public:  
	ADC2(int,int,int); 
	void calculador(int,int);
	
	
};



ADC::ADC(int _numcan=0,int _res=0,int _frec=0): numcan(_numcan),resolucion(_res),frec(_frec)
{
  canales= new int[numcan]; 
  volt= new float[numcan];
  resout= new float[numcan];
}  

ADC2::ADC2(int ,int ,int){
	

	cout<<"Se ha hecho un objeto de una clase heredada"<<endl; 
	
}

void ADC::calculador(){
	
		for(int i=0; i<numcan; i++){
		cout<<"Seleccione el canal a usar como maximo 32: AN";
		cin>>canales[i];
	}   
	
		for(int i=0; i<numcan; i++){
		
			int resl;
			cout<<"Ingresa el voltaje como maximo 3.3 del AN"<<canales[i]<<":";
			cin>> volt[i];
			
			switch(resolucion)
			{
				case 8:
					 resl=255; 
					 resout[i]=(volt[i]/3.3)*resl;
					break; 
					
				case 10:
					 resl=1023;
					 resout[i]=(volt[i]/3.3)*resl;
					break;
				
				case 12: 
					 resl=4095;
					 resout[i]=(volt[i]/3.3)*resl;
					break;
					
				default: break;
			}
	} 
	
	cout<<"\nMostrando datos";
	cout<<"\nResolucion "<<resolucion<<" bits "<<endl;
	cout<<"\nFrecuencia "<<frec<<"Khz "<<endl;
	
	for(int i=0; i<numcan; i++){ 
	    
		cout<<"Canal AN"<<canales[i]<<endl; 
		cout<<"volt de entrada: "<<volt[i]<<"V"<<endl;
		cout<<"Dato digital: "<<resout[i]<<endl; 
	}
	
	delete[] canales; 
	delete[] volt;
	delete[] resout;
}

void ADC2::calculador(int _numcan, int _res ){  

    int _ack,*canales;  
    int numcan=_numcan;
    int res=_res;
    float frecuencia_calculada; 
    float *volt,*resout; 
    
    canales= new int[numcan]; 
  volt= new float[numcan];
  resout= new float[numcan];
    
	cout<<"Ingrese ack prescaler"<<endl; 
	cin>>_ack; 
	ack=_ack; 
	frecuencia_calculada=f_osc/ack; 
	cout<<"Frecuencia: "<<frecuencia_calculada<<"Khz"<<endl; 
	
	
	for(int i=0; i<numcan; i++){
		cout<<"Seleccione el canal a usar maximo 32: AN";
		cin>>canales[i];
	}   
	
		for(int i=0; i<numcan; i++){
		
			int resl;
			cout<<"Ingresa el voltaje como maximo 3.3 del AN"<<canales[i]<<":";
			cin>> volt[i];
			
			switch(res)
			{
				case 8:
					 resl=255; 
					 resout[i]=(volt[i]/3.3)*resl;
					break; 
					
				case 10:
					 resl=1023;
					 resout[i]=(volt[i]/3.3)*resl;
					break;
				
				case 12: 
					 resl=4095;
					 resout[i]=(volt[i]/3.3)*resl;
					break;
					
				default: break;
			}
	} 
	
	cout<<"\nMostrando datos";
	cout<<"\nResolucion :"<<res<<" bits "<<endl;
	cout<<"Frecuenia:"<<frecuencia_calculada<<"KHz"<<endl;
	
	for(int i=0; i<numcan; i++){ 
	    
		cout<<"Canal AN"<<canales[i]<<endl; 
		cout<<"voltaje de entrada: "<<volt[i]<<"V"<<endl;
		cout<<"Dato: "<<resout[i]<<endl; 
	}
	
	delete[] canales; 
	delete[] volt;
	delete[] resout;
}

///Setter
void ADC::setnumcan(int _numcan,int _res,int _frec){
  numcan=_numcan; 
  resolucion=_res; 
  frec=_frec;
}

//getter 
int ADC::getnumcan()
{
	return numcan;
} 

int ADC::getfrec()
{
	return frec;
} 

int ADC::getres()
{
	return resolucion;
}



int main(int argc, char** argv) { 
	
	int validador,numcan,resolucion,frec,opc;
	
	do{
    	
		cout<<"Opcion 1 Convertidor ADC(sin herenia ni polimorfismo)"<<endl;
		cout<<"\nOpcion 2 Calcular Convertidor ADC(Con herencia y polimorfismo)"<<endl;
		cout<<"\nIngrese numero de su opcion"<<endl;
    	if(scanf("%i", &opc) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
	if(opc==1)
	{
	  do{
    	
		cout<<"Ingrese resolucion (8,10,12)"<<endl;
    	if(scanf("%i", &resolucion) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
	    do{
    	
		cout<<"Ingrese  frecuencia"<<endl;
    	if(scanf("%i", &frec) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		
		else
		validador=0;
		
		 }while(validador==1);   
	
		do{
    	
		cout<<"Ingrese no. de canales"<<endl;
    	if(scanf("%i", &numcan) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		else
		validador=0;
		
	}while(validador==1);  
	
	ADC convertidor;
	convertidor.setnumcan(numcan,resolucion,frec); 
	convertidor.calculador(); 
	}
	
	if(opc==2)
	{
		do{
    	
		cout<<"Ingrese resolucion (8,10,12)"<<endl;
    	if(scanf("%i", &resolucion) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;
		}
		
		else
		validador=0;
		
	}while(validador==1); 
	
  
	
		do{
    	
		cout<<"Ingrese no. de canales"<<endl;
    	if(scanf("%i", &numcan) != 1){
    		cout<<"Dato no válido"<<endl; 
	        validador=1;	
		}
		else
		validador=0;
		
	}while(validador==1);  
	
	ADC convertidor;
	convertidor.setnumcan(numcan,resolucion,frec);  
	
	ADC2 convertidor2(convertidor.getnumcan(),convertidor.getres(),convertidor.getfrec());
	convertidor2.calculador(convertidor.getnumcan(),convertidor.getres());
	
	}
 
	return 0;
}