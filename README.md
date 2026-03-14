# Guía rápida para abrir Paparazzi Center y GCS desde este repositorio

Esta guía está pensada para que cualquier usuario del proyecto fondecyt pueda clonar **mi fork** y ejecutar exactamente los módulos/configuraciones que tiene este repositorio.

Repositorio:

```bash
git clone https://github.com/gersongallardo/paparazzi.git
```

---

## 1) Dependencias (Ubuntu 22.04/24.04)

> Si usan otra distro, conviene usar una VM Ubuntu o Docker de Paparazzi.

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

## 2) Clonar tu repositorio y preparar submódulos

```bash
git clone https://github.com/gersongallardo/paparazzi.git
cd paparazzi
git submodule sync --recursive
git submodule update --init --recursive
```

---

## 3) Instalar entorno Python del proyecto

```bash
./install.sh
```

Si `install.sh` crea el entorno virtual `pprzEnv`, activarlo en cada terminal:

```bash
source pprzEnv/bin/activate
```

---

## 4) Compilar Paparazzi con tus módulos

```bash
make clean
make -j"$(nproc)"
```

> Esto compila usando los archivos de configuración y módulos que están en **este fork** (por ejemplo en `conf/` y `sw/`).

---

## 5) Abrir Paparazzi Center

```bash
./paparazzi
```

Alternativa:

```bash
./start.py
```

---

## 6) Abrir GCS

Si la GCS no se abre automáticamente desde Paparazzi Center, abrirla manualmente:

```bash
pprzgcs
```

---

## 7) Flujo mínimo para controlar UAV (simulación)

1. En Paparazzi Center, elegir la aeronave de tu configuración (`conf/`).
2. Elegir target `sim`.
3. Presionar **Build**.
4. Ir a **Operation** → **Simulation** → **Start Session**.
5. Verificar telemetría en GCS (`pprzgcs`).
6. Desde la GCS, activar bloque de navegación / comandos según tu plan de vuelo.

---

## 8) Comandos “copiar y pegar” (resumen completo)

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

## 9) Nota importante para que usen *tus* módulos

Para asegurar que el usuario usa exactamente mis configuraciones:

```bash
cd paparazzi
git remote -v
git branch --show-current
git log --oneline -n 5
```

Debería verse el remoto `gersongallardo/paparazzi` y el commit que tú les indiques.
