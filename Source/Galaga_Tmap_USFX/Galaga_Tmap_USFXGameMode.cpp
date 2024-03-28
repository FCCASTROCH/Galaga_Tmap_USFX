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
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_Tmap_USFXPawn::StaticClass();
	TiempoTranscurrido = 0;
}


void AGalaga_Tmap_USFXGameMode::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	
}



void AGalaga_Tmap_USFXGameMode::BeginPlay()
{
	Super::BeginPlay();
	/*GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AGalaga_Tmap_USFXGameMode::AgregarNaveEnemiga, 10.0f, true);
	GetWorld()->GetTimerManager().SetTimer(AddRowTimerHandle, this, &AGalaga_Tmap_USFXGameMode::AgregarFilaDeNaves, 15.0f, true);
	*/
	//FVector SpawnLocation = FVector(500.0f, 500.0f, 250.0f);
	//FRotator SpawnRotation = FRotator::ZeroRotator;
	//FVector SpawnLocationT = FVector(600.0f, 600.0f, 250.0f);
	//// Crear una nueva instancia de ANaveEnemiga (puedes usar cualquier subclase de ANaveEnemiga)
	//ANaveEnemiga* NuevaNave = GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, SpawnRotation);
	//ANaveEnemiga* NuevaNave2 = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(SpawnLocationT, SpawnRotation);
	//// Llamar a la función AgregarNaveEnemiga para agregar la nueva nave al mapa
	//AgregarNaveEnemiga(1, NuevaNave);
	//AgregarNaveEnemiga(2, NuevaNave2);
	GetWorld()->GetTimerManager().SetTimer(SpawnTimerHandle, this, &AGalaga_Tmap_USFXGameMode::SpawnNaveEnemiga, 10.0f, true);
	//ModificarNaveEnemiga(1, NuevaNave2);
	GetWorld()->GetTimerManager().SetTimer(ModifyTimerHandle, this, &AGalaga_Tmap_USFXGameMode::ModificarNaves, 11.0f, true);
	GetWorld()->GetTimerManager().SetTimer(DeleteTimerHandle, this, &AGalaga_Tmap_USFXGameMode::EliminarNavesPeriodicamente, 14.0f, true);
}

void AGalaga_Tmap_USFXGameMode::AgregarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave)
{
	// Verificar si ya hay una nave enemiga con el mismo ID
	if (NaveEnemiga.Contains(ID))
	{
		// Si ya existe, mostrar un mensaje de advertencia y no agregar la nueva nave
		UE_LOG(LogTemp, Warning, TEXT("Ya existe una nave enemiga con el ID %d"), ID);
	}
	else
	{
		// Si no existe, agregar la nueva nave al mapa
		NaveEnemiga.Add(ID, NuevaNave);
	}
}
void AGalaga_Tmap_USFXGameMode::SpawnNaveEnemiga()
{
	
	for (auto& Pair : NaveEnemiga)
	{
		ANaveEnemiga* Nave = Pair.Value;
		if (Nave)
		{
			Nave->Destroy();
		}
	}
	NaveEnemiga.Empty(); // Limpiar el mapa de naves enemigas

	const int32 NumeroDeColumnas = 2;
	const int32 NumeroDeFilas = 5;
	int32 NaveID = 1; 

	for (int32 Columna = 0; Columna < NumeroDeColumnas; ++Columna)
	{
		for (int32 Fila = 0; Fila < NumeroDeFilas; ++Fila)
		{
			FVector SpawnLocation = FVector(Columna * 200.0f, Fila * 100.0f, 350.0f);
			FRotator SpawnRotation = FRotator::ZeroRotator;

			ANaveEnemiga* NuevaNave = GetWorld()->SpawnActor<ANaveEnemigaCaza>(SpawnLocation, SpawnRotation);
			if (NuevaNave)
			{
			
				AgregarNaveEnemiga(NaveID++, NuevaNave);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("No se pudo crear la nave enemiga caza."));
			}
		}
	}
}

