# ProtoReady: Footstep System

![UE5](https://img.shields.io/badge/Unreal_Engine-5.5+-0078D7?style=for-the-badge&logo=unrealengine&logoColor=white) 
![CPP](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) 
![Replication](https://img.shields.io/badge/REPLICATION-Supported-28A745?style=for-the-badge&labelColor=28A745)

> **Готовая к продакшену система шагов, настройка менее чем за 5 минут.**
>
> *   Компоненты **Drag-and-drop**
> *   **Авто-конфигурация** через DataAssets
> *   **Ноль кода** (boilerplate) не требуется
> *   **Быстрый старт** понятный (< 5 мин)
> *   **Подсказки (Tooltips)** в редакторе

![Showcase Level](Distribution/pr_footstep_banner_v3.png)

![Trace Channel](https://img.shields.io/badge/Trace_Channel-Configurable-28A745?style=flat-square&labelColor=28A745) ![Distance](https://img.shields.io/badge/Trigger-Distance-000000?style=flat-square&labelColor=000000) ![AnimNotify](https://img.shields.io/badge/Trigger-AnimNotify-d00000?style=flat-square&labelColor=d00000)

---

## ⚡ Ключевые возможности

*   **Настройка без кода**: Строго через DataAsset. Дизайнеры управляют конфигурацией, а не логикой.
*   **Физическое взаимодействие**: Автоматически валидирует поверхности через `PhysicalMaterials`, предотвращая "звук камня на траве".
*   **Гибкость трейсов**: Опции Sphere, Line, Box и Multi-trace для точного обнаружения.
*   **Гибридный триггеринг**: Точный по кадру **AnimNotify** или процедурно вычисляемая **Дистанция** (Distance).
*   **Аудио микс**: Полная поддержка Спатиализации (Spatialization), Аттенюации (Attenuation) и случайной модуляции.

---

## Установка (Setup)
![Setup](https://img.shields.io/badge/Setup-≈_5_min-28A745?style=flat-square)

1.  **Включите плагин**: Edit > Plugins > ProtoReady Footstep.
2.  **Определите ваши Физические Поверхности**: Edit > Project Settings > Engine > Physics > Physical Surface.
3.  **Добавьте `PRFootstepComponent`** к вашему Персонажу (или любому Actor).
4.  **Создайте DataAsset `PRFootstepData`** и назначьте его компоненту.

*Примеры поверхностей: Concrete, Dirt, Grass, Water, Wood. Если существует только один `PRFootstepData`, он назначается автоматически при создании.*

![Data Asset](Distribution/Setup_DataAsset.png)

---

## Как это работает

### Триггер шагов (Footstep triggering)
*   **AnimNotify (анимация)**: Добавьте notify `PR_Footstep` к вашим анимациям. Notify открывает `FootSocketName` и доступен немедленно.
*   **Distance (авто)**: Запускает шаг каждые `DistanceInterval` см пройденного пути. В режиме Distance, Tick включается автоматически.

### Приземление (Landing)
*   `bAutoTriggerLand` автоматически привязывается к `ACharacter::LandedDelegate`.
*   `LandingSound` используется, если задан; иначе система проигрывает стандартный звук шага с флагом landing.

### Трейсы и поверхности
*   Обнаружение поверхности выполняется трейсом по **Настраиваемому Каналу Коллизии** (По умолчанию: `ECC_Visibility`).
*   Поверхности берутся из **Physical Material** меша. Если отсутствует, используется `SurfaceType_Default`.
*   `DefaultSound` - это запасной звук, используемый, когда поверхность не сопоставлена или Physical Material не найден.

---

## Содержимое пакета

*   **PRFootstepComponent**: Легковесный C++ Actor Component.
*   **PRFootstepData**: DataAsset конфигурации.
*   **20+ Аудио Сэмплов**: Бетон, Грязь, Трава, Дерево, Вода.
*   **5 SoundCues** и Физических Материалов.
*   **Демонстрационный Уровень (Showcase)**.

![Audio System](Distribution/Audio_System.png)

---

## Технические Характеристики

### Классы
*   **`UPRFootstepComponent`** (`UActorComponent`): Центральный логический движок (Tick, Trace, Spawn). Оптимизирован с LOD.
*   **`UPRFootstepData`** (`UPrimaryDataAsset`): Центральный контейнер конфигурации.

### Blueprint API
![BP](https://img.shields.io/badge/Blueprint-Nodes-00599C?style=flat-square)

Система предоставляет ключевые функции для геймплейной логики:

| Нода | Описание | Пример использования |
| :--- | :--- | :--- |
| **Set Trigger Mode** | Переключение между логикой `AnimNotify` и `Distance` в рантайме. | Патруль NPC vs Боевой режим. |
| **Set Footstep Interval** | Изменение дистанции шага. | Ходьба vs Бег. |
| **Trigger Footstep** | Принудительный запуск одиночного трейса шага. | Катсцены или события приземления. |

---

## Лицензия

**MIT License**.
(c) 2026 ProtoReady Pack
