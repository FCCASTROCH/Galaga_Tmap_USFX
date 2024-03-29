// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_Tmap_USFXGameMode.h"
#include "Galaga_Tmap_USFXPawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaNodriza.h"
#include "Engine/World.h"
#include "TimerManager.h"
AGalaga_Tmap_USFXGameMode::AGalaga_Tmap_USFXGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
	DefaultPawnClass = nullptr;
	// set default pawn class to our character class
	//DefaultPawnClass = AGalaga_Tmap_USFXPawn::StaticClass();
	//TiempoTranscurrido = 0;
		//Listando los objetos del TMap  : Ubicacion en donde apareceran en el escenario **
	SpawnLocationInicial = FVector(-2000.0f, -400.0f, 250.0f); // Ubicación inicial predeterminada

	//Modificando El Tamp : Separación entre columnas y filas **
	SeparacionColumnas = 300.0f; // Separación predeterminada entre columnas
	SeparacionFilas = 200.0f; // Separación predeterminada entre filas
}


void AGalaga_Tmap_USFXGameMode::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
    //Llamamos a la función de eliminación de filas en cada fotograma 
    Eliminacion_Filas_TMap();
}



void AGalaga_Tmap_USFXGameMode::BeginPlay()
{
	Super::BeginPlay();

	/*GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AGalaga_Tmap_USFXGameMode::SpawnNaveEnemiga, 5.0f, true);
	
	GetWorld()->GetTimerManager().SetTimer(ModifyTimerHandle, this, &AGalaga_Tmap_USFXGameMode::ModificarNaves, 6.0f, true);
	GetWorld()->GetTimerManager().SetTimer(DeleteTimerHandle, this, &AGalaga_Tmap_USFXGameMode::EliminarNavesPeriodicamente, 7.0f, true);*/
    //Hacemos uso de la clave del TMap para establecer tanto las columnas como las filat que tendra el Array
    const int32 NumeroDeColumnas = 5;
    const int32 NumeroDeFilas = 5;

    for (int32 Columna = 0; Columna < NumeroDeColumnas; ++Columna)
    {
        // Creamos un TArray para almacenar las naves enemigas caza de la columna actual
        TArray<ANaveEnemigaCaza*> NavesEnColumna;

        // Iteramos sobre el número de filas para esta columna
        for (int32 Fila = 0; Fila < NumeroDeFilas; ++Fila)
        {
            // Calculamos la ubicación de spawneo para la nueva nave enemiga caza
            FVector SpawnLocation = SpawnLocationInicial + FVector(Columna * SeparacionColumnas, Fila * SeparacionFilas, 0.0f);

            // Establecemos la rotación inicial como cero
            FRotator SpawnRotation = FRotator::ZeroRotator;

            // Spawneamos una nueva nave enemiga caza en la ubicación y rotación calculadas
            ANaveEnemigaCaza* NuevaNaveCaza = GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, SpawnRotation);

            // TMap añadiendo : las naves caza enemigas a la matriz **
            // Agregamos la nueva nave enemiga caza al TArray de naves enemigas caza de la columna actual
            NavesEnColumna.Add(NuevaNaveCaza);
        }
        // Agregamos el TArray de naves enemigas caza de la columna actual al TMap, utilizando el índice de columna como clave
        MatizNavesEnemigasCaza.Add(Columna, NavesEnColumna);
    }

}
void AGalaga_Tmap_USFXGameMode::Eliminacion_Filas_TMap()
{
    // Verificar y eliminar filas completas
    for (auto& Par : MatizNavesEnemigasCaza)
    {
        // Acceder al TArray de naves enemigas caza asociado a cada columna
        TArray<ANaveEnemigaCaza*>& MatrizNaves = Par.Value;

        // Variable que indica si la fila está completa (todas las naves de la fila han avanzado más allá de una cierta coordenada)
        bool bRowCompleted = true;

        // Iterar sobre todas las naves enemigas caza en la fila actual
        for (ANaveEnemigaCaza* Nave : MatrizNaves)
        {
            // Verificar si la nave existe y si su posición X es menor que 3000.0f (un límite arbitrario)
            // Si la posición X de cualquier nave en la fila actual es menor que 3000.0f, la fila no está completa
            if (Nave && Nave->GetActorLocation().X < 1700.0f)
            {
                // La fila no está completa si alguna nave no ha alcanzado la posición requerida
                bRowCompleted = false;
                break;
            }
        }

        // Si la fila está completa, destruir todas las naves enemigas caza en esa fila y limpiar el TArray
        if (bRowCompleted)
        {
            // Si la fila está completa, iterar sobre todas las naves enemigas caza en esa fila
            for (ANaveEnemigaCaza* Nave : MatrizNaves)
            {
                // Verificar si la nave existe
                if (Nave)
                {
                    //TMap Eliminacion : las naves enemigas caza de cada fila**
                    // Destruir la nave enemiga caza
                    Nave->Destroy();
                }
            }
            // Limpiar el TArray para eliminar todas las referencias a las naves de la fila
            MatrizNaves.Empty();
        }
    }
}





