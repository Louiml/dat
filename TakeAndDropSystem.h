#include "TakeAndDropSystem.h"
#include "Character.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"

void UMyDropAndPutComponent::Drop()
{
    AMyCharacter* MyCharacter = Cast<AMyCharacter>(GetOwner());
    if (MyCharacter)
    {
        MyCharacter->HandMesh->DetachFromComponent(FDetachmentTransformRules::KeepRelativeTransform);

        MyCharacter->HandMesh->SetSimulatePhysics(true);

        MyCharacter->HandMesh = nullptr;
    }
}

void UMyDropAndPutComponent::Put(UStaticMeshComponent* Object)
{
    AMyCharacter* MyCharacter = Cast<AMyCharacter>(GetOwner());
    if (MyCharacter)
    {
        Object->AttachToComponent(MyCharacter->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, "HandSocket");

        Object->SetSimulatePhysics(false);
        MyCharacter->HandMesh = Object;
    }
}