void AGalaga_Tmap_USFXGameMode::ModificarNaves()
{
	UE_LOG(LogTemp, Warning, TEXT("ModificarNaves() ejecutada"));
	for (auto& Pair : NaveEnemiga)
	{
		int32 ID = Pair.Key;
		ANaveEnemiga* NuevaNave = Pair.Value;
		UE_LOG(LogTemp, Warning, TEXT("Modificando nave ID: %d"), ID);

	
		ANaveEnemigaCaza* NuevaNaveCaza = Cast<ANaveEnemigaCaza>(NuevaNave);
		if (NuevaNaveCaza)
		{
		
			FVector SpawnLocation = NuevaNaveCaza->GetActorLocation();
			FRotator SpawnRotation = NuevaNaveCaza->GetActorRotation();

			// Destruye la nave enemiga actual
			NuevaNaveCaza->Destroy();

			ANaveEnemigaTransporte* NuevaNaveTransporte = GetWorld()->SpawnActor<ANaveEnemigaTransporte>(SpawnLocation, SpawnRotation);
			
			if (NuevaNaveTransporte)
			{
				// Modifica el mapa para que apunte a la nueva nave enemiga de tipo transporte
				NaveEnemiga[ID] = NuevaNaveTransporte;
			}
			else
			{
				// Manejar errores si no se puede crear la nueva nave enemiga
				UE_LOG(LogTemp, Error, TEXT("No se pudo crear la nave enemiga transporte."));
			}
		}
	}
}



void AGalaga_Tmap_USFXGameMode::ModificarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave)
{
	// Verificar si existe una nave enemiga con el ID proporcionado
	if (NaveEnemiga.Contains(ID))
	{
		// Si existe, modificar la nave enemiga con la nueva nave proporcionada
		NaveEnemiga[ID] = NuevaNave;
	}
	else
	{
		// Si no existe, mostrar un mensaje de advertencia
		UE_LOG(LogTemp, Warning, TEXT("No existe una nave enemiga con el ID %d para modificar"), ID);
	}
}
void AGalaga_Tmap_USFXGameMode::EliminarNaveEnemiga(int32 ID)
{
	// Verificar si existe una nave enemiga con el ID proporcionado
	if (NaveEnemiga.Contains(ID))
	{
		// Obtener el puntero a la nave enemiga
		ANaveEnemiga* NaveAEliminar = NaveEnemiga[ID];

		// Verificar si el puntero es válido
		if (NaveAEliminar)
		{
			// Destruir la nave enemiga
			NaveAEliminar->Destroy();

			// Eliminar la entrada del mapa
			NaveEnemiga.Remove(ID);

			// Mostrar un mensaje de confirmación
			UE_LOG(LogTemp, Warning, TEXT("Nave enemiga con ID %d eliminada."), ID);
		}
		else
		{
			// Mostrar un mensaje de advertencia si el puntero no es válido
			UE_LOG(LogTemp, Warning, TEXT("El puntero de la nave enemiga con ID %d no es válido."), ID);
		}
	}
	else
	{
		// Si no existe, mostrar un mensaje de advertencia
		UE_LOG(LogTemp, Warning, TEXT("No existe una nave enemiga con el ID %d para eliminar"), ID);
	}
}

void AGalaga_Tmap_USFXGameMode::EliminarNavesPeriodicamente()
{
	// Almacena los IDs de las naves enemigas que deseas eliminar
	TArray<int32> NavesAEliminarIDs;

	// Iterar sobre todas las naves enemigas y almacenar sus IDs
	for (auto& Pair : NaveEnemiga)
	{
		int32 ID = Pair.Key;
		ANaveEnemiga* NaveAEliminar = Pair.Value;

		// Verificar si la nave es válida antes de intentar eliminarla
		if (NaveAEliminar)
		{
			// Destruir la nave
			NaveAEliminar->Destroy();
		}

		// Almacenar el ID de la nave enemiga para eliminar
		NavesAEliminarIDs.Add(ID);
	}

	// Eliminar las naves enemigas utilizando los IDs almacenados
	for (int32 ID : NavesAEliminarIDs)
	{
		NaveEnemiga.Remove(ID);
	}
}
