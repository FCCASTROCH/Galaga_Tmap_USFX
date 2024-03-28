
// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaNodriza.h"

void ANaveEnemigaNodriza::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    Mover(DeltaTime);
}
const float VelocidadHorizontal = 200.0f;

// Define una velocidad de rotación
ANaveEnemigaNodriza::ANaveEnemigaNodriza()
{
    static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    mallaNaveEnemiga->SetStaticMesh(malla.Object);
    Timer = 0.0f; //Inicializa el timer en 0
    TiempoTranscurrido = 0.0f;
    Velocidad = 200.0f; //Declara la velocidad de la nave 
    TiempoDeVida= 10.0f; //Declara el tiempo de vida de la nave
    TiempoDeCreacion = 0.0f; //Declara el tiempo de creación de la nave
}

void ANaveEnemigaNodriza::Mover(float DeltaTime)
{
    //movimiento mas rapido
     // Obtiene la posición actual del actor
    FVector PosicionActual = GetActorLocation();
    float NewY; //Declara la nueva posición en Y
    float PendienteActual = -100; //Declara la pendiente actual
    
    float NewX; //Declara la nueva posición en X  
    float Amplitud = 5.0f;
    float Frecuencia = 4.0f;

    // Si han pasado más de 5 segundos, cambia la pendiente
    if (Timer <= 1.0f && Timer >= 0)
    {


        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y - Amplitud * FMath::Sin(Frecuencia * Timer);//Es negativa para que se mueva hacia abajo;


    }
    else
    {

        NewX = PosicionActual.X - Velocidad * DeltaTime;
        NewY = PosicionActual.Y + Velocidad * DeltaTime;
    }
    TiempoTranscurrido += PI / 2 * DeltaTime;
    Timer = FMath::Sin(TiempoTranscurrido); //Alternando para que sea positivo y negativo

    // Calcula las nuevas posiciones en X e Y


    // Actualiza la posición del actor
    SetActorLocation(FVector(NewX, NewY, PosicionActual.Z));

    if (GetActorLocation().X <= -1800.0f)
    {

        SetActorLocation(FVector(1850.0f, NewY, PosicionActual.Z));

    }
    if (GetActorLocation().Y >= 1850)
    {
        SetActorLocation(FVector(NewX, -1800.0f, PosicionActual.Z));
    }

    if (GetActorLocation().Y <= -1800)
    {
        SetActorLocation(FVector(NewX, 1800.0f, PosicionActual.Z));
    }

}

void ANaveEnemigaNodriza::Destruirse()
{
}

void ANaveEnemigaNodriza::Escapar(FVector PosicionJugador)
{
}

void ANaveEnemigaNodriza::Atacar(bool bAtacar)
{
}