//
//void AGalaga_Tmap_USFXGameMode::AgregarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave)
//{
//	// Verificar si ya hay una nave enemiga con el mismo ID
//	if (NaveEnemiga.Contains(ID))
//	{
//		// Si ya existe, mostrar un mensaje de advertencia y no agregar la nueva nave
//		UE_LOG(LogTemp, Warning, TEXT("Ya existe una nave enemiga con el ID %d"), ID);
//	}
//	else
//	{
//		// Si no existe, agregar la nueva nave al mapa
//		NaveEnemiga.Add(ID, NuevaNave);
//	}
//}
//void AGalaga_Tmap_USFXGameMode::SpawnNaveEnemiga()
//{
//	const int32 NumeroDeColumnas = 2;
//	const int32 NumeroDeFilas = 5;
//	int32 NaveID = 1;
//
//	for (int32 Columna = 0; Columna < NumeroDeColumnas; ++Columna)
//	{
//		for (int32 Fila = 0; Fila < NumeroDeFilas; ++Fila)
//		{
//			FVector SpawnLocation = FVector(Columna * 200.0f, Fila * 100.0f, 350.0f);
//			FRotator SpawnRotation = FRotator::ZeroRotator;
//
//			// Verificar si ya existe una nave enemiga con el ID correspondiente
//			if (!NaveEnemiga.Contains(NaveID))
//			{
//				// Si no existe, crear una nueva nave enemiga
//				ANaveEnemiga* NuevaNave = GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, SpawnRotation);
//				if (NuevaNave)
//				{
//					// Agregar la nueva nave al mapa con su ID correspondiente
//					AgregarNaveEnemiga(NaveID, NuevaNave);
//				}
//				else
//				{
//					UE_LOG(LogTemp, Error, TEXT("No se pudo crear la nave enemiga caza."));
//				}
//			}
//
//			++NaveID;
//		}
//	}
//}
//
//void AGalaga_Tmap_USFXGameMode::ModificarNaves()
//{
//	UE_LOG(LogTemp, Warning, TEXT("ModificarNaves() ejecutada"));
//	for (auto& Pair : NaveEnemiga)
//	{
//		int32 ID = Pair.Key;
//		ANaveEnemiga* NuevaNave = Pair.Value;
//		UE_LOG(LogTemp, Warning, TEXT("Modificando nave ID: %d"), ID);
//
//	
//		ANaveEnemigaCaza* NuevaNaveCaza = Cast<ANaveEnemigaCaza>(NuevaNave);
//		if (NuevaNaveCaza)
//		{
//		
//			FVector SpawnLocation = NuevaNaveCaza->GetActorLocation();
//			FRotator SpawnRotation = NuevaNaveCaza->GetActorRotation();
//
//			// Destruye la nave enemiga actual
//			NuevaNaveCaza->Destroy();
//
//			ANaveEnemigaTransporte* NuevaNaveTransporte = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(SpawnLocation, SpawnRotation);
//			
//			if (NuevaNaveTransporte)
//			{
//				// Modifica el mapa para que apunte a la nueva nave enemiga de tipo transporte
//				NaveEnemiga[ID] = NuevaNaveTransporte;
//			}
//			else
//			{
//				// Manejar errores si no se puede crear la nueva nave enemiga
//				UE_LOG(LogTemp, Error, TEXT("No se pudo crear la nave enemiga transporte."));
//			}
//		}
//	}
//}
//
//
//
//void AGalaga_Tmap_USFXGameMode::ModificarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave)
//{
//	// Verificar si existe una nave enemiga con el ID proporcionado
//	if (NaveEnemiga.Contains(ID))
//	{
//		// Si existe, modificar la nave enemiga con la nueva nave proporcionada
//		NaveEnemiga[ID] = NuevaNave;
//	}
//	else
//	{
//		// Si no existe, mostrar un mensaje de advertencia
//		UE_LOG(LogTemp, Warning, TEXT("No existe una nave enemiga con el ID %d para modificar"), ID);
//	}
//}
//void AGalaga_Tmap_USFXGameMode::EliminarNaveEnemiga(int32 ID)
//{
//	// Verificar si existe una nave enemiga con el ID proporcionado
//	if (NaveEnemiga.Contains(ID))
//	{
//		// Obtener el puntero a la nave enemiga
//		ANaveEnemiga* NaveAEliminar = NaveEnemiga[ID];
//
//		// Verificar si el puntero es válido
//		if (NaveAEliminar)
//		{
//			// Destruir la nave enemiga
//			NaveAEliminar->Destroy();
//
//			// Eliminar la entrada del mapa
//			NaveEnemiga.Remove(ID);
//
//			// Mostrar un mensaje de confirmación
//			UE_LOG(LogTemp, Warning, TEXT("Nave enemiga con ID %d eliminada."), ID);
//		}
//		else
//		{
//			// Mostrar un mensaje de advertencia si el puntero no es válido
//			UE_LOG(LogTemp, Warning, TEXT("El puntero de la nave enemiga con ID %d no es válido."), ID);
//		}
//	}
//	else
//	{
//		// Si no existe, mostrar un mensaje de advertencia
//		UE_LOG(LogTemp, Warning, TEXT("No existe una nave enemiga con el ID %d para eliminar"), ID);
//	}
//}
//
//void AGalaga_Tmap_USFXGameMode::EliminarNavesPeriodicamente()
//{
//	// Almacena los IDs de las naves enemigas que deseas eliminar en este intervalo de tiempo
//	TArray<int32> NavesAEliminarIDs;
//
//	// Iterar sobre todas las naves enemigas y almacenar sus IDs si fueron creadas durante este intervalo
//	for (auto& Pair : NaveEnemiga)
//	{
//		int32 ID = Pair.Key;
//		ANaveEnemiga* NaveAEliminar = Pair.Value;
//
//		// Verificar si la nave fue creada durante este intervalo de tiempo
//		if (NaveAEliminar && NaveAEliminar->CreationTime >= TiempoTranscurrido - 5.0f)
//		{
//			// Destruir la nave
//			NaveAEliminar->Destroy();
//
//			// Almacenar el ID de la nave enemiga para eliminar
//			NavesAEliminarIDs.Add(ID);
//		}
//	}
//	// Eliminar las naves enemigas utilizando los IDs almacenados
//	for (int32 ID : NavesAEliminarIDs)
//	{
//		NaveEnemiga.Remove(ID);
//	}
//}
