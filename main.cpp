#include "raylib.h"
#include "Heroe.h"
#include "Enemigo.h"
#include "Sala.h"
#include "Arma.h"
#include <vector>

int main() {
    InitWindow(900, 600, "Natal Combat - Enemigos contraatacan");
    SetTargetFPS(60);

    std::vector<Heroe> heroes = {
        Heroe("Aidan", 100, 15, 5, 8, 2),
        Heroe("Lyra", 90, 18, 4, 9, 3),
        Heroe("Bran", 110, 12, 7, 5, 1)
    };

    std::vector<Sala> salas = {
        Sala(1, {
            Enemigo("Soldado", "Goblin", 60, 10, 3, 6, 1),
            Enemigo("Soldado", "Murciélago", 50, 8, 2, 8, 2),
            Enemigo("Soldado", "Orco", 70, 12, 4, 5, 1)
        }, Arma("Espada de Bronce", 3)),

        Sala(2, {
            Enemigo("MiniJefe", "Ogro", 120, 20, 8, 4, 2),
            Enemigo("Soldado", "Brujo", 80, 15, 3, 6, 3),
            Enemigo("Soldado", "Trol", 90, 14, 5, 5, 1)
        }, Arma("Hacha Afilada", 4)),

        Sala(3, {
            Enemigo("GranJefe", "Señor de las Sombras", 200, 25, 10, 6, 5),
            Enemigo("MiniJefe", "Espectro", 120, 18, 6, 7, 4),
            Enemigo("Soldado", "Bestia", 100, 16, 4, 6, 2)
        }, Arma("Espada de Fuego", 5))
    };

    int salaActual = 0;
    bool salaGanada = false;
    bool juegoPerdido = false;
    bool cofreDado = false;
    bool mostrarArma = false;
    std::string armaRecibida;

    int heroeSeleccionado = -1;
    Vector2 mouse;

    while (!WindowShouldClose()) {
        std::vector<Enemigo>& enemigos = salas[salaActual].enemigos;

        salaGanada = true;
        for (auto& e : enemigos)
            if (e.hp > 0) salaGanada = false;

        juegoPerdido = true;
        for (auto& h : heroes)
            if (h.hp > 0) juegoPerdido = false;

        if (salaGanada && !cofreDado) {
            std::vector<int> vivos;
            for (int i = 0; i < heroes.size(); i++)
                if (heroes[i].hp > 0) vivos.push_back(i);

            if (!vivos.empty()) {
                int elegido = vivos[GetRandomValue(0, vivos.size() - 1)];
                Arma* nuevaArma = new Arma(salas[salaActual].cofre);
                heroes[elegido].equiparArma(nuevaArma);
                armaRecibida = nuevaArma->nombre + " (+ATK)";
                mostrarArma = true;
                cofreDado = true;
            }
        }

        mouse = GetMousePosition();

        if (!salaGanada && !juegoPerdido) {
            for (int i = 0; i < heroes.size(); i++) {
                Rectangle area;
                area.x = 50;
                area.y = 80 + i * 80;
                area.width = 200;
                area.height = 30;

                if (CheckCollisionPointRec(mouse, area) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && heroes[i].hp > 0) {
                    heroeSeleccionado = i;
                }
            }

            if (heroeSeleccionado != -1) {
                for (int j = 0; j < enemigos.size(); j++) {
                    Rectangle zona;
                    zona.x = 500;
                    zona.y = 80 + j * 80;
                    zona.width = 200;
                    zona.height = 30;

                    if (CheckCollisionPointRec(mouse, zona) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && enemigos[j].hp > 0) {
                        heroes[heroeSeleccionado].atacar(enemigos[j].def, enemigos[j].hp);

                        std::vector<int> enemigosVivos;
                        for (int k = 0; k < enemigos.size(); k++)
                            if (enemigos[k].hp > 0) enemigosVivos.push_back(k);

                        std::vector<int> heroesVivos;
                        for (int k = 0; k < heroes.size(); k++)
                            if (heroes[k].hp > 0) heroesVivos.push_back(k);

                        if (!enemigosVivos.empty() && !heroesVivos.empty()) {
                            int enemigoQueAtaca = enemigosVivos[GetRandomValue(0, enemigosVivos.size() - 1)];
                            int heroeAtacado = heroesVivos[GetRandomValue(0, heroesVivos.size() - 1)];
                            enemigos[enemigoQueAtaca].atacar(heroes[heroeAtacado].def, heroes[heroeAtacado].hp);
                        }

                        heroeSeleccionado = -1;
                        break;
                    }
                }
            }
        }

        if (salaGanada && IsKeyPressed(KEY_ENTER)) {
            salaActual++;
            if (salaActual >= salas.size()) salaActual = 0;
            for (auto& h : heroes) h.hp = 100;
            cofreDado = false;
            mostrarArma = false;
            heroeSeleccionado = -1;
        }

        if (juegoPerdido && IsKeyPressed(KEY_R)) {
            salaActual = 0;
            for (auto& h : heroes) h.hp = 100;
            cofreDado = false;
            mostrarArma = false;
            heroeSeleccionado = -1;
        }

        BeginDrawing();
        ClearBackground(DARKGRAY);

        DrawText(TextFormat("SALA %d", salas[salaActual].numero), 380, 20, 30, YELLOW);

        for (int i = 0; i < 3; i++) {
            Color c = (i == heroeSeleccionado ? GOLD : WHITE);
            DrawRectangle(45, 80 + i * 80, 360, 30, Fade(c, 0.1f));
            DrawText(("Héroe: " + heroes[i].nombre).c_str(), 50, 80 + i * 80, 20, c);
            DrawText(TextFormat("HP: %d", heroes[i].hp), 200, 80 + i * 80, 20, RED);
            DrawText(TextFormat("ATK: %d", heroes[i].obtenerAtaqueTotal()), 300, 80 + i * 80, 20, ORANGE);
        }

        for (int i = 0; i < 3; i++) {
            DrawRectangle(495, 80 + i * 80, 360, 30, Fade(WHITE, 0.05f));
            DrawText(("Enemigo: " + enemigos[i].nombre).c_str(), 500, 80 + i * 80, 20, WHITE);
            DrawText(("Tipo: " + enemigos[i].tipo).c_str(), 650, 80 + i * 80, 20, GRAY);
            DrawText(TextFormat("HP: %d", enemigos[i].hp), 800, 80 + i * 80, 20, RED);
        }

        if (heroeSeleccionado != -1 && !salaGanada)
            DrawText("Selecciona un enemigo para atacar", 260, 520, 20, GREEN);

        if (salaGanada)
            DrawText("¡Sala superada! Presiona [ENTER]", 270, 520, 20, SKYBLUE);

        if (juegoPerdido)
            DrawText("¡Derrota! Presiona [R] para reiniciar", 250, 520, 20, MAROON);

        if (mostrarArma)
            DrawText(TextFormat("¡Arma obtenida: %s!", armaRecibida.c_str()), 250, 460, 20, GOLD);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
