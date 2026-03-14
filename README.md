# Guía rápida para abrir Paparazzi Center y GCS desde este repositorio

Esta guía está pensada para que cualquier usuario del proyecto fondecyt pueda clonar **mi fork** y ejecutar exactamente los módulos/configuraciones que tienes en este repositorio.

Repositorio:

```bash
git clone https://github.com/gersongallardo/paparazzi.git
```

---

## 1) Compatibilidad por sistema operativo

- **Ubuntu 22.04 y 24.04**: ✅ recomendado, debería funcionar bien con esta guía.
- **Ubuntu 23.xx (23.04/23.10)**: ⚠️ puede funcionar, pero es una versión intermedia/no LTS; algunos paquetes pueden cambiar de nombre o versión.
- **Debian 12 (bookworm)**: ⚠️ funciona para compilar y ejecutar bastante del entorno, pero los paquetes `paparazzi-*` o `pprzgcs` pueden no estar disponibles igual que en Ubuntu.

Si es posible para evaluación, lo más estable es usar **Ubuntu 22.04 o 24.04 LTS**.

---

## 2) Dependencias base (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install -y \
  git build-essential make pkg-config \
  python3 python3-venv python3-pip python3-setuptools \
  python3-pyqt5 python3-lxml python3-numpy python3-serial \
  gcc-arm-none-eabi gdb-multiarch dfu-util \
  pprzgcs
```

Dependencias opcionales recomendadas:

```bash
sudo apt install -y \
  gazebo libgazebo-dev \
  ffmpeg vlc jstest-gtk default-jre
```

---

## 3) Clonar tu repositorio y preparar submódulos

```bash
git clone https://github.com/gersongallardo/paparazzi.git
cd paparazzi
git submodule sync --recursive
git submodule update --init --recursive
```

---

## 4) Instalar entorno Python del proyecto

```bash
./install.sh
```

Si en Ubuntu 23 o Debian falla alguna parte automática de `install.sh`, usar alternativa manual:

```bash
python3 -m venv pprzEnv
source pprzEnv/bin/activate
python3 -m pip install --upgrade pip
python3 setup.py
```

Si `install.sh` crea el entorno virtual `pprzEnv`, activarlo en cada terminal:

```bash
source pprzEnv/bin/activate
```

---

## 5) Compilar Paparazzi con tus módulos

```bash
make clean
make -j"$(nproc)"
```

> Esto compila usando los archivos de configuración y módulos que están en **este fork** (por ejemplo en `conf/` y `sw/`).

---

## 6) Abrir Paparazzi Center

```bash
./paparazzi
```

Alternativa:

```bash
./start.py
```

---

## 7) Abrir GCS

Si la GCS no se abre automáticamente desde Paparazzi Center, abrirla manualmente:

```bash
pprzgcs
```

Si `pprzgcs` no está instalado (caso típico en Debian), abrir el GCS incluido en el repo:

```bash
python3 sw/ground_segment/python/gcs/gcs.py
```

---

## 8) Flujo mínimo para controlar UAV (simulación)

1. En Paparazzi Center, elegir la aeronave de tu configuración (`conf/`).
2. Elegir target `sim`.
3. Presionar **Build**.
4. Ir a **Operation** → **Simulation** → **Start Session**.
5. Verificar telemetría en GCS (`pprzgcs`).
6. Desde la GCS, activar bloque de navegación / comandos según tu plan de vuelo.

---

## 9) Comandos “copiar y pegar” (Ubuntu 22.04/24.04 recomendado)

```bash
sudo apt update
sudo apt install -y git build-essential make pkg-config \
  python3 python3-venv python3-pip python3-setuptools \
  python3-pyqt5 python3-lxml python3-numpy python3-serial \
  gcc-arm-none-eabi gdb-multiarch dfu-util pprzgcs

# opcional
sudo apt install -y gazebo libgazebo-dev ffmpeg vlc jstest-gtk default-jre

git clone https://github.com/gersongallardo/paparazzi.git
cd paparazzi
git submodule sync --recursive
git submodule update --init --recursive

./install.sh
source pprzEnv/bin/activate

make clean
make -j"$(nproc)"

./paparazzi
# en otra terminal, si hace falta:
pprzgcs
```

---

## 10) Variante para Ubuntu 23 / Debian 12 (fallback)

```bash
sudo apt update
sudo apt install -y git build-essential make pkg-config \
  python3 python3-venv python3-pip python3-setuptools \
  python3-pyqt5 python3-lxml python3-numpy python3-serial \
  gcc-arm-none-eabi gdb-multiarch dfu-util

git clone https://github.com/gersongallardo/paparazzi.git
cd paparazzi
git submodule sync --recursive
git submodule update --init --recursive

python3 -m venv pprzEnv
source pprzEnv/bin/activate
python3 -m pip install --upgrade pip
python3 setup.py

make clean
make -j"$(nproc)"

./paparazzi
# GCS alternativa si no existe paquete pprzgcs
python3 sw/ground_segment/python/gcs/gcs.py
```

---

## 11) Nota importante para que usen *mis* módulos

Para asegurar que el usuario usa exactamente mis configuraciones:

```bash
cd paparazzi
git remote -v
git branch --show-current
git log --oneline -n 5
```

Debería verse el remoto `gersongallardo/paparazzi` y el commit que tú les indiques.
