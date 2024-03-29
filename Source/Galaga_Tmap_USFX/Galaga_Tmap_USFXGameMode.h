// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NaveEnemiga.h" // Asegúrate de incluir el archivo de encabezado de ANaveEnemiga aquí
#include "Galaga_Tmap_USFXGameMode.generated.h"
class ANaveEnemigaCaza;
UCLASS(minimalapi)
class AGalaga_Tmap_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_Tmap_USFXGameMode();

protected:
	virtual void BeginPlay() override;

public:
	//Otra forma de realizar el Tmap
	//float TiempoTranscurrido; // Tiempo transcurrido desde el inicio del juego
	////float VelocidadNavesEnemigas; // Velocidad de las naves enemigas

	virtual void Tick(float DeltaTime) override;
	//TMap<int32, ANaveEnemiga*> NaveEnemiga; // Mapa de naves enemigas

	//void AgregarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave);
	//void ModificarNaveEnemiga(int32 ID, ANaveEnemiga* NuevaNave);
	//void EliminarNaveEnemiga(int32 ID);

	//void SpawnNaveEnemiga(); // Declaración de la función SpawnNaveEnemiga
	//void ModificarNaves(); // Declaración de la función ModificarNaves
	//void EliminarNavesPeriodicamente(); // Declaración de la función EliminarNavesPeriodicamente

	//FTimerHandle SpawnTimerHandle; // Manejador del temporizador de spawn
	//FTimerHandle ModifyTimerHandle; // Manejador del temporizador de agregar fila
	//FTimerHandle DeleteTimerHandle; // Manejador del temporizador de eliminar naves

	//Creacion del Tmap para almacenar las naves enemigas caza
	TMap<int32, TArray<ANaveEnemigaCaza*>> MatizNavesEnemigasCaza;


	FVector SpawnLocationInicial; // Ubicación inicial para spawnear las naves enemigas caza

	float SeparacionColumnas; // Separación entre columnas de naves

	float SeparacionFilas; // Separación entre filas de naves

	void Eliminacion_Filas_TMap();//funcion que nos ayudara a eliminar las naves enemigas caza
};

