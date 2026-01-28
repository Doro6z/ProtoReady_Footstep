#pragma once

#include "Chaos/ChaosEngineInterface.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundEffectSource.h"

#include "PRFootstepData.generated.h"

UENUM(BlueprintType)
enum class EPRFootstepTriggerMode : uint8 { AnimNotify, Distance };

UENUM(BlueprintType)
enum class EPRTraceType : uint8 { Line, Sphere, Box, Multi };

UENUM(BlueprintType)
enum class EPRTraceStartReference : uint8 { Capsule, Root, Socket };

class USoundBase;
class USoundEffectSourcePresetChain;

UCLASS(BlueprintType, Const, meta = (DisplayName = "PR Footstep Data Asset"))
class PR_FOOTSTEP_API UPRFootstepData : public UPrimaryDataAsset {
  GENERATED_BODY()

public:
  UPRFootstepData();

  virtual FPrimaryAssetId GetPrimaryAssetId() const override;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|General")
  EPRFootstepTriggerMode TriggerMode = EPRFootstepTriggerMode::AnimNotify;

  UPROPERTY(
      EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|General",
      meta = (ClampMin = "10.0",
              EditCondition = "TriggerMode==EPRFootstepTriggerMode::Distance",
              EditConditionHides))
  float FootIntervalDistance;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Surfaces")
  TMap<TEnumAsByte<EPhysicalSurface>, TObjectPtr<USoundBase>> SurfaceSounds;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Surfaces")
  TObjectPtr<USoundBase> DefaultSound;

  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "PR Footstep|Landing Sound")
  TObjectPtr<USoundBase> LandingSound;

  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "PR Footstep|Landing Sound")
  bool bAutoTriggerLand = true;

  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            Category = "PR Footstep|Landing Sound")
  float LandingTraceOffset = 0.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace")
  EPRTraceType TraceType = EPRTraceType::Sphere;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (ClampMin = "5.0"))
  float TraceLength;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (ClampMin = "1.0",
                    EditCondition = "TraceType==EPRTraceType::Sphere",
                    EditConditionHides))
  float SphereRadius = 10.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "TraceType==EPRTraceType::Box",
                    EditConditionHides))
  FVector BoxHalfExtent = FVector(10.0f, 10.0f, 10.0f);

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace")
  bool bUseFootSockets = true;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace")
  TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "bUseFootSockets", EditConditionHides))
  TArray<FName> FootSockets;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "bUseFootSockets", EditConditionHides))
  TArray<FName> FootBones;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "!bUseFootSockets", EditConditionHides))
  EPRTraceStartReference TraceStartRef = EPRTraceStartReference::Capsule;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "!bUseFootSockets", EditConditionHides))
  FName ReferenceSocketName;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Trace",
            meta = (EditCondition = "!bUseFootSockets", EditConditionHides))
  float CapsuleZOffset = -89.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Audio")
  FVector2D VolumeRange;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Audio")
  FVector2D PitchRange;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Audio")
  TObjectPtr<USoundAttenuation> AttenuationSettings;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|Audio")
  TObjectPtr<USoundEffectSourcePresetChain> EffectsChain;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PR Footstep|LOD")
  float MaxLODDistance = 3000.0f;
};
