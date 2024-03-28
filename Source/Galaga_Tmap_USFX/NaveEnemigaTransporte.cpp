// Fill out your copyright notice in the Description page of Project Settings.

#include "NaveEnemigaTransporte.h"

void ANaveEnemigaTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

ANaveEnemigaTransporte::ANaveEnemigaTransporte()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	
    Timer = 0.0f; //Inicializa el timer en 0
    TiempoTranscurrido = 0.0f;
    Velocidad = 200.0f; //Declara la velocidad de la nave 
    TiempoDeVida = 10.0f; //Declara el tiempo de vida de la nave
    TiempoDeCreacion = 0.0f; //Declara el tiempo de creación de la nave
    LimiteX = 1800.0f; //Declara el límite en el eje X
}


void ANaveEnemigaTransporte::Mover(float DeltaTime)
{
    // Obtén la posición actual del actor
    //FVector PosicionActual = GetActorLocation();

    //// Declara la nueva posición en X e Y
    //float NewX;
    //float NewY;
    //float Amplitud = 4.0f;
    //float Frecuencia = 3.0f;
    //// Calcula el desplazamiento en el eje Y
    //if (Timer <= 1.0f && Timer >= 0)
    //{
    //    // Si han pasado más de 5 segundos, cambia la pendiente
    //    NewX = PosicionActual.X - Velocidad * DeltaTime;
    //    NewY = PosicionActual.Y - Amplitud * FMath::Sin(Frecuencia * Timer); // Es negativa para mover hacia abajo
    //}
    //else
    //{
    //    // Movimiento lineal hacia abajo
    //    NewX = PosicionActual.X - Velocidad * DeltaTime;
    //    NewY = PosicionActual.Y + Velocidad * DeltaTime;
    //}

    //// Actualiza el tiempo transcurrido
    //TiempoTranscurrido += PI / 2 * DeltaTime;
    //Timer = FMath::Sin(TiempoTranscurrido); // Alternando para que sea positivo y negativo

    //// Calcula las nuevas posiciones en X e Y
    //FVector NuevaPosicion = FVector(NewX, NewY, PosicionActual.Z);

    //// Actualiza la posición del actor
    //SetActorLocation(NuevaPosicion);

    //// Verifica los límites y ajusta la posición si es necesario
    //if (GetActorLocation().X <= -1800.0f)
    //{
    //    SetActorLocation(FVector(1850.0f, NewY, PosicionActual.Z));
    //}
    //else if (GetActorLocation().Y >= 1850.0f)
    //{
    //    SetActorLocation(FVector(NewX, -1850.0f, PosicionActual.Z));
    //}
    //else if (GetActorLocation().Y <= -1850.0f)
    //{
    //    SetActorLocation(FVector(NewX, 1850.0f, PosicionActual.Z));
    //}

        // Calcular el desplazamiento en el eje X basado en la velocidad y el tiempo transcurrido
 // Calcular el desplazamiento en el eje X basado en la velocidad y el tiempo transcurrido
    float DeltaPositionX = Velocidad * DeltaTime;

    // Obtener la ubicación actual del actor
    FVector ActorLocation = GetActorLocation();

    // Calcular la nueva ubicación del actor en el eje X
    float NewX = ActorLocation.X + DeltaPositionX;

    // Verificar si la nueva posición en el eje X supera cierto límite
    if (NewX >= LimiteX)
    {
        // Si la nueva posición en el eje X supera el límite, destruir el actor
        Destroy();
    }
    else
    {
        // Crear un vector de la nueva ubicación con la misma coordenada Y y Z que la ubicación actual
        FVector NewLocation = FVector(NewX, ActorLocation.Y, ActorLocation.Z);

        // Establecer la nueva ubicación del actor
        SetActorLocation(NewLocation);
    }
}

void ANaveEnemigaTransporte::Destruirse()
{
}

void ANaveEnemigaTransporte::Escapar(FVector PosicionJugador)
{
}

void ANaveEnemigaTransporte::Atacar(bool bAtacar)
{
}

