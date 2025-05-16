# 🛡️ Natal Combat

**Natal Combat** es un videojuego de combate por turnos en mazmorras (tipo RPG) hecho en C++ utilizando [Raylib](https://www.raylib.com/).  

Permite batallas 3 vs 3 entre héroes y enemigos, con un sistema de cofres, armas equipables y avance por salas.

---

## 🎮 Características

- Combate táctico por turnos: elige qué héroe ataca y a qué enemigo
- Cofres al finalizar cada sala con armas que mejoran el ataque
- Opción para aceptar/rechazar el arma y asignarla a un héroe
- Visualización de arma equipada junto a cada personaje
- Reemplazo interactivo si ya se tiene un arma equipada
- Visual simple usando Raylib (ventana y texto)

---

## 🧱 Estructura del código

- `main.cpp` — lógica principal del juego
- `Heroe.h / Heroe.cpp` — clase para héroes
- `Enemigo.h / Enemigo.cpp` — clase para enemigos
- `Arma.h / Arma.cpp` — define las armas y sus bonus
- `Sala.h / Sala.cpp` — define cada sala y sus enemigos
- `resources/equip.wav` *(opcional)* — sonido al equipar arma (no se usa actualmente)

---

## ▶️ Cómo ejecutar

1. Asegúrate de tener **Raylib** instalado y configurado en tu entorno (por ejemplo, CLion + MinGW + CMake).
2. Clona este repositorio:
   ```bash
   git clone https://github.com/tu-usuario/NatalCombat.git
   cd NatalCombat
   ```
3. Compila el proyecto (`main.cpp` y demás `.cpp`).
4. Ejecuta el juego.

---

## 📦 Requisitos

- C++17 o superior
- Raylib 4.x
- CMake (opcional, para compilar con CLion)

---

## 📌 Controles

| Acción                       | Tecla                    |
|-----------------------------|--------------------------|
| Seleccionar héroe           | Clic en la lista izquierda |
| Atacar enemigo              | Clic en enemigo a la derecha |
| Aceptar arma del cofre      | `A`                      |
| Rechazar arma del cofre     | `R`                      |
| Asignar arma al héroe       | `1`, `2`, `3`            |
| Confirmar reemplazo de arma | `Y` (sí), `N` (no)       |
| Siguiente sala              | `ENTER` (si ganaste)     |
| Reiniciar juego             | `R` (si perdiste)        |

---

## 🧑‍💻 Autor

Desarrollado por **[Tu Nombre]** como proyecto de programación orientada a objetos.

---

## 📜 Licencia

Este proyecto es de uso académico. Puedes reutilizarlo y modificarlo con fines educativos.
