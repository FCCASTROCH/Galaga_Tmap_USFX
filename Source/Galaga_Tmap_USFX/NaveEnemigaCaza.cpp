// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaCaza.h"
//#include "Clases_Galaga_usfxProjectile.h"
//#include "Components/StaticMeshComponent.h"

// Called when the game starts or when spawned
void ANaveEnemigaCaza::BeginPlay()
{
    Super::BeginPlay();

}

ANaveEnemigaCaza::ANaveEnemigaCaza()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
    mallaNaveEnemiga->SetStaticMesh(malla.Object);
    TiempoDeCreacion = 0.0f;
    TiempoDeVida = 10.0f;

}

// Called every frame
void ANaveEnemigaCaza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}



void ANaveEnemigaCaza::Mover(float DeltaTime)
{
    // Velocidad configurable desde el editor de Unreal Engine
    float VelocidadHorizontal = 200.0f; // Utiliza la velocidad configurada

    // Define una velocidad de rotación
    float VelocidadRotacion = 40.0f; // Puedes ajustar este valor según la velocidad deseada

    // Calcula el desplazamiento horizontal en la dirección deseada (hacia adelante en el eje X)
    FVector DesplazamientoHorizontal = FVector(VelocidadHorizontal, 0.0f, 0.0f) * DeltaTime;

    // Obtiene el tiempo transcurrido desde el inicio del juego y lo escala para que avance más lentamente
    float TiempoTranscurrido = GetWorld()->TimeSeconds * 0.1f; // Escala de tiempo para que vaya más lento (0.1f)

    // Calcula el ángulo de rotación basado en el tiempo
    float Angulo = FMath::Fmod(TiempoTranscurrido, 6.0f) * VelocidadRotacion; // El ángulo cambia cada 6 segundos

    // Calcula las coordenadas X e Y para el movimiento circular
    float Radio = 20.0f; // Radio del círculo
    float X = FMath::Cos(Angulo) * Radio; // Coordenada X del círculo
    float Y = FMath::Sin(Angulo) * Radio; // Coordenada Y del círculo

    // Calcula la nueva posición sumando las coordenadas X e Y al desplazamiento horizontal y a la posición actual
    FVector NuevaPosicion = GetActorLocation() + DesplazamientoHorizontal + FVector(X, Y, 0.0f);

    // Establece la nueva posición del actor
    SetActorLocation(NuevaPosicion);
}

void ANaveEnemigaCaza::Destruirse()
{
    Destroy();
}

void ANaveEnemigaCaza::Escapar(FVector PosicionJugador)
{
    // Calcula la dirección opuesta al jugadorw
    //FVector DireccionOpuesta = -PosicionJugador;
}

void ANaveEnemigaCaza::Atacar(bool bAtacar)
{
}