// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaNodriza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_TMAP_USFX_API ANaveEnemigaNodriza : public ANaveEnemiga
{
	GENERATED_BODY()
protected:
	virtual void Tick(float DeltaTime) override;


public:
	// Velocidad de movimiento de la nave nodriza
	float Velocidad;
	float TiempoDeCreacion;
	// Velocidad de giro aleatorio de la nave nodriza
	float VelocidadDeGiro;
	float TiempoDeVida;
	// Ángulo acumulado de giro aleatorio de la nave nodriza
	float AnguloAcumulado;
	float Timer;//Inicializa el timer en 0
	float TiempoTranscurrido ;

	ANaveEnemigaNodriza();
	virtual void Mover(float DeltaTime)override;
	virtual void Destruirse()override;
	virtual void Escapar(FVector PosicionJugador)override;
	virtual void Atacar(bool bAtacar)override;

};
