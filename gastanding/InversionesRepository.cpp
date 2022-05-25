#include "InversionesRepository.h"

//TODO: Validacion antes de guardar
void InversionesRepository::agregar() 
{
	Inversion inversion;

	inversion.cargar(); 

	if (inversion.grabarEnDisco(_fileName)) 
		mostrarMensaje("Ingreso agregado exitosamente", 15, 2);
	
	else 
		mostrarMensaje("No se pudo agregar el ingreso", 15, 4);
	
}
