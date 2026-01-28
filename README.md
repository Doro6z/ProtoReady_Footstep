# 🦶 ProtoReady: Footstep System

> **[UE 5.5+]** **[C++]** **[Production-Ready]**

A high-performance, DataAsset-driven footstep solution built for Unreal Engine. Engineered for C++ efficiency, this system offers a streamlined workflow that eliminates the need for Blueprint dependencies while maintaining full designer control.

![Showcase Level](Distribution/Showcase_Level.png)

---

## 🚀 Key Capabilities

- **Component-Based Architecture**: Seamless integration via the `PRFootstepComponent`.
- **Physics-Driven Detection**: Automatically identifies surface types using the Physical Materials system.
- **Versatile Trace Options**: Sphere, Line, Box, and Multi-trace methods.
- **Dual Triggering Mechanisms**: AnimNotify (Animation-Driven) or Distance (Procedural).
- **Advanced Audio**: Spatialization, Attenuation, and random modulation (Pitch/Volume).

---

## 🛠️ Integration Guide

### 1. Installation & Setup
1. Place `PR_Footstep` in your `Plugins` folder and enable it.
2. Define **Physical Surfaces** in `Project Settings > Engine > Physics`.

![Physics Settings](Distribution/Setup_Physics.png)

### 2. Configuration
Create a `PRFootstepData` asset to map surfaces to sounds and configure trace settings.

![Data Asset Configuration](Distribution/Setup_DataAsset.png)

### 3. Usage
Attach the `PRFootstepComponent` to your Character.
- **AnimNotify**: Insert the `PR_Footstep` notify into your Locomotion animations.
- **Distance Mode**: Set `TriggerMode` to *Distance* for automatic triggering.

---

## 📦 Package Contents

- **PRFootstepComponent**: Lightweight C++ Actor Component.
- **20+ High-Fidelity Audio Samples**: WAVs and SoundCues.
- **Showcase Level**: Fully configured demo environment.

![Audio System](Distribution/Audio_System.png)

---

## 🔧 Technical Specifications

- **Class**: `UPRFootstepComponent` / `UPRFootstepData`.
- **Networking**: Client-side cosmetic execution (RPC replication supported).
- **License**: MIT (Commercial use authorized).

(c) 2026 ProtoReady Pack
