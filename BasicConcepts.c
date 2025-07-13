#include <stdio.h>

//Creando una tarea
void vTarea1(void *pvParameters){
    // *pvParameters es un puntero generico
    //permitiendo pasar cualquier tipo de puntero (int,float)
    // void * parameters es opcional pero util mas adelante
    for(;;){ //Como vimos antes es un bucle infinito
        vTaskDelay(pdMS_TO_TICKS(1000)); //Espera 1000ms
    //hace pausas pero no bloquea otras tareas, preguntar

    }
}
    //& es el operador direccion
    //int pin1 = 5; &pin1 = 0x2000001100
    //(void *) es un vast y ambia el tipo de puntero
    //pvParameters solo acepta puntero directo porque FreeRTOS
    //esta diseñado para que todas las tareas reciban punteros 
    //de datos, de manera que asi puedes acceder a valores
    //mas complejos (estructura) ahorrar memoria, y reutilizar
    // una funcion para distintas tareas

int main (void){

    //Uso de xTaskCreate()
    xTaskCreate(
        vTarea1, //Es la funcion de la tarea
        "Tarea1", //Nombre de la tarea
        128, //Tamaño del stack (en palabras, no bytes)
        // El tamaño de palabra depende del microcontrolador
        // Para STM32 1 word = 4 bytes
        NULL, //Parametro
        1, //Prioridad
        NULL //Handle opcional

    );

    //Iniciando el scheduler
    vTaskStartSchedules();  //Esta funcion inicia al sistema operativo
    //Una vez iniciado el OS las tareas se ejecutaran por siempre
    //Y no retorna nada, si es que retorna algo significa
    //que hubo un error (falta de memoria)

    while(1); //Es una medida de proteccion
    //Sirve para que evitar que el programa sigue ejecutando
    //instrucciones peligrosas

}