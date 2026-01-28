# 🦶 ProtoReady: Footstep System

> **[UE 5.5+]** **[C++]** **[Production-Ready]**

A high-performance, DataAsset-driven footstep system for Unreal Engine. Designed for C++ efficiency with a designer-friendly workflow (No Blueprints required).

---

## 🚀 Features

- **Component-Based**: Drop `PRFootstepComponent` onto any Actor.
- **Physics-Driven**: Automatically detects surfaces via Physical Materials.
- **Flexible Tracing**:
  -  Sphere, Line, Multi, Box.
- **Start** from Root, foots or socket.
- **Trigger Modes**:
  - **AnimNotify**
  - **Distance**: Distance logic-driven stride calculations.
- **Audio Mix** support :
  - Attenuation
  - Sound effect

---

## 🛠️ Setup Guide

### 1. Installation
1. Copy `PR_Footstep` into your project's `Plugins` folder.
2. Enable it via **Edit > Plugins**.

### 2. Configuration
1. Define **Physical Surfaces** in `Project Settings > Engine > Physics`.
2. Create a `PRFootstepData` asset.
3. Map your surfaces to Sounds (Cues or WAVs).

![Surfaces Setup](Distribution/PR_DataAsset_Surfaces.png)

### 3. Usage
Add the `PRFootstepComponent` to your Character.
- **AnimNotify**: Add `PR_Footstep` to your Walk/Run animations.
- **Distance**: Switch `TriggerMode` to *Distance* in the Data Asset.

---

## 📦 Content Included

- PRFootstepComponent  (description succinte du système type : component C++ qui gère l'audio footstep, multiplayer + replication ready.)
- **20+ Audio Samples**: WAVs + SoundCues.
- **Showcase Level** : With NPC test actor + surface demo.
    - 
Technical : 
- **Class**: `UPRFootstepComponent` (UActorComponent).
- **Config**: `UPRFootstepData` (UPrimaryDataAsset).
- **Network**: Client-side cosmetic effect (can be replicated via RPC if needed).

---

## 📄 License

MIT License. Free for commercial use.
(c) 2026 ProtoReady Pack
